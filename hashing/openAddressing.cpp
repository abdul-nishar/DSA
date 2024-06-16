#include <iostream>
#include <vector>
using namespace std;

class MyHash {
    private: 
        int hashSize;
        vector<int> hashTable;

    public: 
        MyHash(int size, vector<int> numArr) {
            hashSize = size;
            for(int i = 0; i < hashSize; i++) hashTable.push_back(-1);
            for(int i = 0; i < hashSize; i++){
                int value = numArr[i], temp =0;
                while(hashTable[value % hashSize] != -1) {
                    if(hashTable[value % hashSize] == numArr[i]) break;
                    temp++;
                    value = numArr[i] +  temp*temp;
                }
                hashTable[value % hashSize] = numArr[i];
            }
        }

        bool searchElement(int value){
            int index = value, temp = 0;
            while(hashTable[index % hashSize] != -1){
                if(hashTable[index % hashSize] == value) return true;
                temp++;
                index = value + temp*temp;
            }
            return false;
        }

        void insertElement(int value){
            int index = value, temp =0;
            while(hashTable[index % hashSize] != -1) {
                if(hashTable[index % hashSize] == value) break;
                temp++;
                index = value +  temp*temp;
            }
            hashTable[index % hashSize] = value;
        }

        void deleteElement(int value){
            int index = value, temp =0;
            while(hashTable[index % hashSize] != -1) {
                if(hashTable[index % hashSize] == value) {hashTable[index % hashSize]= -2;return;}
                temp++;
                index = value +  temp*temp;
            }
            cout << "Element not found" << endl;
        }

        void printHashTable() {
            for(int i = 0; i < hashSize; i++) cout << hashTable[i] << " ";
            cout << endl;
        }
};

int main(){
    vector<int> arr1 = {21,32,32,43,10};
    MyHash hashTable = MyHash(11, arr1);
    hashTable.printHashTable();
    cout << hashTable.searchElement(22);
    cout << endl;
    hashTable.insertElement(65);
    hashTable.deleteElement(32);
    hashTable.printHashTable();
    return 0;
}


