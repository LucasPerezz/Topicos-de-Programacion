#include <stdio.h>

char *strrchr_recursivo(char *cadena, int c);
char *strrchrRec(char *inicio, char *fin,  int c);

int main(){
    char palabra[] = {"Hello World"};
    printf("%s\n", strrchr_recursivo(palabra, 'H'));
    return 0;
}



char *strrchr_recursivo(char *cadena, int c){
    char *inicio,*fin;
    inicio = cadena;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = cadena;
    return strrchrRec(inicio, fin, c);
}

char *strrchrRec(char *inicio, char *fin,  int c){
    if(*fin == c){
        return fin;
    }

    if(fin < inicio){
        return NULL;
    }

    return strrchrRec(inicio, --fin, c);
}
