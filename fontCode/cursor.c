#include <windows.h>
#include <cursor.h>

void setCursor(_Bool states, int x, int y)
{
    if (states)
        printf("\x1b[?25h");
    else
        printf("\x1b[?25l");
    if (x > 0 && y > 0)
        printf("\x1b[%d;%dH", y, x);
}

void _setCursor(Cursor *cursor)
{
    if (cursor->visible)
        printf("\x1b[?25h");
    else
        printf("\x1b[?25l");
    if (cursor->x > 0 && cursor->y > 0)
        printf("\x1b[%d;%dH", cursor->y, cursor->x);
}

void getCursor(int *x, int *y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        *x = csbi.dwCursorPosition.X + 1;
        *y = csbi.dwCursorPosition.Y + 1;
    }
    else
    {
        *x = -1;
        *y = -1;
    }
}

void _getCursor()
{

}