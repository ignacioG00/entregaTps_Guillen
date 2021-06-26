/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°3
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */


#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Biblioteca.h"
#include "menu.h"

int menu(void){

	int option = 0;
	int firstFlag=0;
	int secFlag=0;
	char path[30];

	    LinkedList* listaEmpleados = ll_newLinkedList();

	    do{
	    	puts("\t|**********INICIO**********|");
	    	if(subMenu(&option)){
	        switch(option)
	        {
	        case 1:
				if(firstFlag==0
						&& utn_getNumero(&firstFlag, "Desea abrir: \n"
								"1. data.csv \n"
								"2. Chequeo.csv\n",
								"Error, opcion incorrecta \n"
								"Desea abrir: \n"
								"1. data.csv \n"
								"2. Chequeo.csv\n", 1, 2, 1)==0)
				{
					switch(firstFlag)
					{
					case 1:
						controller_loadFromText("data.csv",listaEmpleados);
						break;
					case 2:
						controller_loadFromText("Chequeo.csv",listaEmpleados);
						break;
					}
				}
				else
				{
					printf("El archivo ya fue cargado.\n");
				}
				break;
	        case 2:
	        	if(firstFlag==0
						&& utn_getNumero(&firstFlag, "Desea abrir: \n"
								"1. data.bin \n"
								"2. Chequeo.bin\n",
								"Error, opcion incorrecta \n"
								"Desea abrir: \n"
								"1. data.bin \n"
								"2. Chequeo.bin\n", 1, 2, 1)==0)
				{
					switch(firstFlag)
					{
					case 1:
						controller_loadFromBinary("data.bin",listaEmpleados);
						break;
					case 2:
						controller_loadFromBinary("Chequeo.bin",listaEmpleados);
						break;
					}
				}else{
					printf("El archivo ya fue cargado.\n");
				}

				break;
			case 3:
				controller_addEmployee(listaEmpleados);
				break;
			case 4:
				controller_editEmployee(listaEmpleados);
				break;
			case 5:
				controller_removeEmployee(listaEmpleados);
				break;
			case 6:
				controller_ListEmployee(listaEmpleados);
				break;
			case 7:
				controller_sortEmployee(listaEmpleados);

				if(validate_Exit_SN("Desea imprimir una lista ordenada?","Error.Reingrese"))
				{
					controller_ListEmployee(listaEmpleados);
				}
				break;
			case 8:
				controller_increaseSalary(listaEmpleados);
				break;
			case 9:
				utn_getNumero(&secFlag, "Desea guardar en: \n1. data.csv \n2. Chequeo.csv \n3. Nuevo archivo", "Error, opcion incorrecta", 1, 3, 1);
				switch(secFlag)
				{
				case 1:
					controller_saveAsText("data.csv",listaEmpleados);
					secFlag=0;
					break;
				case 2:
					controller_saveAsText("Chequeo.csv",listaEmpleados);
					secFlag=0;
					break;
				case 3:
					if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .csv o .txt", 2, 30))==0)
					{
					controller_saveAsText(path,listaEmpleados);
					}
					else
					{
						secFlag=0;
					}
					break;
				}
				break;
			case 10:
				utn_getNumero(&secFlag, "Desea guardar en: \n1. data.bin \n2. Chequeo.bin \n3. Nuevo archivo", "Error, opcion incorrecta", 1, 3, 1);
				switch(secFlag)
				{
				case 1:
					controller_saveAsBinary("data.bin",listaEmpleados);
					firstFlag=0;
					break;
				case 2:
					controller_saveAsBinary("Chequeo.bin",listaEmpleados);
					firstFlag=0;
					break;
				case 3:
					if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .bin", 2, 30))==0)
					{
						controller_saveAsBinary(path,listaEmpleados);
						firstFlag=0;
					}
					else
					{
						secFlag=0;
					}
					break;
				}
				break;

	        	}
	    	}
	    }while(option != 11);
	    puts("\n PROYECTO FINALIZADO! MUCHAS GRACIAS POR UTILIZARLO!");
	    return 0;
}
