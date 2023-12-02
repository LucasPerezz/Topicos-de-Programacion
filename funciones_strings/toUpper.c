#include <stdio.h>

int toUpper(int ch);

int main(){
    char palabra = 'W';
    printf("%c", toUpper(palabra));
    return 0;
}

int toUpper(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 32;
    } else{
        return ch;
    }
}