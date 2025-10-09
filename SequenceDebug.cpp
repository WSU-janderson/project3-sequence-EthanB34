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

//Sequence s;
//Sequence s2(0);
    Sequence s3(0);
//s3.insert(3, "okay");
//s3.insert(2, "yes");
Sequence s2(1);
//s3.insert(0, "maybe");
//s3.insert(1, "no");

    //s2.insert(0, "maybe");
    s2.push_back("no");
    s3.push_back("yes");
    s2[1];
//    s2.pop_back();
// exception thrown   s3.pop_back();

    cout << "DONE" << endl;
    cout << s2 << endl;
  s2.clear();
    s2.push_back("yes");
    cout << s3 << endl;
    
    return 0;
}