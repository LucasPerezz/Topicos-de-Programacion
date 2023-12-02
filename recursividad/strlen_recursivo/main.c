#include <stdio.h>

int strlenRecursivo(char *cadena);

int main(){
    char palabra[] = {"hello world"};
    printf("Largo de la cadena: %d\n", strlenRecursivo(palabra));
    return 0;
}

int strlenRecursivo(char *cadena){
    if(*cadena == '\0'){
        return 0;
    }
    return 1 + strlenRecursivo(++cadena);
}