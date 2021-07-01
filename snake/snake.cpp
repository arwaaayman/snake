#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 30;
const int height = 20;
int w, h, score, fx, fy;       // fx= fruit x coordinate
enum  eDirection { STOP , LEFT, RIGHT, up, down };
eDirection dir;
int tailx[100], taily[100],ntail;
void setup()
{
    gameOver = false;
    dir = STOP;
    w = width / 2;
    h = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            
                cout << "|";
            if (i == h && j == w)
                cout << "O";
            else if (i == fy && j == fx)
                cout << "*";
            else
            {
                bool print = false;
                for (int z = 0; z < ntail; z++)
                {
                    if (tailx[z] == j && taily[z] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                
            if (j == width -1)
                cout << "|";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;
    cout << "score:" << score;
}
void input ()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a' :
        case '4':
       
            dir = LEFT;
            break;
        case 'd' :
        case '6':
            dir = RIGHT;
            break;
        case 'w':
        case '8':
            dir = up;
            break;
        case 's':
        case '2':
            dir = down;
            break;
         default:
            gameOver = true;
            break;
        }
    }
}
void concept ()
{
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X, prev2Y;
    tailx[0] = w;
    taily[0] = h;
    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        w--;
        break;
    case RIGHT:
        w++;
        break;
    case up:
        h--;
        break;
    case down:
        h++;
        break;
    default:
        break;
    }
    if (w >= width)
        w = 0;
    else if (w < 0)
        w= width - 1;
    if (h >= height)
        h = 0;
    else if (h < 0) 
        h = height - 1;
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == w && taily[i] == h)
            gameOver = true;
    if (w == fx && h == fy)
    {
        score += 5;
        fx = rand() % width;
        fy = rand() % height;
        ntail++;
    }

}
int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        concept();
        Sleep(20);
    }
    return 0;
}


