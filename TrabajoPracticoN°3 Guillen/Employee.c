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
	Employee* this = NULL;
	this = employee_new();

	if(this != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && idStr != NULL && sueldo !=NULL)
	{
		if((employee_setId(this,atoi(idStr))!=0) ||
			(employee_setNombre(this,nombreStr)!=0) ||
			(employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))!=0) ||
			(employee_setSueldo(this,atoi(sueldo))!=0))
		{
			free(this);
			this = NULL;
		}
	}
	return this;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		if(validate_OnlyAlphabet(nombre))
		{
			retorno = 1;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		retorno = 1;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		this->id = id;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->id;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=0;

	if(this!=NULL && horasTrabajadas>-1)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=0;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=0;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_sortSueldo(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxSueldoOne;
	int auxSueldoTwo;

	if(thisOne!=NULL && thisTwo!=NULL && employee_getSueldo((Employee*)thisOne, &auxSueldoOne)==0
			&& employee_getSueldo((Employee*)thisTwo, &auxSueldoTwo)==0)
	{
			if(auxSueldoOne < auxSueldoTwo)
			{
				retorno=1;
			}else{
				if(auxSueldoOne > auxSueldoTwo)
				{
					retorno=-1;
				}
			}

	}
	return retorno;
}

int employee_sortHoras(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxHorasOne;
	int auxHorasTwo;

	if(thisOne!=NULL && thisTwo!=NULL && employee_getHorasTrabajadas((Employee*)thisOne, &auxHorasOne)==0
			&& employee_getHorasTrabajadas((Employee*)thisTwo, &auxHorasTwo)==0)
	{
			if(auxHorasOne < auxHorasTwo)
			{
				retorno=1;
			}else{
				if(auxHorasOne > auxHorasTwo)
				{
					retorno=-1;
				}
			}

	}
	return retorno;
}

int employee_sortNombre(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char auxNameOne[128];
	char auxNameTwo[128];

	if(thisOne!=NULL && thisTwo!=NULL && employee_getNombre((Employee*)thisOne, auxNameOne)==0
			&& employee_getNombre((Employee*)thisTwo, auxNameTwo)==0)
	{
			if(strcmp(auxNameOne,auxNameTwo)>0)
			{
				retorno=1;
			}else{
				if(strcmp(auxNameOne,auxNameTwo)<0)
				{
					retorno=-1;
				}
			}
	}
	return retorno;
}

int employee_sortId(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int auxIdOne;
	int auxIdTwo;

	if(thisOne!=NULL && thisTwo!=NULL && employee_getId((Employee*)thisOne, &auxIdOne)==0
			&& employee_getId((Employee*)thisTwo, &auxIdTwo)==0)
	{
			if(auxIdOne < auxIdTwo)
			{
				retorno=1;
			}else{
				if(auxIdOne > auxIdTwo)
				{
					retorno=-1;
				}
			}

	}
	return retorno;
}

void employee_print(Employee* this)
{
	int auxHoras;
	int auxId;
	int auxSueldo;
	char auxNombre[128];

		if(employee_getId(this, &auxId)==0 && employee_getNombre(this, auxNombre)==0 &&
		   employee_getHorasTrabajadas(this, &auxHoras)==0 && employee_getSueldo(this, &auxSueldo)==0)
		{
			printf("|ID|> %d - |NOMBRE|> %s - |HORAS TRABAJADAS|> %d - |SUELDO|> %d\n",auxId, auxNombre,auxHoras,auxSueldo);
		}
}
