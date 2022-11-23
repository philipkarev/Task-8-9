//
// Created by phlilp on 16.11.22.
//

#ifndef TASK_8_9_BTS_H

#include <iostream>
#define N 512

using namespace std;



class BST {

    struct node {

        char* data = NULL;
        node* left = NULL;
        node* right = NULL;

        node(char* x) {

            data = new char[N];

            for (int i = 0; x[i] != '\0'; ++i)
                data[i] = x[i];

            left = right = NULL;
        }

        int operator < (node* n) {

            if (n == NULL)  // NB!
                cout << "Go to BST::operator <" << endl;

            int len_n1;
            for (int i = 0; n->data[i] != '\0'; ++i)
                ++len_n1;

            int len_n2;
            for (int i = 0; this->data[i] != '\0'; ++i)
                ++len_n2;

            return (len_n1 < len_n2 ? 1 : 0);
            }

        int operator >= (node* n) {

            if (n == NULL)  // NB!
                cout << "Go to BST::operator <" << endl;

            int len_n1;
            for (int i = 0; n->data[i] != '\0'; ++i)
                ++len_n1;

            int len_n2;
            for (int i = 0; this->data[i] != '\0'; ++i)
                ++len_n2;

            return (len_n1 >= len_n2 ? 1 : 0);
        }
    };

    node* root;

    node* makeEmpty(node*);
    node* insert(char*, node*);
    node* findMin(node*);
    node* findMax(node*);
//    node* remove(int, node*);
    void inorder(node *);
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
