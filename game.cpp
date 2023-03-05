#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

/*BASIC FUNCTIONS*/
void print();
void printHeader();
void printMaze();
void gotoxy(int x, int y);
char getCharATXY(short int x, short int y);
void addScore();
void minusScore();
void printHeader();
int menu();
int inst();
void win();
void loss();
void setColor(int color);
void showScore();
/*PLAYERS FUNCTIONS*/
void printHero(int x, int y);
void eraseHero(int x, int y);
void heroLeft();
void heroRight();
void heroDown();
void heroUp();
void printBullet(int x, int y);
void generateBullet();
void moveBullet();
void removeBullet(int x);
void eraseBullet(int x, int y);

/*SCOUT 1 FUNCTIONS*/
void printScout(int x, int y);
void eraseScout(int x, int y);
void scou1MovementLeft();
void scou1MovementUp();
void scout1MovementRight();
void scout1Bullet(int x, int y);
void scout1BulletRemove(int x, int y);
void generateScout1Bullet();
void moveScoutBullet();
void removeBulletScout(int x);
void generateScout1Bullet();

/*SCOUT 2 FUNCTIONS*/
void printScout2(int x, int y);
void scou2MovementLeft();
void scou2MovementDown();
void scou2MovementRight();
void eraseScout2(int x, int y);
void scout2Bullet(int x, int y);
void scout2BulletRemove(int x, int y);
void generateScout2Bullet();
void moveScout2Bullet();
void removeBulletScout2(int x);
void generateScout2Bullet();

/*FAT BOY FUNCTIONS*/
void printBoy(int x, int y);
void removeBoy(int x, int y);
void moveBoy();
void moveBoyDown();
void boyBullet(int x, int y);
void boyBulletRemove(int x, int y);
void removeBulletBoy(int x);
void generateBoyBullet();
void moveBoyBullet();

/*COLLOSION CHECK*/
void collosion();
void collosion2();
void enemyCollosion();
void enemyCollosion2();
void enemyCollosion3();

bool check();
bool check2();

/*VARIABLES*/
int option = 0;

int hx = 28;
int hy = 10;

int sx = 140;
int sy = 20;

int s2x = 140;
int s2y = 5;

int fx = 140;
int fy = 10;

int bx[100];
int by[100];
int bulletCount = 0;

int scoutBulletX[100];
int scoutBulletY[100];
int scoutBulletCount = 0;
int score = 0;
int enemyScore = 50;
int count = 0;

int scout2BulletX[100];
int scout2BulletY[100];
int scout2BulletCount = 0;

int boyBulletX[100];
int boyBulletY[100];
int boyBulletCount = 0;

int timer = 0;
int timer2 = 0;
int timer3 = 0;

int count1 = 0;
int count2 = 0;
int count3 = 0;

string direction = "left";
string direction2 = "left";
string direction3 = "up";
char previousChar = ' ';
bool gameRunning = true;
bool flag1 = false;
bool flag2 = false;

bool scout1Active = true;
bool scout2Active = true;
main()
{

op:
    system("cls");
    print();
    getch();
    system("cls");
    printHeader();

    int op = menu();

    while (op != 3)
    {

        if (op == 1)
        {
            system("cls");
            printMaze();
            // printScore();
            printScout(sx, sy);
            printScout2(s2x, s2y);

            while (gameRunning == true)
            {
                showScore();

                /*SCOUT1 MOVEMENTS*/
                if (scout1Active == true)
                {
                    if (direction == "left")
                    {
                        scou1MovementLeft();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();

                    if (direction == "up")
                    {
                        scou1MovementUp();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();
                    if (direction == "right")
                    {
                        scout1MovementRight();
                        if (timer3 == 6)
                        {
                            generateScout1Bullet();
                            timer3 = 0;
                        }
                    }
                    moveScoutBullet();
                    timer3++;
                }

                /*SCOUT 2 MOVEMENTS*/
                if (scout2Active == true)
                {
                    if (direction2 == "left")
                    {
                        scou2MovementLeft();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    if (direction2 == "down")
                    {
                        scou2MovementDown();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    if (direction2 == "right")
                    {
                        scou2MovementRight();
                        if (timer2 == 6)
                        {
                            generateScout2Bullet();
                            timer2 = 0;
                        }
                    }
                    moveScout2Bullet();
                    timer2++;
                }

                if (scout1Active == false && scout2Active == false)
                {
                    printBoy(fx, fy);
                    if (direction3 == "up")
                    {
                        moveBoy();
                    }

                    if (direction3 == "down")
                    {
                        moveBoyDown();
                    }
                    if (timer3 == 6)
                    {
                        generateBoyBullet();
                        timer3 = 0;
                    }
                    timer3++;

                    moveBoyBullet();
                }

                /*PLAYER MOVEMENTS*/

                if (GetAsyncKeyState(VK_LEFT))
                {
                    heroLeft();
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    heroRight();
                }

                if (GetAsyncKeyState(VK_DOWN))
                {
                    heroDown();
                }

                if (GetAsyncKeyState(VK_UP))
                {
                    heroUp();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet();
                }
                moveBullet();

                /*COLLOSION CHECKS*/
                collosion();
                collosion2();
                enemyCollosion2();
                enemyCollosion();
                enemyCollosion3();
                Sleep(50);

                if (check() == true && check2() != true)
                {
                    flag1 = true;
                }
                else if (check() != true && check2() == true)
                {
                    flag2 = true;
                }

                if (flag1 == true)
                {
                    system("cls");
                    win();
                    Sleep(1000);
                    goto op;
                }
                else if (flag2 == true)
                {
                    system("cls");
                    loss();
                    Sleep(1000);
                    goto op;
                }
            }
        }

        else if (op == 2)
        {
            system("cls");
            printHeader();
            inst();
            goto op;
        }
    }
}

/*FUNCTIONS*/

void moveBoyBullet()
{
    for (int i = 0; i < boyBulletCount; i++)
    {
        char nextLocation = getCharATXY(boyBulletX[i] - 2, boyBulletY[i]);
        if (nextLocation != ' ')
        {
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            removeBulletBoy(i);
        }
        else
        {
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            boyBulletX[i] = boyBulletX[i] - 2;
            boyBullet(boyBulletX[i], boyBulletY[i]);
        }
    }
}

void generateBoyBullet()
{
    boyBulletX[boyBulletCount] = fx - 2;
    boyBulletY[boyBulletCount] = fy;

    boyBulletCount++;
}

void removeBulletBoy(int x)
{
    for (int i = x; i < boyBulletCount - 1; i++)
    {
        boyBulletX[i] = boyBulletX[i + 1];
        boyBulletY[i] = boyBulletY[i + 1];
    }
    boyBulletCount--;
}

void boyBulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

void boyBullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "0" << endl;
}

void moveBoy()
{
    char nextLocation = getCharATXY(fx - 5, fy + 5);
    if (nextLocation == ' ')
    {
        removeBoy(fx, fy);
        fy = fy + 1;
        printBoy(fx, fy);
    }
    else if (nextLocation == '#')
    {
        cout << "yes";
        direction3 = "down";
    }
}
void moveBoyDown()
{

    char nextLocation = getCharATXY(fx - 2, fy - 5);
    if (nextLocation == ' ')
    {
        removeBoy(fx, fy);
        fy = fy - 1;
        printBoy(fx, fy);
    }
    else if (nextLocation == '#')
    {
        direction3 = "up";
    }
}

void removeBoy(int x, int y)
{
    gotoxy(x, y);
    cout << "\t  "
         << " ";
    gotoxy(x, y + 1);
    cout << " "
         << " "
         << " ";
    for (int i = 0; i < 10; i++)
    {
        cout << " ";
    }
    cout << " ";

    gotoxy(x, y + 2);
    cout << " "
         << " "
         << " ";
    for (int i = 0; i < 10; i++)
    {
        cout << " ";
    }
    cout << " ";
    gotoxy(x, y + 3);
    cout << "\t  "
         << " ";
}

void printBoy(int x, int y)
{
    setColor(4);
    char box = 219;
    char line = 205;
    char tail = 185;
    char up = 244;
    char down = 245;
    gotoxy(x, y);
    cout << "\t  " << up;
    gotoxy(x, y + 1);
    cout  << line << line << line;
    for (int i = 0; i < 10; i++)
    {
        cout  << box;
    }
    cout  << tail;

    gotoxy(x, y + 2);
    cout  << line << line << line;
    for (int i = 0; i < 10; i++)
    {
        cout  << box;
    }
    cout  << tail;
    gotoxy(x, y + 3);
    cout << "\t  " << down;
    setColor(7);
}

void moveScout2Bullet()
{
    for (int i = 0; i < scout2BulletCount; i++)
    {
        char nextLocation = getCharATXY(scout2BulletX[i] - 1, scout2BulletY[i]);
        if (nextLocation != ' ')
        {
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            removeBulletScout2(i);
        }
        else
        {
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            scout2BulletX[i] = scout2BulletX[i] - 1;
            scout2Bullet(scout2BulletX[i], scout2BulletY[i]);
        }
    }
}

void generateScout2Bullet()
{
    scout2BulletX[scout2BulletCount] = s2x - 1;
    scout2BulletY[scout2BulletCount] = s2y;

    scout2BulletCount++;
}

void removeBulletScout2(int x)
{
    for (int i = x; i < scout2BulletCount - 1; i++)
    {
        scout2BulletX[i] = scout2BulletX[i + 1];
        scout2BulletY[i] = scout2BulletY[i + 1];
    }
    scout2BulletCount--;
}

void scout2BulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

void scout2Bullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "." << endl;
}

void moveScoutBullet()
{
    for (int i = 0; i < scoutBulletCount; i++)
    {
        char nextLocation = getCharATXY(scoutBulletX[i] - 1, scoutBulletY[i]);
        if (nextLocation != ' ')
        {
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            removeBulletScout(i);
        }
        else if (nextLocation == ' ' || nextLocation == '<')
        {
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            scoutBulletX[i] = scoutBulletX[i] - 1;
            scout1Bullet(scoutBulletX[i], scoutBulletY[i]);
        }
    }
}

void generateScout1Bullet()
{
    scoutBulletX[scoutBulletCount] = sx - 1;
    scoutBulletY[scoutBulletCount] = sy;

    scoutBulletCount++;
}

void removeBulletScout(int x)
{
    for (int i = x; i < scoutBulletCount - 1; i++)
    {
        scoutBulletX[i] = scoutBulletX[i + 1];
        scoutBulletY[i] = scoutBulletY[i + 1];
    }
    scoutBulletCount--;
}

void scout1BulletRemove(int x, int y)
{
    gotoxy(x, y + 1);
    cout << " " << endl;
}

void scout1Bullet(int x, int y)
{
    gotoxy(x, y + 1);
    cout << "*" << endl;
}

void eraseScout2(int x, int y)
{
    gotoxy(x, y);
    cout << "                  ";
    gotoxy(x, y + 1);
    cout << "                   ";
    gotoxy(x, y + 2);
    cout << "                  " << endl;
    gotoxy(x, y + 3);
}

void printScout2(int x, int y)
{
    setColor(1);
    gotoxy(x, y);
    cout << "       *   ***";
    gotoxy(x, y + 1);
    cout << "     *** *****";
    gotoxy(x, y + 2);
    cout << "       *   ***" << endl;
    gotoxy(x, y + 3);
    cout << "              " << endl;
    setColor(7);
}

void scou2MovementRight()
{
    char nextLocation = getCharATXY(s2x - 5, s2y + 4);
    if (nextLocation == '|')
    {
        eraseScout(s2x, s2y);
        s2x = s2x + 1;
        printScout(s2x, s2y);
    }
    else if (nextLocation == ' ')
    {
        eraseScout(s2x, s2y);
        s2x = s2x - 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

void scou2MovementDown()
{
    char nextLocation = getCharATXY(s2x - 5, s2y + 3);

    if (s2y == 18)
    {
        direction2 = "right";
    }

    else if (nextLocation == ' ')
    {
        eraseScout(s2x, s2y);
        s2y = s2y + 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

void scou2MovementLeft()
{
    char nextLocation = getCharATXY(s2x - 5, s2y);
    if (nextLocation == '|')
    {
        direction2 = "right";
    }
    else if (s2x == 100)
    {
        direction2 = "down";
    }
    else if (nextLocation == ' ')
    {
        eraseScout(s2x, s2y);
        s2x = s2x - 1;
        previousChar = nextLocation;
        printScout2(s2x, s2y);
    }
}

void scout1MovementRight()
{
    char nextLocation = getCharATXY(sx - 5, sy + 4);
    if (nextLocation == '|')
    {
        direction = "left";
    }
    else if (nextLocation == ' ')
    {
        eraseScout(sx, sy);
        sx = sx - 1;
        previousChar = nextLocation;
        printScout2(sx, sy);
    }
}

void scou1MovementUp()
{
    char nextLocation = getCharATXY(sx - 5, sy + 3);

    if (sy == 5)
    {
        direction = "right";
    }

    else if (nextLocation == ' ')
    {
        eraseScout(sx, sy);
        sy = sy - 1;
        previousChar = nextLocation;
        printScout2(sx, sy);
    }
}

void scou1MovementLeft()
{
    char nextLocation = getCharATXY(sx - 5, sy);
    if (nextLocation == '|')
    {
        direction = "right";
    }
    else if (s2x == 120)
    {
        direction = "up";
    }
    else if (nextLocation == ' ')
    {
        eraseScout(sx, sy);
        sx = sx - 1;
        previousChar = nextLocation;
        printScout(sx, sy);
    }
}

void eraseScout(int x, int y)
{
    gotoxy(x, y);
    cout << "                  ";
    gotoxy(x, y + 1);
    cout << "                   ";
    gotoxy(x, y + 2);
    cout << "                  " << endl;
    gotoxy(x, y + 3);
    cout << "                  " << endl;
}

void printScout(int x, int y)
{
    setColor(1);
    gotoxy(x, y);
    cout << "       *   ***";
    gotoxy(x, y + 1);
    cout << "     *** *****";
    gotoxy(x, y + 2);
    cout << "       *   ***" << endl;
    gotoxy(x, y + 3);
    cout << "              " << endl;
    setColor(7);
}

void generateBullet()
{
    bx[bulletCount] = hx + 20;
    by[bulletCount] = hy;
    gotoxy(hx + 20, hy);
    cout << "-";
    bulletCount++;
}

void removeBullet(int x)
{
    for (int i = x; i < bulletCount - 1; i++)
    {
        bx[i] = bx[i + 1];
        by[i] = by[i + 1];
    }
    bulletCount--;
}

void moveBullet()
{
    for (int i = 0; i < bulletCount; i++)
    {
        char nextLocation = getCharATXY(bx[i] + 1, by[i] + 1);
        if (nextLocation != ' ')
        {
            eraseBullet(bx[i], by[i]);
            removeBullet(i);
        }
        else
        {
            eraseBullet(bx[i], by[i]);
            bx[i] = bx[i] + 1;
            printBullet(bx[i], by[i]);
        }
    }
}
void collosion()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == sx || bx[i] + 1 == sx + 2 || bx[i] + 3 == sx) && (by[i] == sy || by[i] == sy + 1 || by[i] == sy + 2 || by[i] == sy + 3))
        {
            if (scout1Active == true)
            {
                addScore();
                eraseBullet(bx[i], by[i]);
                removeBullet(i);
            }
            count1 = count1 + 1;
            if (count1 == 10)
            {
                scout1Active = false;
                eraseScout(sx, sy);

                count = count;
            }
        }
    }
}

void collosion2()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == s2x || bx[i] + 1 == s2x + 2 || bx[i] + 3 == s2x) && (by[i] == s2y || by[i] == s2y + 1 || by[i] == s2y + 2 || by[i] == s2y + 3))
        {
            if (scout2Active == true)
            {
                addScore();
                eraseBullet(bx[i], by[i]);
                removeBullet(i);
                count2++;
            }
            if (count2 == 10)
            {
                scout2Active = false;
                eraseScout2(s2x, s2y);
                count = count;
            }
        }
    }
}

void collosion3()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if ((bx[i] + 1 == fx || bx[i] + 2 == fx - 1 || bx[i] + 3 == fx - 2 || bx[i] + 1 == fx - 3) && (by[i] == fy || by[i] == fy + 1 || by[i] == fy + 2 || by[i] == fy + 3 || by[i] == fy + 4 || by[i] == fy + 5))
        {

            addScore();
            eraseBullet(bx[i], by[i]);
            removeBullet(i);
            count3++;
        }
    }
}

void enemyCollosion()
{
    for (int i = 0; i < scoutBulletCount; i++)
    {
        if ((scoutBulletX[i] + 1 == hx + 5 || scoutBulletX[i] + 1 == hx + 8 || scoutBulletX[i] + 1 == hx + 9) &&
            (scoutBulletY[i] + 1 == hy + 3 || scoutBulletY[i] + 1 == hy + 2 || scoutBulletY[i] + 1 == hy + 1 || scoutBulletY[i] + 1 == hy || scoutBulletY[i] + 1 == hy - 1 || scoutBulletY[i] + 1 == hy - 2 || scoutBulletY[i] + 1 == hy - 3))
        {
            minusScore();
            scout1BulletRemove(scoutBulletX[i], scoutBulletY[i]);
            removeBulletScout(i);
        }
    }
}

void enemyCollosion2()
{
    for (int i = 0; i < scout2BulletCount; i++)
    {
        if ((scout2BulletX[i] + 1 == hx + 5 || scout2BulletX[i] + 1 == hx + 8 || scout2BulletX[i] + 1 == hx + 9) &&
            (scout2BulletY[i] + 1 == hy + 3 || scout2BulletY[i] + 1 == hy + 2 || scout2BulletY[i] + 1 == hy + 1 || scout2BulletY[i] + 1 == hy || scout2BulletY[i] + 1 == hy - 1 || scout2BulletY[i] + 1 == hy - 2 || scout2BulletY[i] + 1 == hy - 3))
        {
            minusScore();
            scout2BulletRemove(scout2BulletX[i], scout2BulletY[i]);
            removeBulletScout2(i);
        }
    }
}

void enemyCollosion3()
{
    for (int i = 0; i < boyBulletCount; i++)
    {
        if ((boyBulletX[i] + 1 == hx + 5 || boyBulletX[i] + 1 == hx + 8 || boyBulletX[i] + 1 == hx + 9 || boyBulletX[i] + 1 == hx + 7) &&
            (boyBulletY[i] + 1 == hy + 3 || boyBulletY[i] + 1 == hy + 2 || boyBulletY[i] + 1 == hy + 1 || boyBulletY[i] + 1 == hy || boyBulletY[i] + 1 == hy - 1 || boyBulletY[i] + 1 == hy - 2 || boyBulletY[i] + 1 == hy - 3))
        {
            minusScore();
            boyBulletRemove(boyBulletX[i], boyBulletY[i]);
            removeBulletBoy(i);
        }
    }
}

bool check()
{
    if (score >= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check2()
{
    if (enemyScore <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void addScore()
{
    
    score = score + 2;
}
void minusScore()
{
    enemyScore = enemyScore - 5;
}
void printScore()
{
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

void heroUp()
{
    char nextLocation = getCharATXY(hx, hy - 4);
    if ((nextLocation == ' '))
    {
        eraseHero(hx, hy);
        hy = hy - 1;
        printHero(hx, hy);
    }
}

void heroDown()
{
    char nextLocation = getCharATXY(hx, hy + 2);
    if ((nextLocation == ' '))
    {
        eraseHero(hx, hy);
        hy = hy + 1;
        printHero(hx, hy);
    }
}
void heroRight()
{
    char nextLocation = getCharATXY(hx + 20, hy);
    if (nextLocation == ' ' || nextLocation == '-')
    {
        eraseHero(hx, hy);
        hx = hx + 1;
        printHero(hx, hy);
    }
}
void heroLeft()
{
    char nextLocation = getCharATXY(hx - 1, hy);
    if (nextLocation == ' ')
    {
        eraseHero(hx, hy);
        hx = hx - 1;
        printHero(hx, hy);
    }
}

void eraseHero(int x, int y)
{
    cout << endl;
    gotoxy(x + 1, y - 3);
    cout << "           " << endl;
    gotoxy(x + 1, y - 2);
    cout << "    ";

    cout << endl;
    gotoxy(x + 1, y - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << " ";
    }
    cout << "         ";

    cout << endl;
    gotoxy(x + 1, y);
    for (int i = 0; i < 10; i++)
    {
        cout << " ";
    }

    cout << "         ";
    cout << endl;
    gotoxy(x + 1, y + 1);
    cout << "    ";
    cout << "       " << endl;
}

void printHero(int x, int y)
{
    setColor(2);
    char box = 219;
    char box2 = 221;

    cout << endl;
    gotoxy(x + 1, y - 3);
    cout << "    _______" << endl;
    gotoxy(x + 1, y - 2);
    cout << "   |";

    cout << endl;
    gotoxy(x + 1, y - 1);
    for (int i = 0; i < 10; i++)
    {
        cout  << box;

    }
    cout  << "-------->";
    

    cout << endl;
    gotoxy(x + 1, y);
    for (int i = 0; i < 10; i++)
    {
        cout  << box;
        
    }

    cout << "-------->" ;
    
    cout << endl;
    gotoxy(x + 1, y + 1);
    cout << "   |";
    cout  << "_______" << endl;
    setColor(7);
    
}

void printMaze()
{
    setColor(5);

    cout  << "\t\t################################################################################################################################################" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t|                                                                                                                                                |" << endl;
    cout  << "\t\t################################################################################################################################################" << endl;
    setColor(7);

}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharATXY(short int x, short int y)
{

    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void printHeader()
{
    setColor(1);
        cout << " .d8888b.         d8888 888             d8888  .d8888b.  88888888888 8888888  .d8888b." << endl;
        cout<< "d88P  Y88b       d88888 888            d88888 d88P  Y88b     888       888   d88P  Y88b" << endl;
        cout<< "888    888      d88P888 888           d88P888 888    888     888       888   888    888" << endl;
        cout<< "888            d88P 888 888          d88P 888 888            888       888   888       " << endl;
        cout<< "888  88888    d88P  888 888         d88P  888 888            888       888   888       " << endl;
        cout<< "888    888   d88P   888 888        d88P   888 888    888     888       888   888    888" << endl;
        cout<< "Y88b  d88P  d8888888888 888       d8888888888 Y88b  d88P     888       888   Y88b  d88P " << endl;
        cout<< "Y8888P88  d88P     888 88888888 d88P     888   Y8888P       888     8888888   Y8888P" << endl;
        cout << endl << endl;

        cout<< "888       888        d8888 8888888b.  8888888888P  .d88888b.  888b    888 8888888888 " << endl;
        cout<< "888   o   888       d88888 888   Y88b       d88P  d88P"   "Y88b 8888b   888 888        "<< endl;
        cout<< "888  d8b  888      d88P888 888    888      d88P   888     888 88888b  888 888        " << endl;
        cout<< "888 d888b 888     d88P 888 888   d88P     d88P    888     888 888Y88b 888 8888888    " << endl;
        cout<< "888d88888b888    d88P  888 8888888P      d88P     888     888 888 Y88b888 888        " << endl;
        cout<< "88888P Y88888   d88P   888 888 T88b     d88P      888     888 888  Y88888 888        " << endl;
        cout<< "8888P   Y8888  d8888888888 888  T88b   d88P       Y88b. .d88P 888   Y8888 888        " << endl;
        cout<< "888P     Y888 d88P     888 888   T88b d8888888888   Y88888P   888    Y888 8888888888 " << endl;
    setColor(7);
}

int menu()
{

    cout << endl<< endl;
    cout << "\t1.PLAY GAME" << endl;
    cout << "\t2.INSTRUCTIONS" << endl;
    cout << "\t3.EXIT" << endl;
    cout << "Enter your option: ";
    cin >> option;
    cout << endl;
    return option;
}

int inst()
{

    cout << "\tArrow Up = MOVE UP" << endl;
    cout << "\tArrow Down  = MOVE DOWN" << endl;
    cout << "\tLeft arrow = MOVE LEFT" << endl;
    cout << "\tRight arrow = MOVE RIGHT" << endl;
    cout << "RULES:" << endl;
    cout << "\tAvoid enemy bullets and shoot them" << endl;
    cout << "\tFor every bullet you hit the enemy you will get 1 score" << endl;
    cout << "\tIf the enemy bullet hits you their score will be incremented" << endl;
    cout << "\tTake your score to 30 to win the game" << endl;
    cout << "\tIF enemy score gets then 25 game will be over" << endl;
    cout << "\t\t\tBEST OF LUCK" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;

    getch();
}

void win()
{
    cout << "CONGRAGULATIONS!!! YOU WON" << endl;
}

void loss()
{
    cout << "YOU LOST!!";
}

void print()
{
    
        setColor(2);
        cout << "                                        -+" << endl;
        cout << "                                       -#*+" << endl;
        cout << "                                     -.%+=%:-" << endl;
        cout << "                                     **%+=###:" << endl;
        cout << "                                     #%*==*%%:" << endl;
        cout << "                                     %%*==+%%:" << endl;
        cout << "                                   -##+**+**+ " << endl;
        cout << "                                    ####%%###%:" << endl;
        cout << "                                    .=##%%#**. " << endl;
        cout << "                             :.   ==.-#%###%* =+.   :.  " << endl;
        cout << "                         +=-++=. =%%#*%#*%#%#*%## .:*+=-+: " << endl;
        cout << "                      . :####++*##%#*%%***+%%*#%###++#*##=   " << endl;
        cout << "                    :.+=+#*+==:. .##*%#=*%=*%##%: .:-+=*#*+=-:. " << endl;
        cout << "                    *+*#+=+=+**##*%##%#=*#+*%##%*#%*#+=+=+#**+:  " << endl;
        cout << "                  :=#%@%+=-:..  .-##+%#+#***%**%-:  ..:-=+#%@#*-  " << endl;
        cout << "                 .%#*=-.          ##+%%*#%*#%**%          .:=+#%-  " << endl;
        cout << "                  .              =##-#%+%%+##=+#*               .     " << endl;
        cout << "                                 :::-#+%##%+#+.-:                   " << endl;
        cout << "                                    :*%######-                      " << endl;
        cout << "                                   .-*+*##%=%-:                     " << endl;
        cout << "                                   : . .::: . :                     " << endl;
        setColor(7);
    
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void showScore()
{
    gotoxy(1, 1);
    cout << "score: " << score << " ";
    gotoxy(1, 2);
    cout << "Health: " << enemyScore << " ";

}