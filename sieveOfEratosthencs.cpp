#include <iostream>
#include <vector>


/////////////////////////// Method - 1 /////////////////////////////////////

// bool isPrime(int number){
//     if(number == 1)return false;
//     if(number ==2 ||number ==3)return true;
//     if(number % 2 == 0 || number % 3 == 0)return false;
//     for(int i = 5; i*i< number; i=i+6){
//         if(number%i==0 || number%(i+2) ==0) return false;
//     }
//     return true;
// }

// void primeFinder(int number){
//     for(int i=2;i<=number;i++){
//       if(isPrime(i)){
//         std::cout<<i<<" "
//       }
//     }
// }

/////////////////////////// Method - 2 //////////////////////////////////

void primeFinder(int number){
   std::vector<bool> isPrime(number+1,true);
   for(int i=2;i<=number;i++){
        if(isPrime[i]) {
            std::cout<<i<<" ";
            for(int j=i*i;j<=number;j=j+i){
                isPrime[j] = false;
            }
        }
   }
}

int main(){
    int input;
    std::cin>>input;
    primeFinder(input);
}