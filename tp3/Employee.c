#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2021.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* emp;
    emp = (Employee*) malloc(sizeof(Employee));
    if(emp!=NULL)
    {
	(*emp).id = 0;
	strcpy((*emp).nombre, "");
	(*emp).horasTrabajadas = 0;
	(*emp).sueldo = 0;
	return emp;
    }
    return NULL;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* emp = employee_new();
	if(emp!=NULL)
	{
	    employee_setId(emp, atoi(idStr));
	    employee_setNombre(emp, nombreStr);
	    employee_setHorasTrabajadas(emp,atoi(horasTrabajadasStr));
	    employee_setSueldo(emp,atof(sueldo));
	    return emp;
	}
	return NULL;
}
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
	    free(this);
	}
}
int employee_setId(Employee* this,int id)
{
	int retorno = 1;
	if( id > 0 && this != NULL)
	{
	    (*this).id = id;
	    retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno=1;
	if( this != NULL && id!=NULL)
	{
	    *id=(*this).id;
	    retorno=0;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno= 1;
	if(this != NULL && strlen(nombre)<4096)
	{
	    strncpy(/*destino*/(*this).nombre, nombre ,sizeof( (*this).nombre ) );
	    retorno=0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int ret= 1;
	if(this != NULL )
	{
	    strcpy(nombre,(*this).nombre);
	    ret=0;
	}
	return ret;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=1;
    if(this != NULL)
    {
	(*this).horasTrabajadas = horasTrabajadas;
	ret=0;
    }
    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=1;
	if(this != NULL)
	{
	     *horasTrabajadas = this->horasTrabajadas;
	    ret=0;
	}
	return ret;
}
int employee_setSueldo(Employee* this,float sueldo)
{
    int ret=1;

    if(this != NULL)
    {
	(*this).sueldo= sueldo;
	ret=0;
    }
    return ret;
}
int employee_getSueldo(Employee* this,float* sueldo)
{
	int ret;
	ret = 1;

	if(this != NULL)
	{
	    *sueldo = this->sueldo;
	    ret=0;
	}
	return ret;
}
void  employee_showEmployee(Employee* this)
{
    int aux_id,aux_hours;
    char aux_name[60];
    float aux_salary;

    if(this != NULL
    && employee_getHorasTrabajadas(this, &aux_hours)==0
    && employee_getId(this, &aux_id)==0
    && employee_getNombre(this, aux_name)==0
    && employee_getSueldo(this, &aux_salary)==0)
	printf ( " %4d  %s  %d  %.2f \n " ,
		aux_id ,aux_name,aux_hours,aux_salary);
    else
	puts("\nError show employees ");
}
void  employee_showEmployees(LinkedList* this)
{
    Employee* aux_emp = NULL;
    int len = ll_len(this);

    if(this != NULL && len>0)
    {
	for(int i=0 ;  i < len ;  i++)
	{
	    aux_emp = (Employee*) ll_get(this, i);
	    employee_showEmployee(aux_emp);
	}
	printf("\nCantidad empleados <%d>\n",len);
    }
    else
    {
	printf("No hay empleados cargados\n\n");
    }
}
int employee_sortByName(void* empleadoA, void* empleadoB)
{
    int retorno=0;
    Employee* empleado_uno = (Employee*)empleadoA;
    Employee* empleado_dos = (Employee*)empleadoB;
    char nombre_emp_uno[60];
    char nombre_emp_dos[60];
    employee_setNombre(empleado_uno, nombre_emp_uno);
    employee_setNombre(empleado_dos, nombre_emp_dos);

    retorno = strcmp( nombre_emp_uno, nombre_emp_dos );
    if(retorno>0)
    {
	retorno = 1;
    }
    else if(retorno<0)
    {
	retorno = -1;
    }
    return retorno;
}
int employee_sortById(void* empleadoA, void* empleadoB)
{
    int retorno=0;
    Employee* empleado_uno = (Employee*)empleadoA;
    Employee* empleado_dos = (Employee*)empleadoB;
    int aux_id_uno=0;
    int aux_id_dos=0;
    employee_setId(empleado_uno, aux_id_uno);
    employee_setId(empleado_dos, aux_id_dos);

    if( aux_id_uno > aux_id_dos )
    {
	retorno = 1;
    }
    if(  aux_id_uno  < aux_id_dos )
    {
	retorno = -1;
    }
    return retorno;
}
int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int retorno=0;
    Employee* empleadoUno = (Employee*)empleadoA;
    Employee* empleadoDos = (Employee*)empleadoB;
    int aux_hs_uno=0;
    int aux_hs_dos=0;
    employee_setHorasTrabajadas(empleadoUno, aux_hs_uno);
    employee_setHorasTrabajadas(empleadoDos, aux_hs_dos);

    if( aux_hs_uno > aux_hs_dos )
    {
	retorno = 1;
    }
    if( aux_hs_uno < aux_hs_dos )
    {
	retorno = -1;
    }
    return retorno;
}
int employee_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int retorno=0;
    Employee* empleado_uno = (Employee*)empleadoA;
    Employee* empleado_dos = (Employee*)empleadoB;
    int aux_sueldo_uno=0;
    int aux_sueldo_dos=0;
    employee_setSueldo(empleado_uno, aux_sueldo_uno);
    employee_setSueldo(empleado_dos, aux_sueldo_dos);
    if( aux_sueldo_uno > aux_sueldo_dos )
    {
	retorno = 1;
    }
    if( aux_sueldo_uno < aux_sueldo_dos)
    {
	retorno = -1;
    }
    return retorno;
}
int employee_edit(Employee* this)
{
    int retorno=1;
    int option=0;
    char aux_name[60];
    int aux_hs_worked;
    float aux_salary;

    if(this!=NULL)
    {
	puts("\n Usted selecciono :");
	employee_showEmployee(this);
	do{
	getNro(&option, "\nEditar:"
			"\n1)Nombre"
			"\n2)Horas trabajadas"
			"\n3)Sueldo"
			"\n4)Salir","Error edit opcion",1,4, 2);

	switch (option)
	{
	    case 1:
		if(getChar(aux_name,120 ,"Ingrese nuevo nombre","Error", 2)==0)
		{
		    employee_setNombre(this, aux_name);
		    puts("\nNombre actualizado: ");
		    employee_showEmployee(this);
		}
	    break;
	    case 2:
		employee_showEmployee(this);
		if(getNro(&aux_hs_worked,"\nIngrese nuevas hs trabajadas", "Error", 1, 900, 2)==0)
		{
		    employee_setHorasTrabajadas(this, aux_hs_worked);
		    puts("\nHoras actualizadas: ");
		    employee_showEmployee(this);
		}
		break;
	    case 3:
		employee_showEmployee(this);
		if(getfloat(&aux_salary,"\nIngrese nuevo salario","Error", 1,9999,2)==0)
		{
		    employee_setSueldo(this, aux_salary);
		    puts("\nSalario actualizado: ");
		    employee_showEmployee(this);
		}
		break;
	}
	}while(option!=4);

	puts("\nDatos actualizados: ");
	employee_showEmployee(this);

	retorno=0;
    }
    return retorno;
}
