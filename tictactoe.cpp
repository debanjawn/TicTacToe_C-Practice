#include <iostream>
using namespace std;

char space[3][3]= {{'1','2','3'},
                           {'4','5','6'},
                           {'7','8','9'}};
int row;
int column;
char symbol = 'x';
string name1;
string name2;
bool tie=false;

void gameBoardFunction(){
    
    

    cout << "    |     |   \n";
    cout << " " << space[0][0] <<"  |  "<<space[0][1]<<"  |  "<< space[0][2]<<" \n";
    cout <<"____|_____|____ \n";
    cout << "    |     |   \n";
    cout << " " << space[1][0] <<"  |  "<<space[1][1]<<"  |  "<< space[1][2]<<" \n";
    cout <<"____|_____|____ \n";
    cout << "    |     |   \n";
    cout << " " << space[2][0] <<"  |  "<<space[2][1]<<"  |  "<< space[2][2]<<" \n";
    cout << "    |     |   \n";
    cout << "---------------------";
    cout << "  \n"; 

}

void assignmentFunction(){

    int digit;

    if(symbol=='x'){
        cout<<name1<< " please enter one of the numbers";
        cin>>digit;
    }
    if(symbol=='0'){
        cout<<name2<< " please enter one of the numbers";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else{
        cout << "Invalid!!" << endl;
    }

    if(symbol == 'x' && space[row][column] != 'x' && space[row][column] != '0'){
        space[row][column] = 'x';
        symbol = '0';
    }
    else if(symbol == '0' && space[row][column] != '0' && space[row][column] != 'x'){
        space[row][column] = '0';
        symbol = 'x';
    }
    else{
        cout << "There is no empty space" << endl;
        assignmentFunction();
        
    }

gameBoardFunction();
}

bool gameCheckFunction(){

    for(int i=0;i<3;i++){
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]){
            return true;
        }
    }
    if(space[0][0]==space[1][1] && space[0][0] == space[2][2] || space[2][0] == space[1][1] && space[2][0]  == space[0][2]){
        return true;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!= 'x' && space[i][j]!= '0'){
                return false;
            }
        }
    }

    tie=true;
    return false;

}

int main(){

    cout << "Enter Name of First Player : \n";
    cin >> name1;
    cout << "Enter Name of Second Player : \n";
    cin >> name2;
    cout<< name1 << " is player 1 and will go first" << "\n";
    cout<< name2 << " is player 2 and will go second" << "\n";

    while(!gameCheckFunction()){
        gameBoardFunction();
        assignmentFunction();
        gameCheckFunction();
    }
    if(symbol== 'x' && tie == false){
        cout << name2<< " is the winner!!" << endl;
    }
    else if(symbol== '0' && tie == false){
        cout << name1<< " is the winner!!" << endl;
    }
    else{
        cout << "Tie game!!!" << endl;
    }

    return 0;
}
