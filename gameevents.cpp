#include "gameevents.h"

bool GameEvents::isFruitEated(int snakeX, int snakeY, Fruit fruit)
{
    if(snakeX == fruit.GetX() && snakeY == fruit.GetY())
        return true;
    return false;
}

bool GameEvents::CheckGameOver(Snake &snake, WINDOW *mainWin)
{
    for (int i = 1; i < snake.GetCountOfPiecies(); ++i)
    {
        if (snake.GetX() == snake.GetTail()[i].GetX() && snake.GetY() == snake.GetTail()[i].GetY())
        {
            return true;
        }
    }
    if (snake.GetX() == getmaxx(mainWin) - 1 || snake.GetY() == getmaxy(mainWin) - 1 || snake.GetY() == 0 || snake.GetX() == 0 )
    {
        return true;
    }
    if (snake.GetCountOfPiecies() == (getmaxx(mainWin) - 2) * (getmaxy(mainWin) - 2) - 1)
    {
        return true;
    }
    return false;
}
