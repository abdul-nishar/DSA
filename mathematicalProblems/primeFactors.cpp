#include <iostream>

// void primeFactors(int number){
//     if(number<=1) return;
//     while(number%2==0){
//         std::cout<<"2 ";
//         number/=2;
//     }
//     while(number%3==0){
//         std::cout<<"3 ";
//         number/=3;
//     }
//    for(int i = 5; i*i <= number;i=i+6){
//         while(number%i==0){
//             std::cout<<i<<" ";
//             number/=i;
//         }
//         while(number%(i+2)==0){
//             std::cout<<i+2<<" ";
//             number/=i;
//         }
//    }
//    if(number>3) std::cout<<number;
// }

int exactly3Divisors(int N){
    int divisor = 0;
    for(int i=4;i<N;i++){
        int count =1;
        int temp =i;
        for(int j=2;j*j<=temp;j++){
           while(temp%2==0){
                count++;
                temp/=2;
            }
           while(temp%3==0){
                count++;
                temp/=3;
            }
            for(int i = 5; i*i <= temp;i=i+6){
                while(temp%i==0){
                    count++;
                    temp/=i;
                }
                while(temp%(i+2)==0){
                    count++;
                    temp/=i;
                }
            }
        if(temp>3) count++;
        }
    if(count==3) divisor++;
    }
    return divisor;
}

int main(){
    int input;
    std::cin>>input;
    // primeFactors(input);
    std::cout<<exactly3Divisors(input);
}