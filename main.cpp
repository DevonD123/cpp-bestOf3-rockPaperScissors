# include <iostream>
using namespace std;
#include <windows.h> 
#include <ctime> 

void play(int pick, int player){
    if(player == 1){
        if(pick == 3){
            cout << "computer picked scissors" << endl;
        }else if(pick == 2){
            cout << "computer picked paper" << endl;
        }else{
            cout << "computer picked rock" << endl;
        }
    }else{ //player == 2 (or others)
        if(pick == 3){
            cout << "you picked scissors" << endl;
        }else if(pick == 2){
            cout << "you picked paper" << endl;
        }else{
            cout << "you picked rock" << endl;
        }
    }
    
}
void countdown(){
    cout << "rock! ";
    Sleep(300);
    cout << "paper! ";
    Sleep(300);
    cout << "scissors! " << endl;
}

int round( int numb){
    int computer;
    int myChoice;
    if(numb ==1){ 
       cout << "1:rock" <<endl << "2:paper"<< endl << "3:scissors" << endl;
       cout << "pick if you dare:";
    }else{
        cout << endl;
        cout << "1:rock |" << "2:paper |" << "3:scissors" << endl;
        cout << "pick again:";
    }

    
    cin >> myChoice;
    if(myChoice > 3 || myChoice <= 0 ){
        cout << "invalid choice please try again" << endl;
        return 10;
    }
    srand(time(NULL)); //seed random gen with time in s 
    computer = (rand() % 3) + 1; //set = to random number since its 0-2 you add 1 to get 1-3
    countdown();
    cout << endl;
    play(myChoice,2);
    play(computer,1);
    cout << endl;
    if(myChoice == computer){
       cout << "--- it was a tie round:" << numb << endl;
       return 0;
    }else if(myChoice > computer && myChoice >= 2 || myChoice < computer && myChoice < 2){
        if(computer == 1 && myChoice == 3){
            cout << "--- you lose :( round:" <<numb << endl;
            return 1;
        }else{
          cout << "--- you win!! round:" <<numb << endl;   
          return 2;
        }
    }else{
        cout << "--- you lose :( round:" <<numb << endl;
        return 1;
    }
}


int main(){
    int cpuScore = 0;
    int myscore = 0;
    int roundCount = 1;

    while(cpuScore < 2 && myscore <2){
        int myround = round(roundCount);
        if(myround == 10){
            return 1;
        }else if(myround == 1){
            cpuScore += 1;
        }else if(myround == 2){
            myscore += 1;
        }
        roundCount++;
    }
    
    if(cpuScore >= 2){
        cout << "#################### the computer wins the series ->" << cpuScore << ":" << myscore << "#################" << endl; 
    }else if(myscore >= 2){
        cout << "####################  you wins the series ->" << myscore << ":" << cpuScore << "#################" << endl; 
    }
    return 0;

}