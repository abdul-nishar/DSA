#include <iostream>

////////////////////////////// Method-1 //////////////////////////////////////////

// bool isPrime(int number){
//     if(number == 1)return false;
//     for(int i = 2; i< number; i++){
//         if(number%i==0) return false;
//     }
//     return true;
// }

////////////////////////////// Method-1 //////////////////////////////////////////
bool isPrime(int number){
    if(number == 1)return false;
    if(number ==2 ||number ==3)return true;
    if(number % 2 == 0 || number % 3 == 0)return false;
    for(int i = 5; i*i<= number; i=i+6){
        if(number%i==0 || number%(i+2) ==0) return false;
    }
    return true;
}

int main(){
    int input;
    std::cin>>input;
    std::cout<<std::boolalpha<<isPrime(input)<<std::endl;
}