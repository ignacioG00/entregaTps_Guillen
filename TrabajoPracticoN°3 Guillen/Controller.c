#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
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
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE *pFile=fopen(path,"r");
			if(parser_EmployeeFromText(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
				retorno=1;
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
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE *pFile=fopen(path,"rb");
			if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo leer el archivo\n");
			}
			else
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
				retorno=1;
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
		int cantidadLinkedList;
		int id;
		char auxNombre[128];
		int auxHoras;
		int auxSueldo;
		int numMax=0;
		if(pArrayListEmployee!=NULL)
		{
			if(ll_isEmpty(pArrayListEmployee)==0)
			{
				cantidadLinkedList=ll_len(pArrayListEmployee);
				for(int i=0; i<cantidadLinkedList ; i++)
				{
					pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					employee_getId(pAuxEmpleado, &id);
					if(id>numMax)
					{
						numMax=id;
					}
				}
			}
			else
			{

				if(validate_Exit_SN("Desea crear una nueva lista inicializando el ID en 1\n","ERROR REINGRESE.")==0)
				{
					id=0;
				}
				else
				{
					utn_getNumero(&id, "En que numero quiere inicializar el ID?", "Error, ingrese valor numerico", 1, 100000000, 2);
				}
			}
			pAuxEmpleado=employee_new();
			if(pAuxEmpleado!=NULL)
			{
				if(utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error, muy largo", 2, 128)==0 &&
				   utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error, maximo 100000", 0, 100000, 2)==0 &&
				   utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error, maximo 999999", 0, 999999, 2)==0)
				{
						if(employee_setId(pAuxEmpleado, (id+1))==0 &&
						   employee_setNombre(pAuxEmpleado, auxNombre)==0 &&
						   employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0 &&
						   employee_setSueldo(pAuxEmpleado, auxSueldo)==0)
						{
							ll_add(pArrayListEmployee, pAuxEmpleado);
							printf("Carga exitosa\n");
							retorno=1;
						}
						else
						{
							printf("Error al cargar empleado\n");
						}
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
	int retorno=0;
		Employee* pAuxEmpleado=NULL;
		int cantidadLinkedList;
		int auxId, auxHoras, auxSueldo, id, auxInt;
		int numMax=0;
		char auxNombre[128];

		if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
		{
			cantidadLinkedList=ll_len(pArrayListEmployee);
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId>numMax)
				{
					numMax=auxId;
				}
			}
			utn_getNumero(&id, "Ingrese Id de persona a modificar", "Error, ingrese valor numerico", 0, auxId, 2);
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId==id)
				{
					printf("Desea modificar este empleado?\n");
					employee_print(pAuxEmpleado);
					if(validate_Exit_SN("Desea modificar este empleado?\n","ERROR REINGRESE."))
					{
						utn_getNumero(&auxInt, "------Modificar-------\n1. Nombre \n2. Horas trabajadas \n3. Sueldo", "Error, opcion incorrecta", 1, 3, 2);
						switch(auxInt)
						{
							case 1:
								if((utn_getNombre(auxNombre, "Ingrese nombre del empleado", "Error, muy largo", 2, 128)==0) &&
								  (employee_setNombre(pAuxEmpleado, auxNombre)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
							case 2:
								if((utn_getNumero(&auxHoras, "Ingrese horas trabajadas", "Error, maximo 100000", 0, 100000, 2)==0) &&
								   (employee_setHorasTrabajadas(pAuxEmpleado, auxHoras)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
							case 3:
								if((utn_getNumero(&auxSueldo, "Ingrese sueldo", "Error, maximo 999999", 0, 999999, 2)==0) &&
								   (employee_setSueldo(pAuxEmpleado, auxSueldo)==0))
								{
									printf("Datos modificados correctamente\n");
									employee_print(pAuxEmpleado);
								}
								break;
						}//FIN SWITCH
						retorno=1;
					}
				}
			 }//FIN FOR
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
	int retorno=-1;
		Employee* pAuxEmpleado=NULL;
		int cantidadLinkedList;
		int auxId, id, i;
		int numMax=0;

		if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
		{
			cantidadLinkedList=ll_len(pArrayListEmployee);
			for(int i=0; i<cantidadLinkedList ; i++)
			{
				pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmpleado, &auxId);
				if(auxId>numMax)
				{
					numMax=auxId;
				}
			}
			utn_getNumero(&id, "Ingrese Id de persona a borrar", "Error, ingrese valor numerico", 0, auxId, 2);
			for(i=0; i<cantidadLinkedList ; i++)
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
							printf("Operacion exitosa\n");
							retorno=0;
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
	int retorno = 0;
		Employee* pAuxEmpleado=NULL;
		int cantidadLinkedList;
		if(pArrayListEmployee != NULL)
		{
			if(ll_isEmpty(pArrayListEmployee)==0)
			{
				cantidadLinkedList=ll_len(pArrayListEmployee);
				for(int i=0; i<cantidadLinkedList ; i++)
				{
					pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					employee_print(pAuxEmpleado);
	//				printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",(*(pAuxEmpleado)).id, (*(pAuxEmpleado)).nombre,
	//						                                                           (*(pAuxEmpleado)).horasTrabajadas, (*(pAuxEmpleado)).sueldo);
				}
				retorno = 1;
			}
			else
			{
				printf("No hay lista para imprimir\n");
			}
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
		int(*pOrden)(void*,void*);

		if(pArrayListEmployee!=NULL)
		{
			utn_getNumero(&option, "-----ORDENAMIENTO POR-----\n1. Nombre \n2. Horas Trabajadas \n3. Sueldo", "Error, opcion incorrecta\n", 1, 3, 2);
			switch(option)
			{
				case 1:
					pOrden=employee_sortNombre;
					break;
				case 2:
					pOrden=employee_sortHoras;
					break;
				case 3:
					pOrden=employee_sortSueldo;
					break;
			}//FIN SWITCH
			utn_getNumero(&option, "-----CRITERIOR-----\n1. Ascendente(A-Z)\n0. Descendente(Z-A)\n", "Error, opcion incorrecta", 0, 1, 2);
			ll_sort(pArrayListEmployee, pOrden, option);
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
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE* pFile=fopen(path,"w");
			if(parser_EmployeeToText(pFile,pArrayListEmployee)==0)
			{
				printf("Archivo bien escrito. Guardado correctamente\n");
				retorno=1;
			}
			else
			{
				printf("No se pudo escribir el archivo\n");
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
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE* pFile=fopen(path,"wb");
			if(parser_EmployeeToBinary(pFile,pArrayListEmployee)!=0)
			{
				printf("No se pudo escribir el archivo\n");
			}
			else
			{
				printf("Archivo bien escrito. Guardado correctamente\n");
				retorno=1;
			}
			fclose(pFile);
		}
	    return retorno;
}

