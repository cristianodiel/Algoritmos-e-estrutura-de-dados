/* Construir um struct para representar livros
Implementar um programa em C que
- leia 5 livros
- imprima os dados do livro
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

//struct que representa livros
struct livro{
    int codigo;
    char titulo[50];
    char editora [30];
    char genero [30];
    int ocupado;
};

//prototipos das funcoes
void zerar(struct livro biblioteca[], int tam);
struct livro leLivro();
void imprimeLivro(struct livro biblioteca[], int tam);


int main()
{
    struct livro biblioteca[TAM];

    //zerar biblioteca
    zerar (biblioteca,TAM);

    //ler livro
    for(int i=0;i<TAM;i++){
        biblioteca[i]=leLivro();
    }

    //mostrar livro
    imprimeLivro (biblioteca,TAM);

    return 0;
}

void zerar(struct livro biblioteca[], int tam) {
    for(int i=0; i<tam; i++) {
        biblioteca[i].ocupado = 0;
    }
}

struct livro leLivro() {

    struct livro aux;

    fflush(stdin);
    printf("Digite o titulo do livro: \n");
    gets(aux.titulo);


    fflush(stdin);
    printf("Digite o codigo do livro: \n");
    scanf("%d", &aux.codigo);

    fflush(stdin);
    printf("Digite a editora do livro: \n");
    gets(aux.editora);

    fflush(stdin);
    printf("Digite o genero do livro: \n");
    gets(aux.genero);

    printf("----------------\n");

    aux.ocupado = 1;

    return aux;
}

void imprimeLivro(struct livro biblioteca[], int tam) {

    for(int i=0;i<tam;i++) {
            if(biblioteca[i].ocupado == 1) {
                printf("[%d] -----------------------\n", i);
                printf("Titulo: %s\n", biblioteca[i].titulo);
                printf("Codigo: %d\n", biblioteca[i].codigo);
                printf("Editora: %s\n", biblioteca[i].editora);
                printf("Genero: %s\n", biblioteca[i].genero);
                printf("-----------------------\n\n");
            }
    }
}


