#include <iostream>
int countDigits(int input){
    for(int i = 1;;i++){
        input /= 10;
        if (input < 1) return i;
    }
}
int main(){
    int input;
    std::cin>> input;
    std::cout << countDigits(input) << std::endl;
}
