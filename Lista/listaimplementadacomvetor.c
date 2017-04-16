#include <stdio.h>
#define tamanho_lista 10

typedef struct
{
	int dados[tamanho_lista];
	int numero_elementos;
}lista;

void inicializa(lista *l);
bool consulta(lista *l, int n);
bool insere(lista *l, int n);
bool retira(lista *l, int n);
int menor(lista *l);
int nImpares(lista *l);
double media(lista *l);
int somaValores(lista *l);
int SomaQuadradosValores(lista *l);
void eliminaKEsimo(lista *l, int n);
void retiraMaior(lista *l, int n);
void retiraElementos(lista *l, int n);
void AntesDeimpar(lista *l, int n);
void maioresNaFrente(lista *l, int n);
void inverte_lista(lista *l);
void divisiveisPor10Primeiro(lista *l);
void duplicaElemento(lista *l, int n);
void menorRecursivo(lista *l);
void somaQuadradosValoresRecursivo(lista *l);

int main()
{
	lista minhalista;
	inicializa(&minhalista);
	return 0;
}

void inicializa(lista *l)
{
	l->numero_elementos=0;
}

bool consulta(lista *l, int n)
{
	for(int i = 0; i < l->numero_elementos && n!=l->dados[i]; i++);
	return !(l->numero_elementos == i);
} 

bool insere(lista *l, int n)
{
	return !(l->numero_elementos == tamanho_lista || consulta(&l,n));
	l->dados[l->numero_elementos] = n;
	l->numero_elementos++;
	return true;
}

bool retira(lista *l, int n)
{
	return !(l->numero_elementos == 0 || !(consulta(&l,n)));
	for(int i = 0; l->dados[i] != n; i++);
	l->dados[i]=l->dados[l->numero_elementos-1];
	l->numero_elementos--;
	return true;	
}
//Exercício Lista, Questão 1

//Letra a)
int menor(lista *l)
{
	if (l->numero_elementos == 0) return 0;
	int menor = l->dados[0];
	for(int i = 0; i < l->numero_elementos; i++)
		if (l->dados[i] < menor) menor = l->dados[i];
	return menor;	
}

//Letra b)
int nImpares(lista *l)
{
	int nImpares = 0;
	for(int i = 0; i < l->numero_elementos; i++)
		if(l->dados[i]%2 != 0) nImpares++;
	return nImpares;
}

//Letra c)
double media(lista *l)
{
	int media = 0;
	for(int i = 0; i < l->numero_elementos; i++)
		media+=l->dados[i];
	return media/l->numero_elementos;
}

//Letra d)
int somaValores(lista *l)
{
	int soma = 0;
	for(int i = 0; i < l->numero_elementos; i++)
		soma+=l->dados[i];
	return soma;
}

//Letra e)
int SomaQuadradosValores(lista *l)
{
	int soma = 0;
	for(int i = 0; i < l->numero_elementos; i++)
		soma+=l->dados[i]*l->dados[i];
	return soma;
}

//Exercícios Lista, Questão 2

//Letra a)
void eliminaKEsimo(lista *l, int k)
{
	if(l->numero_elementos > 0 && k-1 < l->numero_elementos)
	{
		l->dados[k-1] = l->dados[l->numero_elementos-1];
		l->numero_elementos--;		
	}
}

//Letra b)
void retiraMaior(lista *l, int n)
{
	if (l->numero_elementos == 0) return 0;
	int maior = l->dados[0];
	for(int i = 0; i < l->numero_elementos; i++)
		if (l->dados[i] > maior) maior = l->dados[i];
	retira(&l,maior);
}

//Letra c)
void retiraElementos(lista *l, int n)
{
	while(consulta(&l,n)
	{
		retira(&l,n);
	}
}

//Exercício Lista, Questão 3
void AntesDeimpar(lista *l, int n)
{
	
}
void maioresNaFrente(lista *l, int n);
void inverte_lista(lista *l);
void divisiveisPor10Primeiro(lista *l);
void duplicaElemento(lista *l, int n);
void menorRecursivo(lista *l);
void somaQuadradosValoresRecursivo(lista *l);

