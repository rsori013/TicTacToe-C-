#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

char theBoard[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char current_marker;
int current_player;

void drawBoard(){
    cout << "     |     |     " << endl;
    cout << "  " << theBoard[0][0] << "  |  " << theBoard[0][1]<< "  |  " << theBoard[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << theBoard[1][0] << "  |  " << theBoard[1][1] << "  |  " << theBoard[1][2]<< endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << theBoard[2][0] << "  |  " << theBoard[2][1]<< "  |  " << theBoard[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

bool markingBoard(int box){
    int row = box/3;
    int column;

    if (box % 3 == 0){
        row = row - 1;
        column = 2;
    }
    else column = (box % 3) -1;

    if( theBoard[row][column] !='X' && theBoard[row][column] !='O'){    
        theBoard[row][column] = current_marker;
        return true;
    }
    else{
        return false;
    }



}

char winner(){ // checking who is the winner

    for (int i = 0; i < 3; i++){
        //checking rows
        if(theBoard[i][0] == theBoard[i][1] && theBoard[i][1] == theBoard[i][2]){
            return current_player;
        }
        //checking columns
       if(theBoard[0][i] == theBoard[1][i] && theBoard[1][i] == theBoard[2][i]){
            return current_player;
       }
    }
    //checking diagonals hardcoded
    if(theBoard[0][0] == theBoard[1][1] && theBoard[1][1] == theBoard[2][2]){
        return current_player;
    }
    if(theBoard[0][2] == theBoard[1][1] && theBoard[1][1] == theBoard[2][0]){
        return current_player;
    }

}
void swappingTurns(){
    if(current_player == 1) current_player = 2;
    else current_player = 1;

    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';
}
void displayArt(string txtfile){
    ifstream file;
    file.open(txtfile);
    if(file.fail())
        cout << "Failed to open ASCII file";

    cout << endl;
    string temp;
    while(!file.eof()){
        getline(file, temp);
        cout << "\t\t\t"  << temp << endl;
    }

    cout << endl;

    file.clear();

}
void swappingTurnsComputer(){
    

}
void runGameForOne(){
    cout << "Single player mode:" << endl;
    cout << "YOU (X)  ~  Computer(O)" << endl << endl;
    cout << endl;
    drawBoard();
    int theWinner = 0;
    for (int i = 1; i < 10; i++ ){
        if(i%2 == 0){
            current_player =2;
            cout << "Computer's Turn...thinking..." << endl;
            current_marker = 'O';
            int box;
            box = (rand() % 9) + 1;
        
            
            if(!markingBoard(box)){
            i--;
            continue;
            }
            drawBoard();
             theWinner = winner();
            if (theWinner == 1){
            cout << "YOU win" <<endl;
            break;
            }
            if (theWinner == 2){
            cout << "Computer wins" <<endl;
            break;        
            }
            else {
            theWinner = 0;
            }

        }
        else {
            current_player =1;
            current_marker = 'X';
            cout << "It's your turn. Enter your box: ";
            int box;
            cin >> box;
        
            if(box < 1 || box >9){
            cout << "Invalid Turn, pick a box within the range of 1-9." << endl;
            i--;
            continue;
            }
            if(!markingBoard(box)){
            cout << "box is already taken, pick another box." << endl;
            i--;
            continue;
            }
            drawBoard();
            theWinner = winner();
            if (theWinner == 1){
            cout << "YOU win" <<endl;
            break;
            }
            if (theWinner == 2){
            cout << "Computer wins" <<endl;
            break;        
            }
            else {
            theWinner = 0;
            }
        }
    }
    if(theWinner == 0){
        cout << "Game is Tie" << endl;
    }

}

void runGameForTwo(){
    cout << "Two player Mode:" << endl;
    cout << "Player 1 (X)  ~  Player 2 (O)" << endl << endl;
    cout << endl;
    drawBoard();
    char player1Marker = 'X';
    char player2Marker = 'O';

    current_player = 1;
    current_marker = player1Marker;

    int theWinner = 0;
    for (int i = 0; i < 9; i++ ){
        cout << "It's Player " << current_player << "'s turn. Enter your box: ";
        int box;
        cin >> box;
        
        if(box < 1 || box >9){
            cout << "Invalid Turn, pick a box within the range of 1-9." << endl;
            i--;
            continue;
        }
        if(!markingBoard(box)){
            cout << "box is already taken, pick another box." << endl;
            i--;
            continue;
        }
        drawBoard();
        theWinner = winner();
        if (theWinner == 1){
            cout << "Player 1 wins" <<endl;
            break;
        }
         if (theWinner == 2){
            cout << "Player 2 wins" <<endl;
            break;        
        }
        else {
            theWinner = 0;
        }
        
        //drawBoard();
        swappingTurns();
    }
    if(theWinner == 0){
        cout << "Game is Tie" << endl;
    }
}
void resetBoard(){
    theBoard[0][0] = '1';
    theBoard[0][1] = '2';
    theBoard[0][2] = '3';
    theBoard[1][0] = '4';
    theBoard[1][1] = '5';
    theBoard[1][2] = '6';
    theBoard[2][0] = '7';
    theBoard[2][1] = '8';
    theBoard[2][2] = '9';
}       


int main(){
    displayArt("welcome.txt");
    cout << "\t\t\t\t\tPress 1 To Start the Game and Press 2 to Stop the Game: ";
    int input;
    
    while(cin >> input){

    switch(input){
    case 1:
        cout << "How many Players will there be? " << endl;
        cout << "Press 1 for a single Player and press 2 for a two players: ";
        int numplayers;
        cin >> numplayers;
        if (numplayers == 1){
            system("cls");
            runGameForOne();
            cout << "Would you like to play again? Press 1 if 'Yes' and 2 if 'No' " << endl;
            resetBoard();
            int answer;
            while(cin >> answer){
            if (answer == 1){
                bool keepPlaying = true;
                while(keepPlaying == true){
                    if(answer == 1){
                    runGameForOne();
                    resetBoard();
                    cout << "Would you like to play again? Press 1 if 'Yes' and anything if 'No' " << endl;
                    cin >> answer;
                    }
                    else{
                        cout << "Thank you for playing! Have a good day! " << endl;
                        exit(0);
                        break;
                    }
                }
                break;
            }
            else{
                cout << "Thank you for playing! Have a good day! " << endl;
                exit(0);
            }
            }
        }
        else if (numplayers == 2){
            //system("cls");
            runGameForTwo();
            cout << "Would you like to play again? Press 1 if 'Yes' and 2 if 'No' " << endl;
            resetBoard();
            int answer;
            while(cin >> answer){
            if (answer == 1){
                bool keepPlaying = true;
                while(keepPlaying == true){
                    if(answer == 1){
                    runGameForTwo();
                    resetBoard();
                    cout << "Would you like to play again? Press 1 if 'Yes' and anything if 'No' " << endl;
                    cin >> answer;
                    }
                    else{
                        cout << "Thank you for playing! Have a good day! " << endl;
                        exit(0);
                        break;
                    }
                }
                break;
            }
            else{
                cout << "Thank you for playing! Have a good day! " << endl;
                exit(0);
            }
            }
        }
        break;
    case 2:
        cout << "Game Exiting...Have a good day!" << endl;
        exit(0);
        break;
    default:
        cout << "Invalid input please try again" ;

    }
    }


    
    
    //system("cls"); will be in a if statement
    
    return 0;
}