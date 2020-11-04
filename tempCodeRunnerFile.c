#include <stdio.h>
#include "nivel.h"
#include "menu.h"
#include "rlutil.h"
int main()
{
    cls();
    hidecursor();
    printMenu();
    while (1)
    {

        if (kbhit())
        {
            cls();
            printMenu();
            char k = getkey();
            if (k == '3')
            {
                cls();
                printCreditos();
                anykey("Pressione qualquer tecla para voltar\n");
                cls();
                printMenu();
            }
            if (k == '4')
            {
                break;
            }
        }
    }
    return 0;
}
