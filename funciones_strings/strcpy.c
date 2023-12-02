#include <stdio.h>

char *strcpy(char *string1, const char *string2);

int main(){
    char palabra[] = {"Hello world"};
    char palabraCopiada[15];
    printf("Palabra copiada: %s\n", strcpy(palabraCopiada, palabra));
    return 0;
}

char *strcpy(char *string1, const char *string2){
    char *inicio;
    inicio = string1;
    while(*string2 != '\0'){
        *string1 = *string2;
        string1++;
        string2++;
    }
    *string1 = '\0';
    return inicio;
}