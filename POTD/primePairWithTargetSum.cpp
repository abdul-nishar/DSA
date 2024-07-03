#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int number){
        if(number == 1)return false;
        if(number ==2 ||number ==3)return true;
        if(number % 2 == 0 || number % 3 == 0)return false;
        for(int i = 5; i*i<= number; i=i+6){
            if(number%i==0 || number%(i+2) ==0) return false;
        }
        return true;
    }
vector<int> getPrimes(int n) {
    vector<int> primeNumbers;
    for(int i=2;i<=n-2;i++) if(isPrime(i)) primeNumbers.push_back(i);
        
    int low = 0, high = primeNumbers.size()-1;
    while(low<=high){
        int value = primeNumbers[low] + primeNumbers[high];
        if(value == n) return {primeNumbers[low],primeNumbers[high]};
        else if(value < n) low++;
        else high--;
    }
    
    return {-1,-1};
}

int main(){
    vector<int> pairs = getPrimes(10);
    for(auto value : pairs) cout << value << " ";
}