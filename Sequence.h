/* Student Name: Ethan Barnes
* Project 3: Sequence
* File Name: Sequence.h
*
*This file contains the function declarations to the Sequence class, which definitions are found in Sequence.cpp.
* This file also contains the SequenceNode class which creates a node with a string passed in or empty otherwise.
* SequenceNode variables : next, prev, item
*/
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>

using namespace std;

class Sequence {

public:

//CONSTRUCTORS AND DESTRUCTOR
Sequence(size_t sz=0);
Sequence(const Sequence& s);
~Sequence();

//OPERATOR OVERLOADS
Sequence& operator=(const Sequence& s);
string& operator[](size_t position);
friend ostream& operator<<(ostream& os, const Sequence& s);

//SEQUENCE ADD/REMOVE
void push_back(const string& item);
void pop_back();
void insert(size_t position, const string& item);
void clear();
void erase(size_t position);
void erase(size_t position, size_t count);

//SEQUENCE INFO/STATUS
 string front() const;
 string back() const;
 bool empty() const;
 size_t size() const;





/* Class SequenceNode: contains default and parameterized constructor to create a single node for the Sequence
 * next - pointer to the next node in the sequence
 * prev - pointer to the previous node in the sequence
 * item - string data contained inside each node
 *
 */
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
 // private member variables, only belonging to class Sequence
    SequenceNode* head_ptr;
    SequenceNode* tail_ptr;
    size_t numElts;
};
#endif //SEQUENCE_H