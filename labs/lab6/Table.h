#include <iostream>
#include <cstring>
#include <cctype>

struct node {
    int data;
    node *left, *right;
};

void build(node *&root);  // supplied
void display(node *root); // supplied
void destroy(node *&root); // supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int count(node *root);
int sum(node *root);
int height(node *root);
