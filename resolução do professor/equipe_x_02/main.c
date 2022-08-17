#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int encontraPalavra(char texto[], char palavra[]);

int main() {
    setlocale(LC_ALL, "Portuguese");

    char texto[500];
    char palavra[20];
    int encontrou;

    printf("Digite seu texto: ");
    gets(texto);

    printf("Digite a palavra buscada: ");
    gets(palavra);

    encontrou = encontraPalavra(texto,palavra);
    if( encontrou != -1) {
        printf("A palavra se encontra na posição: %d\n", encontrou);
    } else {
        printf("Palavra não encontrada!\n");
    }

    return 0;
}


int encontraPalavra(char texto[], char palavra[]) {

    int tamPalavra = strlen(palavra);
    int tamTexto = strlen(texto);
    int indTexto;
    int indPalavra;
    int contaLetraIguais;

    for(indTexto = 0; indTexto <= tamTexto-tamPalavra; indTexto++) {
        contaLetraIguais = 0;

        for(indPalavra = 0; indPalavra < tamPalavra; indPalavra++) {

            if (texto[indTexto+indPalavra] == palavra[indPalavra]) {
                contaLetraIguais++;
            }
        }

        if(contaLetraIguais == tamPalavra) {
            return indTexto;
        }

    }

    return -1;
}
