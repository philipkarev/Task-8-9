//
// Created by phlilp on 16.11.22.
//

#include "BST.h"


BST::node::node(char* x) {

    int length = 0;
    while (x[length] != '\0') {
        ++length;
    }
    ++length; // for NULL-byte symbol

    data = new char[length];

    for (int i = 0; x[i] != '\0'; ++i)
        data[i] = x[i];
    data[length - 1] = '\0';

    left = right = NULL;
}


int BST::node::operator < (node* n) {  // reload operator < node with pointer

    if (n == NULL)
        cout << "Error in BST::operator <. The node* is empty." << endl;

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    int len_n = 0;
    for (int i = 0; n->data[i] != '\0'; ++i) {
        ++len_n;
    }
    ++len_n;

    return (len_this < len_n ? 1 : 0);
}


int BST::node::operator > (node* n) {  // reload operator > node with pointer

    if (n == NULL)
        cout << "Error in BST::operator >. The node* is empty." << endl;

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    int len_n = 0;
    for (int i = 0; n->data[i] != '\0'; ++i) {
        ++len_n;
    }
    ++len_n;

    return (len_this > len_n ? 1 : 0);
}

int BST::node::operator < (int n) {  // reload operator < node with integer

    if (n < 0)
        cout << "Error in BST::operator <. n < 0." << endl;

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    return (len_this < n ? 1 : 0);
}


int BST::node::operator > (int n) {  // reload operator > node with integer

    if (n < 0)
        cout << "Error in BST::operator <. n < 0." << endl;

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    return (len_this > n ? 1 : 0);
}


int BST::node::operator < (char* x) { // reload operator < node with string

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    int len_x = 0;
    for (int i = 0;x[i] != '\0'; ++i) {
        ++len_x;
    }
    ++len_x;

    return (len_this < len_x ? 1 : 0);
}


int BST::node::operator > (char* x) {  // reload operator > node with string

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

    int len_x = 0;
    for (int i = 0; x[i] != '\0'; ++i) {
        ++len_x;
    }
    ++len_x;

    return (len_this > len_x ? 1 : 0);
}


BST::node* BST::insert(char* x, node* t) {

    if (t == NULL) {
        t = new node(x);
    }
    else {
        if (*t > x) {
            t->left = insert(x, t->left);
        }
        else if (*t < x) {
            t->right = insert(x, t->right);
        }
    }

    return t;
}


BST::node* BST::makeEmpty(node* t) {

    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete [] t->data;
        delete t;
    }

    return NULL;
}


BST::node* BST::findMin(node* t) {

    if (t == NULL)
        return NULL;

    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

/*
BST::node* BST::findMax(node* t) {

    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
} */


BST::node* BST::remove(char* x, node* t) {

    node* tmp;

    if (t == NULL)
        return NULL;

    if (*t > x) {
        t->left = remove(x, t->left);
    }
    else if (*t < x) {
        t->right = remove(x, t->right);
    }

    else if (t->left && t->right) {
        tmp = findMin(t->right); // search min el in right tree

        int length = 0;

        while (tmp->data[length] != '\0') {
            ++length;
        }
        ++length; // for NULL-byte symbol

        t->data = new char[length];

        for (int i = 0; tmp->data[i] != '\0'; ++i)
            t->data[i] = tmp->data[i];
        t->data[length - 1] = '\0';

        t->right = remove(t->data, t->right);
    }

    else {
        tmp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;

        if (tmp != NULL){
            delete [] tmp->data;
        }
        delete tmp;
    }

    return t;
}


void BST::inorder(node *t) {

    if (t == NULL)
        return;

    inorder(t->left);
    for (int i = 0; t->data[i] != '\0'; ++i)
        cout << t->data[i];
    cout << "   ";
    inorder(t->right);
}


BST::node* BST::find(node* t, int x) {

    if (t == NULL) {
        return NULL;
    }

    if (*t > x)
        return find(t->left, x);
    else if (*t < x)
        return find(t->right, x);
    else {
        cout << "Find element is ";
        for (int i = 0; t->data[i] != '\0'; ++i)
            cout << t->data[i];
        cout << endl;

        return t;
    }
}


BST::node* BST::searchNext(node* node, int x) { // search next element for <

    if (node == NULL) {
        return NULL;
    }

    else if ((find(node, x))->left != NULL) {
        return (find(node, x))->left;
    }
    else {
        return NULL;
    }
}


BST::BST() {

    root = NULL;
}


BST::~BST() {

    root = makeEmpty(root);
}


void BST::insert(char* x) {

    root = insert(x, root);
    if (isBalanced(root) == 0) {
        cout << "Error: tree isn't balanced" << endl;
        remove(x);
    }
}


void BST::remove(char* x) {

    root = remove(x, root);
}


void BST::display() {

    inorder(root);
    cout << endl;
}


void BST::search(int x) {

    find(root, x);
}


int BST::height(node* node) {

    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}


int BST::get_height() {

    return height(root);
}


int BST::isBalanced(node* root) {

    int left_height;
    int right_height;

    if (root == NULL)
        return 1;

    left_height = height(root->left);
    right_height = height(root->right);

    if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
//        cout << "Tree is balanced." << endl;
        return 1;
    }

//    cout << "Tree isn't balanced." << endl;
    return 0;
}


void BST::iterator(int x) { // search next node for <

    node* t = searchNext(root, x);

    if (t == NULL)
        return;

    cout << "The next element is ";
    for (int i = 0; t->data[i] != '\0'; ++i)
        cout << t->data[i];
    cout << endl;
}