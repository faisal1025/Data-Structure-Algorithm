#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//create a struct user defined data type 'info' which stores information of largest BST till each node and 
//return the user defined data type to each node.
struct info{
    int size;
    int min;
    int max;
    int ans;
    bool isbst;
};

info largestBst(Node* root){
    if(!root) return {0, INT_MAX, INT_MIN, 0, true};
    if(!root->left and !root->right){
        info node = {1, root->data, root->data, 1, true};
        return node;
    }

    info leftinfo = largestBst(root->left);
    info rightinfo = largestBst(root->right);

    info curr;
    curr.size = (leftinfo.size + rightinfo.size +1);
    if(leftinfo.isbst && rightinfo.isbst && leftinfo.max < root->data && rightinfo.min > root->data){
        curr.min =  min(leftinfo.min, root->data);
        curr.max = max(rightinfo.max, root->data);
        curr.ans = curr.size;
        curr.isbst = true;
        return curr;
    }
    curr.min = (leftinfo.min);
    curr.max = (rightinfo.max);
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isbst = false;
    return curr;
}

Node* createBst(Node* root, int val){
    if(!root){
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createBst(root->left, val);
    }
    else{
        root->right = createBst(root->right, val);
    }
    return root;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    /*
            13
          /    \
        20      25
       /
      8

    ans = 2

    */

    info ans = largestBst(root);
    cout<<ans.ans<<" ";
}