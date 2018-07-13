/*
Colby Thacker
Lab #10
CECS 130 Section 02
Plays 3-D Tic-Tac-Toe
March 31st, 2018
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class GameBoard
{	
	public:
		GameBoard()
		{
			iNumOfSquares = 9;
			iMoveNum = 1;
			sFirstPlayer = "X";
			sSecondPlayer = "O";
			FirstPWins = "Player one wins!";
			SecondPWins = "Second player wins!";
			Winner = "No winner!";
		}
		void DrawBoard();
		void IncrementMoveNum();
		void InputMove(int);
		void GetWinner();
		bool IsValidMove(int);
		bool IsWinner();
		bool IsGameOver();
		int iMoveNum;
	private:
		int iNumOfSquares;
		//For player location a 1 is X, a 2 is O
		int PlayerLocation[9];
		string sFirstPlayer;
		string sSecondPlayer;
		string FirstPWins;
		string SecondPWins;
		string Winner;
};
void GameBoard::DrawBoard()
{
	system("cls");
	
}
bool GameBoard::IsValidMove(int Selection)
{
	if(PlayerLocation[Selection-1]!=1&&PlayerLocation[Selection-1]!=2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GameBoard::IsGameOver()
{
	bool bReturnValue = false;
	int FullSquares = 0;
	if(IsWinner())
		bReturnValue = true;
	for(int i=0;i<iNumOfSquares;i++)
	{
		if(PlayerLocation[i]==1||PlayerLocation[i]==2)
			FullSquares++;
	}
	if(FullSquares==iNumOfSquares)
		bReturnValue = true;
	return bReturnValue;
}
bool GameBoard::IsWinner()
{
		if(PlayerLocation[0]==PlayerLocation[1]&&PlayerLocation[0]==PlayerLocation[2])
	{
		if(PlayerLocation[0]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[0]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[3]==PlayerLocation[4]&&PlayerLocation[3]==PlayerLocation[5]) {
		if(PlayerLocation[3]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[3]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[6]==PlayerLocation[7]&&PlayerLocation[6]==PlayerLocation[8]) {
		if(PlayerLocation[6]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[6]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[0]==PlayerLocation[4]&&PlayerLocation[0]==PlayerLocation[8]) {
		if(PlayerLocation[0]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[0]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[2]==PlayerLocation[4]&&PlayerLocation[2]==PlayerLocation[6]) {
		if(PlayerLocation[2]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[2]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[0]==PlayerLocation[3]&&PlayerLocation[0]==PlayerLocation[6]) {
		if(PlayerLocation[0]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[0]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[1]==PlayerLocation[4]&&PlayerLocation[1]==PlayerLocation[7]) {
		if(PlayerLocation[1]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[1]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	}else if(PlayerLocation[2]==PlayerLocation[5]&&PlayerLocation[2]==PlayerLocation[8]) {
		if(PlayerLocation[2]==1)
		{
			Winner = "Player One wins!!!";
			return true;
		} else if (PlayerLocation[2]==2) {
			Winner = "Player Two wins!!!";
			return true;
		}
	} else {
		return false;
	}
}
void GameBoard::IncrementMoveNum()
{
	iMoveNum++;
}

//Start of Lab 10 program
class ThreeDGameBoard : public GameBoard
{
	public:
		void DrawBoard();
		void CountThrees();
		bool InputMove(int, int);
		bool GameOver();
		bool IsValidMove(int, int);
		void GetScore();
		ThreeDGameBoard()
		{
			iNumOfSquares = 28;
			for(int i=0;i<3;i++)
			{		
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
						TheBoard[i][j][k] = ' ';
					}
				}
			}
		}
	private:
		char TheBoard[3][3][3];
		int iNumOfSquares;
		int NumOfXThrees;
		int NumOfOThrees;
};
bool ThreeDGameBoard::IsValidMove(int BoardNumb, int BoardLocNum)
{
	if(BoardLocNum<=3)
	{
		if(TheBoard[BoardNumb-1][0][BoardLocNum-1]=='X'||
		TheBoard[BoardNumb-1][0][BoardLocNum-1]=='O')
			return true;
		else
			return false;
	} else if(BoardLocNum>3&&BoardLocNum<=6) {
		if(TheBoard[BoardNumb-1][1][BoardLocNum-4]=='X'||
		TheBoard[BoardNumb-1][1][BoardLocNum-4]=='O')
			return true;
		else
			return false;
	} else if(BoardLocNum>6&&BoardLocNum<=9) {
		if(TheBoard[BoardNumb-1][2][BoardLocNum-7]=='X'||
		TheBoard[BoardNumb-1][2][BoardLocNum-7]=='O')
			return true;
		else
			return false;
	} else {
		return false;
	}
}
bool ThreeDGameBoard::GameOver()
{
	if(iNumOfSquares == iMoveNum)
		return true;
	else
		return false;
}
void ThreeDGameBoard::GetScore()
{
	NumOfXThrees=0;
	NumOfOThrees=0;
	CountThrees();
	cout<<"\nPlayer one scored: "<<NumOfXThrees;
	cout<<"\nPlayer two scored: "<<NumOfOThrees;
	if(NumOfXThrees>NumOfOThrees)
		cout<<"\nCongratulations player one!!!";
	else if(NumOfOThrees>NumOfXThrees)
		cout<<"\nCongratulations player two!!!";
	else if(NumOfOThrees==NumOfXThrees)
		cout<<"\nIt is a tie!";
}
void ThreeDGameBoard::DrawBoard()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				cout<<TheBoard[i][j][k];
				if(k!=2)
					cout<<"|";
				else
					cout<<"\n";
			}
			if(j!=2)
				cout<<"-|-|-\n";
		}
		cout<<"\n\n";
	}
	cout<<"1|2|3\n-|-|-\n4|5|6\n-|-|-\n7|8|9\n\n";
}
void ThreeDGameBoard::CountThrees()
{
	for(int i=0; i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(TheBoard[i][j][0]==TheBoard[i][j][1]&&TheBoard[i][j][2]==TheBoard[i][j][1])
			{
				if(TheBoard[i][j][0]=='X')
				{
					NumOfXThrees++;
				} else if(TheBoard[i][j][0]=='O') {
					NumOfOThrees++;
				}
			}
			if(TheBoard[i][0][j]==TheBoard[i][1][j]&&TheBoard[i][2][j]==TheBoard[i][1][j])
			{
				if(TheBoard[i][0][j]=='X')
				{
					NumOfXThrees++;
				} else if(TheBoard[i][0][j]=='O') {
					NumOfOThrees++;
				}
			}
			if(TheBoard[0][i][j]==TheBoard[1][i][j]&&TheBoard[1][i][j]==TheBoard[2][i][j])
			{
				if(TheBoard[0][i][j]=='X')
				{
					NumOfXThrees++;
				} else if(TheBoard[0][i][j]=='O') {
					NumOfOThrees++;
				}
			}

			//Central Diagonals
		}
					//Parallel Diagonals
		if(TheBoard[i][0][0]==TheBoard[i][1][1]&&TheBoard[i][0][0]==TheBoard[i][2][2])
		{
			if(TheBoard[i][0][0]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[i][0][0]=='O') {
				NumOfOThrees++;
			}
		}
		if(TheBoard[i][2][0]==TheBoard[i][1][1]&&TheBoard[i][0][2]==TheBoard[i][2][0])
		{
			if(TheBoard[i][1][1]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[i][1][1]=='O') {
				NumOfOThrees++;
			}
		}
		if(TheBoard[1][i][1]==TheBoard[2][i][0]&&TheBoard[1][i][1]==TheBoard[0][i][2])
		{
			if(TheBoard[1][i][1]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[1][i][1]=='O') {
				NumOfOThrees++;
			}
		}
		if(TheBoard[1][i][1]==TheBoard[2][i][2]&&TheBoard[1][i][1]==TheBoard[0][i][0])
		{
			if(TheBoard[1][i][1]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[1][i][1]=='O') {
				NumOfOThrees++;
			}
		}
		if(TheBoard[1][1][i]==TheBoard[2][0][i]&&TheBoard[1][1][i]==TheBoard[0][2][i])
		{
			if(TheBoard[1][1][i]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[1][1][i]=='O') {
				NumOfOThrees++;
			}
		}
		if(TheBoard[1][1][i]==TheBoard[2][2][i]&&TheBoard[1][1][i]==TheBoard[0][0][i])
		{
			if(TheBoard[1][1][i]=='X')
			{
				NumOfXThrees++;
			} else if(TheBoard[1][1][i]=='O') {
				NumOfOThrees++;
			}
		}
	}
	if(TheBoard[1][1][1]==TheBoard[2][2][2]&&TheBoard[1][1][1]==TheBoard[0][0][0])
	{
		if(TheBoard[1][1][1]=='X')
		{
			NumOfXThrees++;
		} else if(TheBoard[1][1][1]=='O') {
			NumOfOThrees++;
		}
	}
	if(TheBoard[1][1][1]==TheBoard[0][2][2]&&TheBoard[1][1][1]==TheBoard[2][0][0])
	{
		if(TheBoard[1][1][1]=='X')
		{
			NumOfXThrees++;
		} else if(TheBoard[1][1][1]=='O') {
			NumOfOThrees++;
		}
	}
	if(TheBoard[1][1][1]==TheBoard[2][2][0]&&TheBoard[1][1][1]==TheBoard[0][0][2])
	{
		if(TheBoard[1][1][1]=='X')
		{
			NumOfXThrees++;
		} else if(TheBoard[1][1][1]=='O') {
			NumOfOThrees++;
		}
	}
	if(TheBoard[1][1][1]==TheBoard[0][2][0]&&TheBoard[1][1][1]==TheBoard[2][0][2])
	{
		if(TheBoard[1][1][1]=='X')
		{
			NumOfXThrees++;
		} else if(TheBoard[1][1][1]=='O') {
			NumOfOThrees++;
		}
	}
}
bool ThreeDGameBoard::InputMove(int iBoardNum, int iSquareLoc)
{
	int Row;
	int Column;
	if(iSquareLoc>0&&iSquareLoc<10)
	{
		if(iSquareLoc==1||iSquareLoc==2||iSquareLoc==3)
		{
			Row = 0;
			Column = iSquareLoc-1;
		}
		if(iSquareLoc>3)
		{
			iSquareLoc-=3;
			if(iSquareLoc==1||iSquareLoc==2||iSquareLoc==3)
			{
				Row = 1;
				Column = iSquareLoc-1;
			}
			if(iSquareLoc>3)
			{
				iSquareLoc-=3;
				if(iSquareLoc==1||iSquareLoc==2||iSquareLoc==3)
				{
					Row = 2;
					Column = iSquareLoc-1;
				}	
			}
		}
		if(TheBoard[iBoardNum-1][Row][Column]!='X'&&TheBoard[iBoardNum-1][Row][Column]!='O')
		{
			if(iMoveNum%2==1)
			{
				TheBoard[iBoardNum-1][Row][Column] = 'X';
				IncrementMoveNum();
				return true;
			} else if(iMoveNum%2==0) {
				TheBoard[iBoardNum-1][Row][Column] = 'O';
				IncrementMoveNum();
				return true;
			}
		} else {
			cout<<"Space already taken!";
			return false;
		}
	} else {
		cout<<"Invalid Move!";
		return false;
	}
}
class ArtificialController
{
	public:
		ArtificialController()
		{
			//Need to set pre-set values for each board index
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if((j==0||j==2)&&(i==0||i==2))
					{
						BoardIndexValues[0][i][j] = 7;
						BoardIndexValues[2][i][j] = 7;
					}
					else if((j==1&&(i==0||i==2))||((j==0||j==2)&&i==1))
					{
						BoardIndexValues[0][i][j] = 4;
						BoardIndexValues[2][i][j] = 4;
					}
					else if(i==1&&j==1)
					{
						BoardIndexValues[0][i][j] = 5;
						BoardIndexValues[2][i][j] = 5;
					}
				}
			}
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if((i==0||i==2)&&(j==0||j==2))
						BoardIndexValues[1][i][j] = 4;
					else if(((i==0||i==2)&&(j==1))||(i==1&&(j==0||j==2)))
						BoardIndexValues[1][i][j] = 5;
					else if(i==1&&j==1)
						BoardIndexValues[1][i][j] = 13;
				}
			}
		}
		bool IsEmpty(int,int,int);
		bool IsFull(int, int, int);
		void AddPairs(int, int, int);
		void ReEvaluateIndices();
		void ResetIndexValues();
		void EvaluateThrees();
		void EvaluatePairs();
		void EvaluateFilledSquares();
		void OpponentLastMove(int, int);
		void GetNextMove();
		int getValue();
		int GetNextBoard();
		int GetNextBoardLoc();
	private:
	protected:
		int BoardIndexValues[3][3][3];
		//Board position holds 'C' for computer and 'P' for player
		char BoardPositions[3][3][3];
		const int ThreeEvaluation = 1000;
		const int PairEvaluation = 999;
		int BestBoard;
		int BestBoardLoc;
};
void ArtificialController::ReEvaluateIndices()
{
	ResetIndexValues();
	EvaluateThrees();
	EvaluatePairs();
	EvaluateFilledSquares();
}
void ArtificialController::ResetIndexValues()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((j==0||j==2)&&(i==0||i==2))
			{
				BoardIndexValues[0][i][j] = 7;
				BoardIndexValues[2][i][j] = 7;
			}
			else if((j==1&&(i==0||i==2))||((j==0||j==2)&&i==1))
			{
				BoardIndexValues[0][i][j] = 4;
				BoardIndexValues[2][i][j] = 4;
			}
			else if(i==1&&j==1)
			{
				BoardIndexValues[0][i][j] = 5;
				BoardIndexValues[2][i][j] = 5;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((i==0||i==2)&&(j==0||j==2))
				BoardIndexValues[1][i][j] = 4;
			else if(((i==0||i==2)&&(j==1))||(i==1&&(j==0||j==2)))
				BoardIndexValues[1][i][j] = 5;
			else if(i==1&&j==1)
				BoardIndexValues[1][i][j] = 13;
		}
	}
}
void ArtificialController::EvaluateThrees()
{
	//1st grid square #00 - All 7 Configurations complete
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][0][1]=='C'&&BoardPositions[i][0][2]=='C')||
		(BoardPositions[i][0][1]=='P'&&BoardPositions[i][0][2]=='P'))
			BoardIndexValues[i][0][0]+=ThreeEvaluation;
		if((BoardPositions[i][1][0]=='C'&&BoardPositions[i][2][0]=='C')||
		(BoardPositions[i][1][0]=='P'&&BoardPositions[i][2][0]=='P'))
			BoardIndexValues[i][0][0]+=ThreeEvaluation;
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][0][0]+=ThreeEvaluation;
	}
	if((BoardPositions[1][0][0]=='C'&&BoardPositions[2][0][0]=='C')||
	(BoardPositions[1][0][0]=='P'&&BoardPositions[2][0][0]=='P'))
		BoardIndexValues[0][0][0]+=ThreeEvaluation;
	if((BoardPositions[0][0][0]=='C'&&BoardPositions[2][0][0]=='C')||
	(BoardPositions[0][0][0]=='P'&&BoardPositions[2][0][0]=='P'))
		BoardIndexValues[1][0][0]+=ThreeEvaluation;
	if((BoardPositions[1][0][0]=='C'&&BoardPositions[0][0][0]=='C')||
	(BoardPositions[1][0][0]=='P'&&BoardPositions[0][0][0]=='P'))
		BoardIndexValues[2][0][0]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][2]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		} 
		else if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][2]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		}
		if(BoardPositions[1][0][1]=='C')
		{
			if(i==0&&BoardPositions[2][0][2]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][0][1]=='P')
		{
			if(i==0&&BoardPositions[2][0][2]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][0]=='C')
		{
			if(i==0&&BoardPositions[2][2][0]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='C')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][0]=='P')
		{
			if(i==0&&BoardPositions[2][2][0]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='P')
				BoardIndexValues[i][0][0]+=ThreeEvaluation;
		}
	}
	//3rd grid square #02
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][0][1]=='C'&&BoardPositions[i][0][0]=='C')||
		(BoardPositions[i][0][1]=='P'&&BoardPositions[i][0][0]=='P'))
			BoardIndexValues[i][0][2]+=ThreeEvaluation;
		if((BoardPositions[i][1][2]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][1][2]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][0][2]+=ThreeEvaluation;
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][2][0]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][2][0]=='P'))
			BoardIndexValues[i][0][2]+=ThreeEvaluation;
	}
	if((BoardPositions[1][0][2]=='C'&&BoardPositions[2][0][2]=='C')||
	(BoardPositions[1][0][2]=='P'&&BoardPositions[2][0][2]=='P'))
		BoardIndexValues[0][0][2]+=ThreeEvaluation;
	if((BoardPositions[0][0][2]=='C'&&BoardPositions[2][0][2]=='C')||
	(BoardPositions[0][0][2]=='P'&&BoardPositions[2][0][2]=='P'))
		BoardIndexValues[1][0][2]+=ThreeEvaluation;
	if((BoardPositions[1][0][2]=='C'&&BoardPositions[0][0][2]=='C')||
	(BoardPositions[1][0][2]=='P'&&BoardPositions[0][0][2]=='P'))
		BoardIndexValues[2][0][2]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][0]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][0]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
		if(BoardPositions[1][0][1]=='C')
		{
			if(i==0&&BoardPositions[2][0][0]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][0][1]=='P')
		{
			if(i==0&&BoardPositions[2][0][0]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][2]=='C')
		{
			if(i==0&&BoardPositions[2][2][2]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='C')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][2]=='P')
		{
			if(i==0&&BoardPositions[2][2][2]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='P')
				BoardIndexValues[i][0][2]+=ThreeEvaluation;
		}
	}
	//7th grid square #20
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][1][0]=='C'&&BoardPositions[i][0][0]=='C')||
		(BoardPositions[i][1][0]=='P'&&BoardPositions[i][0][0]=='P'))
			BoardIndexValues[i][2][0]+=ThreeEvaluation;
		if((BoardPositions[i][2][1]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][2][1]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][2][0]+=ThreeEvaluation;
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][0][2]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][0][2]=='P'))
			BoardIndexValues[i][2][0]+=ThreeEvaluation;
	}
	if((BoardPositions[1][2][0]=='C'&&BoardPositions[2][2][0]=='C')||
	(BoardPositions[1][2][0]=='P'&&BoardPositions[2][2][0]=='P'))
		BoardIndexValues[0][2][0]+=ThreeEvaluation;
	if((BoardPositions[0][2][0]=='C'&&BoardPositions[2][2][0]=='C')||
	(BoardPositions[0][2][0]=='P'&&BoardPositions[2][2][0]=='P'))
		BoardIndexValues[1][2][0]+=ThreeEvaluation;
	if((BoardPositions[1][2][0]=='C'&&BoardPositions[0][2][0]=='C')||
	(BoardPositions[1][2][0]=='P'&&BoardPositions[0][2][0]=='P'))
		BoardIndexValues[2][2][0]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][0][2]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][0][2]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][0]=='C')
		{
			if(i==0&&BoardPositions[2][0][0]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][0]=='P')
		{
			if(i==0&&BoardPositions[2][0][0]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
		if(BoardPositions[1][2][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][2]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='C')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][2][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][2]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][2]=='P')
				BoardIndexValues[i][2][0]+=ThreeEvaluation;
		}
	}
	//9th grid square #22
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][1][2]=='C'&&BoardPositions[i][0][2]=='C')||
		(BoardPositions[i][1][2]=='P'&&BoardPositions[i][0][2]=='P'))
			BoardIndexValues[i][2][2]+=ThreeEvaluation;
		if((BoardPositions[i][2][1]=='C'&&BoardPositions[i][2][0]=='C')||
		(BoardPositions[i][2][1]=='P'&&BoardPositions[i][2][0]=='P'))
			BoardIndexValues[i][2][2]+=ThreeEvaluation;
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][0][0]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][0][0]=='P'))
			BoardIndexValues[i][2][2]+=ThreeEvaluation;
	}
	if((BoardPositions[1][2][2]=='C'&&BoardPositions[2][2][2]=='C')||
	(BoardPositions[1][2][2]=='P'&&BoardPositions[2][2][2]=='P'))
		BoardIndexValues[0][2][2]+=ThreeEvaluation;
	if((BoardPositions[0][2][2]=='C'&&BoardPositions[2][2][2]=='C')||
	(BoardPositions[0][2][2]=='P'&&BoardPositions[2][2][2]=='P'))
		BoardIndexValues[1][2][2]+=ThreeEvaluation;
	if((BoardPositions[1][2][2]=='C'&&BoardPositions[0][2][2]=='C')||
	(BoardPositions[1][2][2]=='P'&&BoardPositions[0][2][2]=='P'))
		BoardIndexValues[2][2][2]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][0][0]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][0][0]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][0]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
		if(BoardPositions[1][2][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][0]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][2][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][0]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][0]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][2]=='C')
		{
			if(i==0&&BoardPositions[2][0][2]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='C')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
		else if(BoardPositions[1][1][2]=='P')
		{
			if(i==0&&BoardPositions[2][0][2]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][0][2]=='P')
				BoardIndexValues[i][2][2]+=ThreeEvaluation;
		}
	}
	//2nd grid square #01
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][0][0]=='C'&&BoardPositions[i][0][2]=='C')||
		(BoardPositions[i][0][0]=='P'&&BoardPositions[i][0][2]=='P'))
			BoardIndexValues[i][0][1]+=ThreeEvaluation;	
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][2][1]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][2][1]=='P'))
			BoardIndexValues[i][0][1]+=ThreeEvaluation;
	}
	if((BoardPositions[1][0][1]=='C'&&BoardPositions[2][0][1]=='C')||
	(BoardPositions[1][0][1]=='P'&&BoardPositions[2][0][1]=='P'))
		BoardIndexValues[0][0][1]+=ThreeEvaluation;
	if((BoardPositions[0][0][1]=='C'&&BoardPositions[2][0][1]=='C')||
	(BoardPositions[0][0][1]=='P'&&BoardPositions[2][0][1]=='P'))
		BoardIndexValues[1][0][1]+=ThreeEvaluation;
	if((BoardPositions[1][0][1]=='C'&&BoardPositions[0][0][1]=='C')||
	(BoardPositions[1][0][1]=='P'&&BoardPositions[0][0][1]=='P'))
		BoardIndexValues[2][0][1]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][1]=='C')
				BoardIndexValues[0][0][1]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][1]=='C')
				BoardIndexValues[2][0][1]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][1]=='P')
				BoardIndexValues[0][0][1]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][1]=='P')
				BoardIndexValues[2][0][1]+=ThreeEvaluation;
		}
	}
	if(BoardPositions[2][0][0]=='C'&&BoardPositions[0][0][2]=='C')
		BoardIndexValues[1][0][1]+=ThreeEvaluation;
	else if(BoardPositions[2][0][0]=='P'&&BoardPositions[0][0][2]=='P')
			BoardIndexValues[1][0][1]+=ThreeEvaluation;
	if(BoardPositions[2][0][2]=='C'&&BoardPositions[0][0][0]=='C')
		BoardIndexValues[1][0][1]+=ThreeEvaluation;
	else if(BoardPositions[2][0][2]=='P'&&BoardPositions[0][0][0]=='P')
			BoardIndexValues[1][0][1]+=ThreeEvaluation;
	//4th grid square #10
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][0][0]=='C'&&BoardPositions[i][2][0]=='C')||
		(BoardPositions[i][0][0]=='P'&&BoardPositions[i][2][0]=='P'))
			BoardIndexValues[i][1][0]+=ThreeEvaluation;	
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][1][2]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][1][2]=='P'))
			BoardIndexValues[i][1][0]+=ThreeEvaluation;
	}
	if((BoardPositions[1][1][0]=='C'&&BoardPositions[2][1][0]=='C')||
	(BoardPositions[1][1][0]=='P'&&BoardPositions[2][1][0]=='P'))
		BoardIndexValues[0][1][0]+=ThreeEvaluation;
	if((BoardPositions[0][1][0]=='C'&&BoardPositions[2][1][0]=='C')||
	(BoardPositions[0][1][0]=='P'&&BoardPositions[2][1][0]=='P'))
		BoardIndexValues[1][1][0]+=ThreeEvaluation;
	if((BoardPositions[1][1][0]=='C'&&BoardPositions[0][1][0]=='C')||
	(BoardPositions[1][1][0]=='P'&&BoardPositions[0][1][0]=='P'))
		BoardIndexValues[2][1][0]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][1][2]=='C')
				BoardIndexValues[0][1][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][1][2]=='C')
				BoardIndexValues[2][1][0]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][1][2]=='P')
				BoardIndexValues[0][1][0]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][1][2]=='P')
				BoardIndexValues[2][1][0]+=ThreeEvaluation;
		}
	}
	if(BoardPositions[2][0][0]=='C'&&BoardPositions[0][2][0]=='C')
		BoardIndexValues[1][1][0]+=ThreeEvaluation;
	else if(BoardPositions[2][0][0]=='P'&&BoardPositions[0][2][0]=='P')
			BoardIndexValues[1][1][0]+=ThreeEvaluation;
	if(BoardPositions[2][2][0]=='C'&&BoardPositions[0][0][0]=='C')
		BoardIndexValues[1][1][0]+=ThreeEvaluation;
	else if(BoardPositions[2][2][0]=='P'&&BoardPositions[0][0][0]=='P')
			BoardIndexValues[1][1][0]+=ThreeEvaluation;
	//6th grid square #12
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][0][2]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][0][2]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][1][2]+=ThreeEvaluation;	
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][1][0]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][1][0]=='P'))
			BoardIndexValues[i][1][2]+=ThreeEvaluation;
	}
	if((BoardPositions[1][1][2]=='C'&&BoardPositions[2][1][2]=='C')||
	(BoardPositions[1][1][2]=='P'&&BoardPositions[2][1][2]=='P'))
		BoardIndexValues[0][1][2]+=ThreeEvaluation;
	if((BoardPositions[0][1][2]=='C'&&BoardPositions[2][1][2]=='C')||
	(BoardPositions[0][1][2]=='P'&&BoardPositions[2][1][2]=='P'))
		BoardIndexValues[1][1][2]+=ThreeEvaluation;
	if((BoardPositions[1][1][2]=='C'&&BoardPositions[0][1][2]=='C')||
	(BoardPositions[1][1][2]=='P'&&BoardPositions[0][1][2]=='P'))
		BoardIndexValues[2][1][2]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][1][0]=='C')
				BoardIndexValues[0][1][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][1][0]=='C')
				BoardIndexValues[2][1][2]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][1][0]=='P')
				BoardIndexValues[0][1][2]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][1][0]=='P')
				BoardIndexValues[2][1][2]+=ThreeEvaluation;
		}
	}
	if(BoardPositions[2][0][2]=='C'&&BoardPositions[0][2][2]=='C')
		BoardIndexValues[1][1][2]+=ThreeEvaluation;
	else if(BoardPositions[2][0][2]=='P'&&BoardPositions[0][2][2]=='P')
			BoardIndexValues[1][1][2]+=ThreeEvaluation;
	if(BoardPositions[2][2][2]=='C'&&BoardPositions[0][0][2]=='C')
		BoardIndexValues[1][1][2]+=ThreeEvaluation;
	else if(BoardPositions[2][2][2]=='P'&&BoardPositions[0][0][2]=='P')
			BoardIndexValues[1][1][2]+=ThreeEvaluation;
	//8th grid square #21
	for(int i=0;i<3;i++)
	{
		if((BoardPositions[i][2][0]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][2][0]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][2][1]+=ThreeEvaluation;	
		if((BoardPositions[i][1][1]=='C'&&BoardPositions[i][0][1]=='C')||
		(BoardPositions[i][1][1]=='P'&&BoardPositions[i][0][1]=='P'))
			BoardIndexValues[i][2][1]+=ThreeEvaluation;
	}
	if((BoardPositions[1][2][1]=='C'&&BoardPositions[2][2][1]=='C')||
	(BoardPositions[1][2][1]=='P'&&BoardPositions[2][2][1]=='P'))
		BoardIndexValues[0][2][1]+=ThreeEvaluation;
	if((BoardPositions[0][2][1]=='C'&&BoardPositions[2][2][1]=='C')||
	(BoardPositions[0][2][1]=='P'&&BoardPositions[2][2][1]=='P'))
		BoardIndexValues[1][2][1]+=ThreeEvaluation;
	if((BoardPositions[1][2][1]=='C'&&BoardPositions[0][2][1]=='C')||
	(BoardPositions[1][2][1]=='P'&&BoardPositions[0][2][1]=='P'))
		BoardIndexValues[2][2][1]+=ThreeEvaluation;
	for(int i=0;i<3;i+=2)
	{
		if(BoardPositions[1][1][1]=='C')
		{
			if(i==0&&BoardPositions[2][2][1]=='C')
				BoardIndexValues[0][2][1]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][1]=='C')
				BoardIndexValues[2][2][1]+=ThreeEvaluation;
		}
		if(BoardPositions[1][1][1]=='P')
		{
			if(i==0&&BoardPositions[2][2][1]=='P')
				BoardIndexValues[0][2][1]+=ThreeEvaluation;
			else if(i==2&&BoardPositions[0][2][1]=='P')
				BoardIndexValues[2][2][1]+=ThreeEvaluation;
		}
	}
	if(BoardPositions[2][2][0]=='C'&&BoardPositions[0][2][2]=='C')
		BoardIndexValues[1][2][1]+=ThreeEvaluation;
	else if(BoardPositions[2][2][0]=='P'&&BoardPositions[0][2][2]=='P')
			BoardIndexValues[1][2][1]+=ThreeEvaluation;
	if(BoardPositions[2][2][2]=='C'&&BoardPositions[0][2][0]=='C')
		BoardIndexValues[1][2][1]+=ThreeEvaluation;
	else if(BoardPositions[2][2][2]=='P'&&BoardPositions[0][2][0]=='P')
			BoardIndexValues[1][2][1]+=ThreeEvaluation;
	//5th grid #11
	for(int i=0;i<3;i+=2)
	{
		if((BoardPositions[i][0][0]=='C'&&BoardPositions[i][2][2]=='C')||
		(BoardPositions[i][0][0]=='P'&&BoardPositions[i][2][2]=='P'))
			BoardIndexValues[i][1][1]+=ThreeEvaluation;
		if((BoardPositions[i][0][2]=='C'&&BoardPositions[i][2][0]=='C')||
		(BoardPositions[i][0][2]=='P'&&BoardPositions[i][2][0]=='P'))
			BoardIndexValues[i][1][1]+=ThreeEvaluation;
		if((BoardPositions[i][0][1]=='C'&&BoardPositions[i][2][1]=='C')||
		(BoardPositions[i][0][1]=='P'&&BoardPositions[i][2][1]=='P'))
			BoardIndexValues[i][1][1]+=ThreeEvaluation;
		if((BoardPositions[i][1][0]=='C'&&BoardPositions[i][1][2]=='C')||
		(BoardPositions[i][1][0]=='P'&&BoardPositions[i][1][2]=='P'))
			BoardIndexValues[i][1][1]+=ThreeEvaluation;
	}
	if((BoardPositions[2][1][1]=='C'&&BoardPositions[1][1][1]=='C')||
	(BoardPositions[2][1][1]=='P'&&BoardPositions[1][1][1]=='P'))
		BoardIndexValues[0][1][1];
	if((BoardPositions[0][1][1]=='C'&&BoardPositions[1][1][1]=='C')||
	(BoardPositions[0][1][1]=='P'&&BoardPositions[1][1][1]=='P'))
		BoardIndexValues[2][1][1];
	if(BoardPositions[1][1][1]!='P')
		BoardIndexValues[1][1][1]=1000;
}
void ArtificialController::EvaluatePairs()
{
	//NOTE: THE FOLLOWING LOOP ONLY EVALUATES FOR PAIRS ON THE SAME LVL
		for(int i=0;i<3;i++)
		{
			//#00
			if(IsEmpty(i,0,2)&&IsEmpty(i,0,0)&&IsFull(i,0,1))
			{
				AddPairs(i,0,0);
			} else if(IsEmpty(i,0,1)&&IsEmpty(i,0,0)&&IsFull(i,0,2)) {
				AddPairs(i,0,0);
			}
			if(IsEmpty(i,1,0)&&IsEmpty(i,0,0)&&IsFull(i,2,0))
			{
				AddPairs(i,0,0);
			} else if(IsEmpty(i,1,0)&&IsEmpty(i,0,0)&&IsFull(i,2,0)) {
				AddPairs(i,0,0);
			}
			if(IsEmpty(i,2,2)&&IsEmpty(i,0,0)&&IsFull(i,1,1))
			{
				AddPairs(i,0,0);
			} else if(IsEmpty(i,1,1)&&IsEmpty(i,0,0)&&IsFull(i,2,2)) {
				AddPairs(i,0,0);
			}
			//#02
			if(IsEmpty(i,0,2)&&IsEmpty(i,0,0)&&IsFull(i,0,1))
			{
				AddPairs(i,0,2);
			} else if(IsEmpty(i,0,2)&&IsEmpty(i,0,1)&&IsFull(i,0,0)) {
				AddPairs(i,0,2);
			}
			if(IsEmpty(i,1,2)&&IsEmpty(i,0,2)&&IsFull(i,2,2))
			{
				AddPairs(i,0,2);
			} else if(IsEmpty(i,2,2)&&IsEmpty(i,0,2)&&IsFull(i,1,2)) {
				AddPairs(i,0,2);
			}
			if(IsEmpty(i,0,2)&&IsEmpty(i,2,0)&&IsFull(i,1,1))
			{
				AddPairs(i,0,2);
			} else if(IsEmpty(i,2,0)&&IsEmpty(i,1,1)&&IsFull(i,2,0)) {
				AddPairs(i,0,2);
			}
			//#20
			if(IsEmpty(i,2,0)&&IsEmpty(i,2,2)&&IsFull(i,2,1))
			{
				AddPairs(i,2,0);
			} else if(IsEmpty(i,2,0)&&IsEmpty(i,2,1)&&IsFull(i,2,2)) {
				AddPairs(i,2,0);
			}
			if(IsEmpty(i,2,0)&&IsEmpty(i,0,0)&&IsFull(i,1,0))
			{
				AddPairs(i,2,0);
			} else if(IsEmpty(i,2,0)&&IsEmpty(i,1,0)&&IsFull(i,0,0)) {
				AddPairs(i,2,0);
			}
			if(IsEmpty(i,2,0)&&IsEmpty(i,0,2)&&IsFull(i,1,1))
			{
				AddPairs(i,2,0);
			} else if(IsEmpty(i,2,0)&&IsEmpty(i,1,1)&&IsFull(i,0,2)) {
				AddPairs(i,2,0);
			}
			//#22
			if(IsEmpty(i,2,2)&&IsEmpty(i,2,1)&&IsFull(i,2,0))
			{
				AddPairs(i,2,2);
			} else if(IsEmpty(i,2,2)&&IsEmpty(i,2,0)&&IsFull(i,2,1)) {
				AddPairs(i,2,2);
			}
			if(IsEmpty(i,2,2)&&IsEmpty(i,0,2)&&IsFull(i,1,2))
			{
				AddPairs(i,2,2);
			} else if(IsEmpty(i,2,2)&&IsEmpty(i,1,2)&&IsFull(i,0,2)) {
				AddPairs(i,2,2);
			}
			if(IsEmpty(i,2,2)&&IsEmpty(i,0,0)&&IsFull(i,1,1))
			{
				AddPairs(i,2,2);
			} else if(IsEmpty(i,2,2)&&IsEmpty(i,1,1)&&IsFull(i,0,0)) {
				AddPairs(i,2,2);
			}
			//#01
			if(IsEmpty(i,0,1)&&IsEmpty(i,0,0)&&IsFull(i,0,2))
			{
				AddPairs(i,0,1);
			} else if(IsEmpty(i,0,1)&&IsEmpty(i,0,2)&&IsFull(i,0,0)) {
				AddPairs(i,0,1);
			}
			if(IsEmpty(i,0,1)&&IsEmpty(i,1,1)&&IsFull(i,2,1))
			{
				AddPairs(i,0,1);
			} else if(IsEmpty(i,0,1)&&IsEmpty(i,2,1)&&IsFull(i,1,1)) {
				AddPairs(i,0,1);
			}
			//#10
			if(IsEmpty(i,1,0)&&IsEmpty(i,1,1)&&IsFull(i,1,2))
			{
				AddPairs(i,1,0);
			} else if(IsEmpty(i,1,0)&&IsEmpty(i,1,2)&&IsFull(i,1,1)) {
				AddPairs(i,1,0);
			}
			if(IsEmpty(i,1,0)&&IsEmpty(i,0,0)&&IsFull(i,2,0))
			{
				AddPairs(i,1,0);
			} else if(IsEmpty(i,1,0)&&IsEmpty(i,2,0)&&IsFull(i,0,0)) {
				AddPairs(i,1,0);
			}
			//#12
			if(IsEmpty(i,1,2)&&IsEmpty(i,1,1)&&IsFull(i,1,0))
			{
				AddPairs(i,1,2);
			} else if(IsEmpty(i,1,2)&&IsEmpty(i,1,0)&&IsFull(i,1,1)) {
				AddPairs(i,1,2);
			}
			if(IsEmpty(i,1,2)&&IsEmpty(i,0,2)&&IsFull(i,2,2))
			{
				AddPairs(i,1,2);
			} else if(IsEmpty(i,1,2)&&IsEmpty(i,2,2)&&IsFull(i,0,2)) {
				AddPairs(i,1,2);
			}
			//#21
			if(IsEmpty(i,2,1)&&IsEmpty(i,2,2)&&IsFull(i,2,0))
			{
				AddPairs(i,2,1);
			} else if(IsEmpty(i,2,1)&&IsEmpty(i,2,0)&&IsFull(i,2,2)) {
				AddPairs(i,2,1);
			}
			if(IsEmpty(i,2,1)&&IsEmpty(i,0,1)&&IsFull(i,1,1))
			{
				AddPairs(i,2,1);
			} else if(IsEmpty(i,2,1)&&IsEmpty(i,1,1)&&IsFull(i,0,1)) {
				AddPairs(i,2,1);
			}
			//#11
			if(IsEmpty(i,1,1)&&IsEmpty(i,0,1)&&IsFull(i,2,1))
			{
				AddPairs(i,1,1);
			} else if(IsEmpty(i,1,1)&&IsEmpty(i,2,1)&&IsFull(i,0,1)) {
				AddPairs(i,1,1);
			}
			if(IsEmpty(i,1,1)&&IsEmpty(i,1,0)&&IsFull(i,1,2))
			{
				AddPairs(i,1,1);
			} else if(IsEmpty(i,1,1)&&IsEmpty(i,1,2)&&IsFull(i,1,0)) {
				AddPairs(i,1,1);
			}
			if(IsEmpty(i,1,1)&&IsEmpty(i,0,0)&&IsFull(i,2,2))
			{
				AddPairs(i,1,1);
			} else if(IsEmpty(i,1,1)&&IsEmpty(i,2,2)&&IsFull(i,0,0)) {
				AddPairs(i,1,1);
			}
			if(IsEmpty(i,1,1)&&IsEmpty(i,0,2)&&IsFull(i,2,0))
			{
				AddPairs(i,1,1);
			} else if(IsEmpty(i,1,1)&&IsEmpty(i,2,0)&&IsFull(i,0,2)) {
				AddPairs(i,1,1);
			}
		}
		//THIS FOR LOOP ONLY EVALUATES VERTICAL COLUMNS THROUGH THE BOARD
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(i==0)
					{
						if(IsEmpty(0,j,k)&&IsEmpty(1,j,k)&&IsFull(2,j,k))
						{
							AddPairs(0,j,k);
						} else if(IsEmpty(0,j,k)&&IsEmpty(2,j,k)&&IsFull(1,j,k)) {
							AddPairs(0,j,k);
						}
					} else if(i==1) {
						if(IsEmpty(1,j,k)&&IsEmpty(0,j,k)&&IsFull(2,j,k))
						{
							AddPairs(1,j,k);
						} else if(IsEmpty(1,j,k)&&IsEmpty(2,j,k)&&IsFull(0,j,k)) {
							AddPairs(1,j,k);
						}
					} else if(i==2) {
						if(IsEmpty(2,j,k)&&IsEmpty(1,j,k)&&IsFull(0,j,k))
						{
							AddPairs(2,j,k);
						} else if(IsEmpty(2,j,k)&&IsEmpty(0,j,k)&&IsFull(1,j,k)) {
							AddPairs(2,j,k);
						}
					}
				}
			}
		}
		//THIS CODE ONLY EVALUATES DIAGONALS THROUGH THE CENTER
		if(IsFull(1,1,1))
		{
			//Top grid
			if(IsEmpty(0,0,0)&&IsEmpty(2,2,2))
				AddPairs(0,0,0);
			if(IsEmpty(0,0,1)&&IsEmpty(2,2,1))
				AddPairs(0,0,1);
			if(IsEmpty(0,0,2)&&IsEmpty(2,2,0))
				AddPairs(0,0,2);
			if(IsEmpty(0,1,0)&&IsEmpty(2,1,2))
				AddPairs(0,1,0);
			if(IsEmpty(0,1,2)&&IsEmpty(2,1,0))
				AddPairs(0,1,2);
			if(IsEmpty(0,2,0)&&IsEmpty(2,0,2))
				AddPairs(0,2,0);
			if(IsEmpty(0,2,1)&&IsEmpty(2,0,1))
				AddPairs(0,2,1);
			if(IsEmpty(0,2,2)&&IsEmpty(2,0,0))
				AddPairs(0,2,2);
			//Bottom grid
			if(IsEmpty(2,0,0)&&IsEmpty(0,2,2))
				AddPairs(2,0,0);
			if(IsEmpty(2,0,1)&&IsEmpty(0,2,1))
				AddPairs(2,0,1);
			if(IsEmpty(2,0,2)&&IsEmpty(0,2,0))
				AddPairs(2,0,2);
			if(IsEmpty(2,1,0)&&IsEmpty(0,1,2))
				AddPairs(2,1,0);
			if(IsEmpty(2,1,2)&&IsEmpty(0,1,0))
				AddPairs(2,1,2);
			if(IsEmpty(2,2,0)&&IsEmpty(0,0,2))
				AddPairs(2,2,0);
			if(IsEmpty(2,2,1)&&IsEmpty(0,0,1))
				AddPairs(2,2,1);
			if(IsEmpty(2,2,2)&&IsEmpty(0,0,0))
				AddPairs(2,2,2);
		}
		//Time for the side diagonals
		//Diagonals through 101
		if(IsFull(1,0,1))
		{
			if(IsEmpty(0,0,0)&&IsEmpty(2,0,2))
			{
				AddPairs(0,0,0);
				AddPairs(2,0,2);
			}
			if(IsEmpty(0,0,2)&&IsEmpty(2,0,0))
			{
				AddPairs(0,0,2);
				AddPairs(2,0,0);
			}
		} else if(IsEmpty(1,0,1)) {
			if(IsFull(0,0,0)&&IsEmpty(2,0,2))
			{
				AddPairs(1,0,1);
				AddPairs(2,0,2);
			} else if(IsFull(2,0,2)&&IsEmpty(0,0,0)) {
				AddPairs(1,0,1);
				AddPairs(0,0,0);
			}
			if(IsFull(0,0,2)&&IsEmpty(2,0,0))
			{
				AddPairs(1,0,1);
				AddPairs(2,0,0);
			} else if(IsFull(2,0,0)&&IsEmpty(0,0,2)) {
				AddPairs(1,0,1);
				AddPairs(0,0,2);
			}
		}
		//Diagonals through 110
		if(IsFull(1,1,0))
		{
			if(IsEmpty(0,0,0)&&IsEmpty(2,2,0))
			{
				AddPairs(0,0,0);
				AddPairs(2,2,0);
			}
			if(IsEmpty(0,2,0)&&IsEmpty(2,0,0))
			{
				AddPairs(0,2,0);
				AddPairs(2,0,0);
			}
		} else if(IsEmpty(1,1,0)) {
			if(IsFull(0,0,0)&&IsEmpty(2,2,0))
			{
				AddPairs(1,1,0);
				AddPairs(2,2,0);
			} else if(IsFull(2,2,0)&&IsEmpty(0,0,0)) {
				AddPairs(1,1,0);
				AddPairs(0,0,0);
			}
			if(IsFull(0,2,0)&&IsEmpty(2,0,0))
			{
				AddPairs(1,1,0);
				AddPairs(2,0,0);
			} else if(IsFull(2,0,0)&&IsEmpty(0,2,0)) {
				AddPairs(1,1,0);
				AddPairs(0,2,0);
			}
		}
		//Diagonals through 112
		if(IsFull(1,1,2))
		{
			if(IsEmpty(0,2,2)&&IsEmpty(2,0,2))
			{
				AddPairs(0,2,2);
				AddPairs(2,0,2);
			}
			if(IsEmpty(0,0,2)&&IsEmpty(2,2,2))
			{
				AddPairs(0,0,2);
				AddPairs(2,2,2);
			}
		} else if(IsEmpty(1,1,2)) {
			if(IsFull(0,2,2)&&IsEmpty(2,0,2))
			{
				AddPairs(1,1,2);
				AddPairs(2,0,2);
			} else if(IsFull(2,0,2)&&IsEmpty(0,2,2)) {
				AddPairs(1,1,2);
				AddPairs(0,2,2);
			}
			if(IsFull(0,0,2)&&IsEmpty(2,2,2))
			{
				AddPairs(1,1,2);
				AddPairs(2,2,2);
			} else if(IsFull(2,2,2)&&IsEmpty(0,0,2)) {
				AddPairs(1,1,2);
				AddPairs(0,0,2);
			}
		}
		//Diagonals through 121
		if(IsFull(1,2,1))
		{
			if(IsEmpty(0,2,0)&&IsEmpty(2,2,2))
			{
				AddPairs(0,2,0);
				AddPairs(2,2,2);
			}
			if(IsEmpty(0,2,2)&&IsEmpty(2,2,0))
			{
				AddPairs(0,2,2);
				AddPairs(2,2,0);
			}
		} else if(IsEmpty(1,2,1)) {
			if(IsFull(0,2,0)&&IsEmpty(2,2,2))
			{
				AddPairs(1,2,1);
				AddPairs(2,2,2);
			} else if(IsFull(2,2,2)&&IsEmpty(0,2,0)) {
				AddPairs(1,2,1);
				AddPairs(0,2,0);
			}
			if(IsFull(0,2,2)&&IsEmpty(2,2,0))
			{
				AddPairs(1,2,1);
				AddPairs(2,2,0);
			} else if(IsFull(2,2,0)&&IsEmpty(0,2,2)) {
				AddPairs(1,2,1);
				AddPairs(0,2,2);
			}
		}
		//DONE IT EVALUATES ALL PAIRS
}
void ArtificialController::AddPairs(int BoardNum, int RowNum, int ColumnNum)
{
	BoardIndexValues[BoardNum][RowNum][ColumnNum]+=PairEvaluation;
}
bool ArtificialController::IsFull(int BoardNum, int RowNum, int ColumnNum)
{
	if(BoardPositions[BoardNum][RowNum][ColumnNum]=='C')
		return true;
	else
		return false;
}
bool ArtificialController::IsEmpty(int BoardNum, int RowNum, int ColumnNum)
{
	if(BoardPositions[BoardNum][RowNum][ColumnNum]!='C'&&BoardPositions[BoardNum][RowNum][ColumnNum]!='P')
		return true;
	else
		return false;
}
void ArtificialController::EvaluateFilledSquares()
{
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			for(int j=0;j<3;j++)
			{
				if(BoardPositions[i][j][k]=='C'||BoardPositions[i][j][k]=='P')
					BoardIndexValues[i][j][k] = 0;
			}
		}
	}
}
void ArtificialController::GetNextMove()
{
	ReEvaluateIndices();
	int MaxIndexValue = 0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			for(int j=0;j<3;j++)
			{
				if(BoardIndexValues[i][j][k]>MaxIndexValue)
				{
					MaxIndexValue = BoardIndexValues[i][j][k];
					BestBoard = i+1;
					if(j==0)
					{
						BestBoardLoc = k+1;
					} else if(j==1) {
						BestBoardLoc = k+4;
					} else if(j==2) {
						BestBoardLoc = k+7;
					}
				}
			}
		}
	}
	if(MaxIndexValue==0)
	{
		cout<<"A critical error has occurred!\n The maximum value is: "<<MaxIndexValue;
		system("pause");
	}
	if(BestBoardLoc<=3)
	{
		if(BoardPositions[BestBoard-1][0][BestBoardLoc-1]=='C'||
		BoardPositions[BestBoard-1][0][BestBoardLoc-1]=='P')
		{
			cout<<"THE SPOT IS FILLED";
			system("pause");
		}
		BoardPositions[BestBoard-1][0][BestBoardLoc-1] = 'C';
	} else if(BestBoardLoc>3&&BestBoardLoc<=6) {
		if(BoardPositions[BestBoard-1][1][BestBoardLoc-4]=='C'||
		BoardPositions[BestBoard-1][1][BestBoardLoc-4]=='P')
		{
			cout<<"THE SPOT IS FILLED";
			system("pause");
		}
		BoardPositions[BestBoard-1][1][BestBoardLoc-4] = 'C';
	} else if(BestBoardLoc>6) {
		if(BoardPositions[BestBoard-1][2][BestBoardLoc-7]=='C'||
		BoardPositions[BestBoard-1][2][BestBoardLoc-7]=='P')
		{
			cout<<"THE SPOT IS FILLED";
			system("pause");
		}
		BoardPositions[BestBoard-1][2][BestBoardLoc-7] = 'C';
	} else if(BestBoardLoc>9||BestBoardLoc<1||BestBoard<1||BestBoard>3) {
		cout<<"OUT OF SCOPE OF THE ARRAY";
		system("pause");
	}
}
void ArtificialController::OpponentLastMove(int BoardNum, int BoardLocNum)
{
	if(BoardLocNum<=3)
	{
		BoardPositions[BoardNum-1][0][BoardLocNum-1] = 'P';
	} else if(BoardLocNum>3&&BoardLocNum<=6) {
		BoardPositions[BoardNum-1][1][BoardLocNum-4] = 'P';
	} else if(BoardLocNum>6) {
		BoardPositions[BoardNum-1][2][BoardLocNum-7] = 'P';
	}
}
int ArtificialController::GetNextBoard()
{
	return BestBoard;
}
int ArtificialController::GetNextBoardLoc()
{
	return BestBoardLoc;
}
int ArtificialController::getValue()
{
	//Function meant to debug
	return BoardIndexValues[1][1][1];
}
int main(void)
{
	srand(time(NULL));
	ThreeDGameBoard MyBoard;
	ArtificialController MyOpponent;
	int iBoardSelect = 10;
	int iBoardLoc = 10;
	int CompBoard;
	int CompLoc;
	int ComputerPlayPosition = 1;
	if(ComputerPlayPosition==1)
	{
		MyOpponent.GetNextMove();
		CompBoard = MyOpponent.GetNextBoard();
		CompLoc = MyOpponent.GetNextBoardLoc();
		MyBoard.InputMove(CompBoard, CompLoc);
	}
	while(!MyBoard.GameOver())
	{
		iBoardSelect = 10;
		iBoardLoc = 10;
		do
		{
			system("cls");
			MyBoard.DrawBoard();
			cout<<"Enter the board number: ";
			cin>>iBoardSelect;
			cout<<"Enter the location on the board: ";
			cin>>iBoardLoc;
		}while(!MyBoard.InputMove(iBoardSelect, iBoardLoc));
		if(!MyBoard.GameOver())
		{
			MyOpponent.OpponentLastMove(iBoardSelect, iBoardLoc);
			MyOpponent.GetNextMove();
			CompBoard = MyOpponent.GetNextBoard();
			CompLoc = MyOpponent.GetNextBoardLoc();
			MyBoard.InputMove(CompBoard, CompLoc);
		}
	}
	system("cls");
	MyBoard.DrawBoard();
	MyBoard.GetScore();
}
