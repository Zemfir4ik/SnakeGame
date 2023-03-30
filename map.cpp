#include "map.h"

WINDOW* Map::GetWindow() const
{
    return mainWindow;
}

void Map::RefreshMap() const
{
    box(mainWindow, 0, 0);
    wrefresh(mainWindow);
    refresh();
}

void Map::ClearMap() const
{
    int x,y;
    getmaxyx(mainWindow, y, x);
    x -= 2;
    y -= 2;
    for (int wy = 1; wy <= y; ++wy)
    {
        for (int wx = 1; wx <= x; ++wx)
        {
            mvwprintw(mainWindow, wy, wx, " ");
        }
    }
}
