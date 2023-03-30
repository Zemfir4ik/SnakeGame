#include "gameobject.h"

GameObject::GameObject()
{
    icon = "o";
}

void GameObject::DrawGameObject(WINDOW * window)
{
    mvwprintw(window, y, x, "%s", icon);
}

int GameObject::GetX() const
{
    return x;
}
    
int GameObject::GetY() const
{
    return y;
}

const char* GameObject::GetIcon() const
{
    return icon;
}

void GameObject::SetX(int x)
{
    this->x = x;
}

void GameObject::SetY(int y)
{
    this->y = y;
}
