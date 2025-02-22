/*
 * 	ArrayEmployees.c
 *	TRABAJO PRACTICO N�2
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */
#include "ArrayEmployees.h"

#include "Biblioteca.h"

/*
 * \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int i;
	int retorno=0;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 0;
		}
	}else{
		retorno= -1;
	}
 return retorno;
}

/*
 * \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int retorno = 0;
	if(list[len].isEmpty != 1)
	{
		list[len].id=id;
		strcpy(list[len].name,name);
		strcpy(list[len].lastName,lastName);
		list[len].salary=salary;
		list[len].sector=sector;
	}else{
		printf("\t> ERROR.YA EXISTE UN EMPLEADO CON ESE ID!");
		retorno=-1;
	}
 return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 * pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
		int i;
		if (list != NULL && len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].id== id && list[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

		return retorno;
}

/*
 *  \brief Sort the elements in the array of employees, the argument order
 *  indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int sortEmployees(Employee list[],int len, int order)
{
	int retorno = 0;
	int i;
	int j;
	Employee aux;

	if (list != NULL && len > 0) {
		switch (order) {
		case 0:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == 1
							&& list[j].isEmpty == 1) {
						if (list[i].sector > list[j].sector) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		case 1:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					if (list[i].isEmpty == 1
							&& list[j].isEmpty == 1) {
						if (list[i].sector < list[j].sector) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		default:
			retorno = 0;
			break;
		}
		printf("***EL ORDEN HA SIDO MODIFICADO***");
	}
	return retorno;
}

/*
 *  \brief Ordena los empleados por salario o por apellido-
 * \param list Employee*
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 */
int orderEmployeesBySalaryOrLastName(Employee list[], int len)
{
	Employee auxiliarEmpleado;

	int i;
    char auxiliarOpcion[50];
    int opcion;
    int retorno;

    printf("\n> INGRESE EL TIPO DE ORDENAMIENTO\n \t1-POR APELLIDO\n  \t2-POR SECTOR:\n ");
    fflush(stdin);
    gets(auxiliarOpcion);
    while(validate_OnlyNumberInt(auxiliarOpcion)==0)
    {
        printf("\nERROR. INGRESE NUEVAMENTE LA OPCION: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);
    switch(opcion)
    {
    case 1:
    	for (i = 0; i < len - 1; i++)
			{
				if(strcmp(list[i].lastName,list[i + 1].lastName)>0)
					{
						auxiliarEmpleado=list[i];
						list[i]=list[i + 1];
						list[i + 1]=auxiliarEmpleado;
					}else{
						if(strcmp(list[i].lastName,list[i + 1].lastName)==0 && list[i].sector > list[i + 1].sector)
							{
								auxiliarEmpleado=list[i];
								list[i]=list[i + 1];
								list[i + 1]=auxiliarEmpleado;
							}
						}
					}
    	        break;
		retorno = 1;
        break;
    case 2:
    	sortEmployees(list,len,0);
    	 retorno=1;
	break;
    default:
    	 retorno=0;
    }
	return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 * find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = 0;
	int index;
	int flag = 0;
	int flagSalir=1;

	if (printEmployees(list,len)) {
		flag = 1;
	}
	if (flag) {
		while (findEmployeeById(list, len, id) == -1) {
			if(validate_Exit_SN("> NO EXISTE ID. DESEA SALIR? SI[S] NO[N]: ","> ERROR.REINGRESE"))
			{
				flagSalir=-1;
				break;
			}
			id= get_IntPositive("> INGRESE ID A DAR DE BAJA: ", "> ERROR.REINGRESE:");
		}
		if(flagSalir==1){
		index = findEmployeeById(list, len, id);
		if(validate_Exit_SN("> DESEA CONTINUAR? SI[S] NO[N]: ","> ERROR.REINGRESE"))
			{
		list[index].isEmpty = -1;
		retorno = 0;
			}
		}
	}
	return retorno;
}


/*
 * \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee* list, int length)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t****LISTADO EMPLEADOS****");
	printf("%5s %15s %15s %15s %15s \n\n ",
			"ID" ,"NOMBRE","APELLIDO","SALARIO","SECTOR");

	if (list != NULL && length > 0) {
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == 1) {
				printf("%5d %15s %15s %15f %10d \n\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		retorno = 1;
	}
	return retorno;
}
/*
 * \brief realiza el alta del empleado
 *
 * \param list Employee*
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
 * find a employee] - (1) if Ok
 *
 */

int upEmployee(Employee* list, int len,int* pId)
{
	int retorno = 0;
	Employee auxEmpleado;

	int index = getFreeIndexEmployee(list,len);
	if (index != -1)
	{
		get_OnlyAlphabetStringWithSpaces("> INGRESE EL NOMBRE: \n","> ERROR.REINGRESE EL NOMBRE:\n",auxEmpleado.name,51);
		get_OnlyAlphabetStringWithSpaces("> INGRESE EL APELLIDO: \n","> ERROR.REINGRESE EL APELLIDO:\n",auxEmpleado.lastName,51);
		get_FloatRange(&auxEmpleado.salary,"> INGRESE EL SALARIO\n","> ERROR.REINGRESE EL SALARIO:\n",21600,250000,2);
		auxEmpleado.sector=get_Int("> INGRESE EL SECTOR:\n","> ERROR.REINGRESE EL SECTOR:\n");
		if(validate_Exit_SN("> DESEA CONTINUAR? SI[S] NO[N]: ","> ERROR.REINGRESE"))
			{
		auxEmpleado.isEmpty = 1;
		auxEmpleado.id = *pId += 1;
		addEmployee(list, len, auxEmpleado.id, auxEmpleado.name,auxEmpleado.lastName,auxEmpleado.salary,auxEmpleado.sector);
		list[index] = auxEmpleado;
		retorno = 1;
		}

	}
	return retorno;
}

//BUSCAR ESPACIO LIBRE EN ARRAY
/*
 * \brief busqueda del espacio libre en array ingresado.
 * \param list Employee*
 * \param len int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 * pointer received or employee not found]
 *
 */

int getFreeIndexEmployee(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*
 * \brief Modificar datos necesarios para el MODIFICAR.
 * \param list Employee*
 * \return Retorna una estructura Employee modificada.
 *
 */
Employee modDataEmployee(Employee list)
{
	Employee auxiliar = list;
	int opc;
	printf("> INGRESE QUE QUIERE MODIFICAR: \n");
	opc=get_IntRange("\t1 - NOMBRE \n \t2 - APELLIDO \n \t3 - SALARIO\n \t4 - SECTOR  \n\n-","> ERROR REINGRESE EL QUE QUIERE MODIFICAR:\n "
			"\t1 - NOMBRE \n \t2 - APELLIDO \n \t3 - SALARIO \n \t4 - SECTOR \n-",1,4);
	switch(opc){
		case 1:
	get_OnlyAlphabetStringWithSpaces("> INGRESE EL NOMBRE:\n-","> ERROR.REINGRESE.\n",auxiliar.name,51);
	break;

		case 2:
	get_OnlyAlphabetStringWithSpaces("> INGRESE EL APELLIDO:\n-","> ERROR.REINGRESE.\n",auxiliar.lastName,51);
	break;

		case 3:
	get_FloatRange(&auxiliar.salary,"> INGRESE EL SALARIO\n","> ERROR.REINGRESE EL SALARIO:\n",21600,250000,2);
	break;
		case 4:
	auxiliar.sector=get_Int("> INGRESE EL NRO DE SECTOR:\n","> ERROR. REINGRESE NRO DE SECTOR \n");
			break;
	}
	return auxiliar;
}

/*
 * \brief Modificar datos necesarios para el MODIFICAR.
 * \param list Employee*
 * \param int len
 * \return int Return (0) si no modifico nada o dio error,
 * (1) if Ok
 *
 */

int modEmployee(Employee* list, int len)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;
	Employee auxiliar;

	if (printEmployees(list, len)) {
		flag = 1;
	}

	if (flag) {
		id=get_Int("> INGRESE ID A DAR DE BAJA: \n","> ERROR.REINGRESE ID: \n");

		while (findEmployeeById(list, len, id) == -1) {
			puts("*NO EXISTE ESE ID.*");
			id=get_Int("> INGRESE ID A DAR DE BAJA: \n","> ERROR.NO EXISTE ESE ID REINGRESE:\n");
		}

		index = findEmployeeById(list, len, id);
		auxiliar = modDataEmployee(list[index]);
		if(validate_Exit_SN("> DESEA CONTINUAR? SI[S] NO[N]: ","> ERROR.REINGRESE:"))
		{
		list[index] = auxiliar;
		retorno = 1;
		}
	}
	return retorno;
}

/*
 *
 * \brief devuelve en promResult el salario promedio de los empleados.
 * \param list Employee*
 * \param int len
 * \param float* promResult
 * \return int Return (-1) si no modifico nada o dio error,
 * (0) if Ok
 *
 */

int promSalaryEmployee(Employee* list, int len,float* promResult)
{
	int retorno = -1;
	int i;
	int acumulador=0;
	int contador=0;

	if(promResult != NULL && list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
			acumulador += list[i].salary;
			contador++;
			}
		}
		*promResult = acumulador/contador;
		printf("> EL SALARIO PROMEDIO ES: %.2f\n", *promResult);
		retorno = 0;
	}
	return retorno;
}
/*
 *
 * \brief imprime la cantidad de empleados que supera el salario promedio.
 * \param list Employee*
 * \param int len
 * \param float* salary
 * \return int Return (-1) si no modifico nada o dio error,
 * (0) if Ok
 *
 */

int printHigherSalaryEmployees(Employee* list, int len, float salary)
{
	int retorno=-1;
	int i;
	int contSuperaSalario=0;

	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				if(list[i].salary>salary)
				{
					contSuperaSalario ++;
					retorno=0;
				}
			}
		}
	}
	printf("> La cantidad de empleados que supera el salario promedio es: %d Empleados. \n",contSuperaSalario);
	return retorno;
}
