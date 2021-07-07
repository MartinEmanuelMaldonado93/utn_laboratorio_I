#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2021.h"
#include "entidades.h"
#include <string.h>

int init_employe(worker* employee, int lenght)
{
    int retornus=-1;
    if(employee!=NULL && lenght>0)
    {
	for(int i=0;i<lenght;i++)
	{
	    employee[i].id_emp=0;
	    employee[i].salary=0;
	    employee[i].sector=0;
	    employee[i].isEmpty=1;
	    strcpy(employee[i].name,"nothing");
	    strcpy(employee[i].lastName,"nothing");
	}
	retornus=0;
    }
    return retornus;
}
void hardcode_employee(worker* employee,int lenght,int* id_emp)
{
    worker workers[]={
	    {101,2,"Martin","Bukowski",450.9,0},
	    {102,3,"Aime","Escobar",670.9,0},
	    {103,3,"Kristine","Tancredi",100.2,0},
	    {104,1,"Yanina","Paredes",1022,0},
	    {105,2,"Chris","Luzkcs",670.9,0},
	    {106,2,"Cristal","Smith",300,0},
	    {107,1,"Victor","Bukowski",333,0},
	    {108,1,"Marina","Zokovich",500,0}
    };
    for(int i=0;i<8;i++)
    {
	employee[i]= workers[i];
    }
    *id_emp=*id_emp+8;
}
int findEmptySpace_employe(worker* employee, int lenght,int* empty_position)
{    
    int retornus=-1;
    if (employee !=NULL && lenght >0 )
    {
	retornus=1;
	for (int i=0; i<lenght; i++)
	{
	    if(employee[i].isEmpty == 1)
	    {
		retornus = 0;
		*empty_position = i;
		break;
	    }
	}
    }
    return retornus;
}
void show_employee(worker* employee,int position)
{
    if(employee!=NULL )
    {	// id  name lastname  sector salary
	printf("%d    %-s,     %s      %-5d  %.2f\n",
	employee[position].id_emp
	,employee[position].name
	,employee[position].lastName
	,employee[position].sector
	,employee[position].salary);
    }
}
void print_signboard()
{
    printf("ID     NAME       LASTNAME     SECTOR     SALARY \n");
}
int add_employee(worker* employee,int lenght,int* id_employee)
{
    int retornus=-1;
    int position;
    int attempts = 2;
    worker aux;

    if(employee!=NULL && lenght>0 && *id_employee>0)
    {
	if(findEmptySpace_employe(employee, lenght,&position)==0) // si encuentro lugar vacio
	{
	    printf("\nPOSICION ENCONTRADA %d",position);
	    if(getChar(aux.name,len_text,"\nIngrese nombre: ","\nError nombre",attempts)==0
	    &&getChar(aux.lastName,len_text,"\nIngrese apellido: ","\nError apellido", attempts)==0
	    &&getNro(&aux.sector,"\nIngrese sector 1-3", "\nError sector", 1, 3, attempts)==0
	    &&getfloat(&aux.salary,"\nIngrese salario [100-10,000]", "Error salario", 100, 10000, attempts)==0)
	    {
		formatoName(aux.name);
		formatoName(aux.lastName);
		aux.id_emp = ++(*id_employee);
		aux.isEmpty = 0;

		employee[position] = aux;
		puts("__________________________________________________");
		print_signboard();
		show_employee(employee, position);
		puts("__________________________________________________");
		show_employees(employee, lenght);
		retornus=0;
	    }
	    else
	    {
		puts("\nError carga de empleado");
	    }
	}
    }
    return retornus;
}
int show_employees(worker* employee,int lenght)
{
    int retornus=-1;
    if(employee!=NULL && lenght >0)
    {
	print_signboard();
	for(int i=0; i<lenght ;i++)
	{
	    if(employee[i].isEmpty == 0)
	    {
		show_employee(employee, i);
	    }
	}
	retornus=0;
    }
    return retornus;
}
int findEmployeeById(worker* employee,int lenght,int id_finded,int* position_array)
{
    int retornus=1;

    if(employee!=NULL && lenght>0 && id_finded>0)
    {
	for(int i=0;i<lenght;i++)
	{
	    if(employee[i].isEmpty==0 && employee[i].id_emp==id_finded)
	    {
		retornus=0;
		*position_array=i;
		break;
	    }
	}
    }
    return retornus;
}
int modify_employee(worker* employee,int lenght)
{
    int retornus=1,id,attempts=2,position_finded,option;
    worker aux;
    if(employee!=NULL && lenght>0)
    {
	show_employees(employee, lenght);
	if(getNro(&id,"\nIngresar id de empleado para modificar"," \nError id", 100, 1000,attempts)==0
	&& findEmployeeById(employee, lenght,id, &position_finded)==0)
	{
	    puts("\n__________________USTED SELECCIONO__________________ ");
	    print_signboard();
	    show_employee(employee, position_finded);// muestro emp elegido
	    puts("\n____________________________________________________");
	   do{
	    getNro(&option, "\nElegir campo a modificar "
		    "\n1-Nombre"
		    "\n2-Apellido"
		    "\n3-Sector"
		    "\n4-Salario"
		    "\n5-SALIR" ,"\nError", 1, 5, 2);
	    switch (option)
		{
		case 1:
		    if(getChar(aux.name,len_text,"\nIngresar nuevo nombre: ","Error nombre",2)==0)
		    {
			strcpy(employee[position_finded].name, aux.name);
			print_signboard();
			show_employee(employee, position_finded);
		    }
		    break;
		case 2:
		    if(getChar(aux.lastName,len_text,"\nIngresar nuevo apellido: ","error apellido", 2)==0)
		    {
			strcpy(employee[position_finded].lastName, aux.lastName);
			print_signboard();
			show_employee(employee, position_finded);
		    }
		    break;
		case 3:
		    if(getNro(&aux.sector,"\nIngresar sector [1-3]", "\nError sector", 1, 3,2)==0)
		    {
			employee[position_finded].sector=aux.sector;
			print_signboard();
			show_employee(employee, position_finded);
		    }
		    break;
		case 4:
		    if(getfloat(&aux.salary,"\nIngresar salario [100-10,000]", "Error salario", 100, 10000,2)==0)
		    {
			employee[position_finded].salary=aux.salary;
			print_signboard();
			show_employee(employee, position_finded);
		    }
		    break;
		}
	   }while(option!=5);
	   print_signboard();
	   show_employee(employee, position_finded);
	}
	else
	   puts("\n No se encontro ID !");
    }
    return retornus;
}
int delete_employee(worker* employee,int lenght)
{
    int retornus=1;
    int id;
    int attempts=2;
    int position_finded;
    int option;

    show_employees(employee, lenght);
    if(getNro(&id,"\nIngrese id de empleado que desea eliminar "," \nError  id", 100, 1000,attempts)==0
    &&findEmployeeById(employee, lenght,id, &position_finded)==0)
    {
	print_signboard();
	show_employee(employee, position_finded);
	getNro(&option,"\nEsta seguro que quiere eliminar ? [1 Si] [2 No]", "\error Del", 1, 2,attempts);
	if(option==1)
	{
	    employee[position_finded].isEmpty=1;
	    puts("\nEliminado");
	    retornus=0;
	}
    }
    return retornus;
}
int order_employee_alphabetic(worker* employee,int lenght)
{
    int retornus=1;
    worker aux;
    if(employee!=NULL&& lenght>0)
    {
	for (int i =0; i<lenght-1  ;i++)
	{
	    for(int j=i+1; j<lenght  ;j++)
	    {

		if(strcmp(employee[i].lastName,employee[j].lastName)>0)
		{
		    aux=employee[i];
		    employee[i]=employee[j];
		    employee[j]=aux;
		}
		if(strcmp(employee[i].lastName,employee[j].lastName)==0
		&& employee[i].sector<employee[j].sector)
		{
		    aux=employee[i];
		    employee[i]=employee[j];
		    employee[j]=aux;
		}
	    }
	}
    }
    return retornus;
}
int promedy_salary(worker* employee,int lenght)
{
    int retornus=1;
    int count_high_salaries=0;
    int count=0;
    float acumulator=0;
    float promedy=0;

    if(employee!=NULL && lenght>0)
    {
	for(int i=0;i<lenght;i++)
	{
	    if(employee[i].isEmpty==0)
	    {
		acumulator += employee[i].salary;
		count++;
	    }
	}
	promedy = acumulator/count;

	for(int j=0;j<lenght;j++)
	{
	    if(employee[j].isEmpty==0 && employee[j].salary>promedy)
	    {
		count_high_salaries++;
	    }
	}
	printf("\nPromedio de todos los empleados : $%.2f\nTotal de empleados que exceden el promedio:%d \n",promedy,count_high_salaries);
	retornus=0;
    }

    return retornus;
}
