#include<iostream>
#include<conio.h>
#include<ctime>
#include <windows.h>


void result1();
void draw_grid();
void displayline(int inttop,int intright, char* strline);
void draw_line(int n,char ch);
void gotoXY(int x, int y); 
void WaitKey();
void diceroll1() ;   
                     
void one();
void two();
void three();
void four();
void five();
void six();
void board();
void scoreboard();
void setwindow();                  
void player_1();
void clearplayerarea();
void displayalldice();
void snake();
void ladder();


enum color{
	NONE,
	DARK_BLUE,
	GREEN,
	DARK_CYAN,
	DARK_RED,
	PURPLE,
	DARK_YELLOW,
	NORMAL,
	GRAY,
	BLUE,
	LIME,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};
void setcolor    (color newColor);

using namespace std;
int Background;
int random,random1,score1,newval,charcol,charrow;
int type;
int diceleft=50;
int sml=1;
char name[15];
char ch=sml;
char player1[]={176,'\0'};


int arr[10][10]={{100,99,98,97,96,95,94,93,92,91},
				{81,82,83,84,85,86,87,88,89,90},
				{90,79,78,77,76,75,74,73,72,71},
				{61,62,63,64,65,66,67,68,69,70},
				{60,59,58,57,56,55,54,53,52,51},
				{41,42,43,44,45,46,47,48,49,50},
				{40,39,38,37,36,35,34,33,32,31},
				{21,22,23,24,25,26,27,28,29,30},
				{20,19,18,17,16,15,14,13,12,11},
				{1,2,3,4,5,6,7,8,9,10}};


main()
{
	
	setwindow();
	board();
	scoreboard();
	
	score1=0;
	charcol=4+(score1*5),charrow=35;
	gotoXY(charcol,charrow);
	cout<<player1;
	
	
	draw_grid();
	
	int playerturn = 1;
	while (true)
	{
		if (playerturn == 1)
		{
			player_1();
		}
		
		
		if (score1==100)
		{
			result1();
			break;
		}
		
		
    }
}


void draw_grid() 
 {
  int x,y,nrow,ncol;
  char topl[]={201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187,'\0'};
  char midl[]={204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185,'\0'};
  char bottoml[]={200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188,'\0'};
  nrow=16;
  ncol=5;
  gotoXY(ncol,nrow);
  cout<<topl<<endl;
  for(x=0;x<10;x++)
   {
   	for(y=0;y<10;y++)
   	 {
   	    if(y==0)
   	    {
   	     	++nrow;
   	     	gotoXY(ncol,nrow);
			cout<<char(186);
   	     }
   	    if (arr[x][y] <10)
   	    {
			cout<<char(32)<<char(32)<<arr[x][y];
	    }  
		else
		{
			if (arr[x][y] <100)
				cout<<char(32)<<arr[x][y];
			else
				cout<<arr[x][y];
	    }	
		cout<<char(32)<<char(186);                
     }
    if (x<9)
		{
   	     	++nrow;
   	     	gotoXY(ncol,nrow);
			cout<<midl<<endl;
		}
     
   }
   	     	++nrow;
   	     	gotoXY(ncol,nrow);
   cout<<bottoml<<endl;
  }
void gotoXY(int x, int y) 
{ 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void WaitKey()
{
   _getch(); // Wait for a key
}

void diceroll1()
{
	srand(time(0));
	random = (rand() % 6) + 1;
	
	gotoXY(3,42);
	cout<<"Your dice number is : "<<random;
    
	switch (random)
	{
		case 1:
		{
			displayalldice();
			one();
			break;
		}
		case 2:
		{
			displayalldice();
			two();
			break;
		}
		case 3:
		{
			displayalldice();
			three();
			break;
		}
		case 4:
		{
			displayalldice();
			four();
			break;
		}
		case 5:
		{
			displayalldice();
			five();
			break;
		}
		case 6:
		{
			displayalldice();
			six();
			break;
		}
	}
}      



void one()
{
	int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,32,32,32,32,32,32,186,'\0'};
	char middice2[]={186,32,32,219,219,32,32,186,'\0'};
	char middice3[]={186,32,32,32,32,32,32,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
	
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	    
}

void two()
{
	int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,32,32,32,32,32,32,186,'\0'};
	char middice2[]={186,32,219,32,32,219,32,186,'\0'};
	char middice3[]={186,32,32,32,32,32,32,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
        
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	    
}
void three()
{
    int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,32,32,32,32,32,219,186,'\0'};
	char middice2[]={186,32,32,219,32,32,32,186,'\0'};
	char middice3[]={186,219,32,32,32,32,32,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
        
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	
        }
void four()
{
	int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,32,219,32,32,219,32,186,'\0'};
	char middice2[]={186,32,32,32,32,32,32,186,'\0'};
	char middice3[]={186,32,219,32,32,219,32,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
        
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	    
}
void five()
{
    int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,219,32,32,32,32,219,186,'\0'};
	char middice2[]={186,32,32,219,219,32,32,186,'\0'};
	char middice3[]={186,219,32,32,32,32,219,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
        
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	
        }
void six()
{
    int dicerow=40;
	char topdice[]={201,205,205,205,205,205,205,187,'\0'};
	char middice1[]={186,220,32,32,32,32,220,186,'\0'};
	char middice2[]={186,220,32,32,32,32,220,186,'\0'};
	char middice3[]={186,220,32,32,32,32,220,186,'\0'};
	char botdice[]={200,205,205,205,205,205,205,188,'\0'};
        
    displayline(diceleft,++dicerow,topdice);
	displayline(diceleft,++dicerow,middice1);
	displayline(diceleft,++dicerow,middice2);
	displayline(diceleft,++dicerow,middice3);
	displayline(diceleft,++dicerow,botdice);	
 }
void displayline(int inttop,int intright, char* strline)
{
	gotoXY(inttop,intright);
	cout <<strline;
    
}



void scoreboard()
{
	int boardrow=37,boardcol=80;
	gotoXY(boardcol,++boardrow);
	cout<<char(201)<<char(205)<<"Score Board"<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186);
	gotoXY(boardcol,++boardrow);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(200);
	
}                                         

void board()
{
  int boardrow=15,boardcol=80;	
  gotoXY(boardcol,++boardrow);
  draw_line(22,char(205));
  gotoXY(83,++boardrow);
  cout<<"SNAKE AT POSITION";
  gotoXY(boardcol,++boardrow);
  draw_line(22,char(205));
  gotoXY(boardcol,++boardrow);
  cout<<"From 98 to 28";
  gotoXY(boardcol,++boardrow);
  cout<<"From 95 to 24";
  gotoXY(boardcol,++boardrow);
  cout<<"From 92 to 51";
  gotoXY(boardcol,++boardrow);
  cout<<"From 83 to 19";
  gotoXY(boardcol,++boardrow);
  cout<<"From 73 to  1";
  gotoXY(boardcol,++boardrow);
  cout<<"From 69 to 33";
  gotoXY(boardcol,++boardrow);
  cout<<"From 64 to 36";
  gotoXY(boardcol,++boardrow);
  cout<<"";
  	
  gotoXY(boardcol,++boardrow);
  draw_line(22,char(205));
  gotoXY(83,++boardrow);
  cout<<"LADDER AT POSITION";
  gotoXY(boardcol,++boardrow);
  draw_line(22,char(205));
  gotoXY(boardcol,++boardrow);
  cout<<"From 6 to  27";
  gotoXY(boardcol,++boardrow);
  cout<<"From 23 to 37";
  gotoXY(boardcol,++boardrow);
  cout<<"From 42 to 72";
  gotoXY(boardcol,++boardrow);
  cout<<"From 56 to 88";
  gotoXY(boardcol,++boardrow);
  cout<<"From 62 to 91";
  gotoXY(boardcol,++boardrow);
  cout<<"From 80 to 97";


}
void draw_line(int n,char ch)
{
for(int i=0;i<n;i++)
   cout<<ch;
}
void setwindow()
{
    SMALL_RECT rect;
    COORD coord;
    coord.X = 110; // Defining our X and
    coord.Y = 55;  // Y size for buffer.

    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = coord.Y-1; // height for window
    rect.Right = coord.X-1;  // width for window

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
    SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size
    SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size
} 


void clearplayerarea()
{
	gotoXY(82,40);
	cout<<char(176)<<" ==> Player 1";
	gotoXY(85,42);
	cout<<"Score ==> "<<score1;
	
	gotoXY(3,39);
	cout<<name<<" ==> Your Turn";
	gotoXY(3,40);
	cout<<"Press any key to Roll Dice";
	
	
	gotoXY(3,42);
	cout<<"                      ";
	gotoXY(3,44);
	cout<<"                      ";
	gotoXY(50,40);
	cout<<"                      ";
	gotoXY(50,41);
	cout<<"                      ";
	gotoXY(50,42);
	cout<<"                      ";
	gotoXY(50,43);
	cout<<"                      ";
	gotoXY(50,44);
	cout<<"                      ";
	gotoXY(50,45);
	cout<<"                      ";
	gotoXY(82,41);
	cout<<"           ";
}	
	



void displayalldice()
{
	one();
	Sleep(40);
	two();
	Sleep(40);
	three();
	Sleep(40);
	four();
	Sleep(40);
	five();
	Sleep(40);
	six();
	Sleep(40);
}

void snake()
{
	system("COLOR 4f");
	gotoXY(3,49);
	cout<<"                               _.'''''.           "<<endl;
	gotoXY(3,50);
	cout<<"      --..._                .'' __ o  ';__.      "<<endl;
	gotoXY(3,51);
	cout<<"         ''.'.            .' .''    '....''      "<<endl;
	gotoXY(3,52);
	cout<<"             '.'-....'.'                         "<<endl;
	gotoXY(3,53);
	cout<<"               '-....-'                          "<<endl;
	WaitKey();
	
	gotoXY(3,47);
	cout<<"                                                 "<<endl;
	gotoXY(3,48);
	cout<<"                                                 "<<endl;
	gotoXY(3,49);
	cout<<"                                                 "<<endl;
	gotoXY(3,50);
	cout<<"                                                 "<<endl;
	gotoXY(3,51);
	cout<<"                                                 "<<endl;
	gotoXY(3,52);
	cout<<"                                                 "<<endl;
	gotoXY(3,53);
	cout<<"                                                 "<<endl;
	system("color 5f"); 
}
void ladder()
{
	system("color 2f");
	gotoXY(3,49);
	cout<<"        //---------//";
	gotoXY(3,50);
	cout<<"       //----------//";
	gotoXY(3,51);
	cout<<"      //----------//";
	gotoXY(3,52);
	cout<<"     //----------//";
	gotoXY(3,53);
	cout<<"    //----------//";
	
	WaitKey();
	gotoXY(3,47);
	cout<<"                                                 "<<endl;
	gotoXY(3,48);
	cout<<"                                                 "<<endl;
	gotoXY(3,49);
	cout<<"                                                 "<<endl;
	gotoXY(3,50);
	cout<<"                                                 "<<endl;
	gotoXY(3,51);
	cout<<"                                                 "<<endl;
	gotoXY(3,52);
	cout<<"                                                 "<<endl;
	gotoXY(3,53);
	cout<<"                                                 "<<endl;
	system("color 5f");
}

void player_1()
{
	clearplayerarea();
	WaitKey();
	
	diceroll1();
	
	score1+=random;
	
	gotoXY(3,44);
	cout<<"Your Position is ==> : "<<score1;
	WaitKey();
	switch(score1)
	{
		case 98 :score1=28;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 28";
		snake();
		break;
		
		case 95 :score1=24;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 24";
		snake();
		break;
		
		case 92 :score1=51;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 51";
		snake();
		break;
		
		case 83 :score1=19;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 19";
		snake();
		break;
		
		case 73 :score1=1;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 1";
		snake();
		break;
		
		case 69 :score1=33;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 33";
		snake();
		break;
		
		case 64 :score1=36;
		gotoXY(3,47);
		cout<<"OPPS! Stung BY Snake and You Reached at 36";
		snake();
		break;
		
		case 6 :score1=27;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 27";
		ladder();
		break;
		
		case 23 :score1=37;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 37";
		ladder();
		break;
		
		case 42 :score1=72;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 72";
		ladder();
		break;
		
		case 56 :score1=88;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 88";
		ladder();
		break;
		
		case 62 :score1=91;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 91";
		ladder();
		break;
		
		case 80 :score1=97;
		gotoXY(3,47);
		cout<<"WOW! Jumped Through Ladder and Reached at 97";
		ladder();
		break;
		
	}
	
	if ( score1 >100)
		{
		  score1-=random;	
		}	
		if(score1<=10)
		{
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=4+(score1*5);
			charrow=35;
			gotoXY(charcol,charrow);
			cout<<player1;
		} 
		
	   else if(score1<=20)
		{ 
			newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			
			charcol=59-(newval*5);
			charrow=33;
			gotoXY(charcol,charrow);
			cout<<player1;
		}

	   else if(score1<=30)
		{
			newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=4+(newval*5);
			charrow=31;
			gotoXY(charcol,charrow);
			cout<<player1;
		} 

   		else if(score1<=40)
		{ 
			newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=59-(newval*5);
			charrow=29;
			gotoXY(charcol,charrow);
			cout<<player1;
		}

	   else if(score1<=50)
		{
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=4+(newval*5);
			charrow=27;
			gotoXY(charcol,charrow);
			cout<<player1;
		} 

	   else if(score1<=60)
		{ 
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=59-(newval*5);
			charrow=25;
			gotoXY(charcol,charrow);
			cout<<player1;
		}

	   else if(score1<=70)
		{
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=4+(newval*5);
			charrow=23;
			gotoXY(charcol,charrow);
			cout<<player1;
		} 

	   else if(score1<=80)
		{ 
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=59-(newval*5);
			charrow=21;
			gotoXY(charcol,charrow);
			cout<<player1;
		}

	   else if(score1<=90)
		{
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=4+(newval*5);
			charrow=19;
			gotoXY(charcol,charrow);
			cout<<player1;
		} 

	   else if(score1<=100)
		{ 
			int newval = score1 % 10;
			if (newval==0)
				newval = 10;
			gotoXY(charcol,charrow);
			cout<<" ";
			charcol=59-(newval*5);
			charrow=17;
			gotoXY(charcol,charrow);
			cout<<player1;
		}
	
}



	
void result1()
{
	system("pause");
	system("CLS");
	
	cout<<"\t   ______     ______    _____   _       _    __        ________      "<<endl;
	cout<<"\t  | |    \\  | |       //   ||  | |     | |  |  |      |__    __|     "<<endl;
	cout<<"\t  | |___ // | |__       \\      | |     | |  |  |         |  |        "<<endl;
	cout<<"\t  | |   \\   | |          \\     | |     | |  |  |____     |  |        "<<endl;
	//cout<<"\t  |_|    \\  |_|____  \\___//    \_____/   |_______|    |__|        "<<endl;
	cout<<name<<"\t Yahoo!!! ==> Congratulation!!! ==> You Won "<<" --> "<<score1<<endl;
	
}	
	
	
	
void setcolor(color newColor)
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (newColor + (0 * 16)));
}	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
