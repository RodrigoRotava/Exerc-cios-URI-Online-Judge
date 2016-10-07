#include<stdio.h>
#include<stdlib.h>

#define max 1000

struct pilha {
	int topo;
	char vet[max];
};

typedef struct pilha Pilha;
Pilha* cria(void);
void push (Pilha* p, char letras);
int vazia (Pilha* p);
char pop (Pilha* p);
void libera (Pilha* p);


Pilha* cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p ->topo = 0;
	return p;
}

void push(Pilha* p, char letras){
	if(p -> topo == max){

		printf("A pilha estorou !!!\n\n");
		system("pause");
		exit(1); // aborta o programa.
	}
	//insere elementeos na proxima posição livre.
	p ->topo++;
	p->vet[p->topo] = letras;
}

int vazia(Pilha* p){
	return(p->topo == 0);
}

char pop (Pilha* p){
	char letras;
	if(vazia(p)){
		printf("Pilha vazia !!!\n\n");
		system("pause");
		exit(1);
	}
	//retira elemento da pilha.
	letras = p ->vet[p->topo];
	p->topo--;
	return letras;
}

int verificador1(Pilha *p){
	int a;
	a = pop(p);
	push(p, a);
	return a;
}

void libera(Pilha* p){
	p ->topo = 0;
}

int main(){
	
	Pilha *pprincipal, *ptemp, *ptemp2, *ptemp3, *ptemp4;
	int n, i, j;
	char letra, entrada;
	
	pprincipal = cria();
	ptemp = cria();
	ptemp2 = cria();
	ptemp3 = cria();
	ptemp4 = cria();
	
	while(1){
		
		libera(pprincipal);
		libera(ptemp);
		libera(ptemp3);
		libera(ptemp4);
		libera(ptemp2);
		
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i=0;i<n;i++){
			scanf(" %c", &letra);
			push(pprincipal, letra);
		}
		for(j=0;j<n;j++){
			scanf(" %c", &entrada);
			push(ptemp, entrada);
		}
		for(i=0;i<n;i++){
			push(ptemp3, pop(ptemp));
		}
		for(i=0;i<n;i++){
			push(ptemp4, pop(pprincipal));
		}
		
		for(i=0;i<n;i++){
			j = 0;
			push(ptemp2, pop(ptemp4));
			
			if(verificador1(ptemp3) == verificador1(ptemp2)){
				printf("I");
				j = 1;				
				aqui:
				if(!vazia(ptemp2)){
					if(verificador1(ptemp3) == verificador1(ptemp2)){
						pop(ptemp3);
						pop(ptemp2);
						printf("R");
						goto aqui;
					}
				}
			}
			if(j == 0)
				printf("I");
		}		
		if(!vazia(ptemp3)){
			printf(" Impossible");
		}
		printf("\n");
	}

	return 0;
}