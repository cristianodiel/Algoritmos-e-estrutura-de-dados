/*Cebolinha � um personagem de hist�ria em quadrinhos que quando falava, trocava o "r" pelo "l" (problema conhecido como dislalia).

Fa�a um program que gera uma vers�o de um texto fornecido com todos "r" e "rr" trocados por "l", exceto no caso em que o "r" ocorre no final de uma palavra. .


Exemplo de Entrada:
"e chega de disputar essa rua com a monica, eu poderei comprar ruas, bairros inteiros"
Exemplo de Sa�da:
"e chega de disputar essa lua com a monica, eu podelei complar luas, bailos inteilos"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[100],textol[100];
    int i,j=0;
    printf("****Dislalia****\n");
    printf("Informe um texto para repetir da forma como o Cebolinha diria:\n");
    gets(texto);
    fflush(stdin);
    //printf("%s",texto);

    for(i=0;i<=strlen(texto);i++){
        if ((texto[i]=='r')&&(texto[i+1]=='r')){
            j--;
        }else if ((texto[i]=='r')&&(texto[i+1]>='a')&&(texto[i+1]<='z')&&texto[i+1]!='l'){
            textol[i+j]='l';
        }else{
            textol[i+j]=texto[i];
        }
    }
    printf("\n%s\n\n",textol);

    return 0;
}
