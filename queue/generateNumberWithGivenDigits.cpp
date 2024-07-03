#include <iostream>
#include <queue>

using namespace std;

vector<string> generateNumberWithGivenDigits(int N){
    vector<string> result;
    queue<string> numQueue;

    numQueue.push("1");
    numQueue.push("5");
    numQueue.push("6");


    for(int i=0; i<N; i++){
        string value  = numQueue.front();
        numQueue.pop();
        numQueue.push(value + "0");
        numQueue.push(value + "1");
        numQueue.push(value + "5");
        numQueue.push(value + "6");
        result.push_back(value);
    }

    return result;
}

int main(){
    vector<string> result = generateNumberWithGivenDigits(10);
    for(auto value : result) cout << value << " ";
    return 0;
}


