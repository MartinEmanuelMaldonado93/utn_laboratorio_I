#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "Biblioteca2021.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto). *
 * \param path char*
 * \param ArrayEmployee LinkedList*
 * \return int
 * controla que se haya abierto correctamente el archivo
 */
int controller_loadFromText(char* path , LinkedList* ArrayEmployee)
{
    FILE* pFile = fopen(path,"r");
    int retorno = 1;

    if(pFile != NULL)
    {
	retorno = parser_EmployeeFromText(pFile, ArrayEmployee);
	if(retorno==0)
	{
	    puts("\n#  Carga de texto exitosa   #\n");
	}

    }
    else
    {
	printf("El archivo no pudo ser abierto\n\n");
    }

    fclose(pFile);
    return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param ArrayEmployee LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* ArrayEmployee)
{
    int retorno=1;
    FILE* pBin = NULL;

    if(path !=NULL && ArrayEmployee!=NULL)
    {
	pBin = fopen(path,"rb");
	if(pBin!=NULL)
	{
	    retorno = parser_EmployeeFromBinary(pBin, ArrayEmployee);
	    if(retorno==0)
	    {
		puts("\n#  Carga binaria exitosa   #\n");
	    }
	    else
	    {
		puts("\nError en carga");
	    }
	}
    }
    return retorno;
}
/** \brief Retorna posicion de ArrayEmployee al ingresar Id
 * \param Array de tipo LinkedList*
 * \param id buscado index encontrado
 * \return int
 */
int controller_indexFromId(LinkedList* ArrayEmployee,int len,int id_wanted, int* index_finded)
{
    int retorno=-1, id_aux=0;
    Employee* aux_emp=employee_new();

    if(ArrayEmployee!=NULL && aux_emp!=NULL)
    {
	for(int i = 1; i<len;  i++)
	{
	    aux_emp = ll_get(ArrayEmployee, i);//2
	    employee_getId(aux_emp, &id_aux);

	    if(id_wanted == id_aux)
	    {
		*index_finded= i;
		retorno = 0;
		break;
	    }
	}
    }
    return retorno;
}

/** \brief Retorna el ultimo id cargado en LinkedList* ArrayEmployee
 * \param Array de tipo LinkedList*
 * \return int
 */
int controller_lastIDll(LinkedList* ArrayEmployee)
{
    int retorno=1,max,aux;

    if(ArrayEmployee!=NULL)
    {
	Employee* pEmp;
	int len = ll_len(ArrayEmployee);

	for(int i=1; i<len ; i++)
	{
	    pEmp = ll_get(ArrayEmployee, i);
	    employee_getId(pEmp, &aux);

	    if(i==1 || aux > max )
	    {
		max = aux;
		retorno = max;
	    }
	}
    }

    return retorno;
}
/** \brief Alta de empleado
 * \param Array de tipo LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* ArrayEmployee)
{
    int retorno=-1;
    Employee aux_emp;
    int size_name = sizeof(aux_emp.nombre);

    if(ArrayEmployee!=NULL
    &&getChar(aux_emp.nombre,size_name,"\nIngrese nombre empleado","error",2)==0
    &&getNro(&aux_emp.horasTrabajadas,"\nCuantas horas trabajo?", "error", 1,900, 2)==0
    &&getfloat(&aux_emp.sueldo, "\nIngrese salario", "error", 1.0,999999, 2)==0)
    {
	retorno=1;
	Employee* new_emp = employee_new();

	if(new_emp!=NULL)
	{
	    employee_setHorasTrabajadas(new_emp, aux_emp.horasTrabajadas);
	    employee_setSueldo(new_emp, aux_emp.sueldo);
	    employee_setId(new_emp, controller_lastIDll(ArrayEmployee)+1) ;
	    employee_setNombre(new_emp, aux_emp.nombre);

	    ll_add(ArrayEmployee, new_emp);
	    employee_showEmployee(new_emp);
	    puts("\nAgregado correctamente");
	    retorno=0;
	}
	else
	{
	    puts("\nEmp Null...");
	}
    }
    else
    {
	puts("\nError carga de datos");
    }
    return retorno;
}
/** \brief Modifica datos de empleado
 * \param Array de tipo LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* ArrayEmployee)
{
    int retorno=1, len=ll_len(ArrayEmployee);
    int max_id;
    int id_wanted;
    int index_finded=0;
    Employee* p_aux_emp = employee_new();

    if(ArrayEmployee!=NULL && p_aux_emp && len>0 )
    {
	max_id = controller_lastIDll(ArrayEmployee);
	employee_showEmployees(ArrayEmployee);

	if(getNro(&id_wanted, "\nIngrese el ID del empleado para editar: ","Error ",1,max_id, 2)==0
        && controller_indexFromId(ArrayEmployee,len,id_wanted,&index_finded)==0)
	{
	   p_aux_emp = ll_get(ArrayEmployee, index_finded);

	   employee_edit(p_aux_emp);
	   retorno = 0;
	}
	else
	    puts("\n No se encontro ID");
    }
    return retorno;
}
/** \brief Controla la funcionde baja de empleado
 * \param Array de tipo LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* ArrayEmployee)
{
    int retorno=1,id_wanted=0,index_finded=0,max_id=0,confirmation=0;
    Employee* p_aux_emp=employee_new();

    if(ArrayEmployee!=NULL && p_aux_emp!=NULL)
    {
	max_id = controller_lastIDll(ArrayEmployee);
	employee_showEmployees(ArrayEmployee);

	if( getNro(&id_wanted, "\nIngrese el ID del empleado para eliminar: ","Error ",1,max_id, 2)==0
	&&  controller_indexFromId(ArrayEmployee,ll_len(ArrayEmployee),id_wanted,&index_finded)==0 )
	{
	    if(getNro(&confirmation,"\nSeguro de eliminar registro?\n1)SI\n2)NO","error",1,2,1)==0)
	    {
		if(confirmation==1)
		{
		    ll_remove(ArrayEmployee,index_finded);
		    p_aux_emp = ll_get(ArrayEmployee, index_finded);
		    free(p_aux_emp);
		    puts("\nEliminado ");
		    retorno=0;
		}
	    }
	}
	else
	    puts("Error controllerfromID");
    }
    return retorno;
}
/** \brief Listar empleados
 * \param Array de tipo LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* ArrayEmployee)
{
    int retorno=1;
    if(ArrayEmployee!=NULL)
    {
	employee_showEmployees(ArrayEmployee);
	retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *\param Array de tipo LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* ArrayEmployee)
{
    int retorno=1;
    int order_AD;
    int order_employee=0;
    if(ArrayEmployee!=NULL )
    {
	if(getNro(&order_AD,"\nOrdenar : \n1)Ascendente"
					"\n2)Descendente","Error",1,2,1)==0
	&& getNro(&order_employee,"\nSeleccione tipo de ordenamiento"
				    "\n1)Ordenar por id"
				    "\n2)Ordenar por nombre"
				    "\n3)Ordenar por salario","error", 1, 3, 2)==0)
	{
	    switch (order_employee)
	    {
	    case 1:
		puts("\n Aguarde unos segundos...");
		if(ll_sort(ArrayEmployee, employee_sortById ,order_AD)==0)
		{
		    retorno=0;
		}
		break;
	    case 2:
		puts("\n Aguarde unos segundos...");
		if(ll_sort(ArrayEmployee, employee_sortByName,order_AD)==0)
		{
		    retorno=0;
		}
		break;
	    case 3:
		puts("\n Aguarde unos segundos...");
		if(ll_sort(ArrayEmployee, employee_sortBySueldo,order_AD)==0)
		{
		    retorno=0;
		}
		break;
	    }
	    if(retorno==0)
	    {
		employee_showEmployees(ArrayEmployee);
	    }
	}
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param ArrayEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* ArrayEmployee)
{
    int retorno=1;
    Employee* p_aux_emp;
    FILE* pFile = fopen(path,"w");
    int aux_id;
    char name[128];
    int hs_worked;
    float salary;

    if(pFile!=NULL && ArrayEmployee!=NULL )
    {

	for(int i=1 ;i<ll_len(ArrayEmployee) ;i++)
	{
	    p_aux_emp = ll_get(ArrayEmployee,i);
	    employee_getId(p_aux_emp, &aux_id);
	    employee_getHorasTrabajadas(p_aux_emp, &hs_worked);
	    employee_getSueldo(p_aux_emp, &salary);
	    employee_getNombre(p_aux_emp, name);
	    fprintf(pFile,"%d,%s,%d,%.2f\n",aux_id,name,hs_worked,salary);
	}
	retorno=0;
    }
    fclose(pFile);

    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param ArrayEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* ArrayEmployee)
{
    int retorno=1;
    int len = ll_len(ArrayEmployee);
    FILE* pFile;
    Employee* p_aux_emp;

    if(path!=NULL && ArrayEmployee!=NULL)
    {
	pFile = fopen(path,"wb");
	if(pFile!=NULL )
	{
	    for(int i=0; i<len ;i++)
	    {
		p_aux_emp = (Employee*) ll_get(ArrayEmployee, i);
		//guardarEmp(pFile,p_aux_emp);
		fwrite(p_aux_emp,sizeof(Employee),1,pFile);
	    }
	}
	else
	{
	    puts("\nNo se abrio archivo");
	}
	retorno=0;
    }
    fclose(pFile);
    return retorno;
}

