/*Lista Circular Simplesmente Encadeada
Estrutura de Dados e Algoritmos I - Professor Flávio
2016.1
Daiane Mascarenhas Lauro da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 	noListaInt{
	int conteudo;
	struct noListaInt *prox;	
}noListaInt, *listaInt;

void inicializar(listaInt *l);
_Bool consulta(listaInt l, int x);
_Bool inserir(listaInt *l, int x);
void retira(listaInt *l, int x);
void imprimir (listaInt l);
int main()
{
	int entrada = 0, n;
	listaInt l;
	inicializar(&l);
	do{
		printf("\n--------------------------------\n");
		printf("Digite a operação desejada:\n");
		printf("1. Consultar\n");
		printf("2. Inserir Número na Lista\n");
		printf("3. Retirar Número da Lista\n");
		printf("4. Imprimir Lista\n");
		printf("0. Sair\n");
		printf("\n\nOperação Desejada: ");
		scanf("%d",&entrada);
		switch (entrada)
       		{
        		case 1:
				printf("\n\nDigite o número que deseja procurar na Lista: ");
				scanf("%d", &n);
                		if(consulta(l,n)) printf("\nO número está contido na Lista\n\n");
				else printf("\nO número não está contido na Lista\n\n");
				break;
        		case 2:
				printf("\n\nDigite o número que deseja inserir na Lista: ");
				scanf("%d", &n);
				(inserir(&l,n)); 	
        			break;
        		case 3:
				printf("\n\nDigite o número que deseja remover da Lista: ");
				scanf("%d", &n);
				(retira(&l,n));
        			break;
        		case 4:
        			imprimir(l);
        			break;
        		case 0: printf("\nAdeus!\n\n");
				break;				
        		default:
                		printf ("\n\nValor Inválido\n\n");
        	}
	}
	while(entrada != 0);
	return 0;
}
void inicializar(listaInt *l){
	*l = NULL;
}
_Bool consulta(listaInt l, int x){
	noListaInt *p, *q;
	p = l;
	if(!p) return false;
	for(q = p->prox; q != l && q->conteudo != x; p = q, q = q->prox);
	if(q == l && p->conteudo != x) return false;
	return true;
}
_Bool inserir(listaInt *l, int x){
	noListaInt *p, *novo;
	p = *l;
	if(consulta(*l,x) || !(novo = (noListaInt *)malloc(sizeof(noListaInt)))) return false;
	else
	{
		novo->conteudo = x;
		if(p)
		{
			novo->prox = p->prox;
			p->prox = novo;
		}
		else
		{
			*l = novo;
			novo->prox = novo;
		}
		return true;
	}
}

void retira(listaInt *l, int x){
	noListaInt *p, *anterior, *q;
	q = *l;
	if(q){
		if(consulta(*l,x)){
			for(anterior = q, p = q->prox; p != q && p->conteudo != x; anterior = p, p = p->prox);
			if(p == *l && p->prox == *l){
				free(p);
				*l == NULL;
			}
			else if(*l == p && p->prox != *l){
				*l = p->prox;
				anterior->prox = p->prox;
				free(p);
			
			} 
			else{
				anterior->prox = p->prox;
				free(p);
			}
		}
	}
}
void imprimir (listaInt l){
	noListaInt *p;
	if(l){
		printf("Lista Circular: %d ", l->conteudo);
		for(p = l->prox; p != l; p=p->prox)
			printf("%d ", p->conteudo);
		printf("\n");
	}	 
}
