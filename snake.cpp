#include "snake.h"

Snake::Snake(int maxLength, WINDOW* window)
{
    direction = -1;
    x = getmaxx(window) / 2;
    y = getmaxy(window) / 2;
    icon = "0";
    countOfPiecies = 2;
    tail = new GameObject[maxLength];

    tail[0].SetX(getmaxx(window) / 2 - 1); 
    tail[0].SetY(getmaxy(window) / 2); 

    tail[1].SetX(getmaxx(window) / 2 - 2); 
    tail[1].SetY(getmaxy(window) / 2); 
}

void Snake::MoveSnake()
{
    
    for (int i = countOfPiecies; i > 0; --i)
    {
        tail[i].SetX(tail[i-1].GetX());
        tail[i].SetY(tail[i-1].GetY());
    }
    tail[0].SetX(x);
    tail[0].SetY(y);

    switch (direction)
    {
    case 119:
        y -= 1;
        break;
    case 97:
        x -= 1;
        break;
    case 115:
        y += 1;
        break;
    case 100:
        x += 1;
        break;
    
    default:
        break;
    }
    return;
}

int Snake::GetDirection() const
{
    return direction;
}

int Snake::GetCountOfPiecies() const
{
    return countOfPiecies;
}

void Snake::CheckDirection(int newDirection, WINDOW* window)
{
    if (newDirection == direction)
        return;
        
    if (newDirection == 119 || newDirection == 97 || newDirection == 115 || newDirection == 100)
    {     
        if ((direction == 119 && newDirection == 115) || (direction == 115 && newDirection == 119))
            return;
        if ((direction == 97  && newDirection == 100) || ((direction == 100 || direction == -1) && newDirection == 97))
            return;


        direction = newDirection;
    }

    return;
}

GameObject* Snake::GetTail() const
{
    return tail;
}

void Snake::PlusCountOfPiecies()
{
    countOfPiecies += 1;
}
