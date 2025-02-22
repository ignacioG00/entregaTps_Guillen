/*
 * 	UTN.c
 *	TRABAJO PRACTICO N�3
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


int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

*****************************************************/

int subMenu(int* auxOpcion)
{
	int retorno = 0;
	if(utn_getNumero(auxOpcion,"/****************************************************\n"
			"Menu:\n"
			" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
			" 3. Alta de empleado\n"
			" 4. Modificar datos de empleado\n"
			" 5. Baja de empleado\n"
			" 6. Listar empleados\n"
			" 7. Ordenar empleados\n"
			" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
			" 10. Salir\n"
			"*****************************************************/\n",
			"Error,Reingrese\n"
			"/****************************************************\n"
			"Menu:\n"
			" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
			" 3. Alta de empleado\n"
			" 4. Modificar datos de empleado\n"
			" 5. Baja de empleado\n"
			" 6. Listar empleados\n"
			" 7. Ordenar empleados\n"
			" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
			" 10. Salir\n"
			"*****************************************************/\n",0, 11, 2)==0)
	{
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}




/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado,char* mensaje, char* mensajeError, int reintentos,int longitud)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}



/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int esArchivo(char* cadena)
{
    int retorno=1;
    int i;
    char buffer[1000];
    int contadorPunto=0;
    strcpy(buffer,cadena);
    for(i=0;buffer[i]!='\0';i++)
    {
        if((isalpha(buffer[i])!=0) || (buffer[i]=='.') || (isdigit(buffer[i])!=0))
        {
            continue;
        }
        else
        {
        	retorno=0;
        	break;
        }
        if(buffer[i]=='.')
		{
			contadorPunto++;
		}
    }
	if(contadorPunto==1)
	{
		retorno=1;
	}
    return retorno;
}

int utn_getArchivo(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int longitud)
{
	    int retorno=0;
	    char bufferStr[longitud];
	    if(mensaje!=NULL && mensajeError!=NULL && reintentos>=0 && pResultado!=NULL)
	    {
	        do
	        {
	        	printf("%s",mensaje);
	            if((esArchivo(bufferStr)))
				{
	                strncpy(pResultado,bufferStr,longitud);
	                retorno=1;
	                break;
	            }
	            else
	            {
	                printf("%s",mensajeError);
	                reintentos--;
	            }
	        }
	        while(reintentos>=0);
	    }
	    return retorno;
}

#endif
