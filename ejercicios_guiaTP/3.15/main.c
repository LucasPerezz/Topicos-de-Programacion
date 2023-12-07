// Ejercicio 3.15
// Desarrolle una función de intercambio genérica tal que pueda intercambiar 2 bloques de información
// de manera independiente al tipo de dato.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int intercambiar(void *bloque1, void *bloque2, size_t tamanoDato);

int main(){
    int vec[] = {1,2,3};
    intercambiar(vec, vec+1, sizeof(int));
    for (size_t i = 0; i < 3; i++)
    {
        printf("%d\t", vec[i]);
    }
    
    return 0;
}

int intercambiar(void *bloque1, void *bloque2, size_t tamanoDato){
    void *aux = malloc(tamanoDato);
    if(!aux){
        printf("No se pudo asignar memoria\n");
        return 0;
    }
    memcpy(aux, bloque1, tamanoDato);

    memcpy(bloque1, bloque2, tamanoDato);

    memcpy(bloque2, aux, tamanoDato);

    return 1;
}