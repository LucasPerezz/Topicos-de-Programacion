#include <stdio.h>

int esPalindromo(char *cadena);
int palindromo(char *inicio, char *fin);
int toUpper(int ch);

int main(){
    char cadena[20] = {"anana"};
    if(esPalindromo(cadena)){
        printf("Es palindromo");
    } else{
        printf("No es palindromo");
    }
    return 0;
}

int esPalindromo(char *cadena){
    char *inicio, *fin;
    inicio = cadena;
    while(*inicio != '\0'){
        inicio++;
    }
    fin = inicio - 1;
    inicio = cadena;
    return palindromo(inicio, fin);
}

int palindromo(char *inicio, char *fin){

    if(inicio >= fin){
        return 1;
    }

    if(*inicio == ' '){
        inicio++;
    }
    if(*fin == ' '){
        fin--;
    }

    if(toUpper(*inicio) != toUpper(*fin)){
        return 0;
    } else{
        return palindromo(++inicio, --fin);
    }
}

int toUpper(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 32;
    } else{
        return ch;
    }
}
