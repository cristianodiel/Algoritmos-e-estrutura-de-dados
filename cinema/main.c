#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define LIN 3 //numero de linhas de poltronas
#define COL 4 //numero de colunas de poltronas

typedef struct Poltrona {
    char nome[40];//nome do comprador
    int senha;//senha para efetuar uma compra anteriormente reservada
    int status;//0=livre, 1=reservado, 2=comprado.
}Poltrona;

typedef struct Coord {
    int linha;
    int coluna;
}Coord;

void menu();
void mostrar_poltronas(Poltrona y[LIN][COL]);
void liberar_poltrona(Poltrona y[LIN][COL],int i,int j);
Poltrona reservar_poltrona(Poltrona y[LIN][COL],Coord x);
Poltrona comprar_poltrona(Poltrona y[LIN][COL],Coord x);
void verificar_poltrona(Poltrona y[LIN][COL],Coord x);
Coord selecionar_poltrona(Coord x);




int main()
{
    int opcao;
    Coord coordenada;
    Poltrona poltronas[LIN][COL];

    setlocale(LC_ALL, "Portuguese");

    //limpando reservas da sessão anterior
        for(int i=0;i<LIN;i++){
            for (int j=0;j<COL;j++){
                liberar_poltrona(poltronas,i,j);
            }
        }
        liberar_poltrona(poltronas,3,5);


    while (1){
        menu();
        scanf("%d",&opcao);
        switch (opcao){
            case 1:{
            mostrar_poltronas(poltronas);
            coordenada=selecionar_poltrona(coordenada);
            reservar_poltrona(poltronas,coordenada);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 2:{
            mostrar_poltronas(poltronas);
            coordenada=selecionar_poltrona(coordenada);
            comprar_poltrona(poltronas,coordenada);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 3:{
            mostrar_poltronas(poltronas);
            coordenada=selecionar_poltrona(coordenada);
            liberar_poltrona(poltronas,coordenada.linha,coordenada.coluna);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 4:{
            mostrar_poltronas(poltronas);
            coordenada=selecionar_poltrona(coordenada);
            verificar_poltrona(poltronas,coordenada);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 5:{
                printf("Agradecemos a preferência!");
                return 0;
            }
        }

    }


    return 0;
}
//funcao menu
void menu(){
//    SetConsoleTextAttribute(hConsole, color);
    printf("\n\n");
    printf("**********Menu Cinemãx**********\n");
    printf("1 - Reservar uma poltrona.\n");
    printf("2 - Efetuar a compra.\n");
    printf("3 - Cancelar uma reserva.\n");
    printf("4 - Verificar o status de uma poltrona.\n");
    printf("5 - Sair.\n");
    printf("********************************\n");
    printf("\nFaca sua escolha");
//return 0;
}

//funcao limpar reserva e compra de poltrona//juntar as 3 funcoes (limpar, reservar e comprar) em uma mesma funcao alterar
void liberar_poltrona(Poltrona y[LIN][COL],int i,int j){
    y[i][j].status=0;
    //return y;
}

//funcao reservar poltrona
Poltrona reservar_poltrona(Poltrona y[LIN][COL],Coord x){

    if (y[x.linha][x.coluna].status==0){
        printf("Informe seu nome:");
        fflush(stdin);
        gets(y[x.linha][x.coluna].nome);
        //printf("nome: %s",y[x.linha][x.coluna].nome);
        printf("Informe uma senha (essa senha sera solicitada na hora de efetuar a compra da poltrona):");
        fflush(stdin);
        scanf("%d",&y[x.linha][x.coluna].senha);
        //printf("senha: %d",y[x.linha][x.coluna].senha);
        y[x.linha][x.coluna].status=1;
        return y[x.linha][x.coluna];
    }else{
    printf("A poltrona selecionada nao esta disponivel.");
    }

}

//funcao comprar poltrona
Poltrona comprar_poltrona(Poltrona y[LIN][COL],Coord x){
    char nome_aux[40];
    int senha_aux;
    if (y[x.linha][x.coluna].status==0){
        printf("Informe seu nome:");
        fflush(stdin);
        gets(y[x.linha][x.coluna].nome);
        y[x.linha][x.coluna].status=2;
        return y[x.linha][x.coluna];
    }else if (y[x.linha][x.coluna].status==1){
        printf("Informe seu nome:");
        fflush(stdin);
        gets(nome_aux);
        if (strcmp(nome_aux,y[x.linha][x.coluna].nome)!=0){
            printf("O nome informado e diferente do nome para qual a poltrona esta reservada");
            return y[x.linha][x.coluna];
        }else{
            printf("Informe a senha informada no momento da reserva:");
            fflush(stdin);
            scanf("%d",&senha_aux);
            if(senha_aux!=y[x.linha][x.coluna].senha){
                    printf("Senha incorreta. A compra nao pode ser efetuada.");
                    return y[x.linha][x.coluna];
            }else{
                y[x.linha][x.coluna].status=2;
                return y[x.linha][x.coluna];
            }
        }
    }else{
    printf("A poltrona selecionada nao esta disponivel.");
    }
}
//funcao verificar poltrona
void verificar_poltrona(Poltrona y[LIN][COL],Coord x){
    if (y[x.linha][x.coluna].status==0){
    printf("A poltrona selecionada encontra-se disponivel.");
    }else if(y[x.linha][x.coluna].status==1){
    printf("A poltrona selecionada encontra-se reservada por %s.",y[x.linha][x.coluna].nome);
    }else if(y[x.linha][x.coluna].status==2){
    printf("A poltrona selecionada encontra-se comprada por %s.",y[x.linha][x.coluna].nome);
    }

}

//funcao selecionar poltrona
Coord selecionar_poltrona(Coord x){
    char aux;
    printf("Linha da poltrona:");
    fflush(stdin);
    scanf("%c",&aux);
    //printf("%")
    x.linha=toupper(aux)-'A';
    printf("Coluna da poltrona:");
    fflush(stdin);
    scanf("%d",&x.coluna);
    x.coluna=x.coluna-1;

    return x;
}

//funcao mostrar poltronas
void mostrar_poltronas(Poltrona y[LIN][COL]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    for(int i=0;i<LIN;i++){
        for (int j=0;j<COL;j++){
            if(y[i][j].status==0){
                SetConsoleTextAttribute(hConsole, 160);
                printf("%c%d ",i+'A',j+1);
            }else if(y[i][j].status==1){
                SetConsoleTextAttribute(hConsole, 96);
                printf("%c%d ",i+'A',j+1);
            }else if(y[i][j].status==2){
                SetConsoleTextAttribute(hConsole, 64);
                printf("%c%d ",i+'A',j+1);
            }
        SetConsoleTextAttribute(hConsole, 7);
        }
        printf("\n");
    }
//    return 0;
}

