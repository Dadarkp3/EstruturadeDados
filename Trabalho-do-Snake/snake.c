// Nome completo do aluno:Daiane Mascarenhas Lauro da Silva
// Data da última modificação:22/03/2016
#include "snake.h"
//Etapa 1
void insereSegmentoFinal(struct segmento* m, char letrinha){
	while(m->next != NULL){
		m = m->next;
		
	}
	m->next = malloc(sizeof(struct segmento));
	m = m->next;
	m->c = letrinha;
	m->next=NULL;
}

//Etapa 2
void popPrimeiroSegmento(struct segmento* m){
	if(m->next != NULL){	
		struct segmento* m2;
		m2 = m->next;
		m->next = m2->next;
		free(m2);
	}
}

//Etapa3
struct segmento* searchSegmento(struct segmento* m, char letrinha){
	struct segmento* search;
	search = NULL;		
	while (m->next != NULL && search == NULL){
		m = m->next;
		if(m->c == letrinha) search = m;
	}
	return search;
}
//Etapa4
int contaSegmentos(struct segmento* m){
	int quantidade=1;
	while(m->next != NULL)
	{
		quantidade++;
		m = m->next;
	}
	return quantidade;
}


//Etapa5
void insereSegmentoInicio(struct segmento* m, char letrinha){
	struct segmento* m2;
	m2 = malloc(sizeof(struct segmento));
	m2->c = letrinha;
	m2->next = m->next;
	m->next = m2;
	
}

//Etapa6
void removeUltimoSegmento(struct segmento *m){
	struct segmento* mprecedente;
	mprecedente = m;
	while(m->next != NULL){
		mprecedente = m;
		m = m->next;
	}
	mprecedente->next = NULL;
	free(m);
}


//Etapa 7
void removeSegmento(struct segmento* m, char letrinha){
	struct segmento* mprecedente;
	while(m->next != NULL && m->c != letrinha){
		mprecedente = m;
		m = m->next;
		}
	if (m->c == letrinha){
		mprecedente->next = m->next;
		free(m); 		
	}		
}

//Etapa 8
void insereSegmentoOrdenado(struct segmento* m, char letrinha){
	struct segmento* mchave;
	struct segmento* mprecedente;
	mchave = malloc(sizeof(struct segmento));
	mchave->c = letrinha;
	mchave->next = NULL;
	mprecedente = m;	
	m = m->next;
	while(m->c < letrinha && m->next != NULL){
		mprecedente = m;
		m=m->next;
	}
	if(m->c > letrinha){
		mchave->next = m;
		mprecedente->next = mchave;	
	}
	else m->next = mchave;

}

//Etapa 10
void ordenaSegmentos(struct segmento* m){

}

void printcorpo(struct segmento* m){
	printf("%c", m->c);
	while (m->next != NULL) {
				
		m = m->next;
		printf("%c",m->c);
			
	}
	printf("\n");
}

