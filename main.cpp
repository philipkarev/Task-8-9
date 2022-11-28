//
// Created by phlilp on 16.11.22.
//

#include "BST.h"

int main(){

    BST t;
    char string1[] = "Hello, world! My name is Philip.";
    char string2[] = "Hello", string3[] = "1", string4[] = "a44";
    char string5[] = "g";
    t.insert(string5);
    t.insert(string2);
    t.insert(string1);
    t.insert(string5);
    t.insert(string4);
    t.insert(string3);

    t.display();
    t.search(6); // NB!: memory leak
    cout << "The height of tree is " << t.get_height() << endl;

    t.remove(string4); // memory leak
    t.display();

// 0 is false
// 1 is true

    return 0;
}