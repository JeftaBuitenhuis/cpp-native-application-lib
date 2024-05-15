/* Puffin queue and sll (Singly linked list) */

#ifndef PUF_QUEUE_H
#define PUF_QUEUE_H

#include <iostream>

template <typename T> class PUF_sll_node {
    public:
        T data;
        PUF_sll_node* next = nullptr;

        PUF_sll_node(T data) {
            this->data = data;
        }
};

template <typename T> class PUF_queue {
    private:
        PUF_sll_node<T>* head = nullptr;
        PUF_sll_node<T>* tail = nullptr;

    public:
        void push(T);
        T pop();
        T scan();
        PUF_sll_node<T>* getHeadNode();
        bool empty();
};

template <typename T> void PUF_queue<T>::push(T data) {
    PUF_sll_node<T>* node = new PUF_sll_node<T>(data);

    if (head == nullptr) {
        head = node;
        head->next = tail;
        tail = node;
        return;
    }

    tail->next = node;
    tail = node;
} 

template <typename T> T PUF_queue<T>::pop() {
    T data = head->data;
    head = head->next;
    return data;
} 

template <typename T> T PUF_queue<T>::scan() {
    return head->data;
}

template <typename T> PUF_sll_node<T>* PUF_queue<T>::getHeadNode() {
    return head;
}

template <typename T> bool PUF_queue<T>::empty() {
    return (head == nullptr);
}

#endif