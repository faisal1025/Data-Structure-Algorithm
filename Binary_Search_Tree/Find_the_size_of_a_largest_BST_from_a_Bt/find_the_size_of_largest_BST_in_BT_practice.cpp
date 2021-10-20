#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

struct info{
    int min;
    int max;
    int size;
    int ans;
    bool isbst;
};

int min(int a, int b){
    if(a<b) return a;
    else return b; 
}
int max(int a, int b){
    if(a>b) return a;
    else return b; 
}

info getLargest(Node* root){
    if(!root) return {INT_MAX, INT_MIN, 0, 0, true};

    struct info left = getLargest(root->left);
    struct info right = getLargest(root->right);
    struct info cur;
    cur.size = left.size+right.size+1;
    if(left.isbst and right.isbst and root->data > left.max and root->data < right.min){
        cur.min = min(root->data, left.min);
        cur.max = max(root->data, right.max);
        cur.ans = left.size+right.size+1;
        cur.isbst = true;
    }
    else{
        cur.min = min(min(root->data, left.min), right.min);
        cur.max = max(max(root->data, right.max), left.max);
        cur.ans = max(left.ans, right.ans);
        cur.isbst = false;
    }
    return cur;
}

int largestBST(Node* root){
    info larBST = getLargest(root);
    return larBST.ans;
}

int main(){
    Node *root = new Node(7);
    root->left = new Node(4);
    root->right = new Node(6);
    // root->left->left = new Node(6);
    root->left->right = new Node(9);

    int ans = largestBST(root);
    cout<<ans;
    return 0;
}