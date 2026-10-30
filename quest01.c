#include <stdio.h>
#include <stdlib.h>

int* primeiroPar(int *vetor, int tamanho);

int main(void){
    int tamanho;
    int *pTamanho = &tamanho;
    int *vetor, *resultado;

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
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", vetor + i);
    }

    resultado = primeiroPar(vetor, *pTamanho);

    if(resultado != NULL){
        printf("Primeiro elemento PAR: %d\n", *resultado);
        printf("Endereco: %p\n", (void*)resultado);
    }
    else{
        puts("Nenhum elemento PAR encontrado!");
    }

    free(vetor);

    return 0;
}

int* primeiroPar(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(*(vetor + i) % 2 == 0){
            return vetor + i;
        }
    }

    return NULL;
}