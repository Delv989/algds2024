#include <iostream>

struct node {
    int key, prior;
    node* l, * r;
    node() { }
    node(int key) : key(key), prior(rand()), l(NULL), r(NULL) { }
    node(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef node* ptr_node;

int main()
{
    std::cout << "Hello World!\n";
}
