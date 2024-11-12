#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <compare>
#include <iostream>

struct MyPair {
    int a;
    int b;
    auto operator<=>(const MyPair &other) const = default;
};

template <typename T>
struct Node {
    T value;
    Node *next=nullptr;
    ~Node() = default; //{
        // if (next == nullptr) {}
        // else {
        //     delete next;
        // }
    // } ;
};



// int main() {
//     LinkedList myLinkedList;
// }







#endif //LINKEDLIST_H
