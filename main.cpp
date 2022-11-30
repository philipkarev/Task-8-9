//
// Created by phlilp on 16.11.22.
//

#include "BST.h"

int main(){

    BST t;
    char s2[] = "1", s3[] = "ty", s4[] = "a44";
    char s5[] = "word", s6[] = "hello";
    char s7[] = "height", s8[] = "perfect";
    t.insert(s5);
    t.insert(s2);
    t.insert(s7);
    t.insert(s3);

    t.insert(s4); // not balanced tree

    t.insert(s6);
    t.insert(s8);

    t.iterator(2);

    t.display();
    t.search(6);
    cout << "The height of tree is " << t.get_height() << endl;

    t.remove(s4); // memory leak

    return 0;

}
// 0 is false
// 1 is true