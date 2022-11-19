//
// Created by phlilp on 16.11.22.
//

#include "BST.h"


struct node;

BST::node* BST::makeEmpty(node* t) {

    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    return NULL;
}


BST::node* BST::insert(int x, node* t) {

    if (t == NULL){
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);

    return t;
}


BST::node* BST::findMin(node* t) {

    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}


BST::node* BST::findMax(node* t) {

    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}


BST::node* BST::remove(int x, node* t) {

    node* tmp;

    if (t == NULL)
        return NULL;

    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);

    else if (t->left && t->right) {
        tmp = findMin(t->right);
        t->data = tmp->data;
        t->right = remove(t->data, t->right);
    }

    else {
        tmp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete tmp;
    }

    return t;
}


void BST::inorder(node *t) {

    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}


BST::node* BST::find(node* t, int x) {

    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
        return find(t->right, x);
    else
        return t;
}

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