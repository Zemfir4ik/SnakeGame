#include "map.h"
#include "fruit.h"
#include "snake.h"

class GameEvents
{
public:
    static bool isFruitEated(int snakeX, int snakeY, Fruit fruit);
    static bool CheckGameOver(Snake &snake, WINDOW *mainWin);
};
