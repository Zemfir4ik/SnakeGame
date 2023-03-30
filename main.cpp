#include "gameevents.h"
#include "controller.h"

int main()
{
    Map map; 
    mvwprintw(stdscr, getmaxy(stdscr) / 2 - 2, getmaxx(stdscr) / 2 + 1, "WASD - to move");
    map.RefreshMap(); 

    Fruit fruit;
    fruit.CreateFruit(map.GetWindow());

    const int maxLength = getmaxx(map.GetWindow()) * getmaxy(map.GetWindow());
    Snake snake(maxLength, map.GetWindow());   
 
    int score = 0;

    bool gameOver = false;  

    int pressedKey;
    std::thread input(Controller::Input, std::ref(pressedKey));
    input.detach();

    while(!gameOver)
    {                 
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        snake.CheckDirection(pressedKey, map.GetWindow());
        if (snake.GetDirection() != -1)
        {  
           snake.MoveSnake();
        }

        fruit.DrawGameObject(map.GetWindow());
        snake.DrawGameObject(map.GetWindow());

        GameObject* t = snake.GetTail();
        for (int i = 0; i < snake.GetCountOfPiecies(); ++i)
        {
            t[i].DrawGameObject(map.GetWindow());
        }

        if(GameEvents::isFruitEated(snake.GetX(), snake.GetY(), fruit))
        {
            score += 5;
            snake.PlusCountOfPiecies();
            fruit.CreateFruit(map.GetWindow());
        }

    
        map.RefreshMap();
        map.ClearMap();

        if(GameEvents::CheckGameOver(snake, map.GetWindow()))
        {
            cbreak();
            mvwprintw(map.GetWindow(), getmaxy(map.GetWindow()) / 2, getmaxx(map.GetWindow()) / 2 - 5, "Your score: %d", score);
            mvwprintw(map.GetWindow(), getmaxy(map.GetWindow()) / 2 + 1, getmaxx(map.GetWindow()) / 2 - 8, "Press any key to leave");
            wrefresh(map.GetWindow());
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            wgetch(map.GetWindow());
            break;
        }
    }
    endwin();
}
