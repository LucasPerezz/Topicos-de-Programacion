// Ejercicio 3.10
// Dado un arreglo de elementos de tipo tPersona, utilice la función qsort (biblioteca <stdlib>) para
// ordenarlos por DNI.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dni;
    char apellido[20];
    char nombre[30];
    float peso;
}tPersona;

int comparar(const void *elemento1, const void *elemento2);

int main(){
    tPersona personas[5] = {
        {56789012, "Perez", "Pedro", 68.9},
        {23456789, "Lopez", "Maria", 65.2},
        {12345678, "Gomez", "Juan", 70.5},
        {34567890, "Martinez", "Carlos", 80.3},
        {45678901, "Rodriguez", "Laura", 55.8},
    };
    for(int i = 0; i < 5; i++){
        printf("%8d\t%20s\t%30s\t%4f\n", personas[i].dni, personas[i].apellido, personas[i].nombre, personas[i].peso);
    }
    qsort(personas, sizeof(personas) / sizeof(personas[0]), sizeof(personas[0]), comparar);
    printf("\n\n\n");
    for(int i = 0; i < 5; i++){
        printf("%8d\t%20s\t%30s\t%4f\n", personas[i].dni, personas[i].apellido, personas[i].nombre, personas[i].peso);
    }
    return 0;
}

int comparar(const void *elemento1, const void *elemento2){
    tPersona *per1 = (tPersona*) elemento1;
    tPersona *per2 = (tPersona*) elemento2;
    return per1->dni - per2->dni;
}