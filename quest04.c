#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somar(float *vetor, int tamanho, float *soma);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    float *vetor, soma = 0;
    float *pSoma = &soma;

    srand(time(NULL));

    puts("Digite o tamanho do vetor: ");
    scanf("%d", pTamanho);

    if(*pTamanho <= 0){
        puts("Erro! Digite um tamanho positivo!");
        return 1;
    }

    vetor = malloc(*pTamanho * sizeof(*vetor));

    if(vetor == NULL){
        puts("Erro ao alocar memoria!");
        return 1;
    }

    for(int i = 0; i < *pTamanho; i++){
        *(vetor + i) = (float)(rand() % 100) / 10;
        printf("Vetor X%d: %.2f\n", i + 1, *(vetor + i));
    }

    somar(vetor, *pTamanho, pSoma);

    printf("\nSomatorio: %.2f\n", *pSoma);

    free(vetor);

    return 0;
}

void somar(float *vetor, int tamanho, float *soma){
    for(int i = 0; i < tamanho; i++){
        *soma += *(vetor + i);
    }
}