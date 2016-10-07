#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 1000

struct pilha {
	int topo;
	char vet[max];
};

typedef struct pilha Pilha;
Pilha* cria(void);
void push (Pilha* p, char letra);
int vazia (Pilha* p);
int cheia (Pilha* p);
char pop (Pilha* p);
void libera (Pilha* p);

Pilha* cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = 0;
	/*
	p ->topo++;
	p->vet[p->topo] = 'F';
	p -> topo++;
	p->vet[p->topo] = 'A';
	p -> topo++;
	p->vet[p->topo] = 'C';
	p -> topo++;
	p->vet[p->topo] = 'E';
	*/
	return p;
}

int cheia(Pilha* p){
	
	return (p ->topo == max-1);	
}

void push(Pilha* p, char letra){
	if(cheia(p))
		printf("Pilha Cheia !!!");
		
	else{
		p ->topo++;
		p ->vet[p ->topo] = letra;
	}	
}

int vazia(Pilha* p){
	return(p->topo == 0);
}

char pop (Pilha* p){
	char letra;
	if(vazia(p)){
		printf("Pilha vazia !!!\n\n");
		system("pause");
		exit(1);
	}
	
	letra = p ->vet[p->topo];
	p->topo--;
	return letra;
}

void libera(Pilha* p){
	free(p);
}

int main(){
	
	Pilha *pprincipal;
	char letras[310], e1, e2;
	int cont, i = 0;
		pprincipal = cria();
		if(vazia(pprincipal)){
			printf("AH SAFADA");
		}
	
		while(gets(letras)){
			cont=0;
			pprincipal = cria();
			for(i=0;letras[i]!='\0';i++)
			{					
				  push(pprincipal, letras[i]);
				  if(pprincipal -> topo >=2){
					e2 = pop(pprincipal);
					e1 = pop(pprincipal);
					if((e1 == 'B' && e2 == 'S')||(e1 == 'S' && e2 == 'B') && (e1 != e2)){
						cont++;
					}
					else if((e1 == 'C' && e2 == 'F')||(e1 == 'F' && e2 == 'C') && (e1 != e2)){
						cont++;
					}
					else{
						push(pprincipal, e1);
						push(pprincipal, e2);
					}
				}
			}
			free(pprincipal);
			printf("%d\n",cont);
		}
	return 0;
}













