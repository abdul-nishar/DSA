#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1) : data(data1) , next(nullptr) {}
};


class LinkedList {
    private: Node* head;
    public: 
        LinkedList() : head(nullptr) {}

        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            
            if(head == nullptr) {
                head = newNode;
            }  else {
                Node* mover = head;
                while(mover->next != nullptr) {
                    mover = mover->next;
                }
                mover->next = newNode;
            }
        }

        bool searchNode(int value) {
            Node* temp = head;
            while(temp != nullptr) {
                if(temp->data == value) return true;
                temp = temp->next;
                cout << temp->data << endl;
            }
            return false;
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

struct MyHash {
    int bucket;
    vector<LinkedList*> table;

    MyHash(int b, vector<int> numArr) {
        bucket = b;
        vector<LinkedList*> hashTable(bucket);
        for(int i = 0; i < bucket; i++) hashTable[i] = new LinkedList();
        table = hashTable;
    } 

    bool searchElement(int value) {
        bool found = false;
        for(int i = 0; i < table.size(); i++){
            found = found || table[i]->searchNode(value);
        }

        return found;
    }
};

int main(){
    vector<int> arr1 = {70,71,9,56,72};
    MyHash hashTable = MyHash(7,arr1);
    cout << hashTable.searchElement(9);
    return 0;
}