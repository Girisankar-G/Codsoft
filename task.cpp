#include <iostream> 
#include<string.h>
using namespace std;
int main(){
    char task[100][100],task_new[100],status[100][100],cmp[20]="Completed",ncmp[20]="Pending";
    int ch,c,x=1,del,mod;
    do{
        cout<<"\n1.Add task\n2.View Task\n3.Modify Task\n4.Delete Task\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        cin.ignore();
        switch(ch){
            case 1:
                cout<<"\nEnter the task:";
                cin.getline(task[x],100); 
                cout<<"\nNote:By default Task status is \"Pending\"";
                strcpy(status[x],ncmp);
                x++;
                break;
            case 2:
                if(x==1){
                    cout<<"\nTask list is empty";
                    break;
                }
                cout<<"\nTask list,";
                for(int i=1;i<x;i++){
                    cout<<"\nTask-"<<i<<":";
                    cout<<"\nTask name:"<<task[i];
                    cout<<"\nTask status:"<<status[i];
                }
                break;
            case 3:
                cout<<"\nTask list,";
                for(int i=1;i<x;i++){
                    cout<<"\nTask-"<<i<<":";
                    cout<<"\nTask name:"<<task[i];
                    cout<<"\nTask status:"<<status[i];
                }
                cout<<"\nEnter the Task number to modify:";
                cin>>mod;
                cout<<"\n1.Change Task name\n2.Change Task status";
                cout<<"\nEnter your choice:";
                cin>>c;
                cin.ignore();
                if(c==1){
                    cout<<"\nEnter the new task name:";
                    cin.getline(task_new,100);
                    strcpy(task[mod],task_new); 
                }
                else if(c==2){
                    cout<<"\nCompleted(0) or Pending(1):";
                    cin>>c;
                    if(c==0){
                        strcpy(status[mod],cmp);
                    }
                    else if(c==1){
                        strcpy(status[mod],ncmp);
                    }
                    else{
                        cout<<"\nInvalid only 0 or 1";
                        cout<<"\nTry again";
                    }
                }
                else{
                    cout<<"\nInvalid choice";
                    cout<<"\nTry again";
                }
                break;
            case 4:
                cout<<"\nTask list,";
                for(int i=1;i<x;i++){
                    cout<<"\nTask-"<<i<<":";
                    cout<<"\nTask name:"<<task[i];
                    cout<<"\nTask status:"<<status[i];
                }
                cout<<"\nEnter the Task number to delete:";
                cin>>del;
                for(int i=del;i<x;i++){
                    strcpy(task[i],task[i+1]);
                    strcpy(status[i],status[i+1]);
                }
                x--;
                break;
            case 5:
                cout<<"\n!Terminating program...";
                break;
            default:
                cout<<"\nInvalid choice.";
        }
    }while(ch!=5);
}
