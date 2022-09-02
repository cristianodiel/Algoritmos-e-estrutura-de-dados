#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define LIN 3 //numero de linhas de poltronas
#define COL 4 //numero de colunas de poltronas

typedef struct Poltronas {
    int linha;
    int coluna;
    int status;//0=livre, 1=reservado, 2=comprado.
}Poltronas;

typedef struct Coord {
    int linha;
    int coluna;
}Coord;

void menu();
void mostrar_poltronas();
Poltronas liberar_poltrona(Coord x, Poltronas y[LIN][COL]);
Poltronas reservar_poltrona(Coord x, Poltronas y[LIN][COL]);
Poltronas comprar_poltrona(Coord x, Poltronas y[LIN][COL]);
Coord selecionar_poltrona(Coord x);




int main()
{
    int opcao;
    Coord coordenada_poltrona;
    Poltronas poltronas[LIN][COL];

    setlocale(LC_ALL, "Portuguese");

    //limpando reservas da sessão anterior
        for(int i=0;i<LIN;i++){
            for (int j=0;j<COL;j++){
                liberar_poltrona(Coord x, Poltronas y[i][j]);
            }
        }

    menu();

    while (1){
        scanf("%d",&opcao);
        switch (opcao){
            case 1:{
            mostrar_poltronas();
            coordenada_poltrona=selecionar_poltrona(coordenada_poltrona);
            reservar_poltrona(coordenada_poltrona, poltronas);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 2:{
            mostrar_poltronas();
            coordenada_poltrona=selecionar_poltrona(coordenada_poltrona);
            comprar_poltrona(coordenada_poltrona, poltronas);//poltrona com as coordenadas de coord(coordenada_poltrona)
            break;
            }
            case 3:{
            mostrar_poltronas();
            coordenada_poltrona=selecionar_poltrona(coordenada_poltrona);
            liberar_poltrona(coordenada_poltrona, poltronas);//poltrona com as coordenadas de coord(coordenada_poltrona)
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
    printf("**********Menu Cinemãx**********\n");
    printf("1 - Reservar uma poltrona.\n");
    printf("2 - Efetuar a compra.\n");
    printf("3 - Cancelar uma reserva.\n");
    printf("4 - Sair.\n");
    printf("********************************\n");
//return 0;
}

//funcao para ligar a coordenada da poltrona com a poltrona
Poltronas ligar_poltrona(Coord x, Poltronas y[LIN][COL]){
    y[x.linha][x.coluna];

}

//funcao limpar reserva e compra de poltrona//juntar as 3 funcoes (limpar, reservar e comprar) em uma mesma funcao alterar
Poltronas liberar_poltrona(Coord x, Poltronas y[LIN][COL]){
    y[x.linha][x.coluna].status=0;
    return y;
}

//funcao reservar poltrona
Poltronas reservar_poltrona(Coord x, Poltronas y[LIN][COL]){
    y[x.linha][x.coluna].status=1;
    return y;//arrumar
}

//funcao comprar poltrona
Poltronas comprar_poltrona(Coord x, Poltronas y[LIN][COL]){
    y[x.linha][x.coluna].status=2;
    return y;
}

//funcao selecionar poltrona
Coord selecionar_poltrona(Coord x){
    printf("Linha da poltrona:");
    scanf("%d\n",x.linha);
    printf("Coluna da poltrona:");
    scanf("%d\n",x.coluna);
    return x;
}

//funcao mostrar poltronas
void mostrar_poltronas(){
    for(int i=0;i<LIN;i++){
        for (int j=1;j<=COL;j++){
            printf("%c%d ",i+'A',j);
        }
        printf("\n");
    }
//    return 0;
}

//funcao selecionar poltronas
/*struct coord selecionar_poltronas(){
    for(int i=0;i<LIN;i++){
        for (int j=1;j<=COL;j++){
            printf("%c%d ",i+'A',j);
        }
        printf("\n");
    }
    return ;
}
*/
