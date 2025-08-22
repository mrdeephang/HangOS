#include "screen.h"
#include <cstdint>

namespace Screen
{
    const int WIDTH = 80;
    const int HEIGHT = 25;

    volatile char *buffer = (volatile char *)0xB8000;
    int column = 0;
    int row = 0;
    uint8_t color = 0x0F; // White on black

    void clear()
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                putChar(' ', x, y);
            }
        }
        column = 0;
        row = 0;
    }

    void putChar(char c, int x, int y)
    {
        const int index = (y * WIDTH + x) * 2;
        buffer[index] = c;
        buffer[index + 1] = color;
    }

    void print(const char *str)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '\n')
            {
                column = 0;
                row++;
                if (row >= HEIGHT)
                {
                    scroll();
                    row = HEIGHT - 1;
                }
            }
            else
            {
                putChar(str[i], column, row);
                column++;
                if (column >= WIDTH)
                {
                    column = 0;
                    row++;
                    if (row >= HEIGHT)
                    {
                        scroll();
                        row = HEIGHT - 1;
                    }
                }
            }
        }
    }

    void scroll()
    {
        for (int y = 1; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                const int sourceIndex = (y * WIDTH + x) * 2;
                const int destIndex = ((y - 1) * WIDTH + x) * 2;
                buffer[destIndex] = buffer[sourceIndex];
                buffer[destIndex + 1] = buffer[sourceIndex + 1];
            }
        }

        // Clear the last line
        for (int x = 0; x < WIDTH; x++)
        {
            putChar(' ', x, HEIGHT - 1);
        }
    }
}