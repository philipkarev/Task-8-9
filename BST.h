//
// Created by phlilp on 16.11.22.
//

#ifndef TASK_8_9_BTS_H

#include <iostream>
using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node*);
    node* insert(int, node*);
    node* findMin(node*);
    node* findMax(node*);
    node* remove(int, node*);
    void inorder(node *);
    node* find(node*, int);

    public:
        BST();
        ~BST();
        void insert(int);
        void remove(int);
        void display();
        void search(int);
};

#define TASK_8_9_BTS_H

#endif //TASK_8_9_BTS_H
