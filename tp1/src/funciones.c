#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b)
{
    return a+b;
}
int resta (int a, int b)
{
    return a-b;
}
float division(int a, int b)
{
    float resultado;
    resultado =  a /  b;
    return resultado;
}
int factorial(int numero)
{
    float fact = 1;
    int i = 1;

    if (numero < 0)
    {
	printf("Error! Factorial de un negativo no existe.");
    }
    else
    {
	while(i <= numero)
	{
	    fact = fact * i;
	    i=i+1;
	}
    }
    return fact;
}
