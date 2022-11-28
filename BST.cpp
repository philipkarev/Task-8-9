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


int BST::node::operator < (node* n) {  // reload operator node with pointer

//    if (n == NULL)  // NB!
//        cout << "Go to BST::operator <" << endl;

    int len_n = 0;
//    cout << "\nn->data[i]\n";
    for (int i = 0; n->data[i] != '\0'; ++i) {
//        cout << n->data[i];
        ++len_n;
    }
//    cout << endl;
    ++len_n;
//    cout << "len_n = " << len_n << endl;

//    cout << "\nthis->data[i]\n";
    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
//        cout << this->data[i];
        ++len_this;
    }
    ++len_this;

//    cout << "len_this = " << len_this << endl;
//    cout << "len_n = " << len_n << endl;
//    cout << "result = " << (len_this < len_n ? 1 : 0) << "\n\n\n\n";

    return (len_this < len_n ? 1 : 0);
}


int BST::node::operator >= (node* n) {  // reload operator node with pointer

//    if (n == NULL)  // NB!
//        cout << "Go to BST::operator <" << endl;

    int len_n = 0;
    for (int i = 0; n->data[i] != '\0'; ++i) {
        ++len_n;
//        cout << len_n1 << endl;
    }
    ++len_n;

    int len_this = 0;
    for (int i = 0; this->data[i] != '\0'; ++i) {
        ++len_this;
    }
    ++len_this;

//    cout << "\nLength of n = " << len_n << endl;
//    cout << "\nLength of this = " << len_this << "\n" << endl;
//    cout << "result >= is " << (len_this >= len_n ? 1 : 0) << endl;

    return (len_this >= len_n ? 1 : 0);
}


BST::node* BST::insert(char* x, node* t) {

//    if (t == NULL)
//        cout << "t = " << t << endl;

    if (t == NULL) {
        t = new node(x);
//        cout << 60 << endl;
    }
    else {
        node* u = new node(x);

//        cout << "*t < u return " << (*t < u) << endl;
//        cout << "t < u return " << (t < u) << endl;
//        cout << "u >= t return " << (*t >= u) << endl;

// перегружен оператор сравнения для вершины и указателя. Вызвать оператор из
// можно сейчас так *t < u

        if (*u < t) { // *t < u
//            cout << 66 << endl;
            delete u;
            t->left = insert(x, t->left);
        }
        else if (*u >= t) { // !!
//            cout << 71 << endl;
            delete u;
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


// перегружен оператор сравнения для вершины и указателя. Вызвать оператор из
// можно сейчас так *t < u

/*BST::node* BST::insert(char* x, node* t) {

    if (t == NULL)
        t = new node(x);

    else if (t < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);

    return t;
}*/


//BST::node* BST::findMin(node* t) {
//
//    if (t == NULL)
//        return NULL;
//    else if (t->left == NULL)
//        return t;
//    else
//        return findMin(t->left);
//}
//
//
//BST::node* BST::findMax(node* t) {
//
//    if (t == NULL)
//        return NULL;
//    else if (t->right == NULL)
//        return t;
//    else
//        return findMax(t->right);
//}


/*BST::node* BST::remove(char* x, node* t) {

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
*/

void BST::inorder(node *t) { // !!!

    if (t == NULL)
        return;

    inorder(t->left);
    for (int i = 0; t->data[i] != '\0'; ++i)
        cout << t->data[i];
    cout << "   ";
    inorder(t->right);
}


/*BST::node* BST::find(node* t, int x) {

    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
        return find(t->right, x);
    else
        return t;
} */

BST::BST() {

    root = NULL;
}


BST::~BST() {

    root = makeEmpty(root);
}


// перегружен оператор сравнения для вершины и указателя.
// Вызвать оператор из insert
// можно сейчас так *t < u

void BST::insert(char* x) {

    root = insert(x, root);
}
/*

void BST::remove(int x) {

    root = remove(x, root);
}*/


void BST::display() {

    inorder(root);
    cout << endl;
}


/*void BST::search(int x) {

    root = find(root, x);
}

 */


int BST::height(node* node) {

    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int BST::isBalanced(node* root) {

    int left_height;
    int right_height;

    if (root == NULL)
        return 1;

    left_height = height(root->left);
    right_height = height(root->right);

    if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        cout << "Tree is balanced." << endl;
        return 1;
    }

    cout << "Tree isn't balanced." << endl;
    return 0;
}

/*int BST::operator < (node* n1) {

//    if (n1 == NULL || n2 == NULL)
//        cout << "Go to BST::operator <" << endl;

    int len_n1;
    for (int i = 0; n1->data[i] != '\0'; ++i)
        ++len_n1;

    int len_n2;
    for (int i = 0; this->root->data[i] != '\0'; ++i)
        ++len_n2;

    return (len_n1 < len_n2 ? 1 : 0);
}*/

/*int operator >= (node* n1, node* n2) {

    if (n1 == NULL || n2 == NULL)
        cout << "Go to BST::operator >=" << endl;

    int len_n1;
    for (int i = 0; n1->data[i] != '\0'; ++i)
        ++len_n1;

    int len_n2;
    for (int i = 0; n2->data[i] != '\0'; ++i)
        ++len_n2;

    return (len_n1 >= len_n2 ? 1 : 0);
}*/


// 1) При вводе значения сразу создать узел (написать конструктор) - иниц.данные, указатели по нулям;
// 2) И уже реализовать вставку узла с помощью перегруж.оператора сравн.