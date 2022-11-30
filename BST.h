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
        int operator > (node*);  // reload operator node with pointer

        int operator < (int); // reload operator node with integer
        int operator > (int);  // reload operator node with integer

        int operator < (char*); // reload operator node with string
        int operator > (char*);  // reload operator node with string
    };

    node* root;

    node* makeEmpty(node*);
    node* insert(char*, node*);
    node* findMin(node*);
//    node* findMax(node*);
    node* remove(char*,node*);
    void inorder(node*);
    node* find(node*, int);
    node* searchNext(node*, int); // search next element for <

    public:
        BST();
        ~BST();
        void insert(char*);
        void remove(char*);
        void display();
        void search(int);
        int height(node*);
        int get_height();
        int isBalanced(node*);
        void iterator(int);
};

#define TASK_8_9_BTS_H

#endif //TASK_8_9_BTS_H
