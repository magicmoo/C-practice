#include <iostream>
#include <stack>
#include <string>
using namespace std;
void Error(const string& str){
    cout<<str<<endl;
    exit(1);
}
bool isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return true;
    return false;
}
class MathOperator{
    public:
        char op;
        int ipre;
        explicit MathOperator(char ch){
            op = ch;
            if(ch=='+') ipre = 1;
            else if(ch=='-') ipre = 1;
            else if(ch=='*') ipre = 2;
            else if(ch=='/') ipre = 2;
        }
        operator char(){return op;}
};
void Evaluate(stack<double>& opnds,MathOperator optr){
    double opnd1 = opnds.top();
    opnds.pop();
    double opnd2 = opnds.top();
    opnds.pop();
    switch(char ch = optr){
        case '+': opnds.push(opnd2+opnd1); break;
        case '-': opnds.push(opnd2-opnd1); break;
        case '*': opnds.push(opnd2*opnd1); break;
        case '/': opnds.push(opnd2/opnd1); break;
    }
}
double resolve(stack<double>& opnds,stack<MathOperator>& optrs){
    while(!optrs.empty()){
        Evaluate(opnds,optrs.top());
        optrs.pop();
    }
    return opnds.top();
}
double solve(int flag = 0){
    stack<double> opnds;
    stack<MathOperator> optrs;
    int rank = 0;
    char ch;
    double number;
    while(cin.get(ch)&&ch!='='&&ch!=')'){
        if(isdigit(ch)||ch=='.'){
            cin.putback(ch);
            cin>>number;
            rank++;
            if(rank>1)
                Error("Operator expected!");
            opnds.push(number);
        }
        else if(ch=='('){
            opnds.push(solve(1));
            rank++;
        }
        else if(isoperator(ch)){
            MathOperator optr(ch);
            if(!optrs.empty()&&optr.ipre<=optrs.top().ipre){
                Evaluate(opnds,optrs.top());
                cin.putback(ch);
                optrs.pop();
            }
            else{
                rank--;
                if(rank<0)
                    Error("Operand expected!");
                optrs.push(optr);
            }
        }
    }
    if(ch==')'){
        if(flag==1){
            return resolve(opnds,optrs);
        }
        else if(flag==0) Error("Missing left parenthesis!");
    }
    if(ch=='='){
        if(flag==1) Error("Missing right parenthesis!");
        else{
            return resolve(opnds,optrs);
        }
    }
    return resolve(opnds,optrs);
}
int main(){
    cout<<solve()<<endl;
    return 0;
}
