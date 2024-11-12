#include "Node.h"

#include <iostream>

template<typename T>
Node<T>* insert(Node<T>* list, const T& pair) {
    return new Node<T>(pair, list);
}
template<typename T>
void printList(Node<T>* list) {
    for (Node<T>* node = list; node != nullptr; node = node->next) {
        std::cout<<"("<<node->value.a<<","<<node->value.b<<")";
    }
    std::cout<<"\n";
}


template<typename T>
Node<T>* insertBack(Node<T> *list, T value) {
    Node<T>* newNode = new Node<T>(value, nullptr);
    if (list == nullptr) {
        return newNode;
    }
    Node<T>* current = list;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return list;
}


template<typename T>
Node<T>* remove(Node<T>* list, const T &value) {
    if (list == nullptr) {
        return list;
    }
    Node<T>* current = list;
    Node<T>* previous = nullptr;
    while (current->value != value) {
        previous = current;
        current = current->next;
    }
    if (previous == nullptr) {
        return current->next;
    }
    else{
        previous->next = current->next;
        current->next = nullptr;
        delete current;
        return list;
    }
}

template<typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    int length = 0;
public:
    LinkedList() = default;
    ~LinkedList() {
        Node<T>* node = head;
        while (node!=nullptr) {
            Node<T> *tmp = node;
            node = node->next;
            delete tmp;
        };
    }
    // LinkedList& operator=(const LinkedList& other) {
    //     delete head;
    //     head = other.head;
    //     length = other.length;
    //     return *this;
    // }
    int size() const {return length;}

    void push_front(const T& value) {head = insert(head, value);length++;};
    void push_back(const T& f) {head = insertBack(head, f);(length)++;};
    const T& front() {return head->value;};
    const Node<T>* headNode() {return head;};
    void show() const {printList(head);}
};

int main() {
    Node<MyPair>* list = nullptr;

    list = insert(list, {1,1});
    printList(list);
    list = remove(list, {1,1});
    printList(list);
    // list = insert(list, {1,2});
    // list = insert(list, {1,8});
    // list = insertBack(list, {1,9});
    // printList(list);
    // list = remove(list, {1,1});
    // printList(list);
    delete list;

    // LinkedList list;
    // LinkedList list2;
    // std::cout<<list.size()<<std::endl;
    //
    // list.push_back({1,1});
    // std::cout<<list.size()<<std::endl;
    // list.push_back({1,2});
    // list.push_back({1,8});
    // list.push_back({1,12});
    //
    // list.show();
    // std::cout<<list.size()<<std::endl;
    //
    // list2 = list;
    // list.push_back({2,2});
    // list.show();
    // list2.show();
    //
    // std::cout<<list.size()<<std::endl;
    // std::cout<<list2.size()<<std::endl;



}