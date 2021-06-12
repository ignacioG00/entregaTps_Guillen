#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Biblioteca.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
			int retornoLeido;
			char buffer[4][128];
			Employee* pAuxEmpleado=NULL;

			if(pFile!=NULL && pArrayListEmployee!=NULL)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
				do
				{
					retornoLeido = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
					if(retornoLeido<4)
					{
						employee_delete(pAuxEmpleado);
						retorno=-1;
						break;
					}
					else
					{
						pAuxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
						if(pAuxEmpleado!=NULL)
						{
							ll_add(pArrayListEmployee,pAuxEmpleado);
							retorno=0;
						}
					}
				}while(!feof(pFile));
			}

	    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		int retornoLeido;
		Employee* pAuxEmpleado=NULL;

		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
		do{
			pAuxEmpleado=employee_new();
			if(pAuxEmpleado!=NULL)
			{
				retornoLeido = fread(pAuxEmpleado,sizeof(Employee),1,pFile);
				if(retornoLeido!=1)
				{
					employee_delete(pAuxEmpleado);
					break;
				}
				else
				{
					ll_add(pArrayListEmployee,pAuxEmpleado);
					retorno=0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}

int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int retornoLeido;
	int auxCantLink;
	Employee* pAuxEmpleado=NULL;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
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
				retorno=0;
			}
		}
	}
	return retorno;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int auxCantLink;
	Employee* pAuxEmpleado=NULL;
	int auxId, auxHoras, auxSueldo;
	char auxNombre[128];

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		auxCantLink=ll_len(pArrayListEmployee);
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0; i<auxCantLink; i++)
		{
			pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(employee_getId(pAuxEmpleado, &auxId)==0 &&
			   employee_getNombre(pAuxEmpleado, auxNombre)==0 &&
			   employee_getHorasTrabajadas(pAuxEmpleado, &auxHoras)==0 &&
			   employee_getSueldo(pAuxEmpleado, &auxSueldo)==0)
			{
				//fprintf(pFile,"%d, %s, %d, %d\n",(*(pAuxEmpleado+i)).id, (*(pAuxEmpleado+i)).nombre, (*(pAuxEmpleado+i)).horasTrabajadas, (*(pAuxEmpleado+i)).sueldo);
				fprintf(pFile,"%d, %s, %d, %d\n",auxId, auxNombre, auxHoras, auxSueldo);
			}
			//printf("%d %s %d %d\n",(*(pAuxEmpleado+i)).id, (*(pAuxEmpleado+i)).nombre, (*(pAuxEmpleado+i)).horasTrabajadas, (*(pAuxEmpleado+i)).sueldo);
			retorno=1;
		}

	}
	return retorno;
}
