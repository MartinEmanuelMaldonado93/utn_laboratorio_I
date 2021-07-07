#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;//4
    char nombre[128]; //128
    int horasTrabajadas;//4
    float sueldo;//8
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void  employee_showEmployee(Employee* this);
void  employee_showEmployees(LinkedList* this);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);
int employee_sortById(void* empleadoA, void* empleadoB);
int employee_sortByName(void* empleadoA, void* empleadoB);
int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB);
int employee_sortBySueldo(void* empleadoA, void* empleadoB);
int employee_edit(Employee* this);
#endif
