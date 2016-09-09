/*Fila Implementada com Ponteiros
Estrutura de Dados e Algoritmos I - Professor Flávio
2016.1
Daiane Mascarenhas Lauro da Silva*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 	noFilaInt{
	int conteudo;
	struct noFilaInt *prox;	
}noFilaInt;

typedef struct{
	noFilaInt *prim, *ultimo;
}filaInt;

void inicializar(filaInt *f);
_Bool enfileirar(filaInt *f, int x);
_Bool desenfileirar(filaInt *f, int *x);
void imprimir (filaInt f);
int main()
{
	int entrada = 0, n, x;
	filaInt y;
	inicializar(&y);
	do{
		printf("\n--------------------------------\n");
		printf("Digite a operação desejada:\n");
		printf("1. Inserir Número na Fila\n");
		printf("2. Retirar Número da Fila\n");
		printf("3. Imprimir Fila\n");
		printf("0. Sair\n");
		printf("\n\nOperação Desejada: ");
		scanf("%d",&entrada);
		switch (entrada)
       		{
        		case 1:
				printf("\n\nDigite o número que deseja inserir na Fila: ");
				scanf("%d", &n);
				if(enfileirar(&y,n)) printf("\nO número foi inserido na Fila.\n\n");
				else printf("\nO número não foi inserido na Fila\n\n"); 	
        			break;
        		case 2:
				if(desenfileirar(&y,&x)) printf("O %d era o primeiro da fila\n", x);
				else printf("Lista Vazia\n");
        			break;
        		case 3:
        			imprimir(y);
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

void inicializar(filaInt *f){
	f->prim = NULL;
}

_Bool enfileirar(filaInt *f, int x){
	noFilaInt *p;
	if(!(p = (noFilaInt *)malloc(sizeof(noFilaInt)))) return false;
	p->conteudo = x;
	p->prox = NULL;	
	if(f->prim){
		f->ultimo->prox = p;
		f->ultimo = p;
	}
	else{
		f->ultimo = p;
		f->prim = p;
	}
	return true;
}
_Bool desenfileirar(filaInt *f, int *x){
	noFilaInt *p;
	p = f->prim;
	if(!f->prim) return false;
	*x = f->prim->conteudo;
	if(f->prim == f->ultimo){
		free(p);
		f->prim = NULL;
	}
	else{
		f->prim = f->prim->prox;
		free(p);	
	}
	return true;
	
}

void imprimir(filaInt f){
	noFilaInt *p;
	if(f.prim){
		printf("\nFila: ");
		for(p = f.prim; p != NULL; p=p->prox)
			printf("%d ",p->conteudo);
		printf("\n");
	}
}
