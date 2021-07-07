#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* ArrayEmployee)
{
    int retorno=1,count = 0;
    Employee* aux_emp= NULL;

    char char_id[10];
    char char_name[50];
    char char_hours[50];
    char char_salary[50];

    if(pFile != NULL)
    {	//Lectura fantasma
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", char_id, char_name, char_hours, char_salary);
	do
	{
	    count = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", char_id, char_name, char_hours, char_salary);
	    if(count == 4)
	    {
		aux_emp = employee_newParametros(char_id, char_name, char_hours, char_salary);
		ll_add(ArrayEmployee,aux_emp);
	    }
	    else
	    {
		printf("Error. No se pudieron cargar todos los archivos\n\n");
	    }
	}while(!feof(pFile));

	fclose(pFile);

	retorno=0;
    }

    return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* ArrayEmployee)
{
    int retorno = -1;
    int lectura;

    if(pFile != NULL )
    {
	do{
	    Employee* aux_empleado = employee_new();
	    lectura = leerEmp( aux_empleado ,pFile );
	    if(lectura == 1)
	    {
		if(ll_add(ArrayEmployee, aux_empleado)==0)
		{
		    retorno=0;
		}
	    }
	    else
	    {
		employee_delete(aux_empleado);
		break;
	    }
	}while(!feof(pFile));
	fclose(pFile);
    }
    else
    {
	printf("Error en parametros. * NULL *");
    }
    return retorno;
}
/** Lee un Employee en modo BIN
 * retorna la cantidad de unidades leidas a travez de fread
 * */
int leerEmp(Employee* emp,FILE* pFile)
{
    return fread(emp,sizeof(Employee),1,pFile);
}
int guardarEmp(FILE* pFile,Employee* emp)
{
    return fwrite(emp,sizeof(Employee),1,pFile);
}
