#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* right;
    node* left;
    node(){}
    node(int d){
        data = d;
        right = NULL;
        left = NULL;
    }

};

int height (node* root){
    if (root==NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left,right) + 1;
}

bool balanceHeight(node* root ){

    if (root==NULL)
    {
        return true;
    }
    if (balanceHeight(root->left) == false)
    {
        return false;
    }
    if (balanceHeight(root->right) == false)
    {
        return false;
    }
    int left = height(root->left);
    int right = height (root->right);
    if (abs(left-right)<=1)
    {
        return true;

    }else
    {
        return false;
    }
}
int main(){
    node* root         =       new node(1);
    root->left         =      new node(2);
    root->right        =     new node(3);
    root->left->left   =    new node(4);
    root->left->right  =   new node(5);
    root->right->left  =  new node(6);
    root->right->right = new node(7);

    


    return 0;
}