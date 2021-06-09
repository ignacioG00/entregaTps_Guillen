#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
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



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if(utn_getNumero(&option,"Seleccione una opcion\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    	    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    	    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
    	    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    	    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Salir",
    	    					"Error ingrese: \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    	    			"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    	    			"3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
    	    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    	    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Salir\n",0, 11, 2)==0){
        switch(option)
        {
        case 1:
			if(flag==0)
			{
				utn_getNumero(&flag, "Elija opcion a abrir: \n1. data.csv \n2.Chequeo.csv", "Error, opcion incorrecta", 1, 2, 1);
				switch(flag)
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
				printf("El archivo ya fue cargado");
			}
			break;
		case 2:
			if(flag==0)
			{
				utn_getNumero(&flag, "Elija opcion a abrir: \n1. data.bin \n2.Chequeo.bin", "Error, opcion incorrecta", 1, 2, 1);
				switch(flag)
				{
				case 1:
					controller_loadFromBinary("data.bin",listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("Chequeo.bin",listaEmpleados);
					break;
				}
			}
			else
			{
				printf("El archivo ya fue cargado\n");
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
			break;
		case 8:
			controller_saveAsText("Chequeo.csv",listaEmpleados);
			break;
		case 9:
			controller_saveAsBinary("Chequeo.bin",listaEmpleados);
			break;
        	}
    	}
    }while(option != 10);
    return 0;
}

