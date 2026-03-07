#include <iostream>

using namespace std;

char player='X';

char matrix[3][3] = {'1','2','3',
                     '4','5','6',
                     '7','8','9'};

void Board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << matrix[i][j] <<"  ";
        }
        cout << endl;
    }
}

void Player(){
    int position;
    cout << "Choose a position from 1 to 9.\n Player - " << player << ": ";
    cin >> position;
    int row,column;
    switch(position){
        case 1: 
        row=0;
        column=0;
        break;

        case 2:  
        row=0;
        column=1;
        break;

        case 3: 
        row=0;
        column=2; 
        break;

        case 4:  
        row=1;
        column=0;
        break;

        case 5:  
        row=1;
        column=1;
        break;

        case 6:  
        row=1;
        column=2;
        break;

        case 7:  
        row=2;
        column=0;
        break;

        case 8:  
        row=2;
        column=1;
        break;

        case 9:  
        row=2;
        column=2;
        break;

        default: cout <<"The selected Position is invalid. Please select another position from 1 to 9." << endl;
        Player();
        return;
    }
        if(matrix[row][column]!='X' && matrix[row][column]!='O'){
            matrix[row][column] = player;
        }
        else{
            cout << "Position already taken. Select another position!" << endl;
            Player();
        }
    }

bool Win(){

    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])return true;
    if(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2])return true;

    for(int i=0;i<3;i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])return true;
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])return true;
    }
    return false;
}

int main(){

    for(int i=0;i<9;i++){
        system("cls");
        Board();
        cout << endl;

        Player();
        cout<< endl;

        if(Win()){
            Board();
            cout << "Player " << player << " is the winner! " << endl;
            return 0;
        }

        if(player=='X'){
            player='O';
        }
        else{
           player='X';
        }
   }
   cout <<"Game draw!" << endl;
   return 0;
}