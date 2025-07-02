#ifndef CURSOR_H
#define CURSOR_H

typedef struct
{
    int x;
    int y;
    _Bool visible;
} Cursor;

void setCursor(_Bool states, int x, int y);
void _setCursor(Cursor *cursor);

void getCursor();
void _getCursor();

#endif // CURSOR_H