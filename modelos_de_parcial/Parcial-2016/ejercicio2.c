#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int strlen(char *cad);
char *reemplazarSubcadena(char *cadena, char *subcadenaAReemplazar, char *subcadenaNueva);

int main(){
    char prueba1[] = "hola mundo";
    printf("%s\n", reemplazarSubcadena(prueba1, "hola", "bola"));
    return 0;
}

char *reemplazarSubcadena(char *cadena, char *subcadenaAReemplazar, char *subcadenaNueva){
    if(strlen(subcadenaAReemplazar) == strlen(subcadenaNueva)){

    char *inicio, *auxInicio, *auxSubcadenaNueva, *auxSubcadenaAReemplazar;
    inicio = cadena;

    while(*inicio != '\0'){
        //Inicializo y defino variables auxiliares
        auxInicio = inicio;
        auxSubcadenaAReemplazar = subcadenaAReemplazar;
        int caracteres = 0;

        //Verifico que sean iguales
        while(*inicio == *auxSubcadenaAReemplazar && *inicio != '\0'){
            caracteres++;
            inicio++;
            auxSubcadenaAReemplazar++;
        }
        //Si son caracteres iguales reemplazo
        if(caracteres == strlen(subcadenaAReemplazar)){
            inicio = auxInicio;
            auxSubcadenaAReemplazar = subcadenaAReemplazar;
            auxSubcadenaNueva = subcadenaNueva;

            while(*auxSubcadenaNueva != '\0'){
                *inicio = *auxSubcadenaNueva;
                inicio++;
                auxSubcadenaNueva++;
            }
        } else {
            inicio++;
        }
    }
    return cadena;
    } else {
        return "Error: La cantidad de caracteres no es igual";
    }
}

int strlen(char *cad){
    if(*cad == '\0'){
        return 0;
    }
    return strlen(++cad) + 1;
}

