/*
 * utn_Calculos.c
 *
 *  Created on: 9 abr. 2021
 *      Author: Ignacio Guillen 1�E
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int opUno,int opDos,int* resulSuma)
{
	int x=opUno;
	int y=opDos;
	int flagSuma;

	if(resulSuma!=NULL)
	{
		*resulSuma=x+y;
		flagSuma=1;
	}else{
		flagSuma=0;
	}
	return flagSuma;
}

int restar(int opUno,int opDos,int* resulResta)
{
	int x=opUno;
	int y=opDos;
	int flagResta;

	if(resulResta!=NULL)
	{
		*resulResta=x-y;
		flagResta=1;
	}else{
		flagResta=0;
	}
	return flagResta;
}

int multiplicar(int opUno,int opDos,int* resulMult)
{
	int x=opUno;
	int y=opDos;
	int flagMult;

	if(resulMult!=NULL)
	{
		*resulMult=x*y;
		flagMult=1;
	}else{
		flagMult=0;
	}
	return flagMult;
}

int dividir(int opUno,int opDos,float* resulDiv)
{
	int flagDiv;
	float x=opUno;
	float y=opDos;

	if ((resulDiv!=NULL) && (y!=0))
	{
		*resulDiv =(float) x / y;
		flagDiv= 1;//Funciona.
	}else{
		flagDiv=0;//hubo ERROR.
	}
	return flagDiv;
}

int factorial(int operando,int* resulFact)
{
	int flagFact;
	int i;
	int resul=1;

	if(resulFact!=NULL)
	{
	for(i=1;i<=operando;i++)
		{
		resul= resul*i;
		}
	*resulFact= resul;
	flagFact=1;
	}else{
		flagFact=0;
	}
	return flagFact;
}
