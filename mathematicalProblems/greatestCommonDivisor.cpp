#include <iostream>
/////////////////////////// Method - 1 /////////////////////////////////////

// int GCD(int x,int y){
//     int greatestdivisor;
//     int smallerNumber = (x<y) ? x : y;
//     for(int i=1;i<=smallerNumber;i++){
//         if(x%i==0 && y%i==0){
//             greatestdivisor = i;
//     }
//     }
//     return greatestdivisor;
// }

/////////////////////////// Method - 2 (Optimized Euclidean Algorithm)/////////////////////////////////////

int GCD(int x,int y){
    if(y==0) return x;
    else return GCD(y,x%y);
}

int main(){
    int input1,input2;
    std::cin>>input1>>input2;
    std::cout<<GCD(input1,input2)<<std::endl;
}