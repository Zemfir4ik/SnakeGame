#include <ncurses.h>

class Map
{
public:
    Map()
    {
        initscr();
        curs_set(0);
        noecho();

        getmaxyx(stdscr, maxY, maxX);
        mainWindow = newwin(maxY - 3, maxX / 2, 0, 0);
        box(mainWindow, 0, 0);
        RefreshMap();
    }

    void ClearMap() const;
    void RefreshMap() const;
    WINDOW* GetWindow() const;

private:
    int maxX, maxY;
    WINDOW *mainWindow;
};
