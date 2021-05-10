//
// Created by mau14 on 12/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
#define PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
#include <cstdlib>
#include <iostream>
#include "../Data_Types/Data_Type.h"

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

    void setHead(Node<T> *head) {
        SimplyList::head = head;
    }

    Node<T> *tail = nullptr;
    int len;
    /**
     * @brief Constructor for the simply list.
     */
    SimplyList() {
        this->head = NULL;
        this->len = 0;
        this->tail = NULL;
    }

    /**
     * @brief Getter for the head.
     * @return the head of the list.
     */
    Node<T> *getHead() const {
        return head;
    }
    /**
     * @brief Deletes an element of the list.
     * @param element
     */
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
    /**
     * @brief Adds an element at the end of the list.
     * @param element
     */
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
    /**
     * @brief Prints the list.
     */
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
    /**
     * @brief Gets an element of the list.
     * @param i
     * @return gets the value.
     */
    T get(int i) {

        //if (i >= this->len) {
         //   return 0;
        //}
        Node<T> *tmp = this->head;
        for (int j = 0; j < i; ++j) {

            tmp = tmp->getNext();

        }
        return tmp->getValue();
    }
    /**
     * @brief Gets a node of the list.
     * @param i
     * @return the node that gets searched.
     */
    Node<T>* getNode(int i) {

        if (i >= this->len) {
            return 0;
        }
        Node<T> *tmp = this->head;
        for (int j = 0; j < i; ++j) {

            tmp = tmp->getNext();

        }
        return tmp;
    }
    /**
     * @brief Searches an element and tells if its on the list.
     * @param element
     * @return true if its on the list, false if not.
     */
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
    /**
     *
     * @param index
     */
    void delIndex(int index) {

    }
    /**
     * @brief deletes the head.
     */
    void delHead() {
        this->del(this->head->getValue());
    }

    /**
     * @brief deletes the head.
     */
    void delHeadNode() {
        if (head == NULL){
            cout<<"List empty"<<endl;
        }else if(head->getNext() == nullptr){
            Node<T> *temp = head;
            this->len --;
            delete temp;

        }else{
            Node<T> *temp = head;
            head = head->getNext();
            this->len --;
            delete temp;
        }
    }
    /**
     * @brief Getter for the lenght.
     * @return the lenght of the list.
     */
    int getLen() {
        return this->len;
    }

};
#endif //PROYECTO_1_DATOS_II_SERVER_C__SIMPLYLIST_H
