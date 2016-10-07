#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct pilha Pilha;
Pilha* cria (void);
void push (Pilha* p, int v);
int pop (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
int retornatopo(Pilha* p);
void resto(Pilha *temp, Pilha *entr);
void mostraTodaPilha(Pilha *p);
int retornatopo(Pilha* p);
int retornaTamanho(Pilha* p);
int main()
{

	int vagoes, z, i, j;

	Pilha *temp, *entr, *entr1;
	entr = cria();
	temp = cria();
	entr1 = cria();


	while(1)
	{
		scanf("%d", &vagoes);
		if(!vagoes)
		{
			break;
		}


		while(1)
		{
			libera(entr);
			libera(entr1);
			libera(temp);
			for( j = 0; j < vagoes; j++)
			{
				scanf(" %d", &z);

				if(z == 0)
				{
					break;
				}

				push(entr1, z);
			}
			if(z)
			{
				for( j = 0; j < vagoes; j++)
				{
					push(entr, pop(entr1));
				}

				for( i = 1; i <= vagoes; i++)
				{
					push(temp, i);
					if(retornatopo(entr) == retornatopo(temp))
					{
					//	pop(entr);
					//	pop(temp);
						resto(temp, entr);
					}
				}
				if (vazia(entr))
				{
					printf("Yes\n");
				}
				else
				{
					printf("No\n");
				}
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}

struct pilha
{
	int TOPO;
	int vet[MAX];
};

Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->TOPO = 0; /* inicializa com zero elementos */
	return p;
}
void push (Pilha* p, int v)
{
	if (p->TOPO == MAX)
	{
		/* capacidade esgotada */

		printf("Capacidade da pilha estourou.\n ");

		exit(1); /* aborta programa */

	}
	/* insere elemento na próxima posição livre */
	p->TOPO++;
	p->vet[p->TOPO] = v;
}

int pop (Pilha* p)
{
	int v;
	if (vazia(p))
	{
		printf("Pilha vazia.\n");

		exit(1); /* aborta programa */
	}

	/* retira elemento do topo */

	v = p->vet[p->TOPO];

	p->TOPO-- ;
	return v;

}

int vazia (Pilha* p)
{
	int i;
	i = (p->TOPO == 0);
	return i;

}

void libera (Pilha* p )
{
	p->TOPO = 0;
}
int retornatopo(Pilha* p)
{
	int z;
	z = pop(p);
	push(p, z);
	return z;

}
int retornaTamanho(Pilha* p)
{
	return p->TOPO;

}
void resto(Pilha *temp, Pilha *entr)
{
	if(!vazia(temp))
	{
		if( retornatopo(entr) == retornatopo(temp) )
		{
			pop(temp);
			pop(entr);

			resto(temp, entr);
		}
	}
}
/*
void mostraTodaPilha(Pilha *p)
{
	int x;
	Pilha *alt;
	alt = cria();
	printf("^^^^^^^^^^^^^^^^^^^^^^^^\n");

	while(!vazia(p))
	{
		x = pop(p);
		printf("-> %d", x);
		push(alt, x);
	}
	printf("\n---------------------------------end\n");
	while(!vazia(p))
	{
		push(p, pop(alt));
	}
}
*/