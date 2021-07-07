#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#define tam_titulo 34
/*id,nombre,horasTrabajadas,sueldo\n\0*/
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* ArrayEmployee)
{
    int retorno=1;
    int count = 0;
    Employee* aux_emp= NULL;

    char char_id[10];
    char char_name[50];
    char char_hours[50];
    char char_salary[50];

    if(pFile != NULL)
    {
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
    Employee* aux_empleado = employee_new();

    if(pFile != NULL && ArrayEmployee!=NULL)
    {
	do
	{
	    lectura = leerEmp(aux_empleado,pFile);
	    if(lectura == 1)
	    {
		ll_add(ArrayEmployee, aux_empleado);
		retorno = 0;
	    }
	    else
	    {
		employee_delete(aux_empleado);
		printf("\nValor Lectura %d",lectura);
		puts("\n Lectura fallida ");
		retorno=1;
		break;
	    }
	}while( !feof(pFile));

	fclose(pFile);
    }
    else
    {
	printf("No hay datos. * NULL *");
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
