#include <stdio.h>

int busquedaBinaria(int vec[], int bus, int inicio, int fin);

int main(){
    int vec[] = {1,2,3,4,5,6,7,8,9};
    int elementoBuscado = 4;
    int bus = busquedaBinaria(vec, elementoBuscado, 0, sizeof(vec) / sizeof(int));
    if(bus == -1){
        printf("No se ha encontrado el elemento\n");
    } else{
        printf("Se encontro el elemento en la posicion %d\n", bus);
    }
    return 0;
}

int busquedaBinaria(int vec[], int bus, int inicio, int fin){
    int mitad = (inicio + fin) / 2;

    if(bus == vec[mitad]){
        return mitad;
    }

    if(inicio > fin){
        return - 1;
    }

    if(vec[mitad] > bus){
        return busquedaBinaria(vec, bus, inicio, mitad - 1);
    } else{
        return busquedaBinaria(vec, bus, mitad + 1, fin);
    }
}