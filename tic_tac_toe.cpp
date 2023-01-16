#include<iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};  // Rows and column numbers in spaces. Global Access.
bool switch_player = true;  // To switch from one player to other.

/*Functions for the terminal interface elements.*/
class UI
{
    public:
        // Display tic-tac-toe board.
        void getStructure(char arr[][3])
        {
            cout<<"\n     |     |      "<<endl;
            cout<<"  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  "<<endl;
            cout<<"_____|_____|______"<<endl;
            cout<<"     |     |      "<<endl;
            cout<<"  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  "<<endl;
            cout<<"_____|_____|______"<<endl;
            cout<<"     |     |      "<<endl;
            cout<<"  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  "<<endl;
            cout<<"     |     |      "<<endl;

        }
        // Display Welcomscreen.
        void welcomeScreen()
        {
            cout<<endl;
            cout<<"..........................................."<<endl;
            cout<<"|                                         |"<<endl;
            cout<<"|             W.E.L.C.O.M.E               |"<<endl;
            cout<<"|                                         |"<<endl;
            cout<<"|              TIC TAC TOE                |"<<endl;
            cout<<"|                                         |"<<endl;
            cout<<"..........................................."<<endl;
        }
        // Display Congratulations.
        void congratulationScreen()
        {
            cout<<endl;
            cout<<"..........................................."<<endl;
            cout<<"|                                         |"<<endl;
            cout<<"|    C.O.N.G.R.A.T.U.L.A.T.I.O.N.S        |"<<endl;
            cout<<"|                                         |"<<endl;
            cout<<"..........................................."<<endl;
        }
        // Display menu screen after game.
        void afterGameMenu()
        {
            cout<<endl;
            cout<<"..........................................."<<endl;
            cout<<"|                TYPE:                    |"<<endl;
            cout<<"..........................................."<<endl;
            cout<<"|          1 - Start New Game             |"<<endl;
            cout<<"|          2 - Play Again                 |"<<endl;
            cout<<"|          0 - Exit                       |"<<endl;
            cout<<"..........................................."<<endl;
        }
};

/*Functions for the functionality of the game.*/
class Brain
{
    public:
        // Takes input from players and marks the board.
        void takeInput(string playera, string playerb)
        {
            int digit;  // To take input from players.

            pair<int, int> p;  // To get row and column pair.

            bool wrong_val = true;  // Limiting condition.

            if(switch_player)  // Player 1 is playing
            {
                // To prevent wrong input.
                do
                {
                    cout<<"\n"<<playera<<" your turn. Enter the digit where you want to place token: ";
                    cin>>digit;

                    // Check if player entered value is correct.
                    if(digit == 1 || digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
                    {
                        if(alreadyMarked(digit) == true)
                        {
                            cout<<"\nPlace is already marked. Please choose another digit."<<endl;  // Letting user know their errors.
                        }
                        else
                        {
                            wrong_val = false;  // Flag.
                        }
                    }
                    else
                    {
                        cout<<"\nInvalid Input!!"<<endl;
                    }
                } while (wrong_val);
                
                p = getRowAndCol(digit);  // Storing row and column values in pair datatype.

                placeMark(p.first, p.second);  // Marking the board at the given row and column stored in p.

                switch_player = false;  // Switching player.
            }
            else  // Player 2 is playing.
            {
                // To prevent wrong input.
                do
                {
                    cout<<"\n"<<playerb<<" your turn. Enter the digit where you want to place token: ";
                    cin>>digit;

                    // Check if player entered value is correct.
                    if(digit == 1 || digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
                    {
                        if(alreadyMarked(digit) == true)
                        {
                            cout<<"\nPlace is already marked. Please choose another digit."<<endl;  // Letting user know their errors.
                        }
                        else
                        {
                            wrong_val = false;  // Flag.
                        }
                    }
                    else
                    {
                        cout<<"\nInvalid Input!!"<<endl;
                    }
                } while (wrong_val);
                
                p = getRowAndCol(digit);  // Storing row and column values in pair datatype.

                placeMark(p.first, p.second);  // Marking the board at the given row and column stored in p.

                switch_player = true;  // Switching player.
            }
        }

        // Returns the pair of row and column where mark is to be placed. Takes argument as digits.
        pair<int, int> getRowAndCol(int digit)
        {
            int row, col;
            
            if(digit == 1)
            {
                row = 0;
                col = 0;
            }
            else if(digit == 2)
            {
                row = 0;
                col = 1;
            }
            else if(digit == 3)
            {
                row = 0;
                col = 2;
            }
            else if(digit == 4)
            {
                row = 1;
                col = 0;
            }
            else if(digit == 5)
            {
                row = 1;
                col = 1;
            }
            else if(digit == 6)
            {
                row = 1;
                col = 2;
            }
            else if(digit == 7)
            {
                row = 2;
                col = 0;
            }
            else if(digit == 8)
            {
                row = 2;
                col = 1;
            }
            else if(digit == 9)
            {
                row = 2;
                col = 2;
            }

            return make_pair(row, col);  // Make pair function to return pair.
        } 

        // Places mark of valid player.
        void placeMark(int r, int c)
        {
            if(switch_player)
            {
                board[r][c] = 'X';
            }
            else
            {
                board[r][c] = 'O';
            }
        }

        // Checks if the position is already marked or not.
        bool alreadyMarked(int digit)
        {
            pair<int, int> p;

            p = getRowAndCol(digit);  // Getting row and column entered by the user.

            if(board[p.first][p.second] == 'X' || board[p.first][p.second] == 'O')  // Checks if place is already occupied with either X or O.
            {
                return true;
            }
            return false;
        }

        // Checks if there are any winning patterns on the board.
        bool winPattern()
        {
            for(int i=0;i<3;i++)
            {
                if(board[0][i] == board[1][i] && board[0][i] == board[2][i])  // Horizontal winning pattern.
                {
                    return true;
                }
                if(board[i][0] == board[i][1] && board[i][0] == board[i][2])  // Vertical winning pattern.
                {
                    return true;
                }
            }
            if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2]== board[2][0]))  // Diagonal winning pattern. 
            {
                return true;
            }
            return false;
        }

        // Checks and displays which player has won the game. Taking arguments to display winner.
        bool checkWin(string playerA, string playerB)
        {
            if(winPattern() == true)
            {
                if(switch_player == true)  // Checking which player has won the game.
                {
                    cout<<playerA<<" WINS THE GAME!!"<<endl;
                }
                else
                {
                    cout<<playerB<<" WINS THE GAME!!"<<endl;
                }
                return true;
            }
            return false;
        }

        // Shows menu to user after game ends.
        int afterGameMenuFunc()
        {
            int usr_ch;  // Storing user choice.

            bool correct_optn = false;  // Loop to ensure correct input.

            do
            {
                cout<<"\nYour choice: ";
                cin>>usr_ch;

                if(usr_ch == 1 || usr_ch == 0 || usr_ch == 2)  // User inputs among given options.
                {
                    correct_optn = true;  // To break the loop.

                    switch (usr_ch)
                    {
                    case 1:
                        return 1;
                        break;

                    case 2:
                        return -1;
                        break;

                    case 0:
                        return 0;
                        break;

                    default:
                        break;
                    }
                }
                else
                {
                    cout<<"\nInvalid input!"<<endl;
                }
            } while (!correct_optn);
            
        }

        // Resets board for the next game.
        void resetBoard()
        {
            char num[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};  // Re-defining hardcoded character array.
            int k=0;  // Iterator for num array;

            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    board[i][j] = num[k];  // Replacing Xs and Os with numbers.
                    k++;
                }
            }
        }
};

int main()
{
    // Object for User Interface.
    UI element;
    // Object for accessing functions.
    Brain head;

    bool game_running = true;  // Running the game in loop to provide menu driven funcionality.
    int flag = 0;  //  To decide whether to increment num iterator or not depending on user choice.
    int num = 0;  // Iterator for number of moves. Numbe of moves in TIC TAC TOE is fixed to 9.
    int ch;  // To take user choice given by afterGameMenuFunc().

    string player1, player2;  // Names of Player 1 and Player 2.

    do
    {

        if(flag != 1)
        {
            element.welcomeScreen();  // Display Welcome Screen.
            // Taking input of users.
            cout<<"\nEnter the name of the first player: ";
            getline(cin, player1);

            cout<<"\nEnter the name of the second player: ";
            getline(cin, player2);

            num = 0;  // Initiating to 0 to define bound conditions for loop.

            element.getStructure(board);  // Initail display of structure.
        }
        flag = 0;  // Re-initialising flag to prevent infinite loop.

        while(num!=9)  // Bound condition.
        {
            cout<<num<<endl;
            head.takeInput(player1, player2);  // Take input and do the marking.
            element.getStructure(board);  // Display marked structure of the board.

            if(head.checkWin(player2, player1) == true)  // Check winning conditions everytime.
            {
                element.congratulationScreen();  // If any player wins.

                element.afterGameMenu();  // Displaying Menu.

            ch = head.afterGameMenuFunc();  // Storing user choice explicitly.
                
                if(ch == 0)  // To exit from the game.
                {
                    game_running = false;
                    break;
                }
                else if(ch == -1)  // To play the game AGAIN. 
                {
                    head.resetBoard();  // Resetting board.
                    element.getStructure(board);  // Displaying empty board.
                    switch_player = !switch_player;  // Switching player to initial one.
                    flag = 1;  // To stop incrementing num and start from 0.
                    num = 0;  // Re-initialising num to 0 to play with the same players.
                }
                else if(ch == 1)  // To start new game.
                {
                    head.resetBoard();  // Resetting board.
                    switch_player = !switch_player;  // Switching player.
                    break;  // Breaking of num while loop and starting from inputting user names.
                }    
            }
            // Checking to increment num:
            if(flag != 1)
            { 
                num++;
            }
            flag = 0;  // Re-initialising flag to prevent infinite loop -> If you can solve this condition, without this please put the pull request after optimization. 
        }

        // Tie condition.
        if(num >= 9)
        {
            cout<<"\nGame is tied!"<<endl;  // Displaying TIE message.
            element.afterGameMenu();  // Show menu.

            // Same Funcitonality as above.
            ch = head.afterGameMenuFunc();  // Storing user choice explicitly.
                
            if(ch == 0)  // To exit from the game.
            {
                game_running = false;
                break;
            }
            else if(ch == -1)  // To play the game AGAIN. 
            {
                head.resetBoard();  // Resetting board.
                element.getStructure(board);  // Displaying empty board.
                switch_player = !switch_player;  // Switching player to initial one.
                flag = 1;  // To stop incrementing num and start from 0.
                num = 0;  // Re-initialising num to 0 to play with the same players.
            }
            else if(ch == 1)  // To start new game.
            {
                head.resetBoard();  // Resetting board.
                switch_player = !switch_player;  // Switching player.
            } 
        }

    } while (game_running);
    
    return 0;
}
