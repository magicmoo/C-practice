#include <iostream>
#include <string>
using namespace std;
int main(){
    string num,num1;
    cin>>num;
    while(cin>>num1&&num1!="-1"){
        if(num.length()!=num1.length()){
            cout<<"No"<<endl;
            continue;
        }
        int flag = 1;
        for(int i=0;i<num.length();i++){
            if(num[i]!=num1[i]){
                flag--;
                if(flag<0||abs(num[i]-num1[i])>1){
                    flag = -1;
                    break;
                }
            }
        }
        if(flag==-1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
