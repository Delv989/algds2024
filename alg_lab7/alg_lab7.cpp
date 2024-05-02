#include <iostream>

struct node {
    int key, priority;
    node* left, * right;
    node() { }
    node(int key) : key(key), priority(rand()), left(NULL), right(NULL) { }
    node(int key, int prior) : key(key), priority(prior), left(NULL), right(NULL) { }
};
typedef node* ptr_node;

void split(ptr_node t, int key, ptr_node& left, ptr_node& right) {
    if (!t)
        left = right = NULL;
    else if (t->key <= key) {
        split(t->right, key, t->right, right);
        left = t;
    }
    else {
        split(t->left, key, left, t->left);
        right = t;
    }
}

void merge(ptr_node& t, ptr_node t1, ptr_node t2) {
    if (t2 == NULL) {
        t = t1;
        return;
    }if (t1 == NULL) {
        t  = t2;
        return;
    }
    if (t1->priority > t2->priority) {
        merge(t1->right, t1->right, t2);
        t = t1;
    }
    else {
        merge(t2->left, t1, t2->left);
        t = t2;
    }
    return;
}

void insert(ptr_node& t, ptr_node it) {
    if (!t)
        t = it;
    else if (it->priority > t->priority) {
        split(t, it->key, it->left, it->right);
        t = it;
    }
    else {
        if (t->key <= it->key)
            insert(t->right, it);
        else {
            insert(t->left, it);
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";
}
