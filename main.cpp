//
// Created by phlilp on 16.11.22.
//

#include "BST.h"

int main(){

    BST t;
    char string1[] = "Hello, world! My name is Philip.";
    char string2[] = "Hello", string3[] = "1", string4[] = "a44";
    t.insert(string1);
    t.insert(string2);
    t.insert(string3);
    t.insert(string4);
//    t.insert(30);
    t.display();
//    t.remove(20);
//    t.display();

// 0 is false
// 1 is true

//    t.remove(25);
//    t.display();
//    t.remove(30);
//    t.display();

    return 0;
}