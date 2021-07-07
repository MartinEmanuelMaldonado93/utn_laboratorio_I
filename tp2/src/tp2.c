/*
 ============================================================================
 Author      : Martin Maldonado 1-E
 Description : Trabajo Práctico Número 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2021.h"
#include "entidades.h"
#define QTY 100

int main(void)
{
    setbuf(stdout,NULL);
    int option;
    int option_inform;
    int attempts=2;
    int flag_carga_emp=0;
    int flag_hardcode=0;
    int id_employee = 100;
    worker employee[QTY];
    init_employe(employee,QTY);

  // hardcode_employee(employee, QTY,&id_employee);
   // show_employees(employee, QTY);

    do{
	getNro(&option, "\nSelecciona : "
		"\n1)Agregar empleado"
		"\n2)Modificiar empleado"
		"\n3)Eliminar empleado"
		"\n4)Informes de empleados"
		"\n5)****harcode para facilitar testeo ****"
		"\n6)EXIT ", "error", 1, 6, attempts);

	switch (option)
	{
	    case 1:
		if(add_employee(employee, QTY, &id_employee)==0)
		{
		    flag_carga_emp=1;
		}
		break;
	    case 2:
		if(flag_carga_emp!=0)
		{
		    modify_employee(employee, QTY);
		}
		else
		    {
			puts("\n No hay empleados cargados");
		    }
		break;
	    case 3:
		if(flag_carga_emp!=0)
		{
		   delete_employee(employee, QTY);
		}
		break;
	    case 4:
		if(flag_carga_emp!=0)
		{
		    show_employees(employee, QTY);
		    getNro(&option_inform,"\n1)Listar empleados ordenados alfabeticamente"
		    "\n2)Promedio de salarios de todos los empleados\n3)SALIR", "Error ",1,3, attempts);
		    if(option_inform==1)
		    {
			order_employee_alphabetic(employee, QTY);
			show_employees(employee, QTY);
		    }
		    else if(option_inform == 2)
		    {
			promedy_salary(employee, QTY);
		    }
		}
		else
		{
		    puts("\nCargar empleados primero");
		}
		break;
	    case 5:

		if( flag_hardcode == 0 )
		{
		    hardcode_employee(employee, QTY,&id_employee);
		    flag_carga_emp=1;
		    flag_hardcode = 1;
		    puts("\nLista de empleados cargada...");
		}
		else
		    puts("\nYa cargaste una lista previamente...");

		break;
	    case 6:
		puts("\nHasta luego! ...");
		break;
	    default :
		puts("\n # Elige una opcion valida # ");
	}
    }while(option!=6);


	return EXIT_SUCCESS;
}
