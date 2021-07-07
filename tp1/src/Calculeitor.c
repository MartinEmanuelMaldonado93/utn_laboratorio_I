/*
 ============================================================================
 Name        : Calculeitor.c
 Author      : Martin Maldonado Div-E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2021.h"
#include "funciones.h"
int main(void) {
    setbuf(stdout,NULL);

    int rta;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;
    int flagCalculando=0;
    int primerOperando=0;
    int segundoOperando=0;
    int Suma;
    int Resta;
    float Division;
    int Factorial[2];


    puts("       #### CALCULADORA ####\n");
    do{
	getNro(&rta,"1.Ingresar 1er operando\n"
		    "2.Ingresar 2do operando \n"
		    "3.Calcular todas las operaciones\n"
		    "4.Mostrar resultados\n"
		    "5.SALIR :"
		    ,"Error", 1, 5, 2);

	switch(rta)
	{
	    case 1:
		if(flagPrimerOperando==0)
		{
		    getNro(&primerOperando," Ingrese 1er numero: ","Error",-4000000 ,400000,2);
		    printf("\nPrimer Operando ingresado: %d\n\n",primerOperando);
		    flagPrimerOperando=1;
		}
		else
		    puts("\nUsted ya ingreso el primer operando");
		break;
	    case 2:
		if(flagPrimerOperando==1)
		{
		    getNro(&segundoOperando,"\nIngrese 2do numero :","Error",-4000000 ,400000,2);
		    printf("\nSegundo ingresado: %d\n\n",segundoOperando);
		    flagSegundoOperando=1;
		}
		break;
	    case 3:
		if(flagPrimerOperando!=0 && flagSegundoOperando!=0)
		{
		    if(segundoOperando==0)
		    {
			puts("\nLa division no puede operar con 0 intente con otro numero ");
			getNro(&segundoOperando,"\nIngrese nuevo operando distinto de [0] :","Error",-4000000 ,400000,2);
			printf("\nSegundo ingresado: %d\n\n",segundoOperando);
			Suma = suma(primerOperando,segundoOperando);
			Resta= resta(primerOperando,segundoOperando);
			Division = division(primerOperando,segundoOperando);
			Factorial[1]=factorial(primerOperando);
			Factorial[2]=factorial(segundoOperando);
			puts("\n ### Todo listo para mostrar !... ");
			flagCalculando=1;
		    }
		    else
		    {
			Suma = suma(primerOperando,segundoOperando);
			Resta= resta(primerOperando,segundoOperando);
			Division = division(primerOperando,segundoOperando);
			Factorial[1]=factorial(primerOperando);
			Factorial[2]=factorial(segundoOperando);
			puts("\n ### Todo listo para mostrar !... ");
			flagCalculando=1;
		    }
		}
		break;
	    case 4:
		if(flagCalculando!=0)
		{
		    printf("\nLa suma es %d\nEl resto es:%d\n",Suma,Resta);
		    printf("\nLa division es %.2f\nEl factorial del primero :%d\nEl factorial del segundo :%d\n",Division,Factorial[1],Factorial[2]);
		}
		break;
	    case 5:
		puts("\n Hasta luego! ");
		break;
	}
    }while(rta!=5);

	return EXIT_SUCCESS;
}
