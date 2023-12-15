#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int *vec, int bus, int *inicio, int *fin);

int main() {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    int buscar = 5;

    int resultado = busquedaBinaria(arreglo, buscar, arreglo, arreglo + tamano - 1);

    if (resultado != -1) {
        printf("El elemento %d se encuentra en la posicion %d.\n", buscar, resultado);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", buscar);
    }

    return 0;
}



int busquedaBinaria(int *vec, int bus, int *inicio, int *fin)
{
    if(inicio > fin)
    {
        return -1;
    }

    int *mitad = inicio + (fin - inicio) / 2;

    if(bus == *mitad)
    {
        return mitad - vec;
    }

    if(bus > *mitad)
    {
        return busquedaBinaria(vec, bus, mitad + 1, fin);
    }
    else
    {
        return busquedaBinaria(vec, bus, inicio, mitad - 1);
    }
}