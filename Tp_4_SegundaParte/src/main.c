#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2021.h"
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    setbuf(stdout,NULL);
    int option = 0;
    int flag_bin=0;
    int flag_text=0;
    LinkedList* list_employees = ll_newLinkedList();


    do{
	getNro(&option,"1. Cargar datos de empleados desde data.csv (modo texto)."
		"\n2. Cargar datos de empleados desde  data.bin (modo binario)."
		"\n3. Agregar empleado "
		"\n4. Modificar datos de empleado"
		"\n5. Eliminar empleado "
		"\n6. Listar todos los empleados"
		"\n7. Ordenar empleados "
		"\n8. Guardar informacion de empleados al archivo data.csv (modo texto)."
		"\n9. Guardar informacion de empleados al archivo data.bin (modo binario)."
		"\n10. SALIR ", "Error...", 1, 10, 1);
        switch(option)
        {
            case 1:
        	if(flag_text==0 && flag_bin==0)
		{
        	    controller_loadFromText("data.csv",list_employees);
        	    flag_text=1;
		}
        	else
        	    puts("\n Ya cargaste una lista anteriormente");
                break;
            case 2:
        	if(flag_text == 0)
		{
        	    if(controller_loadFromBinary("data.bin", list_employees)==0)
		    {
        		puts("\nCarga correcta");
        		flag_bin = 1;
		    }
        	    else
		    {
        		puts("\n#  Error en la carga #\n");
		    }

		}
        	else
        	    puts("\nYa cargaste una lista anteriormente");
            	break;
            case 3:
        	    if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
            	    {
        		puts("\n# AGREGAR EMPLEADO #");
        		controller_addEmployee(list_employees);
            	    }
        	    else
        		puts("Debe cargar lista primero");
            	break;
            case 4:
        	if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
        	    puts("\n entro en el if");
		    controller_editEmployee(list_employees);
		}
        	else
        	    puts("\n #######  Error en la logica del main del 4");

            	break;
            case 5:
        	if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
        	    controller_removeEmployee(list_employees);
		}
		break;
            case 6:
        	if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
        	    employee_showEmployees(list_employees);
		}
        	break;
            case 7:
        	if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
        	    controller_sortEmployee(list_employees);
		}
        	break;
            case 8:
        	if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
        	    if(getNro(&option,"\nGuardar una copia con modificaciones[1]"
        		    "\n Guardar en archivo existente [2]","\nError ",1,2,1)==0)
		    {
			if(option == 1
			&& controller_saveAsText("data_copia.csv", list_employees)==0)
			{
			    puts("\n##### Copia con modificaciones guardada !");
			}
			else if(option == 2
			&& controller_saveAsText("data.csv", list_employees)==0)
			{
			    puts("\n##### Datos actualizados .");
			}
		    }

		}
        	break;
	    case 9:
		if((flag_text!=0 && flag_bin==0) || (flag_bin!=0 && flag_text== 0))
		{
		    if(controller_saveAsBinary("data.bin", list_employees)==0)
		    {
			 puts("\n#  Guardado ! # ");
		    }
		}
        	break;
            case 10:
        	    ll_clear(list_employees);
		    ll_deleteLinkedList(list_employees);
		    puts("Bye..");
        	break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}

