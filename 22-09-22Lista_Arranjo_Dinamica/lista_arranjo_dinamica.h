/*
* struct que representa os elementos
* armazenados na lista dentro do arranjo
*/
typedef struct {
    int chave;
    // outros campos ...
} Elemento;

/*
* struct que representa a lista
*/
typedef struct {
    Elemento *Arranjo;
    int qtdElem;
    int tamAtual;
    int tamMin;
} Lista;

/*
* Protótipos das funções
*/
void inicia_lista(Lista *p_l); // ok
void reiniciar_lista(Lista *p_l); // ok
int consultar_tamanho(Lista *p_l); // ok
void imprime_lista(Lista *p_l); //ok
int inserirElemLista(Lista *p_l, Elemento ele, int pos_usu); //ok
int inserirElemFinalLista(Lista *p_l, Elemento ele); // ok
int removerElemPeloIndice(Lista *p_l, int pos_usu); // ok
int removerElemPelaChave(Lista *p_l, int chave); // ok
int buscaSequencial(Lista *p_l, int chave); //ok


