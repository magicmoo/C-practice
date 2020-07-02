#include<iostream>
#include<algorithm>
using namespace std;
#define MAXMUM 10
char map[MAXMUM][MAXMUM];
char book[MAXMUM][MAXMUM];
struct Node{
    int x;
    int y;
    int times;
};
int way[2][4] = {{1,0,0,-1},{0,1,-1,0}};
bool flag;
int N,M,T;
void dfs(int tx,int ty,int time){
    if(flag) return;
    if(time==T&&map[tx][ty]=='D'){
        flag = true;
        return;
    }
    if(time>=T) return;
    book[tx][ty] = 'X';
    for(int k=0;k<4;k++){
        int x = tx+way[0][k];
        int y = ty+way[1][k];
        if(x<1||x>N||y<1||y>M||book[x][y]=='X') continue;
        dfs(x,y,time+1);
        book[x][y] = '.';
    }
}
int main(){
    int sx,sy,dx,dy;
    while(cin>>N>>M>>T&&N&&M&&T){
        flag = false;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>map[i][j];
                book[i][j] = map[i][j];
                if(map[i][j]=='S'){sx = i;sy = j;}
                if(map[i][j]=='D'){dx = i;dy = j;}
            }
        }
        if((abs(sx-dx)+abs(sy-dy))%2!=(T%2)){       //奇偶剪枝
            cout<<"NO"<<endl;
            continue;
        }
        dfs(sx,sy,0);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
