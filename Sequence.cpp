#include "Sequence.h"
#include "Sequence.h"

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
//TODO
}
Sequence& Sequence::operator=(const Sequence &s) {
//TODO
    return *this;
}

string& Sequence::operator[](size_t position) {
//TODO
}

void Sequence::push_back(string item) {
//TODO
}
void Sequence::pop_back() {
//TODO
}
void Sequence::insert(size_t position, string item) {
//TODO
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
//TODO
    return os;
}
