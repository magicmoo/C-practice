#include<iostream>
#include<algorithm>
using namespace std;
#define MAXMUM 100005
int a[MAXMUM];
int dp[MAXMUM];
int main(){
    int T,n;
    cin>>T;
    for(int time=1;time<=T;time++){
        cin>>n;
        int max0 = -1001;
        int begin,end;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i] = max(dp[i-1]+a[i],a[i]);
            if(max0<dp[i]){
                max0 = dp[i];
                end = i;
            }
        }
        int number = 0;
        for(int i=end;i>0;i--){
            number+=a[i];
            if(number==dp[end]) begin = i;
        }
        cout<<"Case "<<time<<":"<<endl;
        cout<<dp[end]<<" "<<begin<<" "<<end<<endl;
        if(time!=T)
            cout<<endl;
    }
    return 0;
}
