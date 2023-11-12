#include <iostream> 
#include <string.h>
using namespace std;
struct book{
    long int isbn;
    char title[100],author[100];
};
void fine_amount(int x){
    int fine;
    cout<<"\n!15 day Return policy";
    cout<<"\nBook has been returned after "<<x<<"days";
    cout<<"\nFine amount "<<(x-15)<<"*"<<"10="<<((x-10)*10);
}
int inteager_conv(char search[]){
    int x,integer=0;
    for(int i=0;search[i]!='\0';i++){
        x=("%d",search[i]);
        if(x<48 || x>57){
            return -1;
        }
        integer=integer*10+(x-48);
    }
    return integer;
}
int main(){
    int i=0,n,x,c,pur=0,total=0,price,f;
    long int isbn;
    char search[100],purchase[100][100],author[100],title[100];
    cout<<"\nEnter the library capacity:";
    cin>>n;
    struct book var[n];
    do{
        cout<<"\n1.Insert book\n2.Search book\n3.Add to cart\n4.Checkout\n5.Return\n6.Exit";
        cout<<"\nEnter your choice:";
        cin>>c;
        switch(c){
            case 1:
                cout<<"\nBook details,";
                cout<<"\nEnter the title:";
                cin>>var[i].title;       
                cout<<"\nEnter the author name:";
                cin>>var[i].author;
                cout<<"\nEnter the ISBN:";
                cin>>var[i].isbn; 
                cout<<"\nStored successfully.";           
                break;
            case 2:
                cout<<"\nEnter the book detail:";
                cin>>search;
                x=0;
                for(int j=0;j<=i;j++){
                    if(strcmp(var[j].title,search)==0 || strcmp(var[j].author,search)==0 || var[j].isbn==inteager_conv(search)){
                        cout<<"\nBook is available.";
                        x=1;
                    }
                }
                if(x==1){
                    break;
                }
                cout<<"\nBook is not available.";
                break;
            case 3:
                cout<<"\nEnter the book tite:";
                cin>>search;
                x=0;
                for(int j=0;j<=i;j++){
                    if(strcmp(var[j].title,search)==0){
                        strcpy(purchase[pur],search);
                        pur+=1;
                        x=1;
                        cout<<"\nAdded succesfully.";
                        break;
                    }
                }
                if(x==0){
                    cout<<"\nBook is not available.";
                }
                break;
            case 4:
                for(int k=0;k<pur;k++){
                    for(int l=0;l<i;l++){
                       if(strcmp(purchase[k],var[l].title)==0){
                            cout<<"Book ISBN-"<<var[k].isbn;
                            cout<<"\nEnter the price:";
                            cin>>price;
                            total+=price;
                        }
                    }
                }
                cout<<"\nPurchase list,";
                for(int k=0;k<pur;k++){
                    cout<<"\nBook-"<<(k+1)<<":"<<purchase[k];
                }
                cout<<"\nTotal Price of books:"<<total;
                break;
            case 5:
                cout<<"\nBook details,";
                cout<<"\nEnter the title:";
                cin>>title;       
                cout<<"\nEnter the author name:";
                cin>>author;
                cout<<"\nEnter the ISBN:";
                cin>>isbn;
                cout<<"\nEnter the no of days it has been:";
                cin>>f;
                if(f>15){
                    fine_amount(f);
                }
                x=0;
                for(int j=0;j<=i;j++){
                    if(strcmp(var[j].title,title)==0){
                        x=1;
                        break;
                    }
                }
                if(x==0){
                    i++;
                    strcpy(var[i].title,title);
                    strcpy(var[i].author,author);
                    var[i].isbn=isbn;
                }
                if(f<15){
                    cout<<"\nReturned succesfully.";
                }
                break;
            case 6:
                cout<<"\nThank you for your visit...";
                break;
            default:
                cout<<"\n!Invalid choice.";
        }
    i++;
    }while(c!=6);
}
