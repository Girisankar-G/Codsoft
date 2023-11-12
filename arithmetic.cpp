#include <iostream> 
using namespace std;
int main(){
    int c,a,b;
    float x,y;
    cout<<"\n1.Addition\n2.Subraction\n3.Division\n4.Multipicayion";
    cout<<"\nEnter your choice:";   
    cin>>c;
    switch(c){
        case 1:
            cout<<"\nEnter the first number:";
            cin>>a;
            cout<<"\nEnter the second number:";
            cin>>b;
            cout<<"\n"<<a<<"+"<<b<<"="<<(a+b);
            break;
        case 2:
            cout<<"\nEnter the first number:";
            cin>>a;
            cout<<"\nEnter the second number:";
            cin>>b;
            cout<<"\n"<<a<<"-"<<b<<"="<<(a-b);
            break;
        case 3:
            cout<<"\nEnter the numerator:";
            cin>>x;
            cout<<"\nEnter the denominator:";
            cin>>y;
            cout<<"\n"<<x<<"/"<<y<<"="<<(x/y);
            break;
        case 4:
            cout<<"\nEnter the first number:";
            cin>>a;
            cout<<"\nEnter the second number:";
            cin>>b;
            cout<<"\n"<<a<<"*"<<b<<"="<<(a*b);
            break;
        default:
            cout<<"\n!Invalid choice...";
    }
}
