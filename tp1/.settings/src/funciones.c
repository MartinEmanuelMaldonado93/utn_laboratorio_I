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
    resultado= (float) a / (float)b;

    return resultado;
}
float factorial(int a)
{
    float fact;

    if (a< 0)
	printf("Error! Factorial de un negativo no existe.");
    else
    {
	for (int i = 1; i <= a; ++i)
	{
	    fact = fact* i;
	}
    }
    return fact;
}
