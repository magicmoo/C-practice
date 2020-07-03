#include <iostream>
using namespace std;
#define MAXMUM 1005
int J[MAXMUM];
int F[MAXMUM];
double value[MAXMUM];
int main(){
    int M,N;
    while(cin>>M>>N&&M!=-1&&N!=-1){
        for(int i=0;i<N;i++){
            cin>>J[i]>>F[i];
            value[i] = 1.0*J[i]/F[i];
        }
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                if(value[i]<value[j]){
                    swap(value[i],value[j]);
                    swap(J[i],J[j]);
                    swap(F[i],F[j]);
                }
            }
        }
        int now = 0;
        double num = 0;
        while(M&&now<N){
            if(M>=F[now]){
                M-=F[now];
                num+=J[now];
            }
            else{
                num+=M*value[now];
                M = 0;
            }
            now++;
        }
        printf("%.3f\n",num);
    }
    return 0;
}
