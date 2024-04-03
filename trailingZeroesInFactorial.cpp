#include <iostream>

int trailingZeroes(int number){
    int powerOfFive =0;

//////////////////////////////// Method - 1 ////////////////////////////////////////
    // for(int i = 2;i<=number;i++){
    //     int temp = i;
    //     while(temp%5==0){
    //         temp/=5;
    //         powerOfFive++;
    //     }
    // }

//////////////////////////////// Method - 2 ////////////////////////////////////////

    // int i = 1;
    // while(pow(5,i)<=number){
    // powerOfFive += floor(number/pow(5,i));
    // i++;
    // }
    // return powerOfFive;

//////////////////////////////// Method - 3 ////////////////////////////////////////

    for(int i=5;i<=number;i*=5){
        powerOfFive += number/i;
    }
    return powerOfFive;
}

int main(){
    int input;
    std::cin>>input;
    std::cout<<trailingZeroes(input)<<std::endl;
}