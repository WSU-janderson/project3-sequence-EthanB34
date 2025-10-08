/*
 *
 *Sequence.h
 *
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>

using namespace std;

class Sequence {
public:



Sequence(size_t sz=0);

Sequence(const Sequence& s);

~Sequence();

Sequence& operator=(const Sequence& s);

string& operator[](size_t position);

void push_back(const string& item);

void pop_back();

void insert(size_t position, const string& item);

 string front() const;
 string back() const;
 bool empty() const;
 size_t size() const;
 void clear();
 void erase(size_t position);
 void erase(size_t position, size_t count);
friend ostream& operator<<(ostream& os, const Sequence& s);

private:
  class SequenceNode {
  public:
      SequenceNode* next;
      SequenceNode* prev;
      string item;

      SequenceNode() : next(nullptr), prev(nullptr), item("") {}
      SequenceNode(const string& item)
      : next(nullptr), prev(nullptr), item(item) {}
  };

    SequenceNode* head_ptr;
    SequenceNode* tail_ptr;
    size_t numElts;
};
#endif //SSEQUENCE_H