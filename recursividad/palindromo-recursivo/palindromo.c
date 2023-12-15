#include <stdio.h>
#include <stdlib.h>


int palindromo_recursivo(char *inicio, char *fin);
int esPalindromo(char *cadena);
int toUpper(int ch);


int main()
{
    char prueba[] = "ani   ta LAVa la TinA    ";
    if(esPalindromo(prueba))
        printf("es palindromo\n");
    else
        printf("no es palindromo\n");
    return 0;
}

int esPalindromo(char *cadena)
{
    char *inicio, *fin;
    inicio = cadena;
    while(*inicio != '\0')
        inicio++;
    fin = inicio - 1;
    inicio = cadena;
    return palindromo_recursivo(inicio, fin);
}

int palindromo_recursivo(char *inicio, char *fin)
{
    while(*inicio == ' ')
        inicio++;
    while(*fin == ' ')
        fin--;
    if(inicio >= fin)
        return 1;
    if(toUpper(*inicio) != toUpper(*fin))
        return 0;
    else
        return palindromo_recursivo(++inicio, --fin);
}

int toUpper(int ch)
{
    if(ch >= 'a' && ch <= 'z')
        return ch - 32;
    else
        return ch;
}
