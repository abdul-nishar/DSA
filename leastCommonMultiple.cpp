#include <iostream>

int GCD(int x,int y){
    if(y==0) return x;
    else return GCD(y,x%y);
}

int LCM(int x, int y){
    return (x*y)/GCD(x,y);
}

int main(){
    int input1,input2;
    std::cin>>input1>>input2;
    std::cout<<LCM(input1,input2)<<std::endl;
}