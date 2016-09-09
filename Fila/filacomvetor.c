/*Fila Implementada com Vetor
Estrutura de Dados e Algoritmos I - Professor Flávio
2016.1
Daiane Mascarenhas Lauro da Silva*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tamanhodaFila 5

typedef struct 	filaInt{
	int conteudo[tamanhodaFila];
	int inicio;
	int nElems;	
}filaInt;

void inicializar(filaInt *f);
_Bool consulta(filaInt, int x);
_Bool inserir(filaInt *f, int x);
void retira(filaInt *f);
void imprimir (filaInt f);
int main()
{
	int entrada = 0, n;
	filaInt f;
	inicializar(&f);
	do{
		printf("\n--------------------------------\n");
		printf("Digite a operação desejada:\n");
		printf("1. Consultar\n");
		printf("2. Inserir Número na Fila\n");
		printf("3. Retirar Número da Fila\n");
		printf("4. Imprimir Fila\n");
		printf("0. Sair\n");
		printf("\n\nOperação Desejada: ");
		scanf("%d",&entrada);
		switch (entrada)
       		{
        		case 1:
				printf("\n\nDigite o número que deseja procurar na Fila: ");
				scanf("%d", &n);
                		if(consulta(f,n)) printf("\nO número está contido na Fila\n\n");
				else printf("\nO número não está contido na Fila\n\n");
				break;
        		case 2:
				printf("\n\nDigite o número que deseja inserir na Fila: ");
				scanf("%d", &n);
				if(inserir(&f,n)) printf("\nO número foi inserido na Fila.\n\n");
				else printf("\nO número não foi inserido na Fila\n\n"); 	
        			break;
        		case 3:
				retira(&f);
        			break;
        		case 4:
        			imprimir(f);
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
	f->nElems = 0;
	f->inicio = 0;

}
_Bool consulta(filaInt f, int x)
{
	int i;
	if(f.nElems == 0) return false;
	for(i = f.inicio; i < f.nElems && f.conteudo[i] != x; i++);
	return (f.conteudo[i] == x);
}

_Bool inserir(filaInt *f, int x){
	if(f->nElems == tamanhodaFila)
		return false;
	f->conteudo[f->nElems] = x;
	f->nElems++;
	return true;
}

void retira(filaInt *f){
	if(f->nElems > 0){
		if(f->nElems == 1)
		{
			f->inicio = 0;
			f->nElems--;
		}	
		else{
			f->inicio++;
			f->nElems--;
		
		}
	}
}

void imprimir (filaInt f){
	int i;
	printf("Fila: ");
	for(i=f.inicio; i < f.nElems; i++)
		printf("%d ", f.conteudo[i]);
	printf("\n");
}
