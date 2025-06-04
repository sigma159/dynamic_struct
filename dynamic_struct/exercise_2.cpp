#include <iostream>
using namespace std;

const int MAX = 100;

class PriorityQueue {
private:
    struct Node {
        int value;
        int priority;
    };

    Node data[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == MAX;
    }

    void InsertWithPriority(int value, int priority) {
        if (IsFull()) {
            cout << "Черга переповнена!" << endl;
            return;
        }

        int i = size - 1;
        while (i >= 0 && data[i].priority < priority) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1].value = value;
        data[i + 1].priority = priority;
        size++;
    }

    void PullHighestPriorityElement() {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }

        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
    }

    int Peek() const {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return -1;
        }
        return data[0].value;
    }

    void Show() const {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }

        cout << "Елементи черги (значення : пріоритет):" << endl;
        for (int i = 0; i < size; i++) {
            cout << data[i].value << " : " << data[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.InsertWithPriority(10, 2);
    pq.InsertWithPriority(20, 4);
    pq.InsertWithPriority(15, 3);
    pq.Show();

    cout << "Peek: " << pq.Peek() << endl;

    pq.PullHighestPriorityElement();
    pq.Show();

    return 0;
}
