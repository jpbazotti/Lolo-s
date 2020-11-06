#include <stdio.h>
#include "nivel.h"
#include "menu.h"
#include "rlutil.h"
int main()
{
    cls();
    hidecursor();
    printMenu();
    int loop = 1;
    //loop principal
    while (loop)
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
                loop = 0;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
