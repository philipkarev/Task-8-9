//
// Created by phlilp on 16.11.22.
//

#include "BST.h"


BST::BST() {

    root = NULL;
}


BST::~BST() {

    root = makeEmpty(root);
}


void BST::insert(int x) {

    root = insert(x, root);
}


void BST::remove(int x) {

    root = remove(x, root);
}


void BST::display() {

    inorder(root);
    cout << endl;
}


void BST::search(int x) {

    root = find(root, x);
}