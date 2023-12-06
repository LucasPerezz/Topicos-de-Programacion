// Ejercicio 5.7
// Se dispone de dos archivos binarios: <empleados> y <estudiantes>.
// Cada registro del primer archivo contiene los campos:
// - <dni>, <apellido>, <nombre> y <sueldo>
// en tanto que los del segundo:
// - <dni>, <apellido>, <nombre> y <promedio>.
// Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> / <dni>.
// Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays. El sueldo es
// double y el promedio es float.
// Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados que
// tengan un registro de estudiante con un promedio superior a 7, en un 7,28%.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct{
    int dni;
    char apellido[30];
    char nombre[30];
    double sueldo;
}T_empleados;

typedef struct{
    int dni;
    char apellido[30];
    char nombre[30];
    float promedio;
}T_estudiantes;


void lotePrueba();
int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo);
int comparar(const void *elemento1, const void *elemento2); 
int actualizarSueldos(FILE *archEmp, FILE *archEst, size_t tamanoEmp, size_t tamanoEst, int (*comparar)(const void *elemento1, const void *elemento2), void (*actualizar)(FILE *archEmp, size_t tamanoEmp, void *empleado, void *estudiante));
void actualizar(FILE *archEmp, size_t tamanoEmp, void *empleado, void *estudiante);
int mostrarArchivo(FILE *arch, size_t tamanoDato, void (*mostrar)(const void *elemento));
void mostrarEmpleado(const void *elemento);
void mostrarEstudiante(const void *elemento);


int main(){
    // lotePrueba();
    FILE *archEmp, *archEst;
    if(!abrirArchivo(&archEmp, "empleados.txt", "r+b")){
        return 0;
    }
    if(!abrirArchivo(&archEst, "estudiantes.txt", "rb")){
        fclose(archEmp);
        return 0;
    }
    printf("******Archivo Empleados**********\n");
    mostrarArchivo(archEmp, sizeof(T_empleados), mostrarEmpleado);
    printf("\n\n");
    printf("*********Archivo Estudiantes**********\n");
    mostrarArchivo(archEst, sizeof(T_estudiantes), mostrarEstudiante);
    printf("\n\n");
    rewind(archEmp);
    rewind(archEst);
    actualizarSueldos(archEmp, archEst, sizeof(T_empleados), sizeof(T_estudiantes), comparar, actualizar);
    rewind(archEmp);
    printf("*********Archivo Empleados Actualizado**********\n");
    mostrarArchivo(archEmp, sizeof(T_empleados), mostrarEmpleado);
    fclose(archEmp);
    fclose(archEst);
    return 0;
}

void lotePrueba(){
    T_empleados vector_empleados[] = {
        {11111111, "Perez", "Lucas", 10000},
        {22222222, "Sanchez", "Florencia", 10000},
        {22222223, "Sainz", "Carlos", 10000},
        {33333333, "Leclerc", "Charles", 10000},
        {44444444, "Piastri", "Oscar", 10000},
        {55555555, "Verstappen", "Max", 10000},
    };

    T_estudiantes vector_estudiantes[] = {
        {11111111, "Perez", "Lucas", 6.77},
        {22222222, "Sanchez", "Florencia", 7.30},
        {22222225, "Hamilton", "Lewis", 10.00},
        {33333333, "Leclerc", "Charles", 4.5},
        {44444444, "Piastri", "Oscar", 8.00}
    };


    FILE *archEmpleados, *archEstudiantes;
    if(!abrirArchivo(&archEmpleados, "empleados.txt", "wb")){
        return;
    }
    if(!abrirArchivo(&archEstudiantes, "estudiantes.txt", "wb")){
        fclose(archEmpleados);
        return;
    }

    fwrite(vector_empleados, sizeof(vector_empleados), 1, archEmpleados);
    fwrite(vector_estudiantes, sizeof(vector_estudiantes), 1, archEstudiantes);
    fclose(archEmpleados);
    fclose(archEstudiantes);
    return;
}

int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo){
    *arch = fopen(nombreArchivo, modo);
    if(!arch){
        printf("No se pudo abrir el siguiente archivo: %s\n", nombreArchivo);
        return 0;
    }
    printf("El siguiente archivo se ha abierto correctamente: %s\n", nombreArchivo);
    return 1;
}

int comparar(const void *elemento1, const void *elemento2){
    T_estudiantes *estudiante = (T_estudiantes*) elemento1;
    T_empleados *empleado = (T_empleados*) elemento2;
    if(strcmpi(empleado->apellido, estudiante->apellido) == 0){
        if(strcmpi(empleado->nombre, estudiante->nombre) == 0){
            return empleado->dni - estudiante->dni;
        } else {
            return strcmpi(empleado->nombre, estudiante->nombre);
        }
    } else{
        return strcmpi(empleado->apellido, estudiante->apellido);
    }
}


int actualizarSueldos(FILE *archEmp, FILE *archEst, size_t tamanoEmp, size_t tamanoEst, int (*comparar)(const void *elemento1, const void *elemento2), void (*actualizar)(FILE *archEmp, size_t tamanoEmp, void *empleado, void *estudiante)){
    void *empleado = malloc(tamanoEmp);
    if(!empleado){
        printf("No se pudo reservar memoria\n");
        return 0;
    }
    void *estudiante = malloc(tamanoEst);
    if(!estudiante){
        printf("No se pudo reservar memoria\n");
        free(empleado);
    }
    fread(empleado, tamanoEmp, 1, archEmp);
    fread(estudiante, tamanoEst, 1, archEst);
    while(!feof(archEmp) && !feof(archEst)){
        if(comparar(empleado, estudiante) == 0){
            actualizar(archEmp, tamanoEmp, empleado, estudiante);
            fread(empleado, tamanoEmp, 1, archEmp);
            fread(estudiante, tamanoEst, 1, archEst);
        } else if (comparar(empleado, estudiante) > 0){
            fread(estudiante, tamanoEst, 1, archEst);
        } else{
            fread(empleado, tamanoEmp, 1, archEmp);
        }
    }
    while(!feof(archEmp)){
        fread(empleado, tamanoEmp, 1, archEmp);
    }
    while(!feof(archEst)){
        fread(estudiante, tamanoEst, 1, archEst);
    }
    free(empleado);
    free(estudiante);
    return 1;
}

void actualizar(FILE *archEmp, size_t tamanoEmp, void *empleado, void *estudiante){
    T_empleados *emp = (T_empleados*) empleado;
    T_estudiantes *est = (T_estudiantes*) estudiante;
    if(est->promedio >= 7.00){
        fseek(archEmp, -(long)tamanoEmp, SEEK_CUR);
        emp->sueldo*=1.028;
        fwrite(emp, tamanoEmp, 1, archEmp);
        fseek(archEmp, 0L, SEEK_CUR);
    }
    return;
}

int mostrarArchivo(FILE *arch, size_t tamanoDato, void (*mostrar)(const void *elemento)){
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

void mostrarEmpleado(const void *elemento){
    T_empleados *emp = (T_empleados*) elemento;
    printf("%30s\t%30s\t%8d\t%9lf\n", emp->nombre, emp->apellido, emp->dni, emp->sueldo);
    return; 
}

void mostrarEstudiante(const void *elemento){
    T_estudiantes *est = (T_estudiantes*) elemento;
    printf("%30s\t%30s\t%8d\t%9f\n", est->nombre, est->apellido, est->dni, est->promedio);
    return; 
}


