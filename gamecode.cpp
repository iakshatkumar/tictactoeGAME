#include<iostream>

using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char turn ='X';
bool draw=false;




void display_board()
{
	system("cls");
	cout<<endl<<"\t\t\t\tTICK TAC TOE\t\t\t\t"<<endl;
	
	cout<<"\tPlayer1[x]"<<endl<<"\tPlayer2[O]"<<endl<<endl;

	cout<<"\t\t\t       |       |       "<<endl;
	cout<<"\t\t\t   "<<board[0][0]<<"   |   "<<board[0][1]<<"   |   "<<board[0][2]<<"   "<<endl;
	cout<<"\t\t\t_______|_______|_______"<<endl;
	cout<<"\t\t\t       |       |       "<<endl;
	cout<<"\t\t\t   "<<board[1][0]<<"   |   "<<board[1][1]<<"   |   "<<board[1][2]<<"   "<<endl;
	cout<<"\t\t\t_______|_______|_______"<<endl;
	cout<<"\t\t\t       |       |       "<<endl;
	cout<<"\t\t\t   "<<board[2][0]<<"   |   "<<board[2][1]<<"   |   "<<board[2][2]<<"   "<<endl;
	cout<<"\t\t\t       |       |       "<<endl;
}

void make_choice()
{
	
	if(turn=='X')
	{
		cout<<"\tPlayer1[X] turn : ";
	}
	else if(turn=='O')
	{
		cout<<"\tPlayer2[O] turn : ";
	}
	int choice;
    
	cin>>choice;
	
	switch(choice){
		
		case 1:
			row=0,column=0;
			break;
			
		case 2:
			row=0,column=1;
			break;
				
		case 3:
			row=0,column=2;
			break;
		case 4:
			row=1,column=0;
			break;
		case 5:
			row=1,column=1;
			break;
		case 6:
			row=1,column=2;
			break;
		case 7:
			row=2,column=0;
			break;
		case 8:
			row=2,column=1;
			break;
		case 9:
			row=2,column=2;
			break;	
		default:
			cout<<"Invalid Choice";
			break;
	}
	
	if(turn == 'X' && board[row][column]!='X' && board[row][column]!='O')
	{
		board[row][column]='X';
		turn='O';		
    }
    else if(turn == 'O' && board[row][column]!='X'&& board[row][column]!='O')
    {
    	board[row][column]='O';
    	turn='X';
	}
	else {
		cout<<"\tBox already filled!!\n\tPlease try again \n";
		make_choice(); 
	}
	
	 display_board();
}

bool game_over()
{
	for(int i=0;i<3;i++)
	{
	
	if( board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i] )
	return false;
	
	}
    
	
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
	return false;
	
	
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		if(board[i][j]!='X' && board[i][j]!='O')
    		return true;
		}
	}
	
	
	draw=true;
	return false;
}



int main()
{
	while(game_over()){
	 	
	display_board();
	
	make_choice();
     
	}
	
	if(turn == 'X' && draw!=true)
		cout<<"\n\n\t\t  Congratulation Player2[O] WINS!!"<<endl;
		
	else if(turn == 'O' && draw!=true)
		cout<<"\n\n\t\t  Congratulation Player1[X] WINS!!"<<endl;	
	
	else
	{
		cout<<"\n\n\t\t###################### GAME DRAW #######################\t\n";
	
		
	}
}
