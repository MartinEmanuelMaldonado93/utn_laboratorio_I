
#ifndef BIBLIOTECA2021_H_
#define BIBLIOTECA2021_H_
int getChar(char* cadena,int longitud,char* mensaje,char* msjerror,int intentos);
int getNro(int* resp,char* mensaje,char* msjError,int minimo,int maximo,int intentos);
int ordenarArrayNrico(int Array[],int i,int L,int condicion);
int ingresoTexto(char* texto[60],char* mensaje,int L);
int mostrarTexto(char texto[][60],char* mensaje,int L);

void formatoName(char* nombreoapellido);
int esNombre(char* cadena,int limite);
int getint(int* resp);
int getfloat(float* resp,char* mensaje,char* msjError,float min,float max,int intentos);
int esfloat(char* cadena);
int getf(float* resultadof);
int esnumerica(char* cadena,int limite);
int migets(char* cadena,int longitud);
//funciones en fase beta de otros proyectos :
int getBinary(int* string,int longitud,char* mensaje,char* msjError,int intentos);
int isbinary(char* cadena,int longitud);
void redondeo(char* cadenaflotante,int longitud);
#include "Biblioteca2021.h"
#endif /* BIBLIOTECA2021_H_ */
