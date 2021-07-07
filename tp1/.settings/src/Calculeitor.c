/*
 ============================================================================
 Name        : Calculeitor.c
 Author      : Martin Maldonado Div-E
 Version     :2.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2020.h"
#include "funciones.h"
int main(void) {
    setbuf(stdout,NULL);

    int rta;
    int flagPrimerOperando=0,flagSegundoOperando=0,flagCalculando=0;
    int primerOperando=0,segundoOperando=0;
    int Suma,Resta;
    float Division,Factorial[2];

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
		    printf("\nPrimer Operando ingresado: %d\n",primerOperando);
		    flagPrimerOperando=1;
		}
		else
		    puts("\nUsted ya ingreso un numero");
		break;
	    case 2:
		if(flagSegundoOperando==0)
		{
		    getNro(&segundoOperando,"\nIngrese 2do numero :","Error",-4000000 ,400000,2);
		    printf("\nSegundo ingresado: %d\n",segundoOperando);
		    flagSegundoOperando=1;
		}
		break;
	    case 3:
		if(flagPrimerOperando!=0 && flagSegundoOperando!=0)
		{
		    puts("\nCalculando ... ");
		    flagCalculando=1;
		    Suma= suma(primerOperando,segundoOperando);
		    Resta= resta(primerOperando,segundoOperando);

		    Factorial[1]=factorial(primerOperando);
		    Factorial[2]=factorial(segundoOperando);

		    if(segundoOperando==0)
			puts("\nLa division no puede operar con 0 intente con otro numero la proxima");

		    Division= division(primerOperando,segundoOperando);


		}
		break;
	    case 4:
		if(flagCalculando!=0)
		{
		    printf("\nLa suma es %d\nEl resto es:%d\n",Suma,Resta);
		    printf("\nLa division es %.2f\nEl factorial del primero :%f\nEl factorial del segundo :%f\n",Division,Factorial[1],Factorial[2]);
		}
		break;
	    case 5:
		puts("\n Hasta luego!- See you later!");
		break;

	}
    }while(rta!=5);



	return EXIT_SUCCESS;
}
