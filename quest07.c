#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarizar(int *matriz, int *matrizS, int tamanho, int limiar);

int main(void){
    int tamanho, limiar;
    int *pTamanho = &tamanho, *pLimiar = &limiar;
    int *matriz, *matrizS;

    srand(time(NULL));

    puts("Digite o tamanho da matriz quadrada: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    puts("Digite o limiar: ");
    scanf("%d", pLimiar);

    matriz = malloc(*pTamanho * *pTamanho * sizeof(*matriz));
    matrizS = calloc(*pTamanho * *pTamanho, sizeof(*matrizS));

    if(matriz == NULL || matrizS == NULL){
        puts("Erro ao alocar memoria!");
        free(matriz);
        free(matrizS);
        return 1;
    }

    puts("\nMatriz M: ");

    for(int i = 0; i < *pTamanho; i++){
        for(int j = 0; j < *pTamanho; j++){
            *(matriz + i * *pTamanho + j) = rand() % 100;

            printf("%d\t", *(matriz + i * *pTamanho + j));
        }

        printf("\n");
    }

    binarizar(matriz, matrizS, *pTamanho, *pLimiar);

    puts("\nMatriz S: ");

    for(int i = 0; i < *pTamanho; i++){
        for(int j = 0; j < *pTamanho; j++){
            printf("%d\t", *(matrizS + i * *pTamanho + j));
        }

        printf("\n");
    }

    free(matriz);
    free(matrizS);

    return 0;
}

void binarizar(int *matriz, int *matrizS, int tamanho, int limiar){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(*(matriz + i * tamanho + j) > limiar){
                *(matrizS + i * tamanho + j) = 1;
            }
            else{
                *(matrizS + i * tamanho + j) = 0;
            }
        }
    }
}