/*Lista Duplamente Encadeada
Estrutura de Dados e Algoritmos I - Professor Flávio
2016.1
Daiane Mascarenhas Lauro da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 	noListaInt{
	int conteudo;
	struct noListaInt *prox, *anter;	
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
				if(inserir(&l,n)) printf("\nO número foi inserido na Lista.\n\n");
				else printf("\nO número não foi inserido na Lista\n\n"); 	
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
	noListaInt *p;
	for(p = l; p!=NULL && p->conteudo!=x; p = p->prox);
	if (p) return true;
	return false;
}

_Bool inserir(listaInt *l, int x){ // Inseri no inicio para economizar com o for
	noListaInt *novo, *p;
	p=*l;
	if(consulta(*l,x) || !(novo = (noListaInt *)malloc(sizeof(noListaInt)))) return false;
	novo->conteudo = x;
	novo->prox=NULL;
	novo->anter = NULL;
	if(p){
		novo->prox = p;
		p->anter = novo;
	}
	*l = novo;
	return true;
}

void retira(listaInt *l, int x){
	noListaInt *p;
	p=*l;
	if(p){
		if(consulta(*l,x)){
			for(p=*l; p->conteudo != x; p=p->prox);
			if(p->anter == NULL){
				*l=p->prox;
				p->anter = NULL;
			}
			else if(p->prox == NULL)
				p->anter->prox = NULL;
			else{
				p->anter->prox = p->prox;
				p->prox->anter = p->anter;
			}
			free(p);
		}
	}

}

void imprimir (listaInt l){
	noListaInt *p;
	printf("\nSua Lista: ");
	for(p = l; p != NULL; p=p->prox)
		printf("%d ", p->conteudo);

	printf("\n");
}
