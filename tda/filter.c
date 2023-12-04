#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ce;
    unsigned tamElemento;
    void *ptr;
} Vector;

void crearVector(Vector *vec);
int asignarVector(Vector *vec, int ce, unsigned tamElemento);
int inicializarVector(Vector *vec, void *valor);
int insertarEnPosicion(Vector *vec, int pos, void *valor);
void eliminarVector(Vector *vec);
void filter(Vector *vec, int (*filtro)(void *dato));
int filtro(void *dato);

int main(){
    Vector vec1;
    int valorParaInicializar = 0, par = 2, impar = 1;
    crearVector(&vec1);
    asignarVector(&vec1, 4, sizeof(int));
    inicializarVector(&vec1, &valorParaInicializar);
    for(int i = 0; i < vec1.ce; i++){
        if(i % 2 == 0){
            insertarEnPosicion(&vec1, i, &par);
        } else{
            insertarEnPosicion(&vec1, i, &impar);
        }
    }

    for(int i = 0; i < vec1.ce; i++){
        printf("%d\t", *(int*)(vec1.ptr + vec1.tamElemento * i));
    }
    printf("\n");
    filter(&vec1, filtro);
    for(int i = 0; i < vec1.ce; i++){
        printf("%d\t", *(int*)(vec1.ptr + vec1.tamElemento * i));
    }
    eliminarVector(&vec1);
    return 0;
}

void crearVector(Vector *vec){
    vec->ce = 0;
    vec->tamElemento = 0;
    vec->ptr = NULL;
    return;
}

int asignarVector(Vector *vec, int ce, unsigned tamElemento){
    vec->ptr = malloc(ce * tamElemento);
    if(!vec->ptr){
        printf("No se pudo reservar memoria\n");
        return 0;
    }
    vec->ce = ce;
    vec->tamElemento = tamElemento;
    return 1;
}

int inicializarVector(Vector *vec, void *valor){
    if(!vec->ptr){
        printf("No hay memoria asignada\n");
        return 0;
    }
    for(int i = 0; i < vec->ce; i++){
        memcpy(vec->ptr + vec->tamElemento * i, valor, vec->tamElemento);
    }
    return 1;
}

int insertarEnPosicion(Vector *vec, int pos, void *valor){
    if(!vec->ptr){
        printf("No hay memoria asignada\n");
        return 0;
    }
    memcpy(vec->ptr + vec->tamElemento * pos, valor, vec->tamElemento);
    return 1;
}

void eliminarVector(Vector *vec){
    free(vec->ptr);
    vec->ptr = NULL;
    vec->ce = 0;
    vec->tamElemento = 0;
    return;
}


void filter(Vector *vec, int (*filtro)(void *dato)){
    Vector vecNuevo;
    crearVector(&vecNuevo);
    asignarVector(&vecNuevo, vec->ce, vec->tamElemento);
    int j = 0;

    for(int i = 0; i < vec->ce; i++){
        if(filtro(vec->ptr + vec->tamElemento * i)){
            insertarEnPosicion(&vecNuevo, j, vec->ptr + vec->tamElemento * i);
            j++;
        }
    }

    free(vec->ptr);
    vec->ptr = vecNuevo.ptr;
    vec->ce = j;
    return;
}

int filtro(void *dato){
    int *numero = (int*) dato;
    if((*numero % 2) == 0){
        return 1;
    } else{
        return 0;
    }
}