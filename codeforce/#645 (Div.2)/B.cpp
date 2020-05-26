#include <iostream>
#include <algorithm>
#define MAXNUM 100005
using namespace std;
int main(){
	int T,number,sum,num[MAXNUM];
	cin>>T;
	while(T--){
		number = 1;
		cin>>sum;
		for(int i=0;i<sum;i++)
			cin>>num[i];
		sort(num,num+sum);
		int head = 0;
		int tail = 0;
		while(tail<sum){
			if(tail-head+number>=num[tail]){
				number+=(tail-head+1);
				tail = head = tail+1;
			}
			else tail++;
		}
		cout<<number<<endl;
	}
	return 0;
}
