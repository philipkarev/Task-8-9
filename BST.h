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

    node* makeEmpty(node* t) {

        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }

        return NULL;
    }


    node* insert(int x, node* t){

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


    node* findMin(node* t) {

        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }


    node* findMax(node* t) {

        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }


    node* remove(int x, node* t) {

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


    void inorder(node *t) {

        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }


    node* find(node* t, int x) {

        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

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
