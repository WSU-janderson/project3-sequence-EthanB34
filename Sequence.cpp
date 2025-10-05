#include "Sequence.h"

using namespace std;




Sequence::Sequence(size_t size) {
//TODO
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
