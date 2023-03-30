#include "gameobject.h"

class Snake : public GameObject
{
public:
    Snake(int maxLength, WINDOW* window);

    void CheckDirection(int newDirection, WINDOW* window);
    void PlusCountOfPiecies();

    int GetDirection() const;
    int GetCountOfPiecies() const;
    GameObject* GetTail() const;
    void MoveSnake();

private:
    int direction;
    int countOfPiecies;
    GameObject *tail;
};
