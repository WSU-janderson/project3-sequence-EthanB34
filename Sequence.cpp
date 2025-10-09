#include "Sequence.h"
#include "Sequence.h"
#include <stdexcept>
#include <iostream>
using namespace std;




Sequence::Sequence(size_t sz)
    : head_ptr(nullptr), tail_ptr(nullptr), numElts(0) {
    for (size_t i = 0; i < sz; i++) {
        SequenceNode* newNode = new SequenceNode(" ");
        if (head_ptr == nullptr) {
            head_ptr = newNode;
            tail_ptr = newNode;
        } else {
            tail_ptr->next = newNode;
            newNode->prev = tail_ptr;
            tail_ptr = newNode;
        }
        numElts++;
    }
}

Sequence::Sequence(const Sequence &s) {
//TODO
}
Sequence::~Sequence() {
    SequenceNode* current = head_ptr;
    while (current != nullptr) {
        SequenceNode* next = current->next;
        delete current;
        current = next;
    }
    head_ptr = nullptr;
    tail_ptr = nullptr;
    numElts = 0;
}
Sequence& Sequence::operator=(const Sequence &s) {
//TODO
    return *this;
}

string& Sequence::operator[](size_t position) {
if (position > numElts) {
    throw out_of_range("Position out of range");
}
    SequenceNode* current = head_ptr;
    for (size_t i = 1; i < position   ; i++) {
        current = current->next;
    }
    return current->item;
}

void Sequence::push_back(const string& item) {
SequenceNode* newNode = new SequenceNode(item);
    if (numElts == 0) {
    head_ptr = newNode;
    tail_ptr = newNode;
        numElts++;
    } else {
        newNode->prev = tail_ptr;
        newNode->next = nullptr;
        tail_ptr->next = newNode;
        tail_ptr = newNode;
        numElts++;
    }
}
void Sequence::pop_back() {
if (numElts == 0) {
    throw out_of_range("Empty sequence, cannot pop");
} else if (numElts == 1) {
    delete head_ptr;
    head_ptr = nullptr;
    tail_ptr = nullptr;
    numElts = 0;
} else {
    SequenceNode* prevTail = tail_ptr;
    tail_ptr = tail_ptr->prev;
    tail_ptr->next = nullptr;
    delete prevTail;
    numElts--;
}
}
void Sequence::insert(size_t position,const string& item) {
    if ( position > numElts ) {
        throw out_of_range("Position out of range");
    }

    SequenceNode* newNode = new SequenceNode(item);

    if (numElts == 0) {
        head_ptr = newNode;
        tail_ptr = newNode;

    } else if ( position == 0) {
        newNode->next = head_ptr;
        newNode->prev = nullptr;
        head_ptr -> prev = newNode;
        head_ptr = newNode;
        numElts++;

    } else if (position == numElts) {
        newNode->next = tail_ptr;
        newNode->prev = tail_ptr->prev;
        if (tail_ptr->prev != nullptr) {
            tail_ptr->prev->next = newNode;
        } else {
            head_ptr = newNode;
        }
        tail_ptr->prev = newNode;
        numElts++;
    } else {

        SequenceNode* current = head_ptr;

        for (size_t i = 0; i < position-1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        current->prev = newNode;
        numElts++;
    }
}
void Sequence::erase(size_t position) {
//TODO
}
void Sequence::clear() {
//TODO
}

string Sequence::front() const {
//TODO
}
string Sequence::back() const {
//TODO
}
bool Sequence::empty() const {
//TODO
}
size_t Sequence::size() const {
//TODO
}



ostream& operator<<(ostream& os, const Sequence& s) {
os << "<";
Sequence::SequenceNode* current = s.head_ptr;
    while (current != nullptr) {
        os << current->item;
        if (current->next != nullptr) {
            os << ", ";
            current = current->next;
        }
            os << current->item;
            current = current->next;
        }

    os << ">";
    return os;
}
