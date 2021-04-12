//
// Created by mau14 on 12/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
#define PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class Node {

    T value;
public:
    Node(T value) : value(value) {}

private:
    Node *next;
public:
    const T &getValue() const {
        return value;
    }

    void setValue(const T &value) {
        Node::value = value;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }
};

template<typename T>
class SimplyList {

public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int len;

    SimplyList() {
        this->head = NULL;
        this->len = 0;
        this->tail = NULL;
    }


    Node<T> *getHead() const {
        return head;
    }

    void del(T element) {

        if (element == this->head->getValue()) {
            this->head = this->head->getNext();
            this->len--;
        } else {
            Node<T> *tmp = this->head;
            for (int i = 0; i < (this->len - 1); ++i) {
                if (tmp->getNext()->getValue() == element) {
                    tmp->setNext(tmp->getNext()->getNext());
                    this->len--;
                    return;
                } else {
                    tmp = tmp->getNext();
                }
            }
        }
    }

    void append(T element) {
        auto *newElement = (Node<T> *) (malloc(sizeof(Node<T>)));
        newElement = new(newElement) Node<T>(element);

        if (this->head == nullptr) {
            this->head = this->tail = newElement;
        } else {
            this->tail->setNext(newElement);
            this->tail = newElement;
        }
        this->len += 1;

    }

    void show() const {

        if (this->head == nullptr) {
            cout << "[]" ;
        } else {
            cout << "[";
            Node<T> *tmp = this->head;
            for (int i = 0; i < (this->len - 1); ++i) {
                cout << tmp->getValue() << ", ";
                tmp = tmp->getNext();
            }
            cout << tmp->getValue() << "]" << "\n";
        }
    }

    T get(int i) {

        if (i >= this->len) {
            return 0;
        }
        Node<T> *tmp = this->head;
        for (int j = 0; j < i; ++j) {

            tmp = tmp->getNext();

        }
        return tmp->getValue();
    }

    bool Search(T element) {
        bool result = false;
        Node<T> *tmp = this->head;
        for (int i = 0; i < (this->len); ++i) {
            if (tmp->getValue() == element) {
                result = true;
                break;
            }
            tmp = tmp->getNext();
        }
        return result;
    }

    void delIndex(int index) {

    }

    void delHead() {
        this->del(this->head->getValue());
    }

    int getLen() {
        return this->len;
    }

};
#endif //PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
