/*Lista Simplesmente Encadeada
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

_Bool inserir(listaInt *l, int x){
	noListaInt *novo, *p;
	p=*l;
	if(consulta(*l,x) || !(novo = (noListaInt *)malloc(sizeof(noListaInt)))) return false;	
	novo->conteudo = x;
	novo->prox = p;
	*l = novo;
	return true;
}

void retira(listaInt *l, int x){
//Melhorar essa parte para não percorrer duas vezes a lista
	noListaInt *p, *aux = NULL;
	if(consulta(*l,x))
	{
		for(p = *l; p->conteudo!= x; aux = p, p = p->prox);
		if(aux == NULL)
			*l = p->prox;
		else
			aux->prox = p->prox;
		free(p);
	}
}

void imprimir (listaInt l){
	noListaInt *p;
	printf("\nSua Lista: ");
	for(p = l; p != NULL; p=p->prox)
		printf("%d ", p->conteudo);

	printf("\n");
}
