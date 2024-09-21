#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    private: 
        int* heapArr;
        int size;
        int capacity;

    public: 
        MinHeap(int c) : heapArr(new int[c]), size(0), capacity(c) {}

        int parent(int i) { 
            return (i-1)/2;
        }

        void heapify(int index){
            int smallest = index, leftNode = 2 * index + 1, rightNode = 2 * index + 2;

            if(index >= 0 && heapArr[leftNode] < heapArr[smallest]) smallest = leftNode;
            if(index >= 0 && heapArr[rightNode] < heapArr[smallest]) smallest = rightNode;

            if(smallest != index) {
                swap(heapArr[smallest], heapArr[index]);
                heapify(parent(index));
            }
        }

        void insert(int val){
            if(size >= capacity) throw overflow_error("Heap is full");;

            int i = size++;

            heapArr[i] = val;

            while (i != 0 && heapArr[parent(i)] > heapArr[i]) {
                swap(heapArr[i], heapArr[parent(i)]);
                i = parent(i);
            }
        }

        void printHeap(){
            for(int i = 0; i < size; i++) cout << heapArr[i] << " ";
            cout << endl;
        }
};

int main(){

    MinHeap heap = MinHeap(10);

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);
    heap.insert(100);
    heap.insert(25);
    heap.insert(45);

    heap.printHeap();

    heap.insert(12);
    heap.insert(13);

    heap.printHeap();

    return 0;
}