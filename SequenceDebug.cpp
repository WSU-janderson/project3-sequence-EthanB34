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
    Sequence s3(3);
//s3.insert(3, "okay");
//s3.insert(2, "yes");

s3.insert(0, "maybe");
s3.insert(1, "no");
    cout << "DONE" << endl;
    return 0;
}