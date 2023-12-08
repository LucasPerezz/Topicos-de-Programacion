// Ejercicio 1.12
// Desarrollar una función para que, dada una matriz cuadrada de reales de orden N, obtenga la
// sumatoria de los elementos que están por encima de la diagonal principal (excluida ésta). Lo mismo
// para la diagonal secundaria. Lo mismo incluyendo la diagonal. Lo mismo, con los que están por
// debajo de la diagonal.

// Ejercicio 1.13
// Desarrollar una función para que, dada una matriz cuadrada de enteros de orden N, obtenga la traza
// de la misma (sumatoria de los elementos de la diagonal principal). Lo mismo, pero con la diagonal
// secundaria.

// Ejercicio 1.14
// Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz
// diagonal (ceros en todos sus elementos excepto en la diagonal principal).

// Ejercicio 1.15
// Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz
// identidad (matriz diagonal, con unos en la diagonal principal y ceros en los restantes).

// Ejercicio 1.16
// Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es simétrica.


// Ejercicio 1.18
// Desarrollar una función para obtener la traspuesta de una matriz dada.


#include <stdio.h>

void diagonalPrincipal(int matriz[][5], int cf);
void diagonalSecundaria(int matriz[][5], int cf);
void arribaDiagonalPrincipal(int matriz[][5], int cf, int cc);
void abajoDiagonalPrincipal(int matriz[][5], int cf);
int esMatrizDiagonal(int matriz[][3], int cf, int cc); //Ejercicio 1.15. Simil 1.15
int esMatrizSimetrica(int matriz[][3], int cf, int cc);
void transponerMatriz(int matriz[][5], int cf, int cc);

int main() {
    int matriz[5][5] = {{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45},{51,52,53,54,55}};
    int matriz1_14[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int matriz1_16[3][3] = {{3,1,4}, {1,2,6}, {4, 6, 1}};
    diagonalPrincipal(matriz, 5);
    diagonalSecundaria(matriz, 5);
    arribaDiagonalPrincipal(matriz, 5, 5);
    abajoDiagonalPrincipal(matriz, 5);

    //Ejercicio 1.15. Simil 1.14
    if(esMatrizDiagonal(matriz1_14, 3, 3)){
        printf("Es matriz diagonal\n");
    } else {
        printf("No es matriz diagonal\n");
    }

    //Ejercicio 1.16
    if(esMatrizSimetrica(matriz1_16, 3, 3)){
        printf("Es matriz simetrica\n");
    } else {
        printf("No es matriz simetrica\n");
    }

    transponerMatriz(matriz, 5, 5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

void diagonalPrincipal(int matriz[][5], int cf){
    for(int i = 0; i < cf; i++){
        printf("%d\t", matriz[i][i]);
    }
    printf("\n\n");
    return;
}

void diagonalSecundaria(int matriz[][5], int cf){
    for(int i = 0; i < cf; i++){
        printf("%d\t", matriz[i][cf - i - 1]);
    }
        printf("\n\n");
}

void arribaDiagonalPrincipal(int matriz[][5], int cf, int cc){
    for(int i = 0; i < cf; i++){
        for(int j = i + 1; j < cc; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

void abajoDiagonalPrincipal(int matriz[][5], int cf){
    for(int i = 1; i < cf; i++){
        for(int j = 0; j < i; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int esMatrizDiagonal(int matriz[][3], int cf, int cc){
    for(int i = 0; i < cf; i++){
        for(int j = 0; j < cc; j++){
            if(i != j){
                if(matriz[i][j] != 0){
                    return 0;
                }
            } else{
                if(matriz[i][j] != 1){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int esMatrizSimetrica(int matriz[][3], int cf, int cc){
    for(int i = 0; i < cf; i++){
        for(int j = 0; j < cc; j++){
            if(matriz[i][j] != matriz[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

void transponerMatriz(int matriz[][5], int cf, int cc){
    for(int i = 0; i < cf; i++){
        for(int j = 0; j < cc; j++){
            matriz[i][j] = matriz[j][i];
        }
    }
    return;
}