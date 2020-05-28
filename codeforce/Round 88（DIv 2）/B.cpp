#include <iostream>
using namespace std;
char map[100][1000];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,x,y,sum = 0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>map[i][j];
        if(y>=2*x){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(map[i][j]=='.')  sum+=x;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m-1;j++){
                    if(map[i][j]=='.'&&map[i][j+1]=='.'){
                        map[i][j] = map[i][j+1] = '*';
                        sum+=y;
                    }
                }
            }
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(map[i][j]=='.')  sum+=x;
        }
        cout<<sum<<endl;
    }
    return 0;
}
