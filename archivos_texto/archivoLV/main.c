#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo; 
}tEmpleado;

void lotePrueba();
int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo);


int main(){
    lotePrueba();

    return 0;
}

void lotePrueba(){
    FILE *arch;
    if(!abrirArchivo(&arch, "lote1.txt", "wt")){
        return;
    }
    tEmpleado vectorEmpleados[] = {
        {44444444, "Persona Cuatro", 'A', {1, 2, 2004}, 44000.4F},
        {22222222, "Persona Dos", 'B', {1, 2, 2002}, 22000.2F},
        {33333333, "Persona Tres", 'B', {1, 3, 2003}, 33000.3F},
        {55555555, "Persona Cinco", 'A', {1, 5, 2005}, 55000.5F},
        {11111111, "Persona Uno", 'C', {1, 1, 2001}, 11000.1F}
    };

    for(int i = 0; i < 5; i++){
        fprintf(arch, "%ld;%s;%c;%d;%d;%d;%f\n", vectorEmpleados[i].dni, vectorEmpleados[i].apyn, vectorEmpleados[i].categoria, vectorEmpleados[i].fecIngreso.dia, vectorEmpleados[i].fecIngreso.mes, vectorEmpleados[i].fecIngreso.anio, vectorEmpleados[i].sueldo);
    }
    fclose(arch);
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