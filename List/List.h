#ifndef _LIST_H_
#define _LIST_H_
#include "Node.h"
using namespace std;
template<typename Type>
class List{
    public:
        Node<Type> *head;
        Node<Type> *tail;
        int size;
};
template<typename Type>
void init(List<Type>& L){
    L.head = new Node<Type>;
    if(L.head==NULL){
        cout<<"Memory allocation failture!"<<endl;
        exit(1);
    }
    L.head->prev = L.head->next = NULL;
    L.tail = new Node<Type>;
    if(L.tail==NULL){
        cout<<"Memory allocation failture!"<<endl;
        exit(1);
    }
    L.tail->prev = L.tail->next = NULL;
    L.head->next = L.tail;
    L.tail->prev = L.head;
    L.size = 0;
}
template<typename Type>
Node<Type>* end(List<Type>& L){
    return L.tail;
}
template<typename Type>
Node<Type>* Get_node(Type item,Node<Type>* prev0,Node<Type>* next0){
    Node<Type>* temp = new Node<Type>;
    if(temp==NULL){
        cout<<"Memory allocation failture!"<<endl;
        exit(1);
    }
    temp->date = item;
    temp->prev = prev0;
    temp->next = next0;
    return temp;
}
template<typename Type>
Node<Type>* insert(List<Type>& L,Node<Type>* n,Type date){
    L.size++;
    Node<Type>* temp = n;
    temp->prev->next = Get_node(date,temp->prev,temp);
    temp->prev = temp->prev->next;
    return temp->prev;
}
template<typename Type>
Node<Type>* begin(const List<Type>& L){
    return L.head->next;
}
template<typename Type>
void erase(List<Type>& L,Node<Type>* n){
    L.size--;
    Node<Type>* temp = n;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
template<typename Type>
Node<Type>* Get_next(Node<Type>* n){
    return n->next;
}
template<typename Type>
Type Get_date(Node<Type>* n){
    return n->date;
}
template<typename Type>
void display_list(Node<Type>* first,Node<Type>* end){
    for(;first!=end;first=Get_node(first)){
        cout<<Get_date(first)<<" ";
    }
}
template<typename Type>
void push_back(List<Type>& L,Type date){
    insert(L,end(L),date);
}
template<typename Type>
Node<Type>* Get_prev(Node<Type>* n){
    return n->prev;
}
template<typename Type>
void pop_back(List<Type>& L){
    erase(L,end(L)->prev);
}
template<typename Type>
Type* front_pointer(const List<Type>& L){
    Node<Type>* last = L.tail->prev;
    return &(last->date);
}
template<typename Type>
Type* back_pointer(const List<Type>& L){
    Node<Type>* first = L.head->next;
    return &(first->date);
}
template<typename Type>
bool empty(const List<Type>& L){
    if(L.size==0) return true;
    return false;
}
template<typename Type>
void clear(List<Type>& L){
    while(!empty(L)){
        pop_back(L);
    }
    L.size = 0;
}
template<typename Type>
void free(List<Type>& L){
    clear(L);
    delete L.head;
    delete L.tail;
}
template<typename Type>
void pop_front(List<Type>& L){
    erase(L,begin(L)->next);
}
#endif
