#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int *vetor, int tamanho);
float calcularMedia(int *vetor, int tamanho);
float calcularMediana(int *vetor, int tamanho);
int calcularModa(int *vetor, int tamanho, int *moda);

int main(void){
    int tamanho, moda, frequencia;
    int *pTamanho = &tamanho, *pModa = &moda;
    int *vetor;
    float media, mediana;

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

    puts("\nVetor Gerado: ");

    for(int i = 0; i < *pTamanho; i++){
        *(vetor + i) = rand() % 20;
        printf("%d\t", *(vetor + i));
    }

    media = calcularMedia(vetor, *pTamanho);

    ordenar(vetor, *pTamanho);

    mediana = calcularMediana(vetor, *pTamanho);

    frequencia = calcularModa(vetor, *pTamanho, pModa);

    puts("\n\nVetor Ordenado: ");

    for(int i = 0; i < *pTamanho; i++){
        printf("%d\t", *(vetor + i));
    }

    printf("\n\nMedia: %.2f", media);
    printf("\nMediana: %.2f", mediana);

    if(frequencia > 1){
        printf("\nModa: %d", *pModa);
        printf("\nFrequencia: %d\n", frequencia);
    }
    else{
        puts("\nNao existe moda!");
    }

    free(vetor);

    return 0;
}

void ordenar(int *vetor, int tamanho){
    int aux;

    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - 1 - i; j++){
            if(*(vetor + j) > *(vetor + j + 1)){
                aux = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = aux;
            }
        }
    }
}

float calcularMedia(int *vetor, int tamanho){
    float soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += *(vetor + i);
    }

    return soma / tamanho;
}

float calcularMediana(int *vetor, int tamanho){
    if(tamanho % 2 != 0){
        return *(vetor + tamanho / 2);
    }

    return (float)(*(vetor + tamanho / 2 - 1) + *(vetor + tamanho / 2)) / 2;
}

int calcularModa(int *vetor, int tamanho, int *moda){
    int frequencia, maiorFrequencia = 1;

    *moda = *vetor;

    for(int i = 0; i < tamanho; i++){
        frequencia = 0;

        for(int j = 0; j < tamanho; j++){
            if(*(vetor + i) == *(vetor + j)){
                frequencia++;
            }
        }

        if(frequencia > maiorFrequencia){
            maiorFrequencia = frequencia;
            *moda = *(vetor + i);
        }
    }

    return maiorFrequencia;
}