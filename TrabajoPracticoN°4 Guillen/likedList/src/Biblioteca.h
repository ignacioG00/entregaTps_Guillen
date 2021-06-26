/*
 * 	UTN.h
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 1000

//Validaciones
int validate_OnlyNumberInt(char* pData);
int validate_OnlyAlphabet(char *pData);
int validate_OnlyAlphabetWithSpaces(char *pData);
int validate_Exit_SN(char *msj,char *msjError);
int esArchivo(char* cadena);

//GET
float get_FloatRange(float* pResult,char *msj,char *msjError,float minimo, float maximo,int reintentos);
int get_Int(char *msj, char *msjError);
int get_IntRange(char *msj,char *msjError,int minimo, int maximo);
void get_String(char *msj, char *msjError, char *pString, int TAM);
char get_Char(char *msj, char *msjError);
int get_IntNegative(char *msj, char *errorMsj);
int get_IntPositive(char *msj, char *errorMsj);
void get_OnlyAlphabetString(char *msj,char *msjError,char *pString,int TAM);
void get_OnlyAlphabetStringWithSpaces(char *msj,char *msjError,char *pString, int TAM);

//Utilities


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado,char* mensaje, char* mensajeError, int reintentos, int longitud);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getArchivo(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int longitud);

int subMenu(int* auxOpcion);

#endif /* UTN_H_ */
