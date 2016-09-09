/*Lista Implementada com Vetor
Estrutura de Dados e Algoritmos I - Professor Flávio
2016.1
Daiane Mascarenhas Lauro da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tamanhodaLista 10

typedef struct{
	int conteudo[tamanhodaLista];
	int nElems;
}lista;

void inicializar(lista *l);
_Bool consulta(lista l, int x);
_Bool inserir(lista *l, int x);
void retira(lista *l, int x);
void imprimir (lista l);

int main()
{
	int entrada = 0, n;
	lista l;
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
void inicializar(lista *l){
	l->nElems = 0;
}
	
_Bool consulta (lista l, int x){
	int i = 0;
	if(l.nElems == 0) return false;
	for(i = 0; i < l.nElems && l.conteudo[i] != x; i++);
	if (i==l.nelems)
		return false;
	return true;

}

_Bool inserir(lista *l, int x){
	if( l->nElems == tamanhodaLista || consulta(*l,x)) return false;
	l->conteudo[l->nElems] = x;
	l->nElems++;
	return true;
}

void retira(lista *l, int x){
	int i;
	if(l){
		if((l->nElems) && (consulta(*l,x))){
			for(i = 0; l->conteudo[i] != x; i++);
			l->conteudo[i] == l->conteudo[l->nElems-1];
			l->nElems--;
		}
	}
}

void imprimir(lista l){
	int i;
	printf("\nLista: ");
	for(i = 0; i < l.nElems; i++)
		printf("%d ", l.conteudo[i]);
	printf("\n");
}

