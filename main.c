#include <stdio.h>
#include "nivel.h"
#include "menu.h"
#include "rlutil.h"
int main()
{
    cls();
    hidecursor();
    printMenu();
    int menu = 1;
    while (menu)
    {

        if (kbhit())
        {
            cls();
            printMenu();
            char k = getkey();
            switch (k)
            {
            case '3':
                cls();
                printCreditos();
                anykey("Pressione qualquer tecla para voltar\n");
                cls();
                printMenu();
                break;
            case '4':
                menu = 0;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
