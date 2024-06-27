#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value){
    Node* tail = new Node(value);
    if(head == nullptr) head = tail;
    else {
        Node* mover = head;
        while(mover->next != nullptr) mover = mover->next;
        mover->next=tail;
    }
}

void printAllNodes(Node* head){
    Node*mover = head;
    while(mover != nullptr) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

Node* addTwoLists(struct Node* num1, struct Node* num2){
    string sum1 = "", sum2 = "";
    
    // Concatenating list elements to sum1
    // Using a flag to ignore initial zeroes
    Node* mover1 = num1; 
    bool flag1 = true;
    while(mover1!=nullptr) {
        if(mover1->data != 0) flag1 = false;
        if(!flag1){
            sum1 += to_string(mover1->data);
        }
        mover1=mover1->next;
    }
    
    // Concatenating list elements to sum1
    Node* mover2 = num2;
    bool flag2 = true;
    while(mover2!=nullptr) {
        if(mover2->data != 0) flag2 = false;
        if(!flag2){
            sum2 += to_string(mover2->data);
        }
        mover2=mover2->next;
    }

    // Adding zeroes to the string which has smaller length
    
    int sum1Len = sum1.length(), sum2Len = sum2.length();
    if(sum1Len>sum2Len){
        for(int i=0;i<sum1Len-sum2Len;i++) sum2  = '0' + sum2;
    }else {
        for(int i=0;i<sum2Len-sum1Len;i++) sum1 = '0' + sum1;
    }


    // Adding each char of both the sums and concatenating them to the result    
    int carry = 0;
    string result = "";
    for(int i=sum1.length() - 1;i>=0;i--){
        int total = (sum1[i] - '0') + (sum2[i]-'0') + carry;
        carry = total / 10;
        result = to_string(total%10) + result;
    }
    
    // If carry is non-zero concatenating it to the start of the result
    if(carry) result = to_string(carry) + result;
    
    // Storing the char as linked list
    Node* head = nullptr;
    Node* mover = head;
    if(result.length() == 0) {
        head = new Node(0);
        return head;
    }
    for(int i=0;i<result.length();i++){
        Node* newNode = new Node(result[i]-'0');
        if(head == nullptr) {head = newNode;mover = newNode;}
        else {
            mover->next = newNode;
            mover = mover->next;
        }
    }
    
    return head;
}

int main(){
    Node* num1 = nullptr;
    insertAtEnd(num1, 4);
    insertAtEnd(num1, 5);

    Node* num2 = nullptr;
    insertAtEnd(num2, 3);
    insertAtEnd(num2, 4);
    insertAtEnd(num2, 5);

    Node* head = addTwoLists(num1, num2);

    printAllNodes(head);

}


