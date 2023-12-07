// Escriba una función que devuelva en qué dirección de memoria se encuentra un elemento dentro de
// un array. Si el elemento no se encuentra, debe devolver NULL.

#include <stdio.h>
#include <stdlib.h>

int *busquedaSecuencial(int *vec, int bus, int ce);

int main(){
    int vec[] = {1,2,3,4,5,6,7,8,9};
    int *ptr = busquedaSecuencial(vec, 10, sizeof(vec) / sizeof(int));
    if(ptr == NULL){
        printf("No se pudo encontrar el elemento buscado\n");
    } else{
        printf("El elemento buscado se encuentra en la posicion: %p\n", ptr);
    }
    return 0;
}

int *busquedaSecuencial(int *vec, int bus, int ce){
    int i = 0;
    int *pos;
    pos = NULL;
    while(i < ce && pos == NULL){
        if(*vec == bus){
            pos = vec;
        }
        vec++;
        i++;
    }
    return pos;
}
