#include <iostream>

using namespace std;

class DynamicList {
    private:
        int *arr;
        int size;
        int capacity;
    public:
        DynamicList(int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->arr = new int[capacity];
        }

        void checkSize() {
            if (this->size == this->capacity) {
                this->capacity *= 2;
                int *new_arr = new int[this->capacity];
                for (int i = 0; i < this->size; i++) {
                    new_arr[i] = this->arr[i];
                }
                delete[] this->arr;
                this->arr = new_arr;
            }
        }

        void append(int value) {
            this->checkSize();
            this->arr[this->size] = value;
            this->size++;
        }

        void remove(int index) {
            if (index < 0 || index >= this->size) {
                cout << "Index out of range" << endl;
                return;
            }
            for (int i = index; i < this->size - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->size--;
        }

        void get(int index) {
            if (index < 0 || index >= this->size) {
                cout << "Index out of range" << endl;
                return;
            }
            cout << this->arr[index] << endl;
        }

        void print() {
            for (int i = 0; i < this->size; i++) {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }

        int getSize() {
            return this->size;
        }

        int getCapacity() {
            return this->capacity;
        }

        int search(int value) {
            for (int i = 0; i < this->size; i++) {
                if (this->arr[i] == value) {
                    return i;
                }
            }
            return -1;
        }

        ~DynamicList() {
            delete[] this->arr;
        }
};

int main() {
    DynamicList list(2);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);


    list.print();

    list.remove(4);
    list.print();
}
