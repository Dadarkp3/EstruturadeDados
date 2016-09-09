#include <stdio.h>
#include <stdlib.h>

int main()
{
	float resultado = 0, entrada = 0;
	int flag = 0;
	do
	{
		scanf("%f",&entrada);
		if(entrada >= 0 && entrada <= 10)
		{
			flag++; 
			resultado+=entrada;
		}
		else printf("nota invalida\n");	
	}while(flag !=2);
	printf("media = %.2f\n", resultado/2);
}
