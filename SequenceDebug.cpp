/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>

#include "Sequence.h"

using namespace std;

int main() {

Sequence s1;
    s1.push_back("yes");
    s1.push_back("maybe");
    s1.push_back("no");
    Sequence s2;
    s2.push_back("hmmm");
    s2 = s1;
s2.erase(0);


    cout << "DONE" << endl;


    return 0;
}