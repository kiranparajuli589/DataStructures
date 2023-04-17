#include <iostream>

#define SIZE 10

using namespace std;

class StaticList {
    private:
        int arr[SIZE];
        int size;

    public:
        StaticList() {
            size = 0;
        }
        void append(int value) {
            if (size < SIZE) {
                arr[size] = value;
                size++;
            } else {
                cout << "List is full." << endl;
            }
        }
        void remove(int index) {
            if (index >= 0 && index < size) {
                for (int i = index; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--; // decrease size after removing element
            } else {
                cout << "Index out of range." << endl;
            }
        }

        int get(int index) {
            if (index >= 0 && index < size) {
                return arr[index];
            } else {
                return -1;
            }
        }

        int getSize() {
            return size;
        }

        int* search(int value) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == value) {
                    return &arr[i];
                }
            }
            return NULL;
        }
};

int main () {
    StaticList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);
    list.append(11); // list is full

    cout << "Size: " << list.getSize() << endl;
    cout << "Element at index 3: " << list.get(3) << endl;
    cout << "Element at index 10: " << list.get(10) << endl; // index out of range

    list.remove(3);
    cout << "Size: " << list.getSize() << endl;
    cout << "Element at index 3: " << list.get(3) << endl;
    cout << "Element at index 10: " << list.get(10) << endl; // index out of range

    int* searchResult = list.search(5);
    if (searchResult != NULL) {
        cout << "Found element: " << *searchResult << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}