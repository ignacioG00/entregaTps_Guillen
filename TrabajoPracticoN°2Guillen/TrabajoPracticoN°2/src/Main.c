/*
 * 	Main.c
 *	TRABAJO PRACTICO N�2
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Biblioteca.h"
#define TAM_EMPLEADOS 5

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int opcSubMenu;
	int flagHayEmpleado = 0;
	static int idAutomatico=0;
	float auxFloat;

	//CREO ARRAY DE EMPLEADO
	Employee Empleado[TAM_EMPLEADOS];

	//INICIALIAZO ARRAY DE EMPLEADO
	initEmployees(Empleado,TAM_EMPLEADOS);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		menu();
		opc=get_IntRange("\n> INGRESE OPCION:\n","> ERROR.REINGRESE OPCION:\n",0,4);

		//MENU SWITCH
		switch (opc)
		{
		case 1:
			//ALTA
			puts("\t****ALTA DE EMPLEADO****");
			if(upEmployee(Empleado,TAM_EMPLEADOS,&idAutomatico))
			{
				puts(" **EMPLEADO DADO DE ALTA EXITOSAMENTE**");
				printEmployees(Empleado,TAM_EMPLEADOS);
				flagHayEmpleado ++;
			} else {
				puts("\n > NO SE DIO DE ALTA.");
			}
			system("pause");

			break;
		case 2:
			//MODIFICACION
			if(flagHayEmpleado>0){
				puts("\t****MODIFICAR EMPLEADO****");
			if (modEmployee(Empleado,TAM_EMPLEADOS)) {
				puts("\n **MODIFICACION DE EMPLEADO EXITOSA**\n");
				printEmployees(Empleado, TAM_EMPLEADOS);
			} else {
				puts("\n > MODIFICACION DE EMPLEADO CANCELADA");
			}
			system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN EMPLEADO*\n");
				system("pause");
			}
			break;
		case 3:
			//BAJA
			if(flagHayEmpleado>0)
			{
				puts("\t****BAJA DE EMPLEADO****");
				printEmployees(Empleado,TAM_EMPLEADOS);
				int id = get_Int("> INGRESE ID DE EMPLEADO:\n","> ERROR.REINGRESE ID:\n");
			if (removeEmployee(Empleado, TAM_EMPLEADOS, id)) {
				puts("\n **BAJA DE EMPLEADO EXITOSA**\n");
				printEmployees(Empleado,TAM_EMPLEADOS);
				flagHayEmpleado --;
			} else {
				puts("\n > BAJA DE EMPLEADO CANCELADA");
			}
			system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN EMPLEADO*\n");
				system("pause");
			}
			break;

		case 4:
			//INFORMES
			if(flagHayEmpleado>0){
				puts("\t****INFORME DE EMPLEADOS****");
				printf("\t1 - LISTADO DE EMPLEADOS.\n \t2 - TOTAL Y PROMEDIO DE EMPLEADOS.\n");
				printf("> INGRESE QUE QUIERE INFORMAR:\n ");
				scanf("%d", &opcSubMenu);
				switch(opcSubMenu)
				{
				case 1:
					orderEmployeesBySalaryOrLastName(Empleado,TAM_EMPLEADOS);
					printEmployees(Empleado,TAM_EMPLEADOS);
					break;
				case 2:
					promSalaryEmployee(Empleado,TAM_EMPLEADOS,&auxFloat);
					printHigherSalaryEmployees(Empleado,TAM_EMPLEADOS,auxFloat);
					break;
				}
				system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN EMPLEADO*\n");
				system("pause");
			}
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA ...");

	return 0;
}

