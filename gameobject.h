#pragma once
#include <ncurses.h>

class GameObject
{
public:
    GameObject();

    void SetX(int x);
    void SetY(int y);

    int GetX() const;
    int GetY() const;
    const char* GetIcon() const;

    void DrawGameObject(WINDOW * window);
protected:
    int x, y;
    const char* icon;
};
