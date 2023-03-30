#include "fruit.h"

void Fruit::CreateFruit(WINDOW *window)
{
    std::srand(std::time(0));

    x = std::rand() % (getmaxx(window) - 2) + 1;
    y = std::rand() % (getmaxy(window) - 2) + 1;
    while (mvwinch(window, y, x) != ' ')
    {
        x = std::rand() % (getmaxx(window) - 2) + 1;
        y = std::rand() % (getmaxy(window) - 2) + 1;       
    }
    icon = "F";
}
