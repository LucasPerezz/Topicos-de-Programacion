#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void trozado(tEmpleado *emp, char *s);


int main(){
    // lotePrueba();
    char cadena[100];
    tEmpleado emp;
    FILE *arch;
    if(!abrirArchivo(&arch, "lote1.txt", "rt")){
        return 0;
    }
    while(fgets(cadena, sizeof(cadena), arch)){
        trozado(&emp, cadena);
        printf("%ld;%s;%c;%d;%d;%d;%f\n", emp.dni, emp.apyn, emp.categoria, emp.fecIngreso.dia, emp.fecIngreso.mes, emp.fecIngreso.anio, emp.sueldo);
    }

    fclose(arch);
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

void trozado(tEmpleado *emp, char *s){
    char *aux;
    aux = strrchr(s, '\n');
    *aux = '\0';

    aux = strrchr(s, ';');
    sscanf(aux + 1, "%f", &emp->sueldo);
    *aux = '\0';

    aux = strrchr(s, ';');
    sscanf(aux + 1, "%d", &emp->fecIngreso.anio);
    *aux = '\0';

    aux = strrchr(s, ';');
    sscanf(aux + 1, "%d", &emp->fecIngreso.mes);
    *aux = '\0';

    aux = strrchr(s, ';');
    sscanf(aux + 1, "%d", &emp->fecIngreso.dia);
    *aux = '\0';

    aux = strrchr(s, ';');
    sscanf(aux + 1, "%c", &emp->categoria);
    *aux = '\0';

    aux = strrchr(s, ';');
    strcpy(emp->apyn, aux + 1);
    *aux = '\0';

    sscanf(s, "%ld", &emp->dni);
    return;
}