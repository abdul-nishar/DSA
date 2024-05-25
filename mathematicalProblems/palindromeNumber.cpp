#include <iostream>
///////////////////////////// Method-1 ///////////////////////////////////
// {
// int countDigits(int input){
//     for(int i = 1;;i++){
//         input /= 10;
//         if (input < 1) return i;
//     }
// }

// bool palindrome(int number){
//     int numberLength = countDigits(number);
//     int numberArr[numberLength];
//     for(int i = numberLength - 1; i >= 0; i--){
//         numberArr[i] = number % 10;
//         number /= 10;
//     }
//     for(int i = 0; i < numberLength; i++){
//         if(numberArr[i] != numberArr[numberLength - 1 - i]) return false;
//     }

//     return true;
// }
// }

/////////////////////////////// Method-2 (Better Method)/////////////////////////////////

bool palindrome(int number){
    int temp = number;
    int reverseNumber = 0;
    while(number>1){
        int lastDigit = number % 10;
        reverseNumber = reverseNumber * 10 + lastDigit;
        temp /= 10;
    }
    if(reverseNumber == number) return true;
    else return false;
}

/////////////////////////////// Main Function ////////////////////////////////
int main(){
    int input;
    std::cin>>input;
    std::cout<< std::boolalpha << palindrome(input)<<std::endl;
}