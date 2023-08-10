#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int i,j,k,x[4][4],score,highscore,y[4][4],line,column;
const int dim=4;
char control;
bool gameOver,test,winCondition;
void controls()
{
    cout<<"New Game - n\nQuit - q\n\nUp - w\nDown - s\nLeft - a\nRight - d\n\nScore - "<<score<<"\nHighscore - "<<highscore<<"\n\n";
}
int digits(int a)
{
    int s=0;
    while (a)
    {
        s++;
        a/=10;
    }
    return s;
}
void generateNewPosition()
{
    srand(time(0));
    line=rand()%4;
    column=rand()%4;
    while (x[line][column])
    {
        line=rand()%4;
        column=rand()%4;
    }
    if (rand()%100<90)
        x[line][column]=2;
    else
        x[line][column]=4;
}

void gameOverInstructions()
{
    if (score>highscore)
    {
        cout<<"New highscore - "<<score;
        highscore=score;
    }
    else
        cout<<"Score - "<<score;
    score=0;
    gameOver=1;
}
void newGame()
{
    for (i=0; i<dim; i++)
        for (j=0; j<dim; j++)
            x[i][j]=0;
    generateNewPosition();
    generateNewPosition();
}
void game()
{
    for (i=0; i<dim; i++)
    {
        for (j=0; j<dim; j++)
        {
            if (x[i][j])
            {
                switch (digits(x[i][j]))
                {
                case 1:
                    cout<<x[i][j]<<"    ";
                    break;
                case 2:
                    cout<<x[i][j]<<"   ";
                    break;
                case 3:
                    cout<<x[i][j]<<"  ";
                    break;
                case 4:
                    cout<<x[i][j]<<" ";
                    break;
                }
            }
            else
                cout<<".    ";
        }
        cout<<"\n\n";
    }
}
void gameCopy()
{
    for (i=0; i<dim; i++)
        for (j=0; j<dim; j++)
        {
            y[i][j]=x[i][j];
            if (x[i][j]==2048)
                winCondition=1;
        }
}
void gameTest()
{
    for (i=0; i<dim&&!test; i++)
        for (j=0; j<dim; j++)
            if (y[i][j]!=x[i][j])
            {
                test=1;
                break;
            }
}
void upLoop()
{
    for (j=0; j<dim; j++)
        for (i=1; i<dim; i++)
            if (x[i][j])
                for (k=0; k<i; k++)
                {
                    if (x[k][j]==0)
                    {
                        swap (x[k][j],x[i][j]);
                        break;
                    }
                }
}
void downLoop()
{
    for (j=0; j<dim; j++)
        for (i=dim-2; i>=0; i--)
            if (x[i][j])
                for (k=dim-1; k>i; k--)
                    if (x[k][j]==0)
                    {
                        swap (x[k][j],x[i][j]);
                        break;
                    }
}
void leftLoop()
{
    for (i=0; i<dim; i++)
        for (j=1; j<dim; j++)
            if (x[i][j])
                for (k=0; k<j; k++)
                    if (x[i][k]==0)
                    {
                        swap (x[i][k],x[i][j]);
                        break;
                    }
}
void rightLoop()
{
    for (i=0; i<dim; i++)
        for (j=dim-2; j>=0; j--)
            if (x[i][j])
                for (k=dim-1; k>j; k--)
                    if (x[i][k]==0)
                    {
                        swap (x[i][k],x[i][j]);
                        break;
                    }
}
void up()
{
    upLoop();
    for (j=0; j<dim; j++)
        for (i=1; i<dim; i++)
            if (x[i][j]==x[i-1][j]&&x[i-1][j])
            {
                x[i-1][j]*=2;
                score+=x[i-1][j];
                x[i][j]=0;
            }
    upLoop();
}
void down()
{
    downLoop();
    for (j=0; j<dim; j++)
        for (i=dim-2; i>=0; i--)
            if (x[i][j]==x[i+1][j]&&x[i+1][j])
            {
                x[i+1][j]*=2;
                score+=x[i+1][j];
                x[i][j]=0;
            }
    downLoop();
}
void left()
{
    leftLoop();
    for (i=0; i<dim; i++)
        for (j=1; j<dim; j++)
            if (x[i][j]==x[i][j-1]&&x[i][j-1])
            {
                x[i][j-1]*=2;
                score+=x[i][j-1];
                x[i][j]=0;
            }
    leftLoop();
}
void right()
{
    rightLoop();
    for (i=0; i<dim; i++)
        for (j=dim-2; j>=0; j--)
            if (x[i][j]==x[i][j+1]&&x[i][j+1])
            {
                x[i][j+1]*=2;
                score+=x[i][j+1];
                x[i][j]=0;
            }
    rightLoop();
}
int main()
{
    newGame();
    while (1)
    {
        if (!gameOver)
        {
            system("cls");
            controls();
            game();
        }
        else
        {
            Sleep(2000);
            gameOver=0;
            newGame();
            continue;
        }
        gameCopy();
        test=0;
        switch (getch())
        {
        case 'q':
            return 0;
        case 'n':
            newGame();
            continue;
        case 'w':
            up();
            break;
        case 's':
            down();
            break;
        case 'a':
            left();
            break;
        case 'd':
            right();
            break;
        }
        gameTest();
        if (test)
            generateNewPosition();
        else
        {
            bool f=0;
            for (i=0; i<dim&&!f; i++)
                for (j=0; j<dim; j++)
                {
                    int pos=x[i][j];
                    if (!pos||(pos==x[i+1][j]&&i+1<dim)||(pos==x[i-1][j]&&i-1>=0)||(pos==x[i][j+1]&&j+1<dim)||(pos==x[i][j-1]&&j-1>=0))
                    {
                        f=1;
                        break;
                    }
                }
            if (!f)
            {
                cout<<"\nGame Over!\n";
                gameOverInstructions();
                continue;
            }
        }
        if (winCondition)
        {
            winCondition=0;
            cout<<"\nYon won!\n";
            gameOverInstructions();
        }
    }
    return 0;
}
