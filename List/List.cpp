#include "List.h"
int main(){
	List<int> l;
	init(l);
	for(int i=0;i<10;i++)
		push_back(l,i);
	Node<int>* now;
	now = begin(l);
	now = Get_next(now);
	cout<<now->date<<endl;
	now = Get_prev(now);
	cout<<now->date<<endl;
	erase(l,now);
	pop_back(l);
	erase(l,begin(l));
	cout<<begin(l)->date<<endl;
	return 0;
}
