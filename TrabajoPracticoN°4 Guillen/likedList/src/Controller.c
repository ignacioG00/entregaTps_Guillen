/*
 * 	UTN.c
 *	TRABAJO PRACTICO N�4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "Biblioteca.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
		if(path!=NULL && pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==1)
		{
			retorno=1;
			FILE *pFile=fopen(path,"r");
			if(parser_EmployeeFromText(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo leido y cerrado correctamente\n");
			}
			fclose(pFile);
		}else{
			if(validate_Exit_SN("Existen datos en la LinkedList. Desea borrarlos? S/N",
					"Error.Reingrese S/N") && ll_clear(pArrayListEmployee)==0)
			{
				FILE *pFile=fopen(path,"r");
				if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo leido y cerrado correctamente\n");
				}
				fclose(pFile);
			}
		}
		return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
		if(path!=NULL && pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==1)
		{
			retorno=1;
			FILE *pFile=fopen(path,"rb");
			if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
				fclose(pFile);
			}
		}else{
			if(validate_Exit_SN("Existen datos en la LinkedList. Desea borrarlos? S/N",
					"Error.Reingrese S/N") && ll_clear(pArrayListEmployee)==0)
			{
				FILE *pFile=fopen(path,"rb");
				if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0 && pFile!=NULL)
				{
					printf("No se pudo leer el archivo\n");
				}
				else
				{
					printf("Archivo leido y cerrado correctamente\n");
				}
				fclose(pFile);
			}
		}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
		Employee* pAuxEmpleado=NULL;
		int auxId;
		char auxNombre[128];
		int auxHoras;
		int auxSueldo;
		int respuesta;
		if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee))
		{

				if(validate_Exit_SN("\t CARGA DE DATOS!\n"
						"Desea inicializar un Id o generar un Id propio ? S/N \n","Error.Reingrese S/N"))
				{
					utn_getNumero(&respuesta, "Elegir una opcion: \n"
							"1. Crear una nueva lista inicializando el ID en 1.\n"
							"2. Inicializar el ID en otro numero.\n","Error, reingrese opcion. \n", 1, 2, 1);
						switch(respuesta)
						{
							case 1:
								auxId=1;
								break;
							case 2:
								utn_getNumero(&auxId, "En que numero quiere inicializar el ID?\n", "Error, ingrese valor numerico\n", 1, 100000000, 2);
								break;
						}
						pAuxEmpleado=employee_new();
						if(pAuxEmpleado!=NULL)
						{
							if(utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error ingrese nombre valido\n", 2, 128)==0 &&
							   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
							   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error ingrese numero valido, maximo 999999\n", 0, 999999, 2)==0)
							{
								if(employee_setId(pAuxEmpleado, auxId)==0 &&
								   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
								   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
								   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
								{
									ll_add(pArrayListEmployee, pAuxEmpleado);
									employee_print(pAuxEmpleado);
									printf("Carga exitosa\n");
									retorno=0;
								}
								else
								{
									printf("Error al cargar empleado\n");
								}
							}
						}
					}else{
						auxId=controller_getMaxId(pArrayListEmployee);
						pAuxEmpleado=employee_new();

						if(pAuxEmpleado!=NULL)
						{
							if(utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error, ingrese nombre valido\n", 2, 128)==0 &&
							   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error ingrese numero valido, maximo 745\n", 0, 745, 2)==0 &&
							   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error numero valido, maximo 999999", 0, 999999, 2)==0)
							{
							if(employee_setId(pAuxEmpleado, (auxId+1))==0 &&
							   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
							   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
							   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
							{
								ll_add(pArrayListEmployee, pAuxEmpleado);
								employee_print(pAuxEmpleado);
								printf("Carga exitosa\n");
								retorno=0;
							}else{
								printf("Error al cargar empleado\n");
							}
						}
					}
				}
			}
		return retorno;
}

/** \brief Busca Id Maximo
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_getMaxId(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int cantidadLinkedList;
	int id;

	Employee* pAuxEmpleado=NULL;
	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		cantidadLinkedList=ll_len(pArrayListEmployee);
		for(int i=0; i<cantidadLinkedList ; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pAuxEmpleado, &id);
			if(id>retorno)
			{
				retorno=id;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{

		Employee* pAuxEmpleado=NULL;
		int cantLinkedList;
		int auxId;
		int auxHoras;
		int auxSueldo;
		int id;
		int auxInt;
		char auxNombre[128];
		int numMax=0;
		int retorno=0;

		if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
		{
			cantLinkedList=ll_len(pArrayListEmployee);
			for(int i=0; i<cantLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId>numMax)
				{
					numMax=auxId;
				}
			}
			utn_getNumero(&id, "Ingrese Id de persona a modificar", "Error, reingrese valor numerico", 0, auxId, 2);
			for(int i=0; i<cantLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId==id)
				{
					puts("|***EMPLEADO***|\n");
					employee_print(pAuxEmpleado);
					if(validate_Exit_SN("\n Desea modificar este empleado?\n","Error, reingrese."))
					{
						utn_getNumero(&auxInt, "|***MODIFICAR***|\n1. Nombre \n2. Horas trabajadas \n3. Sueldo", "Error, opcion incorrecta", 1, 3, 2);
						switch(auxInt)
						{
							case 1:
								if((utn_getNombre(auxNombre, "Ingrese nombre del empleado\n", "Error, muy largo", 2, 128)==0) &&
								  (employee_setNombre(pAuxEmpleado, auxNombre)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
							case 2:
								if((utn_getNumero(&auxHoras, "Ingrese horas trabajadas\n", "Error, maximo 100000", 0, 100000, 2)==0) &&
								   (employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
							case 3:
								if((utn_getNumero(&auxSueldo, "Ingrese sueldo\n", "Error, maximo 999999", 0, 999999, 2)==0) &&
								   (employee_setSueldo(pAuxEmpleado, auxSueldo)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
						}
						retorno=1;
					}
				}
			}
		}
		return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
		Employee* pAuxEmpleado=NULL;
		int cantLinkedList;
		int auxId;
		int id;
		int i;
		int numMax=0;

		if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
		{
			cantLinkedList=ll_len(pArrayListEmployee);
			for(int i=0; i<cantLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId>numMax)
				{
					numMax=auxId;
				}
			}
			utn_getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico", 0, auxId, 2);
			for(i=0; i<cantLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId==id)
				{
					printf("Desea borrar este empleado?\n");
					employee_print(pAuxEmpleado);
					if(validate_Exit_SN("Desea modificar este empleado?\n","ERROR REINGRESE."))
					{
						if(ll_remove(pArrayListEmployee, i)==0)
						{
							printf("Operaci�n exitosa!\n");
							retorno=1;
							break;
						}
					}
				}
			}
		}
	    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
		Employee* pAuxEmpleado=NULL;
		int auxId;
		int auxHoras;
		int auxSueldo;
		char auxNombre[128];
		int cantLinkedList;

		if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee)==0)
		{
			cantLinkedList=ll_len(pArrayListEmployee);
			printf("| ID   |	NOMBRE	|	HORAS TRABAJADAS	|    SUELDO	|\n");
			for(int i=0; i<cantLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				if(employee_getId(pAuxEmpleado, &auxId)==0 ||
				   employee_getNombre(pAuxEmpleado, auxNombre)==0 ||
				   employee_getHorasTrabajadas(pAuxEmpleado, &auxHoras)==0 ||
				   employee_getSueldo(pAuxEmpleado, &auxSueldo)==0)
				{
					retorno=-1;
					printf("Error, al imprimir lista");
					break;
				}else{
					printf("|%5d |%15s |%15d		|%10d	|\n",auxId, auxNombre, auxHoras, auxSueldo);
				}
			}
			retorno = 0;
		}else{
			printf("No hay lista para imprimir\n");
		}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
		int option;
		int(*pCritOrden)(void*,void*);

		if(pArrayListEmployee!=NULL)
		{
			utn_getNumero(&option, "\t|***ORDENAMIENTO***|"
					"\n1. Id"
					"\n2. Nombre "
					"\n3. Horas Trabajadas "
					"\n4. Sueldo",
					"Error, opcion incorrecta\n", 1, 4, 2);
			switch(option)
			{
				case 1:
					pCritOrden=employee_sortId;
					utn_getNumero(&option, "\t|***CRITERIO***|\n"
										"0. Descendente(1000-1)\n"
										"1. Ascendente(1-1000) \n",
										"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 2:
					pCritOrden=employee_sortNombre;
					utn_getNumero(&option, "\t|***CRITERIO***|\n"
										"0. Descendente(Z-A)\n"
										"1. Ascendente(A-Z) \n",
										"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 3:
					pCritOrden=employee_sortHoras;
					utn_getNumero(&option, "\t|***CRITERIO***|\n"
											"0. Descendente(Mayor a Menor)\n"
											"1. Ascendente(Menor a Mayor) \n",
											"Error, opcion incorrecta", 0, 1, 2);
					break;
				case 4:
					pCritOrden=employee_sortSueldo;
					utn_getNumero(&option, "\t|***CRITERIO***|\n"
											"0. Descendente(Mayor a Menor)\n"
											"1. Ascendente(Menor a Mayor) \n",
											"Error, opcion incorrecta", 0, 1, 2);
					break;
			}

			ll_sort(pArrayListEmployee, pCritOrden, option);
			retorno=1;
		}
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int cantLinkedList;
	char auxNombre[128];
	int auxId;
	int auxHoras;
	int auxSueldo;
	FILE* pFile;

	Employee* pAuxEmpleado=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
		{
			if((pFile=fopen(path,"w"))==NULL)
			{
				printf("No se pudo escribir el archivo\n");
			}
			else
			{
				cantLinkedList=ll_len(pArrayListEmployee);
				fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
				for(int i=0; i<cantLinkedList; i++)
				{
					pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					if(employee_getId(pAuxEmpleado, &auxId)==0 &&
					   employee_getNombre(pAuxEmpleado, auxNombre)==0 &&
					   employee_getHorasTrabajadas(pAuxEmpleado, &auxHoras)==0 &&
					   employee_getSueldo(pAuxEmpleado, &auxSueldo)==0)
					{
					   fprintf(pFile,"%d,%s,%d,%d\n",auxId, auxNombre, auxHoras, auxSueldo);
					   retorno=1;
					}
				}
				printf("Archivo escrito y guardado correctamente\n");
			}
			fclose(pFile);
		}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int auxCantLink, retornoLeido;
	FILE* pFile=NULL;
	Employee* pAuxEmpleado=NULL;

		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			if((pFile=fopen(path,"wb"))==NULL)
			{
				printf("No se pudo escribir el archivo\n");
			}
			else
			{
				auxCantLink=ll_len(pArrayListEmployee);
				for(int i=0; i<auxCantLink; i++)
				{
					pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					retornoLeido=fwrite(pAuxEmpleado, sizeof(Employee),1,pFile);
					if(retornoLeido!=1)
					{
						employee_delete(pAuxEmpleado);
						break;
						retorno=-1;
					}
					else
					{
						retorno=1;
						printf("Archivo escrito y guardado correctamente\n");
					}
				}
			}
			fclose(pFile);
		}
	    return retorno;
}

void controller_chooseLoadText(int flagChoose,LinkedList* list)
{
	utn_getNumero(&flagChoose, "Elija opcion a abrir: \n"
			"1. Data.csv \n"
			"2. Chequeo.csv\n",
			"Error, opcion incorrecta", 1, 2, 1);
		switch(flagChoose)
		{
		case 1:
			controller_loadFromText("data.csv",list);
			break;
		case 2:
			controller_loadFromText("Chequeo.csv",list);
			break;
		}
}

void controller_chooseLoadBin(int flagChoose,LinkedList* list)
{
	utn_getNumero(&flagChoose, "Elija opcion a abrir: \n"
			"1. Data.bin \n"
			"2. Chequeo.bin \n",
			"Error, opcion incorrecta", 1, 2, 1);
		switch(flagChoose)
		{
		case 1:
			controller_loadFromBinary("data.bin",list);
			break;
		case 2:
			controller_loadFromBinary("Chequeo.bin",list);
			break;
		}
}

//EXTRA TP4

int controller_increaseSalary(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	LinkedList* sueldoAumentado=NULL;

	if(pArrayListEmployee!=NULL)
	{
		sueldoAumentado=ll_map(pArrayListEmployee,employee_increaseSalary);
		retorno=1;
	}

	controller_saveAsText("data.csv",sueldoAumentado);

	return retorno;
}
