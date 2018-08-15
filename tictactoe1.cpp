#include <iostream>
#include<stdlib.h>

using namespace std;

//X is 5
//O is 3
//blank is 2
int vector[9];

void initialise_vector();
void Go(int box, int sym);
int is_blank(int box);
void disp_matrix();
int Posswin(int sym);
int Make2();
void move(int turn);
void win();

int main()
{
    char c;
    cout<<"\n Human versus AI Tic Tac Toe ";
    cout<<"\n The current board is \n";
    disp_matrix();

    cout<<"\n Do you want to make the first move ? (Y/N) \n";
    cin>>c;
    int t=1;
    if(c=='y' || c=='Y')
    {
        cout<<"\n You will be playing against AI as X ";
        initialise_vector();
        while(t<=9)
        {
            if(t%2==0)
            {
                cout<<"\n AI's turn \n";
                move(t);
                disp_matrix();
            }
            else
            {
                int box;
                cout<<"\n Your turn ";
                cout<<"\n Enter the box number ";
                cin>>box;
                if(is_blank(box)!=1)
                {
                    cout<<"\n Invalid move. Please enter a valid box number ";
                    cin>>box;
                }
                Go(box,5);
                disp_matrix();
            }
            t++;
            win();
        }
        if(t>9)
            cout<<"\n Game Draw ";
    }
    else
    {
        cout<<"\n You will be playing against AI as X ";
        initialise_vector();
        while(t<=9)
        {
            if(t%2==0)
            {
                int box;
                cout<<"\n Your turn ";
                cout<<"\n Enter the box number ";
                cin>>box;
                if(is_blank(box)!=1)
                {
                    cout<<"\n Invalid move. Please enter a valid box number ";
                    cin>>box;
                }
                Go(box,5);
                disp_matrix();
            }
            else
            {
                cout<<"\n AI's turn \n";
                move(t);
                disp_matrix();
            }
            t++;
            win();
        }
        if(t>9)
            cout<<" Game Draw ";
    }
}

void initialise_vector()
{
    for(int i=1;i<=9;i++)
    {
        vector[i]=2;
    }
}

void Go(int box, int sym)
{
   vector[box]=sym;
}

int is_blank(int box)
{
    if(vector[box]==2)
        return 1;
    else
        return 0;
}

void disp_matrix() //matrix display
{
    char board[9];
    for(int i=1;i<=9;i++)
    {
        if(vector[i]==5)
            board[i-1]='X';
        else if(vector[i]==3)
            board[i-1]='O';
        else
            board[i-1]=' ';
    }
    for(int i=0; i<=6; i=i+3)
    {
        cout<<board[i]<<"  | "<<board[i+1]<<" | "<<board[i+2];
        cout<<"\n---|---|---\n";
    }
    cout<<endl;
}

int Posswin(int sym)
{
    int a=0,pro;
    if(sym==3)
        pro=18;
    else if(sym==5)
        pro=50;

    /* check rows */
    for(int i=1; i<=7; i=i+3)
    {
        if(vector[i]*vector[i+1]*vector[i+2] == pro)
        {
            if(vector[i]==2)
                a=i;
            else if(vector[i+1]==2)
                a=i+1;
            else if(vector[i+2]==2)
                a=i+2;
        }
    }

    /*check columns*/
    for(int i=1;i<=3;i++)
    {
        if(vector[i]*vector[i+3]*vector[i+6]==pro)
        {
            if(vector[i]==2)
                a=i;
            else if(vector[i+3]==2)
                a=i+3;
            else if(vector[i+6]==2)
                a=i+6;
        }
    }

    /*check diagonals*/
    if(vector[1]*vector[5]*vector[9]==pro)
    {
        if(vector[1]==2)
            a=1;
        else if(vector[5]==2)
            a=5;
        else if(vector[9]==2)
            a=9;
    }

    if(vector[3]*vector[5]*vector[7]==pro)
    {
        if(vector[3]==2)
            a=3;
        else if(vector[5]==2)
            a=5;
        else if(vector[7]==2)
            a=7;
    }
    return a;
}

int find_blank()
{
	for(int i=1;i<=9;i++)
		{
			if(vector[i]==2)
				return i;
		}
}

int Make2()
{
    if(vector[5]==2)
    {
        return 5;
    }
    else if(vector[2]==2)
    {
        return 2;
    }
    else if(vector[4]==2)
    {
        return 4;
    }
    else if(vector[6]==2)
    {
        return 6;
    }
    else if(vector[8]==2)
    {
        return 8;
    }
}

void move(int turn)
{
    switch(turn)
    {
    case 1:
        {
            Go(1,3);
        }
        break;
    case 2:
        {
            if(is_blank(5))
                Go(5,3);
            else
                Go(1,3);
        }
        break;
    case 3:
        {
            if(is_blank(9))
                Go(9,3);
            else
                Go(3,3);
        }
        break;
    case 4:
        {
            if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else
                Go(Make2(),3);
        }
        break;
    case 5:
        {
            if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else if(Posswin(3)!=0)
                Go(Posswin(3),3);
            else if(vector[7]==2)
                Go(7,3);
            else
                Go(3,3);
        }
        break;
    case 6:
        {
            if(Posswin(3)!=0)
                Go(Posswin(3),3);
            else if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else
                Go(Make2(),3);
        }
        break;
    case 7:
        {
            if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else if(Posswin(3)!=0)
                Go(Posswin(3),3);
            else
                Go(find_blank(),3);
        }
        break;
    case 8:
        {
            if(Posswin(3)!=0)
                Go(Posswin(3),3);
            else if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else
                Go(find_blank(),3);
        }
        break;
    case 9:
        {
            if(Posswin(5)!=0)
                Go(Posswin(5),3);
            else if(Posswin(3)!=0)
                Go(Posswin(3),3);
            else
                Go(find_blank(),3);
        }
        break;
    }
}

void win()
{
    int a=0;

    //for X i.e. user
    /* check columns */
    for(int i=1;i<=3;i++)
    {
        if(vector[i]*vector[i+3]*vector[i+6]==125)
            a=1;
    }
    /* check rows */
    for(int i=1; i<=7; i=i+3)
    {
        if(vector[i]*vector[i+1]*vector[i+2]==125)
            a=1;
    }
    /* check diagonals*/
    if(vector[1]*vector[5]*vector[9]==125 || vector[3]*vector[5]*vector[7]==125)
        a=1;

    //for O i.e. AI
    /* check columns */
    for(int i=1;i<=3;i++)
    {
        if(vector[i]*vector[i+3]*vector[i+6]==27)
            a=2;
    }
    /* check rows */
    for(int i=1; i<=7; i=i+3)
    {
        if(vector[i]*vector[i+1]*vector[i+2]==27)
            a=2;
    }
    /* check diagonals*/
    if(vector[1]*vector[5]*vector[9]==27 || vector[3]*vector[5]*vector[7]==27)
        a=2;

    if(a==1)
    {
        cout<<"\n Congrats, you won !! :) AI lost ";
        exit(0);
    }

    if(a==2)
    {
        cout<<"\n Oh, you lost !! :( AI won ";
        exit(0);
    }
}
