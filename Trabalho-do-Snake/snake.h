// Nome completo do aluno:Daiane Mascarenhas Lauro da Silva
// Data da última modificação:23/03/2016
#include <curses.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */
#include <stddef.h>
#include <time.h>

#ifndef SNAKE_H
#define SNAKE_H

// Uma snake eh formada por uma cadeia de segmentos
struct segmento {
	int x, y;   /// posicao
	char c;   // letra consumida 
	struct segmento* next;
	struct segmento* prev;
};

void insereSegmentoFinal(struct segmento *m, char letrinha);

void popPrimeiroSegmento(struct segmento* m);

struct segmento* searchSegmento(struct segmento* m, char letrinha);

int contaSegmentos(struct segmento* m);

void insereSegmentoInicio(struct segmento* m, char letrinha);

void removeUltimoSegmento(struct segmento *m);

void removeSegmento(struct segmento* m, char letrinha);

void insereSegmentoOrdenado(struct segmento* m, char letrinha);

void ordenaSegmentos(struct segmento* m);

#endif
