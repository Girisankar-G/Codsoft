#include <iostream> 
#include <string.h>
using namespace std;
int pos(int m,int pos_arr[2],char value[3][3]){
    int x;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x++;
            if(x==m){
                if(value[i][j]=='X' || value[i][j]=='O'){
                    cout<<"\nPosition already filled";
                    return 1;
                }
                pos_arr[0]=i;
                pos_arr[1]=j;
                return 0;
            }
        }
    }
    return -1;
}
int winner(char value[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (value[i][0]==value[i][1]&&value[i][0]==value[i][2] || value[0][i]==value[1][i]&&value[0][i]==value[2][i]) {
            return 0;
        }
    }
    if (value[0][0]==value[1][1] && value[0][0]==value[2][2] || value[0][2]==value[1][1] && value[0][2]==value[2][0]){
        return 0;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (value[i][j]!='X' && value[i][j]!='O'){
                return 1;
            }
        }
    }
    return 2;
}

void display(char value[3][3]){
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<value[0][0]<<"  |  "<<value[0][1]<<"  |  "<<value[0][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<value[1][0]<<"  |  "<<value[1][1]<<"  |  "<<value[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<value[2][0]<<"  |  "<<value[2][1]<<"  |  "<<value[2][2]<<" \n";
    cout<<"\t     |     |     \n";
}
int main(){
    char value[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char pl1[100],pl2[100],p1wh,p2wh;
    int y,z,move,x=0,pos_arr[2],tot_moves=0;
    cout<<"\n\nTICK-TAC-TOE-GAME\n\n";   
    cout<<"\nEnter the player1 name:";
    cin>>pl1;
    cout<<"\nEnter the player2 name:";
    cin>>pl2;
    cout<<"\nPlayer-1(X or O)?:";
    cin>>p1wh;
    while((p1wh!='X' && p1wh!='O') && (p1wh!='x' && p1wh!='o')){
        cout<<"\n!X or O only";
        cout<<"\nPlayer-1(X or O)?:";
        cin>>p1wh;
    }
    if(p1wh=='X' || p1wh=='x'){
        p1wh='X';
        p2wh='O';
    }
    else{
        p1wh='O';
        p2wh=='X';
    }
    display(value);
    do{
        if(tot_moves%2==0){
            cout<<"\nPlayer X enter your move:";
            cin>>move;
            x=pos(move,pos_arr,value);
            if(x==-1){
                tot_moves--;
                cout<<"\nInvalid posistion";
            }
            else if(x==0){
                value[pos_arr[0]][pos_arr[1]]='X';
                display(value);
            }
            else if(x==1){
                tot_moves--;
            }
        }
        else if(tot_moves%2!=0){
            cout<<"\nPlayer O enter your move:";
            cin>>move;
            x=pos(move,pos_arr,value);
            if(x==-1){
                tot_moves--;
                cout<<"\nInvalid posistion";
            }
            else if(x==0){
                value[pos_arr[0]][pos_arr[1]]='O';
                display(value);
            }
            else if(x==1){
                tot_moves--;
            }
        } 
        y=winner(value);
        if(y==0){
            if(tot_moves!=0){
                cout<<"\nX is the WINNER\n";
                if(p1wh=='X'){
                    cout<<pl1<<" you have won";
                }
                else{
                    cout<<pl2<<" you have won";
                }
            }
            else{
                cout<<"\nO is the WINNER\n";
                if(p1wh=='O'){
                    cout<<pl1<<" you have won";
                }
                else{
                    cout<<pl2<<" you have won";
                }
            }
            break;
        }
        cout<<"\nContinuing the match...";
        tot_moves++;
    }while(tot_moves<9);
    if(y==2){
        cout<<"\nMatch DRAW";
    }
    cout<<"\nPlay again?";
    cout<<"[0(yes)/1(no)]:";
    cin>>z;
    if(z==0){
        main();
    }
    else{
        cout<<"\n!GAME OVER... ";
    }
    return 0;
}
