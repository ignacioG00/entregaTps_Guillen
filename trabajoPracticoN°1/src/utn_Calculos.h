/*
 * utn_Calculos.h
 *
 *  Created on: 9 abr. 2021
 *      Author: Ignacio Guillen 1°E
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_


int sumar(int opUno,int opDos,int* resulSuma);
/**
 * Brief: Realiza una suma de dos operandos.
 * Parámetro opUno: recibe un operando int.
 * Parámetro opDos: recibe un segundo operando int.
 * Parámetro resulSuma: un puntero que recibe el valor del resultado de la operacion.
 * Return: retorna un [1] si el programa funciono, [0] caso contrario.
 */

int restar(int opUno,int opDos,int* resulResta);
/**
 * Brief: Realiza una resta de dos numeros ingresados.
 * Parámetro opUno: recibe un operando int.
 * Parámetro opDos: recibe un segundo operando int.
 * Parámetro resulSuma: un puntero que recibe el valor del resultado de la operacion.
 * Return: retorna un [1] si el programa funciono, [0] caso contrario.
 */

int multiplicar(int opUno,int opDos,int* resulMult);
/**
 * Brief: Realiza una multiplicacion entre dos numeros ingresados.
 * Parámetro opUno: recibe un operando int.
 * Parámetro opDos: recibe un segundo operando int.
 * Parámetro resulSuma: un puntero que recibe el valor del resultado de la operacion.
 * Return: retorna un [1] si el programa funciono, [0] caso contrario.
 */

int dividir(int opUno,int opDos,float* resulDiv);
/**
 * Brief: Realiza una division entre dos numeros ingresados.
 * Parámetro opUno: recibe un operando int.
 * Parámetro opDos: recibe un segundo operando int.
 * Parámetro resulSuma: un puntero que recibe el valor del resultado de la operacion.
 * Return: retorna un [1] si el programa funciono, [0] caso contrario.
 */

int factorial(int operando,int* resulFact);
/**
 * Brief: Realiza el factoreo de un entero ingresado.
 * Parámetro opUno: recibe un operando int.
 * Parámetro opDos: recibe un segundo operando int.
 * Parámetro resulSuma: un puntero que recibe el valor del resultado de la operacion.
 * Return: retorna un [1] si el programa funciono, [0] caso contrario.
 */


#endif /* UTN_CALCULOS_H_ */
