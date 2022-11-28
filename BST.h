//
// Created by phlilp on 16.11.22.
//

#ifndef TASK_8_9_BTS_H

#include <iostream>

using namespace std;



class BST {

    struct node {

        char* data = NULL;
        node* left = NULL;
        node* right = NULL;

        node(char*);

        int operator < (node*); // reload operator node with pointer
        int operator >= (node*);  // reload operator node with pointer
    };

    node* root;

    node* makeEmpty(node*);
    node* insert(char*, node*);
//    node* findMin(node*);
//    node* findMax(node*);
//    node* remove(int, node*);
    void inorder(node*);
//    node* find(node*, int);

    public:
        BST();
        ~BST();
        void insert(char*);
//        void remove(int);
        void display();
//        void search(int);
        int height(node*);
        int isBalanced(node*);
};

#define TASK_8_9_BTS_H

#endif //TASK_8_9_BTS_H
