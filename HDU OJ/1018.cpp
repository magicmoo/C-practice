#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int num;
        double n = 0;
        cin>>num;
        for(int i=1;i<=num;i++){
            n+=log10(i);
        }
        cout<<(long int)n+1<<endl;
    }
    return 0;
}
