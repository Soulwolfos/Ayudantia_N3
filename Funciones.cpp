#include <iostream> //cout
#include <cmath>    //pow, sqrt
#include <cstdlib>  //rand, srand
#include <ctime> //time

#include "Funciones.h"

using namespace std;

/*
 * \brief ingresa un numero random a cada numero entero del arreglo
 * \param arreglo de enteros creado en el main.cpp
 */
void NumerosRandom(int enteros[100000]){
    srand(time(NULL));
    
    for (int i=0 ; i<100000 ; i++){
        enteros[i] = rand() % 10000;
    }
    
}



/*
 * \brief calcula el promedio del arreglo de numeros 
 * \param arreglo de enteros creado en el main.cpp
 * \return Devuelve valor del promedio
 */

float Promedio(int enteros[100000],int desde, int hasta){
    float suma = 0;
    float prome = 0;
    int count = 0;
    for (int i = desde; i <= hasta; i++){
        suma = float(enteros[i] + suma);
        count = count + 1;
    }
    
    prome = float(suma/count);
    
    return  prome;
}



/*
 * \brief Calcula la varianza 
 * \param arreglo de enteros creado en el main.cpp
 * \return Devuelve valor de la varianza
 */
float Varianza(int enteros[100000], float media){
    float aux=0, total=0, vari=0;
    
    for (int i=0; i<100000; i++){
        aux = media - enteros[i];        
        total = total + pow(aux,2);
        aux=0;
    }
    
    vari = total/99999;
    return vari;

}



/*
 * \brief Calcula la Desviacion Estandar 
 * \param float que contiene el valor de la varianza "varian" 
 * \return Devuelve valor de la Desviacion Estandar
 */
float DesvEstandar(float varian){
    
    return sqrt(varian);
    
}


