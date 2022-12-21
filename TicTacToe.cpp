#include<iostream>
#include<cstdlib>
using namespace std;

///Made by Mihai Bucilă
///December 2020

bool GameOver=false;

char Table[31][31];
int x,round,winner,decision,mode;
char response,XorO;
int marked;
int game;
int score1,score2;
int scoreYou,scoreComputer;
char decision1;
int decision2;
char Nickname1[32]="Player#1",Nickname2[32]="Player#2";
char YourNickname[32]="You";

void MainMenu()
{
    GameOver=false;
    game=1;
    score1=score2=scoreComputer=scoreYou=0;
    system("cls");
    cout<<"               TicTacToe         "<<"\n";
    cout<<"               - game -        "<<"\n";
    cout<<"                                 "<<"\n";
    cout<<"1) Play"<<"\n";
    cout<<"2) Instructions"<<"\n";
    cout<<"3) Nickname"<<"\n";
    cout<<"4) Quit"<<"\n"<<"\n";
    cout<<"Choose a number: ";
    cin>>decision;
    if(decision==1)
    {
        system("cls");
        cout<<"               TicTacToe         "<<"\n";
        cout<<"               - game -        "<<"\n";
        cout<<"                                 "<<"\n";
        cout<<"Modes available"<<"\n"<<"\n";
        cout<<"1) 1 vs. 1 "<<"\n";
        cout<<"2) You vs. Computer "<<"\n"<<"\n";;
        cout<<"Choose a number: ";
        cin>>mode;
    }
}

void Score()
{
    if(mode==1)
    {
        cout<<"        Score       "<<"\n";
        cout<<"       Game #"<<game<<"\n";
        cout<<Nickname1<<" "<<score1<<" || "<<Nickname2<<" "<<score2<<"\n"<<"\n";
    }
    else
    {
        cout<<"          Score       "<<"\n";
        cout<<"         Game #"<<game<<"\n";
        cout<<YourNickname<<" "<<scoreYou<<" || "<<"Computer "<<scoreComputer<<"\n"<<"\n";
    }
}

void Draw()
{
    int i,j;
    for(i=1;i<=11;i++)
    {
        if(i==4 || i==8)
        {
            for(j=1;j<=25;j++)
                Table[i][j]='-';
            Table[i][8]='|';
            Table[i][17]='|';
            Table[i][j]=0;
        }
        else
        {
            for(j=1;j<=25;j++)
                Table[i][j]=' ';
            Table[i][8]='|';
            Table[i][17]='|';
            Table[i][j]=0;
        }
    }
    round=1;
}

void Display()
{
    if(decision==1)
        Score();
    int i,j;
    for(i=1;i<=11;i++)
    {
        for(j=1;j<=25;j++)
            cout<<Table[i][j];
        cout<<'\n';
    }
}

void Instructions()
{
    cout<<"There are two modes available for you: "<<"\n";
    cout<<"     - 1 vs. 1, perfect when you want to play with a friends"<<"\n";
    cout<<"     - You vs. Computer"<<"\n"<<"\n";
    Draw();
    Table[2][4]='1';
    Table[2][13]='2';
    Table[2][21]='3';
    Table[6][4]='4';
    Table[6][13]='5';
    Table[6][21]='6';
    Table[10][4]='7';
    Table[10][13]='8';
    Table[10][21]='9';
    Display();
    cout<<"You need to choose a number from 1 - 9 to mark the square you want"<<"\n";
    cout<<"Did you understand?"<<'('<<"Y/N"<<')'<<"\n";
    cin>>response;
}

void MarkForX()
{
    if(x==1 && Table[2][4]==' ')
        Table[2][4]='X',round++;
    if(x==2 && Table[2][13]==' ')
        Table[2][13]='X',round++;
    if(x==3 && Table[2][21]==' ')
        Table[2][21]='X',round++;
    if(x==4 && Table[6][4]==' ')
        Table[6][4]='X',round++;
    if(x==5 && Table[6][13]==' ')
        Table[6][13]='X',round++;
    if(x==6 && Table[6][21]==' ')
        Table[6][21]='X',round++;
    if(x==7 && Table[10][4]==' ')
        Table[10][4]='X',round++;
    if(x==8 && Table[10][13]==' ')
        Table[10][13]='X',round++;
    if(x==9 && Table[10][21]==' ')
        Table[10][21]='X',round++;
}

void MarkForO()
{
    if(x==1 && Table[2][4]==' ')
        Table[2][4]='O',round++;
    if(x==2 && Table[2][13]==' ')
        Table[2][13]='O',round++;
    if(x==3 && Table[2][21]==' ')
        Table[2][21]='O',round++;
    if(x==4 && Table[6][4]==' ')
        Table[6][4]='O',round++;
    if(x==5 && Table[6][13]==' ')
        Table[6][13]='O',round++;
    if(x==6 && Table[6][21]==' ')
        Table[6][21]='O',round++;
    if(x==7 && Table[10][4]==' ')
        Table[10][4]='O',round++;
    if(x==8 && Table[10][13]==' ')
        Table[10][13]='O',round++;
    if(x==9 && Table[10][21]==' ')
        Table[10][21]='O',round++;
}

void Verify()
{
    //// ROW CHECK ////
    if((Table[2][4]=='X' && Table[2][13]=='X' && Table[2][21]=='X') ||
        (Table[6][4]=='X' && Table[6][13]=='X' && Table[6][21]=='X') ||
        (Table[10][4]=='X' && Table[10][13]=='X' && Table[10][21]=='X'))
        {
            winner=1;
            GameOver=true;
            if(mode==1)
                score1++;
            else
            {
                if(XorO=='X')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }

    if((Table[2][4]=='O' && Table[2][13]=='O' && Table[2][21]=='O') ||
        (Table[6][4]=='O' && Table[6][13]=='O' && Table[6][21]=='O') ||
        (Table[10][4]=='O' && Table[10][13]=='O' && Table[10][21]=='O'))
         {
            winner=2;
            GameOver=true;
            if(mode==1)
                score2++;
            else
            {
                if(XorO=='O')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }

    //// COLUMN CHECK ////
    if((Table[2][4]=='X' && Table[6][4]=='X' && Table[10][4]=='X') ||
        (Table[2][13]=='X' && Table[6][13]=='X' && Table[10][13]=='X') ||
        (Table[2][21]=='X' && Table[6][21]=='X' && Table[10][21]=='X'))
        {
            winner=1;
            GameOver=true;
            if(mode==1)
                score1++;
            else
            {
                if(XorO=='X')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }
    if((Table[2][4]=='O' && Table[6][4]=='O' && Table[10][4]=='O') ||
        (Table[2][13]=='O' && Table[6][13]=='O' && Table[10][13]=='O') ||
        (Table[2][21]=='O' && Table[6][21]=='O' && Table[10][21]=='O'))
        {
            winner=2;
            GameOver=true;
            if(mode==1)
                score2++;
            else
            {
                if(XorO=='O')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }

    //// DIAGONAL CHECK ////
    if((Table[2][4]=='X' && Table[6][13]=='X' && Table[10][21]=='X') ||
        (Table[2][21]=='X' && Table[6][13]=='X' && Table[10][4]=='X'))
        {
            winner=1;
            GameOver=true;
            if(mode==1)
                score1++;
            else
            {
                if(XorO=='X')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }
    if((Table[2][4]=='O' && Table[6][13]=='O' && Table[10][21]=='O') ||
        (Table[2][21]=='O' && Table[6][13]=='O' && Table[10][4]=='O'))
         {
            winner=2;
            GameOver=true;
            if(mode==1)
                score2++;
            else
            {
                if(XorO=='O')
                    scoreYou++;
                else
                    scoreComputer++;
            }
        }
}

/*
    |      |
2 4 | 2 13 | 2 21
    |      |
-----------------
    |      |
6 4 | 6 13 | 6 21
    |      |
-----------------
    |      |
10 4| 10 13| 10 21
    |      |
*/

void MarkForWin()
{
    if(XorO=='X')
    {
        if(((Table[2][13]=='O' && Table[2][21]=='O') || (Table[6][4]=='O' && Table[10][4]=='O') || (Table[6][13]=='O' && Table[10][21]=='O')) && Table[2][4]==' ')
            Table[2][4]='O',marked=1;
        else if(((Table[2][4]=='O' && Table[2][21]=='O') || (Table[6][13]=='O' && Table[10][21]=='O')) && Table[2][13]==' ')
            Table[2][13]='O',marked=1;
        else if(((Table[2][4]=='O' && Table[2][13]=='O') || (Table[6][21]=='O' && Table[10][21]=='O') || (Table[6][13]=='O' && Table[10][4]=='O')) && Table[2][21]==' ')
            Table[2][21]='O',marked=1;
        else if(((Table[2][4]=='O' && Table[10][4]=='O') || (Table[6][13]=='O' && Table[6][21]=='O')) && Table[6][4]==' ')
            Table[6][4]='O',marked=1;
        else if(((Table[6][4]=='O' && Table[6][13]=='O') || (Table[2][21]=='O' && Table[10][21]=='O')) && Table[6][21]==' ')
            Table[6][21]='O',marked=1;
        else if(((Table[2][4]=='O' && Table[6][4]=='O') || (Table[10][13]=='O' && Table[10][21]=='O') || (Table[2][21]=='O' && Table[6][13]=='O')) && Table[10][4]==' ')
            Table[10][4]='O',marked=1;
        else if(((Table[10][4]=='O' && Table[10][21]=='O') || (Table[2][13]=='O' && Table[6][13]=='O')) && Table[10][13]==' ')
            Table[10][13]='O',marked=1;
        else if(((Table[10][4]=='O' && Table[10][13]=='O') || (Table[2][21]=='O' && Table[6][21]=='O') || (Table[2][4]=='O' && Table[6][13]=='O')) && Table[10][21]==' ')
            Table[10][21]='O',marked=1;
    }
    else
    {
        if(((Table[2][13]=='X' && Table[2][21]=='X') || (Table[6][4]=='X' && Table[10][4]=='X') || (Table[6][13]=='X' && Table[10][21]=='X')) && Table[2][4]==' ')
            Table[2][4]='X',marked=1;
        else if(((Table[2][4]=='X' && Table[2][21]=='X') || (Table[6][13]=='X' && Table[10][21]=='X')) && Table[2][13]==' ')
            Table[2][13]='X',marked=1;
        else if(((Table[2][4]=='X' && Table[2][13]=='X') || (Table[6][21]=='X' && Table[10][21]=='X') || (Table[6][13]=='X' && Table[10][4]=='X')) && Table[2][21]==' ')
            Table[2][21]='X',marked=1;
        else if(((Table[2][4]=='X' && Table[10][4]=='X') || (Table[6][13]=='X' && Table[6][21]=='X')) && Table[6][4]==' ')
            Table[6][4]='X',marked=1;
        else if(((Table[6][4]=='X' && Table[6][13]=='X') || (Table[2][21]=='X' && Table[10][21]=='X')) && Table[6][21]==' ')
            Table[6][21]='X',marked=1;
        else if(((Table[2][4]=='X' && Table[6][4]=='X') || (Table[10][13]=='X' && Table[10][21]=='X') || (Table[2][21]=='X' && Table[6][13]=='X')) && Table[10][4]==' ')
            Table[10][4]='X',marked=1;
        else if(((Table[10][4]=='X' && Table[10][21]=='X') || (Table[2][13]=='X' && Table[6][13]=='X')) && Table[10][13]==' ')
            Table[10][13]='X',marked=1;
        else if(((Table[10][4]=='X' && Table[10][13]=='X') || (Table[2][21]=='X' && Table[6][21]=='X') || (Table[2][4]=='X' && Table[6][13]=='X')) && Table[10][21]==' ')
            Table[10][21]='X',marked=1;

    }
}

void MarkForDefense()
{
    if(XorO=='X')
    {
        if(((Table[2][13]=='X' && Table[2][21]=='X') || (Table[6][4]=='X' && Table[10][4]=='X') || (Table[6][13]=='X' && Table[10][21]=='X')) && Table[2][4]==' ')
            Table[2][4]='O';
        else if(((Table[2][4]=='X' && Table[2][21]=='X') || (Table[6][13]=='X' && Table[10][21]=='X')) && Table[2][13]==' ')
            Table[2][13]='O';
        else if(((Table[2][4]=='X' && Table[2][13]=='X') || (Table[6][21]=='X' && Table[10][21]=='X') || (Table[6][13]=='X' && Table[10][4]=='X')) && Table[2][21]==' ')
            Table[2][21]='O';
        else if(((Table[2][4]=='X' && Table[10][4]=='X') || (Table[6][13]=='X' && Table[6][21]=='X')) && Table[6][4]==' ')
            Table[6][4]='O';
        else if(((Table[6][4]=='X' && Table[6][13]=='X') || (Table[2][21]=='X' && Table[10][21]=='X')) && Table[6][21]==' ')
            Table[6][21]='O';
        else if(((Table[2][4]=='X' && Table[6][4]=='X') || (Table[10][13]=='X' && Table[10][21]=='X') || (Table[2][21]=='X' && Table[6][13]=='X')) && Table[10][4]==' ')
            Table[10][4]='O';
        else if(((Table[10][4]=='X' && Table[10][21]=='X') || (Table[2][13]=='X' && Table[6][13]=='X')) && Table[10][13]==' ')
            Table[10][13]='O';
        else if(((Table[10][4]=='X' && Table[10][13]=='X') || (Table[2][21]=='X' && Table[6][21]=='X') || (Table[2][4]=='X' && Table[6][13]=='X')) && Table[10][21]==' ')
            Table[10][21]='O';
        else if(Table[2][4]==' ')
            Table[2][4]='O';
        else if(Table[2][13]==' ')
            Table[2][13]='O';
        else if(Table[2][21]==' ')
            Table[2][21]='O';
        else if(Table[6][4]==' ')
            Table[6][4]='O';
        else if(Table[6][13]==' ')
            Table[6][13]='O';
        else if(Table[6][21]==' ')
            Table[6][21]='O';
        else if(Table[10][4]==' ')
            Table[10][4]='O';
        else if(Table[10][13]==' ')
            Table[10][13]='O';
        else if(Table[10][21]==' ')
            Table[10][21]='O';
    }
    else
    {
        if(((Table[2][13]=='O' && Table[2][21]=='O') || (Table[6][4]=='O' && Table[10][4]=='O') || (Table[6][13]=='O' && Table[10][21]=='O')) && Table[2][4]==' ')
            Table[2][4]='X';
        else if(((Table[2][4]=='O' && Table[2][21]=='O') || (Table[6][13]=='O' && Table[10][21]=='O')) && Table[2][13]==' ')
            Table[2][13]='X';
        else if(((Table[2][4]=='O' && Table[2][13]=='O') || (Table[6][21]=='O' && Table[10][21]=='O') || (Table[6][13]=='O' && Table[10][4]=='O')) && Table[2][21]==' ')
            Table[2][21]='X';
        else if(((Table[2][4]=='O' && Table[10][4]=='O') || (Table[6][13]=='O' && Table[6][21]=='O')) && Table[6][4]==' ')
            Table[6][4]='X';
        else if(((Table[6][4]=='O' && Table[6][13]=='O') || (Table[2][21]=='O' && Table[10][21]=='O')) && Table[6][21]==' ')
            Table[6][21]='X';
        else if(((Table[2][4]=='O' && Table[6][4]=='O') || (Table[10][13]=='O' && Table[10][21]=='O') || (Table[2][21]=='O' && Table[6][13]=='O')) && Table[10][4]==' ')
            Table[10][4]='X';
        else if(((Table[10][4]=='O' && Table[10][21]=='O') || (Table[2][13]=='O' && Table[6][13]=='O')) && Table[10][13]==' ')
            Table[10][13]='X';
        else if(((Table[10][4]=='O' && Table[10][13]=='O') || (Table[2][21]=='O' && Table[6][21]=='O') || (Table[2][4]=='O' && Table[6][13]=='O')) && Table[10][21]==' ')
            Table[10][21]='X';
        else if(Table[2][4]==' ')
            Table[2][4]='X';
        else if(Table[2][13]==' ')
            Table[2][13]='X';
        else if(Table[2][21]==' ')
            Table[2][21]='X';
        else if(Table[6][4]==' ')
            Table[6][4]='X';
        else if(Table[6][13]==' ')
            Table[6][13]='X';
        else if(Table[6][21]==' ')
            Table[6][21]='X';
        else if(Table[10][4]==' ')
            Table[10][4]='X';
        else if(Table[10][13]==' ')
            Table[10][13]='X';
        else if(Table[10][21]==' ')
            Table[10][21]='X';
    }
}

void ComputerTurn()
{
    round++;
    marked=0;
    MarkForWin();
    if(!marked)
        MarkForDefense();
}

void Play1()
{
    round=1;
    GameOver=false;
    winner=0;
    system("cls");
    Draw();
    while(!GameOver)
    {
        Display();
        cout<<"\n";
        cout<<"Choose a number: "<<"\n";
        cin>>x;
        if(round%2)
        {
            if(game%2)
                MarkForX();
            else
                MarkForO();
        }
        else
        {
            if(game%2)
                MarkForO();
            else
                MarkForX();
        }
        Verify();
        system("cls");
        if(round>9)
            GameOver=true;
    }
    Display();
    game++;
    if(winner)
    {
        if(winner==1)
            cout<<Nickname1<<" won!"<<"\n";
        else
            cout<<Nickname2<<" won!"<<"\n";
    }
    else
        cout<<"No one won!"<<"\n";
    cout<<"Do you want to play again?"<<'('<<"Y/N"<<')'<<"\n";
    cin>>decision1;
}

void Play2()
{
    round=1;
    GameOver=false;
    winner=0;
    system("cls");
    Draw();
    while(!GameOver)
    {
        Display();
        if(round%2)
        {
            if(game%2)
            {
                cout<<"\n";
                cout<<"Choose a number: "<<"\n";
                cin>>x;
                if(XorO=='X')
                    MarkForX();
                if(XorO=='O')
                    MarkForO();
            }
            else
                ComputerTurn();
        }
        else
        {
            if(game%2)
                ComputerTurn();
            else
            {
                cout<<"\n";
                cout<<"Choose a number: "<<"\n";
                cin>>x;
                if(XorO=='X')
                    MarkForX();
                if(XorO=='O')
                    MarkForO();
            }
        }
        Verify();
        system("cls");
        if(round>9)
            GameOver=true;
        }
    Display();
    game++;
    if(winner)
    {
        if((winner==1 && XorO=='X') || (winner==2 && XorO=='O'))
            cout<<"You won!"<<"\n";
        else
            cout<<"Computer won!"<<"\n";
    }
    else
        cout<<"No one won!"<<"\n";
    cout<<"Do you want to play again?"<<'('<<"Y/N"<<')'<<"\n";
    cin>>decision1;
}

int main()
{
    MainMenu();
    if(decision==1)
    {
        if(mode==1)
        {
            decision1='Y';
            while(decision1=='Y')
            {
                Play1();
                system("cls");
            }
            main();
        }
        if(mode==2)
        {
            system("cls");
            cout<<"Type 'X' or 'O' to choose what to play with: "<<"\n";
            cin>>XorO;
            system("cls");
            decision1='Y';
            while(decision1=='Y')
            {
                Play2();
                system("cls");
            }
            main();
        }
    }
    else
    {
        if(decision==2)
        {
            system("cls");
            Instructions();
            if(response=='Y')
                main();
            else
                main();
        }
        else
        {
            if(decision==3)
            {
                system("cls");
                cout<<"If you want to play with 1 vs. 1 mode, enter '1' and then the nicknames."<<"\n";
                cout<<"If you want to play with You vs. Computer mode, enter '2' and then your nickname."<<"\n"<<"\n";
                cout<<"Choose a number: ";
                cin>>decision2;
                if(decision2==1)
                {
                    cout<<"Choose your nicknames: "<<"\n";
                    cin>>Nickname1>>Nickname2;
                }
                else
                {
                    cout<<"Choose your nickname: "<<"\n";
                    cin>>YourNickname;
                }
                main();
            }
            else
                system("cls");
        }

    }
    return 0;
}
