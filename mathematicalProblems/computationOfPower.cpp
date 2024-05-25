#include <iostream> 

////////////////////////////// Method-1 //////////////////////////////////////////////

// int power(int number,int exponent){
//     int temp=1;
//     for(int i=1;i<=exponent;i++){
//         temp*=number;
//     }
//     return temp;
// }

////////////////////////////// Method-2 //////////////////////////////////////////////

// int power(int number,int exponent){
//     // if(exponent==1) return number;
//     // if(exponent%2==0) return power(number, exponent/2)*power(number, exponent/2);
//     // else return power(number, exponent-1)*number;

//     int temp;
// 	if (exponent == 0)
// 		return 1;
// 	temp = power(number, exponent / 2);
// 	if (exponent % 2 == 0)
// 		return temp * temp;
// 	else
// 		return number * temp * temp;
// }

/////////////////////////////////////// Method-3 /////////////////////////////////////////////////////////

int power(int number, int exponent){
    int result = 1;
    while(exponent>0){
        if(exponent % 2 != 0){
            result *= number;
        }
    number*=number;
    exponent = exponent /2;
    }
    return result;
}


int main(){
    int input1,input2;
    std::cin>>input1>>input2;
    std::cout<<power(input1,input2)<<std::endl;
}