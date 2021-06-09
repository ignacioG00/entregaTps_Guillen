#include "Employee.h"
#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Employee* employee_new(void)
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* empleado = NULL;
	empleado = employee_new();
	if(empleado != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && idStr != NULL && sueldo !=NULL)
	{
		if((employee_setId(empleado,atoi(idStr))!=0) ||
			(employee_setNombre(empleado,nombreStr)!=0) ||
			(employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr))!=0) ||
			(employee_setSueldo(empleado,atoi(sueldo))!=0))
		{
			employee_delete(empleado);
			empleado = NULL;
		}
	}
	return empleado;
}

Employee* employee_newParametrosTxt(char* nombreStr,char* sueldo,char* idStr,char* horasTrabajadasStr)
{
	Employee* empleado = NULL;
	empleado = employee_new();
	if(empleado != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && idStr != NULL && sueldo !=NULL)
	{
		if((employee_setId(empleado,atoi(idStr))!=0) ||
				(employee_setNombre(empleado,nombreStr)!=0) ||
				(employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr))!=0) ||
				(employee_setSueldo(empleado,atoi(sueldo))!=0))
		{
			employee_delete(empleado);
			empleado = NULL;
		}
	}
	return empleado;
}


void employee_delete(Employee* empleado)
{
	if(empleado != NULL)
	{
		free(empleado);
	}
}

int employee_setNombre(Employee* empleado,char* nombre)
{
	int retorno = -1;
	if(empleado != NULL && nombre != NULL)
	{
		if(validate_OnlyAlphabet(nombre))
		{
			retorno = 0;
			strncpy(empleado->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* empleado,char* nombre)
{
	int retorno = -1;
	if(empleado != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,empleado->nombre,NOMBRE_LEN);
	}
	return retorno;
}


int employee_setId(Employee* empleado,int id)
{
	int retorno = -1;
	if(empleado != NULL)
	{
		retorno = 0;
		empleado->id = id;
	}
	return retorno;
}

int alumno_setIdTxt(Employee* empleado,char* id)
{
	int retorno = -1;
	if(empleado != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			empleado->id = atoi(id);
		}
	}
	return retorno;
}

int employee_getId(Employee* empleado,int* id)
{
	int retorno = -1;
	if(empleado != NULL && id != NULL)
	{
		retorno = 0;
		*id = empleado->id;
	}
	return retorno;
}

int empleado_getIdTxt(Employee* empleado,char* id)
{
	int retorno = -1;
	if(empleado != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",empleado->id);
	}
	return retorno;
}



int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas)
{
	int retorno=-1;
	if(empleado!=NULL && horasTrabajadas>-1)
	{
		empleado->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee* empleado,char* horasTrabajadas)
{
	int retorno=-1;
	int auxHorasTrabajadas;
	if(empleado!=NULL && horasTrabajadas!=NULL)
	{
		auxHorasTrabajadas= atoi(horasTrabajadas);
		if(auxHorasTrabajadas>-1)
		{
			empleado->horasTrabajadas=auxHorasTrabajadas;
			retorno=0;
		}
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas)
{
	int retorno=-1;
	if(empleado!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=empleado->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* empleado,int sueldo)
{
	int retorno=-1;
	if(empleado!=NULL)
	{
		empleado->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldoTxt(Employee* empleado,char* sueldo)
{
	int retorno=-1;
	if(empleado!=NULL && sueldo!= NULL)
	{
		if(esNumerica(sueldo,10))
		{
			retorno = 0;
			empleado->sueldo = atoi(sueldo);
		}
	}
	return retorno;
}

int employee_getSueldo(Employee* empleado,int* sueldo)
{
	int retorno=-1;
	if(empleado!=NULL && sueldo!=NULL)
	{
		*sueldo=empleado->sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_sortSueldo(void* thisOne, void* thisTwo)
{
	int retorno=-1;
	Employee* pAuxEmpleado1;
	Employee* pAuxEmpleado2;
	if(thisOne!=NULL && thisTwo!=NULL)
	{
		pAuxEmpleado1=(Employee*)thisOne;
		pAuxEmpleado2=(Employee*)thisTwo;
		if( (*(pAuxEmpleado1)).sueldo > (*(pAuxEmpleado2)).sueldo )
		{
			retorno=1;
		}
		if( (*(pAuxEmpleado1)).sueldo < (*(pAuxEmpleado2)).sueldo )
		{
			retorno=-1;
		}
	}
	return retorno;
}

int employee_sortHoras(void* thisOne, void* thisTwo)
{
	int retorno=0;
	Employee* pAuxEmpleado1;
	Employee* pAuxEmpleado2;
	if(thisOne!=NULL && thisTwo!=NULL)
	{
		pAuxEmpleado1=(Employee*)thisOne;
		pAuxEmpleado2=(Employee*)thisTwo;
		if( (*(pAuxEmpleado1)).horasTrabajadas > (*(pAuxEmpleado2)).horasTrabajadas )
		{
			retorno=1;
		}
		if( (*(pAuxEmpleado1)).horasTrabajadas < (*(pAuxEmpleado2)).horasTrabajadas )
		{
			retorno=-1;
		}
	}
	return retorno;
}

int employee_sortNombre(void* thisOne, void* thisTwo)
{
	int retorno=0;
	Employee* pAuxEmpleado1;
	Employee* pAuxEmpleado2;
	if(thisOne!=NULL && thisTwo!=NULL)
	{
		pAuxEmpleado1=(Employee*)thisOne;
		pAuxEmpleado2=(Employee*)thisTwo;
		if(strcmp((*(pAuxEmpleado1)).nombre,(*(pAuxEmpleado2)).nombre)>0)
		{
			retorno=1;
		}
		if(strcmp((*(pAuxEmpleado1)).nombre,(*(pAuxEmpleado2)).nombre)<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

void employee_print(Employee* this)
{
	printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",(*(this)).id, (*(this)).nombre,
																	   (*(this)).horasTrabajadas, (*(this)).sueldo);
}
