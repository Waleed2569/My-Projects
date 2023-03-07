#include<iostream>
#include<fstream>
#include"mygraphics.h"
using namespace std;
// function for boundaries
void copyy(int array[][100], float& padx1, float& padx2, float& ballx1, float& ballx2, float& bally1, float& bally2,int&lives,int &score)
{
	ifstream savefile("save.txt");
	savefile >> padx1 >> padx2 >>  ballx1 >> ballx2 >> bally1 >> bally2>>lives>>score ;

	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			savefile >> array[a][b];
		}
	}
}
void save(int array[][100], float padx1, float padx2, float ballx1, float ballx2, float bally1, float bally2,int lives,int score)
{
	ofstream savefile("save.txt");
	savefile << padx1 << " " << padx2 << " " << ballx1 << " " << ballx2 << " " << bally1 << " " << bally2 << " " << lives << " " << score<<" ";

	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			savefile << array[a][b] << " ";
		}
	}
}
void shighscore(int high[1000], int& score)
{
	ifstream shigh("high.txt");
	{
		ofstream shigh("high.txt");
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (high[i] <= high[i + 1])
				{
					swap(high[i], high[i + 1]);
				}

			}
		}
		for (int i = 0; i < 5; i++)
		{
			shigh << high[i] << " ";
		}
	}
}
void lhighscore(int high[1000], int score)
{
	ifstream shigh("high.txt");
	for (int i = 0; i < 5; i++)
	{
		shigh >> high[i];
		cout << high[i];
		cout << " ";
	}
}
void llhighscore(int high[5])
{
	ifstream shigh("high.txt");
	for (int i = 0; i < 5; i++)
	{
		shigh >> high[i];
	}
}

void boundaries()
{
	drawLine(20, 30, 890, 30,204,0,153);
	drawLine(20, 460, 890, 460, 204, 0, 153);
	drawLine(20, 30, 20, 460, 204, 0, 153);
	drawLine(890, 30, 890, 460, 204, 0, 153);
}
int liv = 0;
//arrays for bricks
int br1[100][100];
int br2[100][100];
//function for bricks
void brickk(int array1[][100])
{
	int x = 35, y = 80;
	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			if (array1[a][b] == 1)
			{
				if ((a == 5 && b == 10)|| (a == 3 && b == 6) || (a == 4 && b == 2) || (a == 0 && b == 11) || (a == 1 && b == 2))
				{
					drawRectangle(x, y, x + 60, y + 15, 0, 51, 0, 0, 51, 0);
					br1[a][b] = x;
					br2[a][b] = y;
				}
				else if ((a == 4 && b == 5)||(a==2 && b==8)||(a == 0 && b == 1))
				{
					drawRectangle(x, y, x + 60, y + 15, 0, 0, 102, 51, 102, 153);
					br1[a][b] = x;
					br2[a][b] = y;
				}
				else if ((a == 3 && b == 2) || (a == 1 && b == 10))
				{
					drawRectangle(x, y, x + 60, y + 15, 128, 0, 0, 255, 0, 0);
					br1[a][b] = x;
					br2[a][b] = y;
				}
				else
				{
					drawRectangle(x, y, x + 60, y + 15, 0, 51, 0, 51, 204, 51);
					br1[a][b] = x;
					br2[a][b] = y;
				}
			}
			x += 69;
		}
		y += 25;
		x = 35;
	}
}
//function to display lives
void livesdispaly(int life)
{
	int change = 3;
	int i = 0;
	int lx1 = 810, ly1 = 50, ly2 = 70, lx2 = 830;
	if (life == 3)
		while (i < 3)
		{

			drawEllipse(lx1, ly1, lx2, ly2, 0, 0, 255, 255, 0, 0);
			lx1 = lx1 + 20;
			lx2 = lx2 + 20;
			i++;
		}
	if (life == 2) {
		while (i < 2)
		{
			drawEllipse(lx1, ly1, lx2, ly2, 0, 0, 255, 255, 0, 0);
			lx1 = lx1 + 20;
			lx2 = lx2 + 20;
			i++;
		}
		drawEllipse(lx1, ly1, lx2, ly2, 255, 255, 255, 0, 0, 0);
	}
	if (life == 1) {
		drawEllipse(lx1, ly1, lx2, ly2, 0, 0, 255, 255, 0, 0);
		lx1 = lx1 + 20;
		lx2 = lx2 + 20;
		while (i < 2)
		{
			drawEllipse(lx1, ly1, lx2, ly2, 255, 255, 255, 0, 0, 0);
			lx1 = lx1 + 20;
			lx2 = lx2 + 20;
			i++;
		}

	}

}



void main()
{
	cout << "Would you like to continue saved game?\n";
	delay(2000);
	cout << "Press and enter 'y' for yes and 'n' to start new game: ";
	char choice;
	cin >> choice;
	cls();
	gotoxy(0, 0);
	int brick[10][100];
	fstream saveGame,highscores;

	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			brick[a][b] = 1;
		}
	}
	bool check = true;
	bool array1[100][100] = { true };
	int lives = 3, score = 0;
	//start up screen
	cout << "Name: Brick Breaker\n\nControls: Press 'a' for paddle to go left, Press 'f' for paddle to go right, press 'p' to pause the game, 'r' to resume the game, 'm' to save the game and press 'q' to quit\n\nPoint System:-\nBricks of first row are 6 points each\nBricks of second row are 5 points each\nBricks of third row are 4 points each\nBricks of fourth row are 3 points each\nBricks of fifth row are 2 points each\nBricks of last row are 1 point each\n\nRules:-\nBreak all the bricks within the given three lives\nWhen all lives are lost or all the bricks are destroyed the game ends\nDark Green bricks require two hits\nLight Green bricks require one hit\n\nPowerups:-\nBlue Bricks increase the size of the paddle\nRed bricks give an extra life\n\nPress space to start the game  ";
	char game;
	while (true)
	{
		game = getKey();
		if (game == ' ')
		{
			break;
		}
	}
	int high[1000] = {0};
	llhighscore(high);
	if (game == ' ')
	{
		int b1 = 1, b2 = 1, b3 = 1, b4 = 1, b5 = 1,s=0;
		while (lives > 0)
		{
			//game complete
			if (score >=252)
			{
				gotoxy(0, 0);
				cls();
				cout << "\nCONGRATULATIONS";
				delay(2000);
				cout << "  YOU WON";
				delay(2000);
				cout << "  FINAL SCORE:" << score<<endl;
				delay(2000);
				cout << "TOP SCORES: ";
				lhighscore(high, score);
				cout << endl;
				system("pause");
				break;

			}

			float ballx1 = 400, ballx2 = 410, bally1 = 310, bally2 = 320;
			float reflectionx = 1;
			float reflectiony = 1;
			float padx1 = 400, padx2 = 490, pady = 410;
			cls();
			bool gamestatus = true;
			if (lives == 3)
				if (gamestatus)
				{
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					int x = 35, y = 80;
					//printing bricks
					gotoxy(40, 15);
					if(choice == 'y')
					{
						cout << "      GAME CONTINUED";
					}
					else
					{
						cout << "      GAME STARTED";
					}
					delay(1500);
					cls();
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					cout << " 3";
					delay(1500);
					cls();
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					cout << " 2";
					delay(1500);
					cls();
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					cout << " 1";
					delay(1500);
					cls();
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					cout << " LETS GO";
					delay(1500);
					cls();
					gotoxy(12, 21);
					// calling function for boundaries
					boundaries();
					// calling function to display lives
					livesdispaly(lives);
					cout << "\n\n\n\n\n\n  ";
					if (choice != 'y')
					{
						for (int a = 0; a < 6; a++)
						{
							for (int b = 0; b < 12; b++)
							{
								if ((a == 5 && b == 10) || (a == 3 && b == 6) || (a == 4 && b == 2) || (a == 0 && b == 11) || (a == 1 && b == 2))
								{
									drawRectangle(x, y, x + 60, y + 15, 0, 51, 0, 0, 51, 0);
									br1[a][b] = x;
									br2[a][b] = y;
								}
								else if ((a == 4 && b == 5) || (a == 2 && b == 8) || (a == 0 && b == 1))
								{
									drawRectangle(x, y, x + 60, y + 15, 0, 0, 102, 51, 102, 153);
									br1[a][b] = x;
									br2[a][b] = y;
								}
								else if ((a == 3 && b == 2) || (a == 1 && b == 10))
								{
									drawRectangle(x, y, x + 60, y + 15, 128, 0, 0, 255, 0, 0);
									br1[a][b] = x;
									br2[a][b] = y;
								}
								else
								{
									drawRectangle(x, y, x + 60, y + 15, 0, 51, 0, 51, 204, 51);
									br1[a][b] = x;
									br2[a][b] = y;
								}

								x += 69;
								delay(30);
							}
							y += 25;
							x = 35;
						}
					}
				}
			while (choice == 'y'&& s == 0)
			{
				copyy(brick, padx1, padx2, ballx1, ballx2, bally1, bally2, lives, score);
				s++;
			}
			//printing bricks
			brickk(brick);
			//displaying score
			if (score == 0)
			{
				gotoxy(2, 27);
				cout << "  SCORE: 0";
			}
			else if(score > 0)
			{
				cout << "\b\b\b\b\b\b\b\bSCORE: " << score;
			}
			
			while (gamestatus == true)
			{
				if (lives == 2)
				{
					gotoxy(12, 27);
				}
				// calling function for boundaries
				boundaries();
				// calling function to display lives
				livesdispaly(lives);
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 12; j++)
					{
						int bx = br1[i][j];
						int by = br2[i][j];
						if (brick[i][j] == 0)
						{
							continue;
						}
						if ((ballx1 < bx + 75 && ballx1 + 20 > bx) && ((bally1 + 15 > by && bally2 < by + 25)))
						{
							if ((i == 4 && j == 5) || (i == 2 && j == 8) || (i == 0 && j == 1))
							{
								padx1 -= 10;
								padx2 += 10;
							}
							if ((i == 3 && j == 2) || (i == 1 && j == 10))
							{
								if (lives < 3)
								{
									lives++;
								}
							}
							if (i == 5 && j == 10&&b1==1)
							{
								drawRectangle(bx, by, bx + 60, by + 15, 0, 51, 0, 51, 204, 51);
								//reflection in y
								if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								b1++;
							}
							else if (i == 3 && j == 6 && b2 == 1)
							{
								drawRectangle(bx, by, bx + 60, by + 15, 0, 51, 0, 51, 204, 51);
								//reflection in y
								if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								b2++;
							}
							else if (i == 4 && j == 2 && b3 == 1)
							{
								drawRectangle(bx, by, bx + 60, by + 15, 0, 51, 0, 51, 204, 51);
								//reflection in y
								if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								b3++;
							}
							else if (i == 0 && j == 11 && b4 == 1)
							{
								drawRectangle(bx, by, bx + 60, by + 15, 0, 51, 0, 51, 204, 51);
								//reflection in y
								if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								b4++;
							}
							else if (i == 1 && j == 2 && b5 == 1)
							{
								drawRectangle(bx, by, bx + 60, by + 15, 0, 51, 0, 51, 204, 51);
								//reflection in y
								if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								b5++;
							}
							
							else
							{
								check != check;
								//calculating score
								if (i == 0)
								{
									score += 6;
								}
								else if (i == 1)
								{
									score += 5;
								}
								else if (i == 2)
								{
									score += 4;
								}
								else if (i == 3)
								{
									score += 3;
								}
								else if (i == 4)
								{
									score += 2;
								}
								else
								{
									score += 1;
								}
								//reflection in y
								if (bally1<by + 14 && bally2 > by-1)
								{
									reflectionx = reflectionx * -1;
								}
								else if (bally1 <= by + 15)
								{
									reflectiony = reflectiony * -1;
								}
								else if (bally1 <= by)
								{
									reflectiony = reflectiony * -1;
								}
								drawRectangle(bx, by, bx + 60, by + 15, 12, 12, 12, 12, 12, 12);
								brick[i][j] = 0;
								if (ballx1 == bx + 75)
								{
									reflectionx = reflectionx * -1;
								}
								else if (ballx1 == bx)
								{
									reflectionx = reflectionx * -1;
								}
								//displaying score
								gotoxy(12, 27);
								if (score < 10)
								{
									cout << "\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
								}
								else if (score < 100)
								{
									cout << "\b\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
								}
								else if (score < 1000)
								{
									cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
								}
							}

						}

					}

				}
				//game complete
				if (score >=252)
				{
					shighscore(high, score);
					high[5] = score;
					shighscore(high, score);
					break;
				}

				drawEllipse(ballx1, bally1, ballx2, bally2, 12, 12, 12, 255, 0, 102);

				//paddle reflection
				 if (ballx2 >= padx1 - 1 && ballx1 <= padx2 + 15 && bally2 == pady)
				{
					reflectiony = reflectiony * -1;
				}
				//x axis
				ballx1 = ballx1 + 1 * reflectionx;
				ballx2 = ballx2 + 1 * reflectionx;

				if (ballx2 == 890 || ballx2 > 890)
					reflectionx = reflectionx * -1;
				if (ballx1 == 20 || ballx1 < 20)
					reflectionx = reflectionx * -1;

				//y axis
				bally1 = bally1 + 1 * reflectiony;
				bally2 = bally2 + 1 * reflectiony;
				delay(1);
				if (bally1 == 30 || bally1 < 30)
				{
					reflectiony = reflectiony * -1;
				}
				if (bally2 == 460 || bally2 > 460)
				{

					//reflectiony = reflectiony * -1; 
					gamestatus = false;
					lives--;
					gotoxy(12, 27);

					if (lives == 0)
					{
						high[5] = score;
						shighscore(high, score);
						cls();
						gotoxy(0, 0);
						cout << "\nYOU LOST";
						cout << "\nFinal Score: " << score << endl;
						delay(2000);
						cout << "TOP SCORES: ";
						lhighscore(high, score);
						cout << endl;
						system("pause");
						gamestatus = false;
					}

				}




				//ball removal 
				if (reflectionx == 1 && reflectiony == 1)
					drawEllipse(ballx1 - 10, bally1 - 10, ballx2 - 10, bally2 - 10, 12, 12, 12, 12, 12, 12);
				else if (reflectiony == -1 && reflectionx == -1)
					drawEllipse(ballx1 + 10, bally1 + 10, ballx2 + 10, bally2 + 10, 12, 12, 12, 12, 12, 12);



				//paddle
				drawRectangle(padx1, 410, padx2, 416, 255, 255, 0, 255, 255, 0);
				char input = 'a';
				input = getKey();
				//quit game
				if (input == 'q' || input == 'Q')
				{
					lives = 0;
					cls();
					cout << "Game over";
					gamestatus = false;
				}
				//paddle right
				if (input == 'f')
				{

					if (padx2 < 890) {
						padx1 = padx1 + 10;
						padx2 = padx2 + 10;
						drawRectangle(padx1 - 10, 410, padx2 - 10, 416, 12, 12, 12, 12, 12, 12);
						drawRectangle(padx1, 410, padx2, 416, 255, 255, 0, 255, 255, 0);
					}
				}
				//paddle left
				if (input == 'a')
				{

					if (padx1 > 20) 
					{
						padx1 = padx1 - 10;
						padx2 = padx2 - 10;
						drawRectangle(padx1 + 10, 410, padx2 + 10, 416, 12, 12, 12, 12, 12, 12);
						drawRectangle(padx1, 410, padx2, 416, 255, 255, 0, 255, 255, 0);
					}
				}
				//pause and resume
				if (input == 'p')
				{
					gotoxy(48, 15);
					cout << " GAME PAUSED";
					while (input != 'r')
					{
						delay(1);
						input = getKey();
					}
					cls();
					brickk(brick);
					gotoxy(12, 27);
					if (score < 10)
					{
						cout << "\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
					}
					else if (score < 100)
					{
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
					}
					else if (score < 1000)
					{
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   SCORE: " << score;
					}
				}
				if (input == 'm')
				{
					save(brick,padx1,padx2,ballx1,ballx2,bally1,bally2,lives,score);
					delay(1000);
				}
			}
		}

	}
}
//40 430

//x1 y1  x2   y2
   //drawRectangle(100,100, 150, 150, 255, 255, 255, 0, 0, 0