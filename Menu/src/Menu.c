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



int main(void) {

	setbuf(stdout, NULL);
	int a;
	int b;

	int retorno = 0;
	do{

	printf("\n Ingrese el primer numero");
	scanf("%d ", &a);

	printf("\nIngrese el segundo numero");
	scanf("%d ", &b);

	mostrarMenu(a,b);

	}
	while(retorno==-1);

	int mostrarMenu(int x,int y)
	{
		int opcion=0;

		printf("Ingrese una opcion: \n 1)Suma. \n 2)Resta  \n 3)Multiplicacion. \n 4)Division \n 5)Factorial. \n 6)salir.");
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			sumar(&x,&y);
			break;
		case 2:
			restar(&x,&y);
			break;
		case 3:
			multiplicar(&x,&y);
			break;
		case 4:
			dividir(&retorno,&x,&y);
			break;
		case 5:

			break;
		case 6:

			break;
		default:
			printf("Error.Reingrese una opcion: \n 1)Suma. \n 2)Resta  \n 3)Multiplicacion. \n 4)Division \n 5)Factorial. \n 6)salir.");
			scanf("%d", &opcion);
			;
		}
		return 0;
	}

	return EXIT_SUCCESS;
}




