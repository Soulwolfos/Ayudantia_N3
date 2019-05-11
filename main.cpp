//Rodrigo Lobos Leal 
//Ayudantia Computacion Paralela y Distribuida

#include <iostream> //cout

/* cabecera de las llamadas a MPI */
#include <mpi.h> 

#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    
    //arreglo de enteros.
    int enteros[100000];
    //Funcion que ingresa numeros random al arreglo
    NumerosRandom(enteros);
    
    int mi_rango; // rango del proceso
    int p;      // numero de procesos  
    int fuente; // rango del que envia 
    int dest;   // rango del que recibe 
    int tag = 0; // etiqueta del mensaje 
    
    // Comienza las llamadas a MPI 
    MPI_Init(&argc, &argv);

    // Averiguamos el rango de nuestro proceso MPI_Finalize();
    MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);

    //Averiguamos el número de procesos que estan 
    //ejecutando nuestro porgrama 
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    
    
    int partido = 100000 / p; //es dividido los procesos -1 por que el 0 es el que saca el promedio final
    //entonces 

    int ultimo = 0;
       
    int particion[p][2];//guarda el numero en los que se divide el arreglo de enteros
    int cuenta = 0;
    
    for(int q = 0; q < p;q++){
        if(q == (p-1) ){
            
            ultimo = 100000 - cuenta;
            
            particion[q][0] = cuenta + 1;
            particion[q][1] = cuenta + ultimo;
          
        }
        else{
            if(q!=0){
                particion[q][0] = cuenta + 1;
                particion[q][1] = cuenta + partido;
            
            }else{
                particion[q][0] = 0;
                particion[q][1] = partido;
               
            }
           
        }
        
        cuenta = cuenta + partido;
        
        // cout << " q " << q <<" desde: " << particion[q][0] <<" - Hasta: "<< particion[q][1] << " cuenta: "<< cuenta<<endl;       
    }
    
    // cout << " p = " << p << " aux_p = "<<aux_p<< " mi_rango = " << mi_rango << endl;
    
    
    /*
    for(int y =0 ; y< aux_p;y++){
        cout<<"q = " << y <<" desde: " << particion[y][0] <<" - Hasta: "<< particion[y][1]<<endl;
    }
    */
   
     
    float auxPromedios = 0; 
    
    int desde = particion[mi_rango][0];
    int hasta = particion[mi_rango][1];     
        
    
    //cout <<"En el rango: " << mi_rango << " Desde = " << desde << " Hasta = "<< hasta <<endl;

                
    auxPromedios = Promedio(enteros,desde,hasta);
        
        
    //cout<< "en el rango: " <<mi_rango <<" calculo el promedio de: "<<auxPromedios << endl;
             
    float sumaPromedios;   
    MPI_Reduce(&auxPromedios,&sumaPromedios, 1 , MPI_FLOAT,MPI_SUM, 0, MPI_COMM_WORLD);
          
    if(mi_rango == 0){
        
        float promed = sumaPromedios/p;
        cout.precision(8);
        cout<<"Promedio: "<< promed <<endl;
        float varian = Varianza(enteros,promed);
        cout.precision(10);
        cout <<"Varianza: "<< varian <<endl;
        float estandar = DesvEstandar(varian);
        cout <<"Desviacion Estandar: "<< estandar <<endl;
        
    }
    
    MPI_Finalize();
   
    
    return 0;
}
