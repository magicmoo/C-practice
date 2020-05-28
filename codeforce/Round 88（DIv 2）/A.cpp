#include <iostream>
using namespace std;
int main(){
    int n,m,k,number,T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        number = n/k;
        if(m<=number)   cout<<m<<endl;
        else{
            cout<<number-(m-number+k-2)/(k-1)<<endl;
        }
    }
    return 0;
}
