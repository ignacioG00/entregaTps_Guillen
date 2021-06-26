/*
 * 	UTN.c
 *	TRABAJO PRACTICO N°4
 *  DNI:42.432.724
 *  AUTHOR:IGNACIO GUILLEN
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
