#include <iostream>


//////////////////////////// Iterative Method(Better Method) ////////////////////////////////////

///@remark In this method, time complexity is O(n) whereas space complexity is O(1)

// int factorial(int number){
//     int factorial = 1;
//     for(int i = number; i > 0; i--){
//         factorial *= i;
//     }
//     return factorial;
// }

//////////////////////////// Recursive Method ////////////////////////////////////

///@remark In this method, time complexity is O(n) whereas space complexity(auxiliary space) is O(n) because of function call stack

int factorial(int number){
    if (number == 0) return 1;
    return number * factorial(number-1);
}

///////////////////////////// Main Function ///////////////////////////////////

int main(){
    int input;
    std::cin >> input;
    std::cout << factorial(input) << std::endl;
}