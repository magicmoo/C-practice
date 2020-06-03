#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.1415927
using namespace std;
int Pow(int x,int y){
    int sum = 1;
    for(int i=0;i<y;i++){
        sum*=x;
    }
    return sum;
}
class Coding{
    public:
        string code;
        Coding(const string& str):code(str){}
        double decoding(){
            double distance = 0;
            for(int i=0;i<22;i++){
                distance+= (code[21-i]-'0')*Pow(2,i);
            }
            distance = -1+distance/3000000;
            return distance;
        }
};
class Individual:public Coding{
    public:
        double fitness;
        Individual(const string& str):Coding(str){
            double x = decoding();
            if(x>2||x<-1) fitness = 0;
            else fitness = x*sin(10*PI*x)+2;
        }
        void mutation(){
            int num = rand()%5;
            for(int i=0;i<num;i++){
                int item = rand()%22;
                if(code[item]=='0') code[item] = '1';
                else code[item] = '0';
            }
        }
};
class Population{
    public:
        vector<Individual> Individuals;
        Population(){
            string code;
            for(int i=0;i<1000;i++){
                code = "";
                for(int i=0;i<22;i++){
                    char ch = '0'+rand()%2;
                    code += ch;
                }
                Individual tem(code);
                Individuals.push_back(tem);
            }
        }
        void selection(){
            double maxfitness = 0;
            int max1 = 0;
            for(int i=0;i<500;i++){
                if(Individuals[i].fitness>maxfitness){
                    max1 = i;
                    maxfitness = Individuals[i].fitness;
                }
            }
            maxfitness = 0;
            int max2 = 0;
            for(int i=500;i<1000;i++){
                if(Individuals[i].fitness>maxfitness){
                    max2 = i;
                    maxfitness = Individuals[i].fitness;
                }
            }
            Individual p1(Individuals[max1].code);
            Individual p2(Individuals[max2].code);
            Individuals.clear();
            for(int i=0;i<500;i++){
                Individuals.push_back(p1);
                Individuals.push_back(p2);
            }
        }
        double mostFit(){
            int maxfitness = 0;
            int max = 0;
            for(int i=0;i<1000;i++){
                if(Individuals[i].fitness>maxfitness){
                    max = i;
                    maxfitness = Individuals[i].fitness;
                }
            }
            return Individuals[max].decoding();
        }
};
void crossover(Individual p1,Individual p2){
    int point1 = rand()%22;
    int point2 = rand()%22;
    char ch;
    for(int i=point1;i<=point2;i++){
        ch = p1.code[i];
        p1.code[i] = p2.code[i];
        p2.code[i] = ch;
    }
}
int main(){
    Population p;
    int Times = 100000;  //迭代次数
    int number = 10;     //每次迭代后存在交叉或变异的次数
    int item;
    while(Times--){
        p.selection();
        for(int i=0;i<number;i++){
            item = rand()%1000;
            crossover(p.Individuals[item],p.Individuals[item+1]);
            item = rand()%1000;
            p.Individuals[item].mutation();
        }
    }
    cout<<"the answer is: ";
    cout<<p.mostFit()<<endl;
    return 0;
}
