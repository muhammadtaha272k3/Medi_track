#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue {

    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    queue() : front(nullptr), rear(nullptr), count(0) {}

    ~queue() {
        while (!isEmpty())
            dequeue();
    }
    queue(const queue& other) : front(nullptr), rear(nullptr), count(0) {
        Node* current = other.front;
        while (current != nullptr) {
            enqueue(T(current->data));  // Explicit copy of the data
            current = current->next;
        }
    }

    queue<T> copy() const {
        queue<T> newQueue;
        Node* current = front;
        while (current != nullptr) {
            newQueue.enqueue(current->data);
            current = current->next;
        }
        return newQueue;
    }

    queue& operator=(const queue& other) {
        if (this != &other) {
            while (!isEmpty())
                dequeue();

            Node* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void enqueue(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            return T();
        }
        Node* temp = front;
        T value = front->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        count--;
        return value;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int size() const {
        return count;
    }

    T peek() const {
        if (isEmpty())
            return T();
        return front->data;
    }
};

#endif // QUEUE_H
