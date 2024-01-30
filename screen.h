#ifndef SCREEN_H
#define SCREEN_H

typedef struct {
    int x;
    int y;
} Pixel;

typedef struct {
    int width;
    int height;
} Screen;

void screen_init(int width, int height, Screen scr);
void screen_set_pixel(int x, int y, char c);
void screen_clear();

#endif // SCREEN_H

#ifdef SCREEN_IMPLEMENTATION

Screen* screen_init(int width, int height)
{
    Screen scr;
    scr.width = width;
    scr.height = height;

    return scr;
}

void screen_set_pixel(int x, int y, char c)
{

}

void screen_clear()
{

}

#endif
