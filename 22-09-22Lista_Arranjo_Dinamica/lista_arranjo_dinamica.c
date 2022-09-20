#include <stdio.h>
#include <stdlib.h>
#include "lista_arranjo_dinamica.h"


// inicializa uma lista
void inicia_lista(Lista *p_l) {
    p_l->tamAtual = 100;
    p_l->tamMin = 10;
    p_l->qtdElem = 0;
    p_l->Arranjo = malloc(p_l->tamAtual * sizeof(Elemento));
}

// reinicia a lista
void reiniciar_lista(Lista *p_l) {
    free( p_l->Arranjo );
    inicia_lista(p_l);
}

// imprime os elementos da Lista
void imprime_lista(Lista *p_l) {
    int pos;
    for(pos=0; pos < p_l->qtdElem; pos++) {
        printf("%d ",p_l->Arranjo[pos].chave);
    }
}

// inserir elemento na lista a partir de uma posição
int inserirElemLista(Lista *p_l, Elemento ele, int pos_usu) {
    if( (pos_usu <0) || (pos_usu > p_l->qtdElem) )
        return 0; // falso, não foi possível realizar a inserção

    // tamanho não é suficiente
    if( p_l->qtdElem >= p_l->tamAtual ) {
        // 1) criar um arranjo com o dobro do tamanho
        Elemento *novo_arranjo = malloc( p_l->tamAtual*2 * sizeof(Elemento) );

        if(novo_arranjo == NULL) {
            return 0; // não foi possível alocar novo arranjo
        }

        // 2) copiar o arranjo antigo para o novo
        for(int i=0;i< p_l->qtdElem ; i++) {
            novo_arranjo[i] = p_l->Arranjo[i];
        }

        // 3) liberar o arranjo antigo da memória
        free(p_l->Arranjo);

        // 4) fazer o novo arranjo apontar para o arranjo antigo
        p_l->Arranjo = novo_arranjo;

        // 5) atuliza o tamanho atual
        p_l->tamAtual = p_l->tamAtual * 2; // p_l->tamAtual *= 2;

        printf("Log: aumentando o tamanho para %d\n", p_l->tamAtual);
    }

    int j;
    for(j=p_l->qtdElem; j > pos_usu; j--) {
        p_l->Arranjo[j] = p_l->Arranjo[j-1]; // desloca
    }

    p_l->Arranjo[j] =  ele;
    p_l->qtdElem++;

    return 1; // a inserção ocorreu com sucesso
}


// inserir elemento ao final da lista
int inserirElemFinalLista(Lista *p_l, Elemento ele) {
    // tamanho não é suficiente
    if( p_l->qtdElem >= p_l->tamAtual ) { //(p_l).qtdElem
        // 1) criar um arranjo com o dobro do tamanho
        Elemento *novo_arranjo = malloc( p_l->tamAtual*2 * sizeof(Elemento) );

        if(novo_arranjo == NULL) {
            return 0; // não foi possível alocar novo arranjo
        }

        // 2) copiar o arranjo antigo para o novo
        for(int i=0;i< p_l->qtdElem ; i++) {
            novo_arranjo[i] = p_l->Arranjo[i];
        }

        // 3) liberar o arranjo antigo da memória
        free(p_l->Arranjo);

        // 4) fazer o novo arranjo apontar para o arranjo antigo
        p_l->Arranjo = novo_arranjo;

        // 5) atuliza o tamanho atual
        p_l->tamAtual = p_l->tamAtual * 2; // p_l->tamAtual *= 2;

        printf("Log: aumentando o tamanho para %d\n", p_l->tamAtual);
    }

    p_l->Arranjo[p_l->qtdElem] = ele;
    p_l->qtdElem++;

    return 1; // sucesso na insercao
}

// retorna o tamanho utilizado da lista
int consultar_tamanho(Lista *p_l) {
    return p_l->qtdElem;
}

// remover um elemento de uma posição especificada pelo usuário
int removerElemPeloIndice(Lista *p_l, int pos_usu) {
    if( (pos_usu <0) || (pos_usu >= p_l->qtdElem) )
        return 0; // falso: posição invalida

    p_l->Arranjo[pos_usu] = p_l->Arranjo[p_l->qtdElem - 1];
    p_l->qtdElem--;


    // tamanho utilizado é inferior à 20% do tamanho alocado. Liberando memoria.
    if( 0.5*(p_l->qtdElem) > p_l->tamMin && p_l->qtdElem < (0.2*p_l->tamAtual) ) {
        // 1) criar um arranjo com a metade do tamanho atual
        Elemento *novo_arranjo = malloc( p_l->tamAtual*0.5 * sizeof(Elemento) );

        if(novo_arranjo == NULL) {
            return 0; // não foi possível alocar novo arranjo
        }

        // 2) copiar o arranjo antigo para o novo
        for(int i=0;i< p_l->qtdElem ; i++) {
            novo_arranjo[i] = p_l->Arranjo[i];
        }

        // 3) liberar o arranjo antigo da memória
        free(p_l->Arranjo);

        // 4) fazer o novo arranjo apontar para o arranjo antigo
        p_l->Arranjo = novo_arranjo;

        // 5) atuliza o tamanho atual
        p_l->tamAtual = p_l->tamAtual * 0.5; // p_l->tamAtual *= 0.5;

        printf("Log: diminuindo o tamanho para %d\n", p_l->tamAtual);
    }
    return 1; // remocao concluida com sucesso
}

// retorna o indice do primeiro elemento encontrado
// caso não encontre retorna -1
int buscaSequencial(Lista *p_l, int chave) {
    int i;
    for(i=0; i< p_l->qtdElem; i++)
        if(p_l->Arranjo[i].chave == chave)
            return i; // retorna o indice do elemento encontrado

    return -1; // elemento não encontrado
}


// remove elemento baseado na chave
int removerElemPelaChave(Lista *p_l, int chave) {
    return removerElemPeloIndice(p_l, buscaSequencial(p_l, chave));
}
