// suma o resta de vectores
// Dados dos archivos de texto “arch1.txt” y “arch2.txt”. Cada archivo contiene los datos de un vector.
// ● El primer registro de cada archivo contiene la cantidad de elementos del vector:
// (dim1) //Los caracteres marcados en rojo, aparecen en forma literal en el archivo.
// ● el segundo registro que indica la operación: “+” o “-”, seguido del tamaño del dato (el mismo
// puede ser entero, flotante o doble)
// ● Luego aparecen desordenados, los valores NO nulos del vector. Cada registro del archivo
// contiene:
// “pos|valor” //Los caracteres marcados en rojo, aparecen en forma literal en el archivo.
// ● Tenga en cuenta que para poder realizar la suma o resta ambos vectores deben tener la
// misma dimensión. En caso que las dimensiones sean diferentes completar con el valor
// neutro de la suma / resta.

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int ce;
    unsigned tamElemento;
    void *ptr;
}Vector;

void crearVector(Vector *vec);
int asignarVector(Vector *vec, int ce, unsigned tamElemento);
int inicializarVector(Vector *vec, void *valor);
int insertarEnPosicion(Vector *vec, int pos, void *valor);
void eliminarVector(Vector *vec);
void lotePrueba();
int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo);
void operarVectores(Vector *vec1, Vector *vec2, FILE *archResultado, char op,  unsigned (*suma)(const void *numero1, const void *numero2), unsigned (*resta)(const void *numero1, const void *numero2));
unsigned suma(const void *numero1, const void *numero2);
unsigned resta(const void *numero1, const void *numero2);
void cargarDatosEnMemoria(Vector *vec, FILE *arch);

int main(){
    // lotePrueba();
    Vector vec1, vec2;
    int ce1, ce2, ce, valorInicial=0;
    char op1, op2;
    unsigned tam1, tam2;
    FILE *arch1, *arch2, *archResultado;
    if(!abrirArchivo(&arch1, "arch1.txt", "rt")){
        return 0;
    }
    if(!abrirArchivo(&arch2, "arch2.txt", "rt")){
        fclose(arch1);
        return 0;
    }
    crearVector(&vec1);
    crearVector(&vec2);
    fscanf(arch1, "(%d)\n", &ce1);
    fscanf(arch2, "(%d)\n", &ce2);
    if(ce1 > ce2){
        ce = ce1;
    } else{
        ce = ce2;
    }
    fscanf(arch1, "%c%d\n", &op1, &tam1);
    fscanf(arch2, "%c%d\n", &op2, &tam2);
    if(op1 != op2 || tam1 != tam2){
        printf("Error en los datos\n");
        fclose(arch1);
        fclose(arch2);
        return 0;
    }
    asignarVector(&vec1, ce, tam1);
    asignarVector(&vec2, ce, tam2);
    inicializarVector(&vec1, &valorInicial);
    inicializarVector(&vec2, &valorInicial);
    cargarDatosEnMemoria(&vec1, arch1);
    cargarDatosEnMemoria(&vec2, arch2);
    if(!abrirArchivo(&archResultado, "resultados.txt", "wt")){
        fclose(arch1);
        fclose(arch2);
        return 0;
    }
    operarVectores(&vec1, &vec2, archResultado, op1, suma, resta);
    fclose(arch1);
    fclose(arch2);
    fclose(archResultado);
    return 0;
}

void operarVectores(Vector *vec1, Vector *vec2, FILE *archResultado, char op,  unsigned (*suma)(const void *numero1, const void *numero2), unsigned (*resta)(const void *numero1, const void *numero2)){
    if(op == '+'){
        for(int i = 0; i < vec1->ce; i++){
            fprintf(archResultado, "%u %c %u = %u\n", *(unsigned*)(vec1->ptr + vec1->tamElemento * i), op, *(unsigned*)(vec2->ptr + vec2->tamElemento * i), suma(vec1->ptr + vec1->tamElemento * i, vec2->ptr + vec2->tamElemento * i));
        }
    }
    if(op == '-'){
        for(int i = 0; i < vec1->ce; i++){
            fprintf(archResultado, "%u %c %u = %u\n", *(int*)(vec1->ptr + vec1->tamElemento * i), op, *(unsigned*)(vec2->ptr + vec2->tamElemento * i), resta(vec1->ptr + vec1->tamElemento * i, vec2->ptr + vec2->tamElemento * i));
        }
    }
}

unsigned suma(const void *numero1, const void *numero2){
    int *num1 = (int*) numero1;
    int *num2 = (int*) numero2;
    return *num1 + *num2;
}

unsigned resta(const void *numero1, const void *numero2){
    int *num1 = (int*) numero1;
    int *num2 = (int*) numero2;
    return *num1 - *num2;
}

void cargarDatosEnMemoria(Vector *vec, FILE *arch){
    int pos;
    unsigned valor;
    fscanf(arch, "%d|%u\n", &pos, &valor);
    insertarEnPosicion(vec, pos, &valor);
    while(!feof(arch)){
        fscanf(arch, "%d|%u\n", &pos, &valor);
        insertarEnPosicion(vec, pos, &valor);
    }
    return;
}

void lotePrueba(){
    FILE *arch1, *arch2;
    if(!abrirArchivo(&arch1, "arch1.txt", "wt")){
        return ;
    }
    if(!abrirArchivo(&arch2, "arch2.txt", "wt")){
        fclose(arch1);
        return ;
    }
    fprintf(arch1, "(3)\n");
    fprintf(arch1, "+4\n");
    fprintf(arch1, "1|1\n2|1\n3|10\n");

    fprintf(arch2, "(4)\n");
    fprintf(arch2, "+4\n");
    fprintf(arch2, "2|10\n0|3\n");
    fclose(arch1);
    fclose(arch2);
    return;
}

int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo){
    *arch = fopen(nombreArchivo, modo);
    if(!arch){
        printf("No se pudo abrir el siguiente archivo: %s\n", nombreArchivo);
        return 0;
    }
    printf("Se abrio correctamente el siguiente archivo: %s\n", nombreArchivo);
    return 1;
}

void crearVector(Vector *vec){
    vec->ce = 0;
    vec->tamElemento = 0;
    vec->ptr = NULL;
    return;
}

int asignarVector(Vector *vec, int ce, unsigned tamElemento){
    vec->ptr = malloc(tamElemento * ce);
    if(!vec->ptr){
        printf("No se pudo asignar memoria\n");
        return 0;
    }
    vec->ce = ce;
    vec->tamElemento = tamElemento;
    return 1;
}

int inicializarVector(Vector *vec, void *valor){
    if(!vec->ptr){
        printf("No habia memoria asignada\n");
        return 0;
    }
    for(int i = 0; i < vec->ce; i++){
        memcpy(vec->ptr + vec->tamElemento * i, valor, vec->tamElemento);
    }
    return 1;
}

int insertarEnPosicion(Vector *vec, int pos, void *valor){
    if(!vec->ptr){
        printf("No habia memoria asignada\n");
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