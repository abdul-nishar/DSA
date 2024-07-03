#include <iostream>
#include <deque>

using namespace std;

class CustomDeque {
    private: deque<int> deq;

    public: CustomDeque() {}

        void insertMin(int value){
            if(!deq.empty() && value > deq.front()){
                cout << "This is not the minimum value" << endl;
                return;
            }
            deq.push_front(value);
        }

        void insertMax(int value){
            if(!deq.empty() && value < deq.back()){
                cout << "This is not the maximum value" << endl;
                return;
            }
            deq.push_back(value);
        }

        int getMin(){
            if(deq.empty()) return -1;
            else return deq.front();
        }

        int getMax(){
            if(deq.empty()) return -1;
            else return deq.back();
        }

        int extractMin(){
            if(deq.empty()) return -1;
            int value = deq.front();
            deq.pop_front();
            return value;
        }

        int extractMax(){
            if(deq.empty()) return -1;
            int value = deq.back();
            deq.pop_back();
            return value;
        }
};

int main(){
    CustomDeque deq = CustomDeque();

    deq.insertMin(5);
    deq.insertMax(10);
    deq.insertMin(3);
    deq.insertMax(15);
    deq.insertMin(2);

    cout << deq.getMin() << endl;
    cout << deq.getMax() << endl;

    deq.insertMin(1);

    cout << deq.getMin() << endl;

    deq.insertMax(20);

    cout << deq.getMax() << endl;

    return 0;
}