#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data1) : data(data1), next(nullptr) {}
};

class LinkedList {
    private: Node *head;
    
    public: 
        LinkedList(): head(nullptr) {}

        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if(head == nullptr) head = newNode;
            else {
                Node *mover = head;
                while(mover->next != nullptr){
                    mover = mover->next;
                }
                mover->next = newNode;
            }
        }

        void removeNode(int value){
            Node* mover = head;
            Node* prevNode;
            while(mover){
                if(mover->data == value){
                    prevNode->next = mover->next;
                    break;
                }else {prevNode = mover;mover = mover->next;}
            }
        }

        bool search(int value) {
            Node *mover = head;
            while(mover){
                if(mover->data == value) return true;
                else mover = mover->next;
            };
            return false;
        }

        void print() {
            Node *mover = head;
            while(mover){
                cout << mover->data << " ";
                mover = mover->next;
            }
        }

        vector<int> convertIntoArr(){
            vector<int> result;
            Node *mover = head;
            while(mover){
                result.push_back(mover->data);
                mover = mover->next;
            }
            return result;
        }
};

class HashTable {
    private: 
        int bucket;
        vector<LinkedList*> hashTable;

    public: 
        HashTable(int b, vector<int> numArr){
            bucket = b;
            for(int i=0;i<bucket;i++) hashTable.push_back(new LinkedList());
            for(int i=0;i<numArr.size();i++){
                int value = numArr[i];
                int index = value % bucket;
                hashTable[index]->insertAtEnd(value);
            }
        }

        bool searchElement(int value){
            for(int i = 0; i < bucket; i++){
                if(hashTable[i]->search(value)) return true;
            }
            return false;
        }

        void insertElement(int value){
            int index = value % bucket;
            hashTable[index]->insertAtEnd(value);
        }

        void removeElement(int value){
            int index = value % bucket;
            hashTable[index]->removeNode(value);
        }

        void printHashTable(){
            for(int i=0; i<bucket; i++) hashTable[i]->print();
        }

        vector<vector<int>> getHashTable(){
            vector<vector<int>> result;
            for(int i=0; i<bucket; i++) result.push_back(hashTable[i]->convertIntoArr());

            return result;
        }
};

int main(){
    vector<int> numbersArray = {15, 11, 27, 8, 12};
    HashTable* hashTable = new HashTable(7, numbersArray);
    vector<vector<int>> result = hashTable->getHashTable();
    for(int i = 0; i < result.size();i++){
        for(int j = 0; j <result[i].size();j++) cout << result[i][j] << "->";
        cout << endl;
    }

}