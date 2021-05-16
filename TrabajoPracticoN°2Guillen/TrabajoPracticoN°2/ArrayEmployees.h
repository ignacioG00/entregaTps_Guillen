/*
 * 	ArrayEmployees.h
 *	TRABAJO PRACTICO N°2
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

//***ESTRUCTURAS
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int orderEmployees(Employee list[], int len);
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int sortEmployees(Employee list[],int len, int order);
int removeEmployee(Employee* list, int len, int id);
int printEmployees(Employee* list, int length);
int modEmployee(Employee* list, int len);
int salaryListEmployees(Employee* list, int len, float salary);
int promSalaryEmployee(Employee* list, int len ,float* pPromedioResultado );
int getFreeIndexEmployee(Employee* list, int len);
int upEmployee(Employee* list, int len,int* pId);

Employee modDataEmployee(Employee list);

#endif /* ARRAYEMPLOYEES_H_ */
