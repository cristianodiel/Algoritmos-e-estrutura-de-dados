#include <stdio.h>
#include "lista_arranjo_dinamica.h"

int main() {
    Lista teste;
    inicia_lista(&teste);
    Elemento aux;

    for(int i=0;i<500;i++) {
        aux.chave = i;
        inserirElemFinalLista(&teste,aux);
    }

    for(int i=0;i<480;i++) {
        removerElemPeloIndice(&teste, 0);
    }

    //printf("Quantiade de elementos: %d\n", consultar_tamanho(&teste));
    imprime_lista(&teste);


    return 0;
}
