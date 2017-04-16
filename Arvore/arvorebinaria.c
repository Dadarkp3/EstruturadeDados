/*Segundo Trabalho de Estrututura de Dados e Algoritmos
Professor Flávio Assis | Universidade Federal da Bahia
Aluna: Daiane Mascarenhas Lauro da Silva 214115634 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noArvore{
	int chave;
	struct noArvore *direita, *esquerda;
}noArvore, *arvore;

void inicializar(arvore *raiz);
void inserir(arvore *raiz);
_Bool consulta(arvore *raiz, int n);
noArvore *menorChave(noArvore *w);
void remover(arvore *raiz, int n);
void listarcrescente(noArvore *raiz);
void listardecrescente(noArvore *raiz);
void listarnivel(noArvore *raiz, int n);
void imprimir(noArvore *raiz);

int main(){
	int num;
	char entrada;
	arvore a;
	inicializar(&a);
	do
	{
		scanf(" %c", &entrada);
		switch(entrada)
		{
			case 'i':
				inserir(&a);		
				break;		
			case 'r':
				scanf("%d", &num);
				remover(&a, num);
				break;
			case 'c':
				scanf("%d", &num);
				if(consulta(&a, num)) 
					printf("existe no com chave: %d\n", num);
				else 
					printf("nao existe no com chave: %d\n", num);
				break;
			case 'p':
				scanf(" %c",&entrada);
				if(entrada == 'c') 
					listarcrescente(a);
				else 
					if (entrada == 'd') 
						listardecrescente(a);
				break;
			case 'n':
				scanf("%d", &num);
				listarnivel(a, num);
				break;
			case 'd':
				imprimir(a);
		}
	}
	while(entrada != 'e');
	return 0;
}

void inicializar(arvore *raiz){
	*raiz = NULL;
}

void inserir(arvore *raiz){
	noArvore *novo, *y, *x;
	int num;
	if(novo = (noArvore *)malloc(sizeof(noArvore)))
	{
		scanf("%d", &num);
		novo->chave = num;
		novo->esquerda = NULL;
		novo->direita = NULL;
		if(!*raiz){
			*raiz = novo;
		}
		else{
			y = NULL;
			x = *raiz;
			while(x && x->chave != num){
				y = x;
				if(novo->chave < x->chave) 
					x = x->esquerda;
				else 
					x = x->direita;
			}
			if(!x){
				if(novo->chave < y->chave) 
					y->esquerda = novo;
				else 
					y->direita = novo;
			}
		}
	}
}
_Bool consulta(arvore *raiz, int n){
	noArvore *x;
	x = *raiz;
	while(x && n != x->chave){
		if(n < x->chave) 
			x = x->esquerda;
		else 
			x = x->direita;
	}
	if(x) 
		return true;
	return false;
}

noArvore *menorChave(noArvore *w){
	while(w->esquerda){
		w = w->esquerda;
	}
	return w;
}

void remover(arvore *raiz, int n){
	noArvore *z, *x, *y, *anterior =  NULL;
	z = *raiz;
	while(z && n != z->chave){
		anterior = z;
		if(n < z->chave)
			z = z->esquerda;
		else
			z = z->direita;
	}
	if(!z) 
		return;
	if(!z->esquerda || !z->direita) 
		y = z;
	else 
		y = menorChave(z->direita);
	if(y->esquerda) 
		x = y->esquerda;
	else 
		x = y->direita;
	if(!anterior) 
		*raiz = x;
	else{
		if ( y == anterior->esquerda)
			anterior->esquerda = x;
		else
			anterior->direita = x;
	}
	if(y != z) 
		z->chave = y->chave;
	free(y);
}
void listarcrescente(noArvore *raiz){
	if(!raiz) 
		return;
	listarcrescente(raiz->esquerda);
	printf("%d\n", raiz->chave);
	listarcrescente(raiz->direita);
}
void listardecrescente(noArvore *raiz){
	if(!raiz)
		return;
	listardecrescente(raiz->direita);
	printf("%d\n", raiz->chave);
	listardecrescente(raiz->esquerda);
}
void listarnivel(noArvore *raiz, int n){
	if(n == 1){
		if(raiz) 
			printf("%d\n", raiz->chave);
	}
	else{
		if(raiz->esquerda)
			listarnivel(raiz->esquerda,n-1);
		if(raiz->direita)
			listarnivel(raiz->direita, n-1);
	}
}

void imprimir(noArvore *raiz){
	if(!raiz)
		return;
	imprimir(raiz->esquerda);
	if(raiz->esquerda && raiz->direita)
		printf("chave %d fesq %d fdir %d\n", raiz->chave,raiz->esquerda->chave, raiz->direita->chave);
	else{
		if(raiz->esquerda && raiz->direita == NULL) 
			printf("chave %d fesq %d fdir NULL\n", raiz->chave, raiz->esquerda->chave);
		else 
			if(raiz->esquerda == NULL && raiz->direita)
				printf("chave %d fesq NULL fdir %d\n", raiz->chave, raiz->direita->chave);
		else 
			if(raiz->esquerda == NULL && !raiz->direita)
				printf("chave %d fesq NULL fdir NULL\n", raiz->chave);
	}	 
	imprimir(raiz->direita);
}
