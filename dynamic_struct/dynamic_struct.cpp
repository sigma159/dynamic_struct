#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap = 10) {
        capacity = cap;
        data = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    void Enqueue(const T& value) {
        if (IsFull()) {
            cout << "Черга переповнена!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void Show() const {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }
        cout << "Елементи черги: ";
        for (int i = 0; i < size; i++) {
            cout << data[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Show();

    q.Dequeue();
    q.Show();

    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Enqueue(70); 

    q.Show();

    return 0;
}

