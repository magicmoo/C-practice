#include <iostream>
using namespace std;
int main(){
    int num,sum=0,msum=0,wsum=0;
    int mnum = 0,wnum = 0;
    cin>>num;
    for(int i=0;i<num;i++){
        int sex,score;
        cin>>sex;
        if(sex==0){
            cin>>score;
            wsum+=score;
            sum+=score;
            wnum++;
        }
        else{
            cin>>score;
            msum+=score;
            sum+=score;
            mnum++;
        }
    }
    if(mnum!=0&&wnum!=0)
        printf("%.1f %.1f %.1f\n",1.0*sum/num,1.0*msum/mnum,1.0*wsum/wnum);
    else if(mnum==0)
        printf("%.1f X %.1f\n",1.0*sum/num,1.0*wsum/wnum);
    else
        printf("%.1f %.1f X\n",1.0*sum/num,1.0*msum/mnum);
    return 0;
}
