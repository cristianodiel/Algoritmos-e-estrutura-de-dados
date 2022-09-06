#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define LIN 3 //numero de linhas de poltronas
#define COL 4 //numero de colunas de poltronas

typedef struct Poltrona {
    int nome;//nome do comprador
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
    printf("4 - Sair.\n");
    printf("********************************\n");
//return 0;
}

//funcao limpar reserva e compra de poltrona//juntar as 3 funcoes (limpar, reservar e comprar) em uma mesma funcao alterar
void liberar_poltrona(Poltrona y[LIN][COL],int i,int j){
    y[i][j].status=0;
    //return y;
}

//funcao reservar poltrona
Poltrona reservar_poltrona(Poltrona y[LIN][COL],Coord x){
    y[x.linha][x.coluna].status=1;
    return y[x.linha][x.coluna];
}

//funcao comprar poltrona
Poltrona comprar_poltrona(Poltrona y[LIN][COL],Coord x){
    y[x.linha][x.coluna].status=2;
    return y[x.linha][x.coluna];
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
    printf("%d %d",x.linha,x.coluna);
    return x;
}

//funcao mostrar poltronas
void mostrar_poltronas(Poltrona y[LIN][COL]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    for(int i=0;i<LIN;i++){
        for (int j=1;j<=COL;j++){
            if(y[i][j].status==0){
                SetConsoleTextAttribute(hConsole, 160);
                printf("%c%d ",i+'A',j);
            }else if((y[i][j].status)==1){
                SetConsoleTextAttribute(hConsole, 96);
                printf("%c%d ",i+'A',j);
            }else if(y[i][j].status==2){
                SetConsoleTextAttribute(hConsole, 64);
                printf("%c%d ",i+'A',j);
            }

        }
        printf("\n");
    }
//    return 0;
}

