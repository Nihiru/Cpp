/**
 * Binary Search Tree
 * -) The left subtree of node contains only nodes with keys lesser than the nodes key
 * -) The right subtree of node contains only nodes with keys greater than the nodes key
 * -) There must be no duplicate nodes 
 * -) The depth of the node is the number of edges from the node to the tree's root node
 * -) The height of a node is the number of edges on the longest path from the node to a leaf.
 * 
 * 
*/
#include <iostream>

// using namespace std;

extern typedef struct node_s{
    int data;
    struct node_s  *left, *right;
}node;
// Iterative search operation
// based on the key we're performing a search opeartion
bool iterativeSearch(node* root, int key){
    while(root != NULL){
        if(key > root->data)
            root = root->right;
        else if(key < root->data)
            root = root->left;
        else
            return true;
    }
    return false;
}

// recursive approach for findig an element
bool recursiveSearch(node* root, int key){
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    else if(root->data > key)
        return recursiveSearch(root->left, key);
    else if(root->data < key)
        return recursiveSearch(root->right, key);
    else 
        return false;
}
// Defining a structure for inserting a new node into the structure
struct node *newNode(int item){
    struct node * temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;

}

// inserting a new data structure
struct node *insert(node * node, int data){
    if(node == NULL)
        return newNode(data);
    // recursive call for inserting nodes to the tree
    if(data < node->data)
        node->left = insert(node->left, data); 
    else if(data > node->data)
        node->right = insert(node->right, data);
    
    return node;
}
// finding the minimum value in a tree
int minimum_value(node * node){
    struct node* current = node;
    while(current && current->left != NULL)
            current = current->left;
     
           
    return current->data;
}

// return the height of the tree
int height(node * node){
    if(node == NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if(lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void delete_Item(node* root, int element){

}
int main(){
    bool found = false;
    int dele_item = -1;
    node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 05);
    insert(root, -5);
    insert(root, 100);
    insert(root, 200);
    insert(root, 300);
    insert(root, 400);
    insert(root, 500);
    insert(root, 600);
    int hei = height(root);
    std::cout << "Height of a tree " << hei << std::endl;
    // found = recursiveSearch(root, 30);
        if(found == true)
        std::cout << "Element found" << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    // dele_item =  delete_Item(root, -5);
    if(dele_item == -1)
        std::cout << "Something went wrong while deleting" << std::endl;
    else
        std::cout << "Deletion successful" << std::endl;




    std::cout << root->data  << std::endl;
    return 0;
}
