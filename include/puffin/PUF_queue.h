/* Puffin queue and sll (Singly linked list) */

#ifndef PUF_QUEUE_H
#define PUF_QUEUE_H

template <typename T> class PUF_sll_node {
    private:
        T* node = nullptr;
        T* next = nullptr;

    public:
        T* getNext();
        void setNext(T*);
        T get();
        void set(T);

        PUF_sll_node(T n_node) {
            node = &n_node;
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

#include "puffin/PUF_queue.h"

template <typename T> T* PUF_sll_node<T>::getNext() {
    return next;
}

template <typename T> T PUF_sll_node<T>::get() {
    return *node;
}

template <typename T> void PUF_sll_node<T>::setNext(T* t) {
    next = t;
}

template <typename T> void PUF_sll_node<T>::set(T t) {
    node = &t;
} 

template <typename T> void PUF_queue<T>::push(T t) {
    PUF_sll_node node = PUF_sll_node(t);
    if (tail == nullptr) {
        head = &node;
        head->setNext(&t);
        tail = &node;
    } else {
        tail->setNext(&t);
        tail = &node;
    }
} 

template <typename T> T PUF_queue<T>::pop() {
    T head_val = head->get();
    PUF_sll_node node = PUF_sll_node(*(head->getNext())); //seg-fault!?!?
    head = &node;
    return head_val;
} 

template <typename T> T PUF_queue<T>::scan() {
    T head_val = head->get();
    return head_val;
}

template <typename T> PUF_sll_node<T>* PUF_queue<T>::getHeadNode() {
    return head;
}

template <typename T> bool PUF_queue<T>::empty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

#endif