#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi 3.141592

typedef struct
{
    float latitud;
    float longitud;
    char patente[9];
    float distancia;
} T_embarcaciones;

float aRadianes(float grados)
{
    return grados/180 * pi;
}

float calcularDistanciaEnMetros(float lat1, float long1, float lat2, float long2)
{
    //NOTA: distancia aproximada en metros para puntos poco distantes y alejado de los polos.
    //es una aproximacion, no usar en proyectos reales donde se requiera precision.
    double dist;
    dist = sin(aRadianes(lat1)) * sin(aRadianes(lat2)) + cos(aRadianes(lat1)) * cos(aRadianes(lat2)) * cos(aRadianes(long1 - long2));
    dist = acos(dist);
    dist = 6371*1000 * dist;
    return dist;
}

int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo);

int main(){
    T_embarcaciones embarcaciones[20];
    FILE *archEmbarcaciones;
    if(!abrirArchivo(&archEmbarcaciones, "embarcaciones.csv", "rt")){
        return 0;
    }
    fclose(archEmbarcaciones);
    return 0;
}

int abrirArchivo(FILE **arch, char *nombreArchivo, char *modo){
    *arch = fopen(nombreArchivo, modo);
    if(!arch){
        printf("No se pudo abrir el archivo\n");
        return 0;
    }
    printf("Se abrio con exito el archivo: %s\n", nombreArchivo);
    return 1;
}

