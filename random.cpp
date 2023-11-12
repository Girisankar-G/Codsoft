#include <cstdlib> 
#include <iostream> 
using namespace std;
int main(){
    int a=rand(),n,x,i=0;
    cout<<"\nEnter the number limit:";
    cin>>n;
    a=rand()%n;
    while(x!=-1){
        cout<<"\nEnter your guess(-1 to exit):";
        cin>>x;
        i++;
        if(x==a){
            cout<<"\nYou guessed the right number";
            cout<<"\nTotal guess:"<<i;
            break;
        }
        else if(x>a){
            cout<<"\nYour guess is too high";
        }
        else if(x<a){
            cout<<"\nYour guess is too less";
        } 
        else if(x==-1){
            break;
        }
    }
    
}
