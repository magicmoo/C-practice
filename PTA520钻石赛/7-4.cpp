#include <iostream>
#include <string>
using namespace std;
int main(){
    long long A,B;
    cin>>A>>B;
    long long C = A+B,D = C;
    if(C<0){
        cout<<"-"<<endl;
        C = -C;
    }
    string str = "";
    while(C!=0){
        char ch = C%10+'0';
        str+=ch;
        C/=10;
    }
    if(D==0)
        cout<<"0"<<endl;
    else{
        for(int i=str.length()-1;i>=0;i--)
            cout<<str[i]<<endl;
    }
    return 0;
}
