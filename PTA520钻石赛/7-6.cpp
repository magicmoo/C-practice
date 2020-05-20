#include <iostream>
#include <string>
using namespace std;
int main(){
    int N;
    int num[10];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>num[i];
    string move[3] = {"ChuiZi","JianDao","Bu"};
    string win[3] = {"Bu","ChuiZi","JianDao"};
    string lose[3] = {"JianDao","Bu","ChuiZi"};
    for(int k=0;;k++){
        if(k>=N)
            k-=N;
        int flag = 0;
        string skill;
        for(int i=0;i<num[k];i++){
            cin>>skill;
            if(skill=="End"){
                break;
                flag = 1;
            }
            for(int j=0;j<3;j++){
                if(move[j]==skill){
                    cout<<win[j]<<endl;
                    break;
                }
            }
        }
        cin>>skill;
        if(skill=="End"){
            break;
            flag = 1;
        }
        for(int j=0;j<3;j++){
            if(move[j]==skill){
                cout<<lose[j]<<endl;
                break;
            }
        }
        if(flag) break;
    }
    return 0;
}
