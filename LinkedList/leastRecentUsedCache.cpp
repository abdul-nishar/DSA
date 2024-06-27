#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    private: 
        unordered_map<int,Node*> keyValueMap;
        Node* head;
        Node* tail;
        int capacity;

    public: 

        LRUCache(int cap) {
            head = nullptr;
            tail = nullptr;
            capacity = cap;
        }    

        void moveToHead(Node* node){
            if(node == head) return;
            if(node == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
        }

        void removeTail(){
            if(tail == nullptr) return;
            keyValueMap.erase(tail->key);
            if(tail->prev != nullptr){
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }else {
                delete tail;
                head = tail = nullptr;
            }
        }

        int GET(int key){
            if(!keyValueMap.count(key)) return -1;
            Node* node = keyValueMap[key];
            moveToHead(node);

            return node->value;
        }

        void SET(int key,int value){
            if(!keyValueMap.count(key)){
                Node* newNode = new Node(key, value);
                if(keyValueMap.size() == capacity) removeTail();
                if(head == nullptr) head = tail = newNode;
                else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                keyValueMap[key] = newNode;
            }else {
                Node* node = keyValueMap[key];
                node->value = value;
                moveToHead(node);
            }
        }
};

int main(){

    return 0;
}