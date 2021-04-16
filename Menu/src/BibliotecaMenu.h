/*
 * BibliotecaMenu.h
 *
 *  Created on: 9 abr. 2021
 *      Author: ignacio Guillen
 */

#ifndef BIBLIOTECAMENU_H_
#define BIBLIOTECAMENU_H_


//int mostrarMenu(int punteroMenu);
/*
 * Brief: muestra un menu y le pide al usuar que operacion quiere realizar.
 * Parámetro: recibe como parámetro un puntero.
 * Return: retorna un int si funciona.
 */

int sumar(int opUno,int opDos,int* resSuma);
int multiplicar(int opUno,int opDos,int* resMult);
int restar(int opUno,int opDos,int* resResta);
int multiplicar(int opUno,int opDos,int* resMult);
int dividir(int opUno,int opDos,int* resDiv);

#endif /* BIBLIOTECAMENU_H_ */
