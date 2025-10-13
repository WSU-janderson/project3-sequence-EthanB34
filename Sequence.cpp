/* Student Name: Ethan Barnes
* Project 3: Sequence
* File Name: Sequence.cpp
*
*This file contains the class Sequence, which implements a doubly linked list.
* Functions :
* Parameterized/ Default constructor - creates a sequence with zero nodes if no size is passed in, otherwise create a
* sequence with the same amount of nodes as the value passed.
*
* Copy Constructor - creates a new deep copy of a sequence
*
*Destructor - Deletes any created sequeneces automatically when main goes out of scope
*
* Operator Overloads - <<, [], = - overload these operators to preform a new action, for << when given a sequence, print its contents to the console.
*  [], returns a reference to the string at the index passed to the function, if out of bounds throw an exception. = assigns a previously created sequence
*  with another.
*
* Push / Pop back - Pop simply removes a node from the end of the Sequence, Push takes in a string and creates a new node at the end of the Sequenece.
*
* Insert - Takes a position and item and creates a new node at that position for the Sequence, throw an exception if acessing out of bounds.
*
* Erase / Erase (pos, count) - The erase function when called with just a position removes the node at that position, if called with position and count,
* remove count nodes starting from position if an attempt is made to access out of bounds, throw an exception.
*
* Clear - takes in a sequence and deletes all of the respective nodes.
*
* Size - takes in a sequence and returns the amount of nodes it contains.
*
* Front / Back - Returns the first or last element of the sequence.
*
* Empty - return a true or false boolean value depending on the status of the sequence passed in.
*
* Variables - head_ptr, tail_ptr, numElts
*/
#include "Sequence.h"
#include <stdexcept>
#include <iostream>

using namespace std;



/* Default / Parameterized constructor:
 * Creates an empty sequence or a sequence with numElts nodes.
 * The first nodes index is 0, last nodes index is numElts -1.
 *
 * Parameters : sz , number of nodes
 * Returns : Nothing, constructor
 */
Sequence::Sequence(size_t sz)
    : head_ptr(nullptr), tail_ptr(nullptr), numElts(0) {

    for (size_t i = 0; i < sz; i++) {
        SequenceNode* newNode = new SequenceNode(" ");
        //after creating a node, check if the head of the list is null, if it is, make the new node head and tail.
        if (head_ptr == nullptr) {
            head_ptr = newNode;
            tail_ptr = newNode;
        //otherwise, make the tail point to the new node, and update tail to this new node
        } else {
            tail_ptr->next = newNode;
            newNode->prev = tail_ptr;
            tail_ptr = newNode;
        }
        numElts++;
    }
}
/*Copy Constructor -
* takes in a sequence s amd creates a deep copy of it
 *
 *Parameters: reference to original sequence
 *
 *Returns: Nothing, constructor.
 */
Sequence::Sequence(const Sequence& s) {
    head_ptr = nullptr;
    tail_ptr = nullptr;
    numElts = 0;
    // check if the list is empty first
    if (s.head_ptr != nullptr) {
        head_ptr = new SequenceNode(s.head_ptr->item); //make a new head node with the original heads item
        SequenceNode* currentNew = head_ptr; // new sequence
        SequenceNode* currentOld = s.head_ptr->next; // original sequence to be copied

        numElts= 1;
        // traverse the old list, and make a new node for each item in the list, assigning next and prev pointers to each node.
        while (currentOld != nullptr) {
            SequenceNode* newNode = new SequenceNode(currentOld->item);
            currentNew->next = newNode;
            newNode->prev = currentNew;
            currentNew = newNode;
            currentOld = currentOld->next;
            numElts++;
        }
        tail_ptr = currentNew;
    }

}
/* Destructor -
 * Destroys all nodes in the sequence and releases any dynamically allocated memory
 *
 * Parameters: Nothing
 *
 * Returns: Nothing
 */
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
/* Operator = overload -
 * the sequence passed in allocated memory is released and a new deep copy is made in place.
 *
 * Parameters: reference to original sequence
 *
 * Returns: reference to the new deep copy
 *
 */
Sequence& Sequence::operator=(const Sequence& s) {

head_ptr = nullptr;
tail_ptr = nullptr;
numElts = 0;

    if (s.head_ptr != nullptr) {
        head_ptr = new SequenceNode(s.head_ptr->item);
        SequenceNode* currentNew = head_ptr;
        SequenceNode* currentOld = s.head_ptr->next;
        numElts = 1;

        while (currentOld != nullptr) {
            SequenceNode* newNode = new SequenceNode(currentOld->item);
            currentNew->next = newNode;
            newNode->prev = currentNew;
            currentNew = newNode;
            currentOld = currentOld->next;
            numElts++;
        }
        tail_ptr = currentNew;
    }
    return *this;
}
/* Operator [] overload -
 *
 * Returns the item at the specified index, if index is out of bounds, throw an xception.
 *
 *
 * Parameters: position, index of the node
 *
 * Returns: string item contained at the specified index
 *
 */
string& Sequence::operator[](size_t position) {

if (position >= numElts ) {
    throw out_of_range("Position out of range");
}

    SequenceNode* current = head_ptr;
    for (size_t i = 0; i < position   ; i++) {
        current = current->next;
    }
    return current->item;
}
/* push back -
 * Appends and item to the end of a Sequence, growing its size by one
 *
 * Parameters:  reference to the desired item to be appended to the end of the sequence
 *
 * Returns: Nothing
 *
 */
void Sequence::push_back(const string& item) {

SequenceNode* newNode = new SequenceNode(item);
    //if the list is empty, make the new node head and tail
    if (numElts == 0) {
    head_ptr = newNode;
    tail_ptr = newNode;
    numElts++;
        // otherwise link the old tail to this node and update the tail
    } else {
        newNode->prev = tail_ptr;
        newNode->next = nullptr;
        tail_ptr->next = newNode;
        tail_ptr = newNode;
        numElts++;
    }
}
/* pop back -
 *
 * Removes the last node from the sequence, if called on an empty sequence, throw an exception
 *
 * Parameters: Nothing
 *
 * Returns: Nothing
 *
 */
void Sequence::pop_back() {

if (numElts == 0) {
    throw out_of_range("Empty sequence, cannot pop");
    // if the sequence has only one node, make head and tail null after popping
    } else if (numElts == 1) {

    delete head_ptr;
    head_ptr = nullptr;
    tail_ptr = nullptr;
    numElts = 0;

} else {
    // if the sequence has more than one node, make the tail the previous item, and delete the old tail
    SequenceNode* prevTail = tail_ptr;
    tail_ptr = tail_ptr->prev;
    tail_ptr->next = nullptr;
    delete prevTail;
    numElts--;
}
}
/* insert -
 *
 * Creates a new node after the given index , if index is out of bounds, throw an exception
 *
 *
 * Parameters: Position, index of the sequence, and reference to the item to be added
 *
 * Returns: Nothing
 *
 */
void Sequence::insert(size_t position, const string& item) {

    if ( position > numElts ) {
        throw out_of_range("Position out of range");
    }

    SequenceNode* newNode = new SequenceNode(item);
// if the list is empty, update head and tail to the new node
    if (numElts == 0) {
        head_ptr = newNode;
        tail_ptr = newNode;
// if the node to be added is at the beginning of the sequence, update head and link the new node
    } else if ( position == 0) {
        newNode->next = head_ptr;
        newNode->prev = nullptr;
        head_ptr -> prev = newNode;
        head_ptr = newNode;
        numElts++;
// the node to be added is the end of the sequence, update tail and link the new node
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
        //otherwise traverse the list, and link the node to be added to the existing nodes
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
/* erase (single parameter) -
 *
 *Removes the node at the specified index, if index is out of bounds, throw an exception
 *
 * Parameters: position, index of the sequence to be erased
 *
 * Returns: Nothing
 *
 */
void Sequence::erase(size_t position) {

if ( position > numElts -1 ) {
    throw out_of_range("Position out of range");
}

    SequenceNode* current = head_ptr;

    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    // erase and update the head
    if (current == head_ptr) {
        head_ptr = current->next;
        if ( head_ptr != nullptr ) {
            head_ptr->prev = nullptr;
        } else {
            tail_ptr = nullptr;
        }
    //erase and update the tail
    } else if ( current == tail_ptr ) {
        tail_ptr = current->prev;
        if ( tail_ptr != nullptr ) {
            tail_ptr->next = nullptr;
        }  else {
                head_ptr = nullptr;
            }
// erase in the middle
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
    }
    delete current;
    numElts--;

}
/* erase (two parameters) -
 *
 * removes specified amount of nodes starting from  specified index, if index or count attempts to access out of bounds, throw an exception
 *
 * Parameters: position, first node to be erased
 * count, amount of nodes to be erased
 *
 * Returns: Nothing
 *
 */
void Sequence::erase(size_t position, size_t count) {

    if ( position >= numElts  || count == 0 || position + count > numElts  ) {
        throw out_of_range("Position out of range");
    }

    SequenceNode* firstDelete = head_ptr;

    for (size_t i = 0; i < position; i++) {
        firstDelete = firstDelete->next;
    }

    SequenceNode* lastDelete = firstDelete;

    for (size_t i = 1; i < count; i++) {
        lastDelete = lastDelete->next;
    }
    // after traversing the list and finding the first and last node to delete, create new pointers to node before first and after last
    SequenceNode* beforeFirst = firstDelete->prev;
    SequenceNode* afterLast = lastDelete->next;

    if (beforeFirst != nullptr) {
        beforeFirst->next = afterLast;
    } else {
        head_ptr = afterLast;
    }

    if ( afterLast != nullptr ) {
        afterLast->prev = beforeFirst;
    } else {
        tail_ptr = beforeFirst;
    }

    SequenceNode* current = firstDelete;
//repeatedly delete nodes and update the links until we reach the final node to be deleted
    while ( current != afterLast ) {
        SequenceNode* next = current->next;
        delete current;
        current = next;
        numElts--;
    }
}
/* clear -
 *
 * removes all nodes from a sequence
 *
 * Parameters: nothing
 *
 * Returns: nothing
 *
 */
void Sequence::clear() {

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
/* front -
 * returns the item at index 0, if called on empty sequence, throw exception
 *
 * Parameters: Nothing
 *
 * Returns: string item at index 0
 *
 */
string Sequence::front() const {

if (head_ptr == nullptr) {
    throw out_of_range("Empty sequence, cannot get front");
} else {
    return head_ptr->item;
}
}
/* back -
 * returns the last item of the sequence, if empty throw an exception
 *
 * Parameters:
 *
 * Returns: string item at index numElts - 1
 *
 */
string Sequence::back() const {

if (head_ptr == nullptr) {
    throw out_of_range("Empty sequence, cannot get back");
} else {
    return tail_ptr->item;
}
}
/* empty -
 *
 * returns true if the sequence is empty, otherwise false.
 *
 * Parameters: none
 *
 * Returns: boolean value
 *
 */
bool Sequence::empty() const {

    SequenceNode* current = head_ptr;

    if (current != nullptr) {
        return false;
    } else {
        return true;
    }
}
/* size -
 *
 * returns the current number of nodes in the sequence
 *
 * Parameters: none
 *
 * Returns: numElts
 *
 */
size_t Sequence::size() const {
    return numElts;
}
/* operator << overload -
 *
 * Prints the given sequence in the format " <Bob, Eddy, Dylan> "
 *
 * Parameters: os and reference of sequence to be printed
 *
 * Returns: os
 *
 */
ostream& operator<<(ostream& os, const Sequence& s) {

os << "<";

Sequence::SequenceNode* current = s.head_ptr;

    while (current != nullptr) {
        os << current->item;
        if (current->next != nullptr) {
            os << ", ";

        }
        current = current->next;

        }

    os << ">";
    return os;
}
