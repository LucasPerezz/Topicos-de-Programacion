#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct 
{
    char producto[20];
    float precio;
    int stock;
}t_producto;

void lotePrueba();
int mostrarArchivo(FILE *arch, size_t tamanoDato, void (*mostrar)(void *elemento));
void mostrar(void *elemento);
int unirArchivos(FILE *arch1, FILE *arch2, FILE *archUnion, size_t tamanoDato, void (*sumarStock)(FILE *archUnion, void *elemento1, void *elemento2, size_t tamanoDato), int (*comparar)(const void *elemento1, const void *elemento2));
int comparar(const void *elemento1, const void *elemento2);
void sumarStock(FILE *arch, void *elemento1, void *elemento2, size_t tamanoDato);

int main(){
    // lotePrueba();
    FILE *arch1, *arch2, *archUnion;
    arch1 = fopen("arch.txt", "rb");
    if(!arch1){
        printf("No se pudo abrir el archivo 1\n");
        return 0;
    }
    arch2 = fopen("arch1.txt", "rb");
    if(!arch2){
        printf("No se pudo abrir el archivo 2\n");
        fclose(arch1);
        return 0;
    }
    archUnion = fopen("archUnion.txt", "w+b");
    if(!archUnion){
        printf("No se pudo abrir el archivo de union\n");
        fclose(arch1);
        fclose(arch2);
        return 0;
    }
    printf("*******Archivo 1**********\n");
    mostrarArchivo(arch1, sizeof(t_producto), mostrar);
    printf("\n\n");
    printf("*******Archivo 2**********\n");
    mostrarArchivo(arch2, sizeof(t_producto), mostrar);
    printf("\n\n");
    rewind(arch1);
    rewind(arch2);
    unirArchivos(arch1, arch2, archUnion, sizeof(t_producto), sumarStock, comparar);
    rewind(archUnion);
    printf("*********Archivo Unido**********\n");
    mostrarArchivo(archUnion, sizeof(t_producto), mostrar);
    printf("\n\n");
    fclose(arch1);
    fclose(arch2);
    fclose(archUnion);
    return 0;
}

void lotePrueba(){
    t_producto productos1[] = {
        {"Azucar", 100.00, 10},
        {"Gaseosa", 200.00, 10},
        {"Leche", 150.00, 10},
        {"Manteca", 80.00, 10}
    };
    t_producto productos2[] = {
        {"Fideos", 140.00, 10},
        {"Gaseosa", 200.00, 5},
        {"Queso", 350.00, 20}
    };
    FILE *arch1, *arch2;
    arch1 = fopen("arch1.txt", "wb");
    if(!arch1){
        printf("No se pudo abrir el archivo 1\n");
        return;
    }
    arch2 = fopen("arch.txt", "wb");
    if(!arch2){
        printf("No se pudo abrir el archivo 2\n");
        fclose(arch1);
        return;
    }
    fwrite(productos1, sizeof(productos1), 1, arch1);
    fwrite(productos2, sizeof(productos2), 1, arch2);
    fclose(arch1);
    fclose(arch2);
    return;
}


int unirArchivos(FILE *arch1, FILE *arch2, FILE *archUnion, size_t tamanoDato, void (*sumarStock)(FILE *archUnion, void *elemento1, void *elemento2, size_t tamanoDato), int (*comparar)(const void *elemento1, const void *elemento2)){
    void *elemento1 = malloc(tamanoDato);
    if(!elemento1){
        printf("No se pudo reservar memoria\n");
        return 0;
    }
    void *elemento2 = malloc(tamanoDato);
    if(!elemento2){
        printf("No se pudo reservar memoria\n");
        free(elemento1);
        return 0;
    }
    fread(elemento1, tamanoDato, 1, arch1);
    fread(elemento2, tamanoDato, 1, arch2);
    while(!feof(arch1) && !feof(arch2)){
        if(comparar(elemento1, elemento2) == 0){
            sumarStock(archUnion, elemento1, elemento2, tamanoDato);
            fread(elemento1, tamanoDato, 1, arch1);
            fread(elemento2, tamanoDato, 1, arch2);
        } else if(comparar(elemento1, elemento2) > 0){
            fread(elemento2, tamanoDato, 1, arch2);
        } else{
            fread(elemento1, tamanoDato, 1, arch1);
        }
    }

    while(!feof(arch1)){
        fread(elemento1, tamanoDato, 1, arch1);
    }

    while(!feof(arch2)){
        fread(elemento2, tamanoDato, 1, arch2);
    }

    free(elemento1);
    free(elemento2);
    return 1;
}

int comparar(const void *elemento1, const void *elemento2){
    t_producto *prod1 = (t_producto*)elemento1;
    t_producto *prod2 = (t_producto*)elemento2;
    return strcmpi(prod1->producto, prod2->producto);
}

void sumarStock(FILE *arch, void *elemento1, void *elemento2, size_t tamanoDato){
    t_producto *prod1 = (t_producto*)elemento1;
    t_producto *prod2 = (t_producto*)elemento2;
    prod1->stock = prod1->stock + prod2->stock;
    fwrite(prod1, tamanoDato, 1, arch);
    fseek(arch, 0, SEEK_END);
    return;
}

int mostrarArchivo(FILE *arch, size_t tamanoDato, void (*mostrar)(void *elemento)){
    void *elemento = malloc(tamanoDato);
    if(!elemento){
        printf("No se pudo reservar memoria\n");
        return 0;
    }
    fread(elemento, tamanoDato, 1, arch);
    while(!feof(arch)){
        mostrar(elemento);
        fread(elemento, tamanoDato, 1, arch);
    }
    free(elemento);
    return 1;
}

void mostrar(void *elemento){
    t_producto *prod = (t_producto*) elemento;
    printf("Producto: %20s\tPrecio: %8f\tStock: %8d\n", prod->producto, prod->precio, prod->stock);
}