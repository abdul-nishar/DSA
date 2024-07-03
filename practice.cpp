#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> numDeque = {50,60,70};
    numDeque.push_front(10);
    numDeque.push_back(20);
    cout << numDeque.front() << endl;
	cout << numDeque.back() << endl;
    numDeque.pop_front();
    numDeque.pop_back();

	cout << numDeque.front() << endl;
	cout << numDeque.back() << endl;
    cout << numDeque.size() << endl;

    cout << numDeque.empty() << endl;


    return 0;
}