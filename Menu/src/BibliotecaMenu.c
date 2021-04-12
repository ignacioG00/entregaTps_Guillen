/*
 * BibliotecaMenu.c
 *
 *  Created on: 9 abr. 2021
 *      Author: ignac
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int* opUno,int* opDos)
{
	int x = *opUno;
	int y = *opDos;

	int res = x + y;

	printf("El resultado es: %d\n", res);

	return 0;
}

int restar(int* opUno,int* opDos)
{
	int x = *opUno;
	int y = *opDos;

	int res = x - y;

	printf("El resultado es: %d\n", res);

	return 0;
}

int multiplicar(int* opUno,int* opDos)
{
	int x = *opUno;
	int y = *opDos;

	int res = x * y;

	printf("El resultado es: %d\n", res);

	return 0;
}

int dividir(int* flagValidez, int* x,int* y)
{
	float res =(float) *x / *y;

	if (*y==0)
	{
		*flagValidez=-1;
		printf("No es posible dividir por cero");
	}else{
		*flagValidez=1;
		printf("El resultado de A/B es: %f", res);
	}

	return *flagValidez;
}
