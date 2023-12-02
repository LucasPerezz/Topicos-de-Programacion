#include <stdio.h>
#include <stddef.h>

size_t mystrlen(const char *s);


int main(){
    char palabra[] = {"Hola"};
    printf("Largo de la cadena: %d\n", mystrlen(palabra));
    return 0;
}

size_t mystrlen(const char *s){
    size_t longitud = 0;
    while(*s != '\0'){
        longitud++;
        s++;
    }
    return longitud;
}