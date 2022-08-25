#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define LIN 3 //numero de linhas de poltronas
#define COL 4 //numero de colunas de poltronas

void menu();
void mostrar_poltronas();

struct poltrona {
    int linha;
    int coluna;
    int status;//0=livre, 1=reservado, 2=comprado.
};

struct coord {
    int linha;
    int coluna;
};

int main()
{
    int opcao;
    struct coord coordenada_poltrona;

    setlocale(LC_ALL, "Portuguese");

    menu();

    while (1){
        scanf("%d",&opcao);
        switch (opcao){
            case 1:{
            mostrar_poltronas();
            //selecionar poltrona(coordenada_poltrona);
            }
            case 2:{
            }
            case 3:{
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
return 0;
}

//funcao limpar reservas e compras de poltronas
void limpar_reservas(){
    for(int i=0;i<LIN;i++){
        for (int j=1;j<=COL;j++){
            status=0;
        }
    }
    return 0;
}

//funcao mostrar poltronas
void mostrar_poltronas(){
    for(int i=0;i<LIN;i++){
        for (int j=1;j<=COL;j++){
            printf("%c%d ",i+'A',j);
        }
        printf("\n");
    }
    return 0;
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
