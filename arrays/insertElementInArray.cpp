#include <iostream>

using namespace std;

void insertElementIntoArray(int *array, int n,int cap, int element, int position) {
    if (n == cap) return;

   for (int i = n; i >= position - 1; i--) 
        array[i+1] = array[i];
    array[position - 1] = element;

    return;
} 


int main() {
    int arrayOfNumbers[12] = {5,3,7,10,20, 6,7}; 
    insertElementIntoArray(arrayOfNumbers, sizeof(arrayOfNumbers) / sizeof(int), 7,456, 3);
    for(int i = 0; i < sizeof(arrayOfNumbers)/ sizeof(int); i++){
        cout<<arrayOfNumbers[i]<<" "<<endl;
    } 
    return 0;
}