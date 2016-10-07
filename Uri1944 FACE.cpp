#include<stdio.h>
#include<stdlib.h>

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
	p ->topo++;
	p->vet[p->topo] = 'F';
	p -> topo++;
	p->vet[p->topo] = 'A';
	p -> topo++;
	p->vet[p->topo] = 'C';
	p -> topo++;
	p->vet[p->topo] = 'E';

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
	
	int n, i=0, brinde = 0;
	char letra, e1, e2, e3, e4, d1, d2, d3, d4;
	Pilha *pprincipal;
	pprincipal = cria();
	scanf("%d", &n);
	while(i<n){
			if(vazia(pprincipal))
				pprincipal = cria();			
						
			scanf(" %c", &letra);
			push(pprincipal, letra);
			scanf(" %c", &letra);
			push(pprincipal, letra);
			scanf(" %c", &letra);
			push(pprincipal, letra);
			scanf(" %c", &letra);
			push(pprincipal, letra);			
			
			e4 = pop(pprincipal);
			e3 = pop(pprincipal);
			e2 = pop(pprincipal);
			e1 = pop(pprincipal);
			
			d1 = pop(pprincipal);
			d2 = pop(pprincipal);
			d3 = pop(pprincipal);
			d4 = pop(pprincipal);
			
			if((e1 == d1)&&(e2 == d2)&&(e3 == d3)&&(e4 == d4)){
				brinde++;
			}
			else{
				push(pprincipal, d4);
				push(pprincipal, d3);
				push(pprincipal, d2);
				push(pprincipal, d1);
				push(pprincipal, e1);
				push(pprincipal, e2);
				push(pprincipal, e3);
				push(pprincipal, e4);
			}			
			i++;		
	}
	printf("%d\n", brinde);
	
	return 0;
}