//
// Created by phlilp on 16.11.22.
//

#include "BST.h"

int main(){

    BST t;
    char string1[] = "Hello, world! My name is Philip.";
    char string2[] = "Hello";
    t.insert(string1);
    t.insert(string2);
//    t.insert(35);
//    t.insert(55);
//    t.insert(30);
//    t.display();
//    t.remove(20);
    t.display();
//    t.remove(25);
//    t.display();
//    t.remove(30);
//    t.display();

    return 0;
}