#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class HashNode {
public:
    int key;
    string value;
    HashNode(int Key, string Value) {
        key = Key;
        value = Value;
    }
        
};

class HashMap {
private:
    int tableSize;
    vector<list<HashNode>> table;

public:
    HashMap(int size) {
        tableSize = size;
        table.resize(tableSize);
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insertNode(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back(HashNode(key, value));
    }

    void removeNode(int key) {
        int index = hashFunction(key);
        list<HashNode>& bucket = table[index];
        //auto key changes the datatype to the type of value stored in it
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->key == key) {
                bucket.erase(it);
                break;
            }
        }
    }

    void searchNode(int key) {
        int index = hashFunction(key);
        list<HashNode>& bucket = table[index];
        //auto key changes the datatype to the type of value stored in it
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->key == key) {
                cout << "Key : "<<key<<" -> Value : " << it->value << endl;
            }
        }
        cout << "Value not Found" << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of HashTable" << endl;
    cin >> size;
    HashMap hashMap(size);
    hashMap.insertNode(1, "Ali");
    hashMap.insertNode(2, "Ahmed");
    hashMap.insertNode(3, "Omer");

    hashMap.searchNode(1);
    hashMap.searchNode(2);
    hashMap.searchNode(3);

    hashMap.removeNode(2);
    
    hashMap.searchNode(2);

    return 0;
}
