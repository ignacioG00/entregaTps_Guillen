/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°2
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef BIBLIOTECA_C_
#define BIBLIOTECA_C_

#include "Biblioteca.h"

//VALIDACIONES

int validate_OnlyNumberInt(char* pData)
{
	int retorno=1;
	if(strlen(pData)>0)
	{
		for(int i=0;i<strlen(pData);i++)
		{
			if(isdigit(pData[i])==0)
			{
				if(i==0)
				{
					if(pData[0]!='-')
					{
						retorno=0;
						break;
					}
				}else{
					retorno=0;
					break;
				}
			}
		}
	}else{
		retorno=0;
	}
	return retorno;
}

int validate_OnlyAlphabet(char *pData)
{
	int retorno = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}

	return retorno;
}

int validate_OnlyAlphabetWithSpaces(char *pData)
{
	int retorno = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					retorno = 0;
					break;
				}
			}
		}
	} else {
		retorno = 0;
	}

	return retorno;
}

int validate_Exit_SN(char *msj,char *msjError)
{
	int retorno=0;
	char c;
	c = get_Char(msj,msjError);
	c = toupper(c);

	while(c!='S' && c!='N')
	{
		puts("> ERROR.OPCION NO VALIDA\n");
		c=get_Char(msj,msjError);
		c=toupper(c);
	}
	if(c=='S')
	{
		retorno=1;
	}
	return retorno;
}

//GETS

int get_Int(char *msj, char *msjError)
{
	char buffer[TAM_BUFFER];
	int retorno;

		printf("%s", msj);
		fflush(stdin);
		gets(buffer);

	while(validate_OnlyNumberInt(buffer)==0)
	{
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}

	retorno=atoi(buffer);
	return retorno;
}

int get_IntRange(char *msj,char *msjError,int minimo, int maximo)
{
	int retorno = get_Int(msj, msjError);
	while(retorno<minimo || retorno>maximo)
	{
		printf("Error.Fuera de rango -> [Minimo]= %d [Maximo]= %d. \n", minimo,maximo);
		retorno= get_Int(msj,msjError);
	}
	return retorno;
}

int get_IntPositive(char *msj, char *errorMsj)
{
	int retorno= get_Int(msj,errorMsj);
	while(retorno<0)
	{
		printf("Solo numeros positivos!!\n");
		retorno=get_Int(msj,errorMsj);
	}
	return retorno;
}

int get_IntNegative(char *msj, char *errorMsj)
{
	int retorno= get_Int(msj,errorMsj);
	while(retorno>=0)
	{
		printf("Solo numeros negativos!!\n");
		retorno=get_Int(msj,errorMsj);
	}
	return retorno;
}



float get_FloatRange(float* pResult,char *msj,char *msjError,float minimo, float maximo,int reintentos)
{
	int retorno = -1;
		float bufferInterno;
		if(pResult != NULL && msj != NULL && msjError != NULL && minimo <= maximo && reintentos>0)
		{

			do
			{
				printf("%s", msj);
				scanf("%f", &bufferInterno);
				if(bufferInterno>=minimo && bufferInterno<=maximo)
				{
					*pResult=bufferInterno;
					retorno=0;
					break;
				}
				else
				{
					printf("%s", msjError);
					reintentos--;
				}
			}while(reintentos>=0);
		}
		return retorno;
}

void get_String(char *msj, char *msjError, char *pString, int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);
	while(strlen(buffer)>TAM||strlen(buffer)==0)
	{
		printf("Error.Fuera de rango. CARACTERES [Minimo]= 1 [Maximo]= %d. \n", TAM);
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}
	strcpy(pString,buffer);
}

void get_OnlyAlphabetString(char *msj,char *msjError,char *pString,int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)>TAM || strlen(buffer)==0 || validate_OnlyAlphabet(buffer)==0)
	{
		if(strlen(buffer)>TAM || strlen(buffer)==0)
		{
			printf("Error.Fuera de rango. CARACTERES [minimo]=1 [maximo]=%d. \n",TAM);
		}else{
			printf("Error.Solo caracteres alfabeticos Validos.\n");
		}
		printf("%s",msjError);
		fflush(stdin);
		gets(buffer);
	}
	strcpy(pString,buffer);
}

void get_OnlyAlphabetStringWithSpaces(char *msj,char *msjError,char *pString, int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)>TAM || strlen(buffer)==0 || validate_OnlyAlphabetWithSpaces(buffer)==0)
		{
			if(strlen(buffer)>TAM || strlen(buffer)==0)
			{
				printf("Error.Fuera de rango. CARACTERES [minimo]=1 [maximo]=%d. \n",TAM);
			}else{
				printf("Error.Solo caracteres alfabeticos Validos.\n");
			}
			printf("%s",msjError);
			fflush(stdin);
			gets(buffer);
		}
	strcpy(pString,buffer);
}

char get_Char(char *msj, char *msjError)
{
	char buffer[TAM_BUFFER];
	char retorno;

	printf("%s",msj);
	fflush(stdin);
	gets(buffer);
	while(strlen(buffer)>1 || validate_OnlyAlphabet(buffer)==0)
	{
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}
	retorno = buffer[0];
	return retorno;
}

//UTILITIES


void menu(void)
{
	puts("\t****BIENVENIDOS****\n");
	puts("1 - ALTA DE EMPLEADOS");
	puts("2 - MODIFICAR EMPLEADO");
	puts("3 - BAJA DE EMPLEADO");
	puts("4 - INFORMAR");
	puts("0 - SALIR");
}


#endif
