#include "controller.h"

void Controller::Input(int &out)
{
    while(true)
    {
        if(out = getch())
            halfdelay(200);
        else
        {
            cbreak();
        }
    }
}
