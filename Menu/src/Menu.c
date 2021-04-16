/*
 ============================================================================
 Name        : Menu.c
 Author      : Guillen ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaMenu.h"

int mostrarMenu();

int main(void) {

	int* retorno = 0;

	do{
	mostrarMenu(&retorno);
	}
	while(*retorno==-1);

	return EXIT_SUCCESS;
}

	int mostrarMenu(int* retorna)
	{
		setbuf(stdout, NULL);
		int opcionMenu= 0;//opciones de menu a elegir.

		int a=0;
		int b=0;

		int funciona=0;//Variable que indica el funcionamiento de la funcion.

		int resSuma=0;
		int resResta=0;
		float resDiv=0;
		int resMult=0;


			printf("¡Bienvenido a la Calculadora!");
		do{
			printf("\n1)Ingresar primer numero. \n2)Ingresar segundo numero. \n3)Calculos \n4)Informar resultados. \n5)Salir.");
			scanf("%d", &opcionMenu);
		switch(opcionMenu)
		{
		case 1:
			printf("ingrese el primer numero:");
			scanf("%d", &a);
			break;
		case 2:
			printf("ingrese el segundo numero:");
			scanf("%d", &b);
			break;
		case 3:
			sumar(a,b,&funciona);
			restar(a,b,&funciona);
			multiplicar(a,b,&funciona);
			dividir(a,b,&funciona);

			if(funciona==1)//Si la variable es 1, entonces las funciones estan bien. Caso contrario dara 0.
			{
				printf("Se han realizado los calculos con exito.");
			}else{
				printf("Error en los calculos.Reingresar datos!");
			}
			break;
		case 4:

			resSuma=sumar(a,b,&funciona);
			resResta=restar(a,b,&funciona);
			resMult=multiplicar(a,b,&funciona);
			resDiv=dividir(a,b,&funciona);

			printf("El resultado de A+B es: %d \n", resSuma);
			printf("El resultado de A-B es: %d \n", resResta);
			printf("El resultado de A*B es: %d \n", resMult);

			if(funciona==-1){
				printf("No es posible dividir por cero \n");
			}else{
				printf("El resultado de A/B es: %f \n", resDiv);
			}
			break;
		case 5:
			break;

		default:
			printf("Error.Reingrese una opcion: \n1)Ingresar primer numero. \n2)Ingresar segundo numero. \n3)Calculos \n4)Informar resultados. \n5)Salir.");
			scanf("%d", &opcionMenu);
			}
		}
		while(opcionMenu!=5);

		printf("¡Gracias por utilizar la calculadora!");
		return 0;
	}




