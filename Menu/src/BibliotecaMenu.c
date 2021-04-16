/*
 * BibliotecaMenu.c
 *
 *  Created on: 9 abr. 2021
 *      Author: ignac
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int opUno,int opDos,int* resSuma)
{
	int x=opUno;
	int y=opDos;
	int res;

	if(resSuma!=NULL)
	{
		res=x+y;
		*resSuma=1;
	}
	return res;
}

int restar(int opUno,int opDos,int* resResta)
{
	int x=opUno;
	int y=opDos;
	int res;

	if(resResta!=NULL)
	{
		res=x-y;
		*resResta=1;
	}
	return res;
}

int multiplicar(int opUno,int opDos,int* resMult)
{
	int x=opUno;
	int y=opDos;
	int res;

	if(resMult!=NULL)
	{
		res=x*y;
		*resMult=1;
	}
	return res;
}

int dividir(int opUno,int opDos,int* resDiv)
{
	float res;
	float x=opUno;
	float y=opDos;

	if ((resDiv!=NULL) && (y!=0))
	{
		res = x / y;
		*resDiv= 1;
	}else{
		*resDiv= -1;
	}
	return res;
}
