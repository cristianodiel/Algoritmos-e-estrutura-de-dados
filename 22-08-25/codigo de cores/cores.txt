#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvando os atributos do console */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    /* Alterando as cores do console */
    for(int color=0;color<255;color++) {
        SetConsoleTextAttribute(hConsole, color);
        printf("[COR:%3d] ", color);

        // pula de linha a cada 10 impressões
        if(color % 10 == 0)
            printf("\n");
    }

    /* Restaurando a cor original do console */
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\nVoltando ao normal");

    return 0;
}
