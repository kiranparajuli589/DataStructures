#include <iostream>
#include <list>

using namespace std;

class Queue {
    private:
        list<int> q;
    
    public:
        void enqueue(int x) {
            // Insert at the end of the list
            q.push_back(x);
        }

        void dequeue() {
            // Remove from the front of the list
            q.pop_front();
        }

        int front() {
            return q.front();
        }

        bool empty() {
            return q.empty();
        }

        int size() {
            return q.size();
        }

        void print() {
            for (int x : q) {
                cout << x << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    return 0;
}