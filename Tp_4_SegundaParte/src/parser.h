/*
 * parser.h
 *
 *  Created on: 5 nov. 2020
 *      Author: Usuario
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int leerEmp(Employee* emp,FILE* elpFile);
int guardarEmp(FILE* pFile,Employee* emp);
