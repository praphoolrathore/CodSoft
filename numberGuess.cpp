#include<iostream>
#include <time.h> 
using namespace std;
int main(){
    srand(time(0));
    int userInput,i=0,ub=100,lb=0;
    int rndNumer=(rand() % 100);
    while(true){
        cout<<"\nGuess between 0 to 100"<<endl;
        cout<<"Enter your Guess : ";
        cin>>userInput;
        i++;
        if(rndNumer==userInput){
            cout<<"Correct Guess"<<endl;
            cout<<"No. of attempts : "<<i<<endl;
            break;
        }
        else if(rndNumer>userInput){
            cout<<"Your Guess is LOW"<<endl;
        }
        else{
            cout<<"Your Guess is HIGH"<<endl;
        }
    }
    return 0;
}