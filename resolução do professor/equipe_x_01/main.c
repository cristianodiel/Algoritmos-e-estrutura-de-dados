#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void insereFila(int fila[], int tam, int indElemento);
void imprimeVetor(int vet[], int tam);

int main() {

    char nomes[TAM][50];
    int idades[TAM];
    int indMenorIdade = 0;

    int filaMenores[] ={0, 0, 0};

    for(int i=0; i<TAM;i++) {
        printf("\n-------- %2d --------\n", i);
        printf("Nome: ");
        gets(nomes[i]);

        printf("Idade: ");
        scanf("%d", &idades[i]);

        fflush(stdin);

        // atualiza o local de quem tem a menor idade
        if((idades[i] < idades[filaMenores[0]]) ||
            (idades[i] < idades[filaMenores[1]]) ||
            (idades[i] < idades[filaMenores[2]]) ||
            (i < 3)) {
            indMenorIdade = i;
            insereFila(filaMenores, 3, indMenorIdade);
            imprimeVetor(filaMenores, 3);
        }


        /*
        if(idades[i] < idades[indMenorIdade]) {
            indMenorIdade = i;
            insereFila(filaMenores, 3, indMenorIdade);
            imprimeVetor(filaMenores, 3);
        }
        */
    }



    // lista todos os nomes e idades
    printf("\nLista das menores idades:\n");
    for(int i=0;i<TAM;i++) {
        if( (idades[i] == idades[filaMenores[0]]) ||
            (idades[i] == idades[filaMenores[1]]) ||
            (idades[i] == idades[filaMenores[2]]) ) {
            printf("%10s : %2d\n", nomes[i], idades[i]);
        }
    }


    return 0;
}

void insereFila(int fila[], int tam, int indElemento, int idades[], int tamIdade) {

    for(int i=tam-1; i>=1; i--) {
        fila[i] = fila[i-1];
    }

    fila[0] = indElemento;
}

void imprimeVetor(int vet[], int tam) {

    for(int i=0; i<tam;i++) {
        printf("%d ", vet[i]);
    }
}
