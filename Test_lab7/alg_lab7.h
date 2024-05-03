#pragma once
struct node {
    int key, priority;
    node* left, * right;
    node() { }
    node(int key) : key(key), priority(rand()), left(NULL), right(NULL) { }
    node(int key, int prior) : key(key), priority(prior), left(NULL), right(NULL) { }
};
typedef node* ptr_node;

void split(ptr_node t, int key, ptr_node& left, ptr_node& right);

void merge(ptr_node& t, ptr_node t1, ptr_node t2);

void insert(ptr_node& t, ptr_node it);