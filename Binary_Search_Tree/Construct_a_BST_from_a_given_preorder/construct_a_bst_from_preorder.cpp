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

void Preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

class Solution{
    public:
    int findLargest(int pre[], int data, int start, int end){
        for(int i = start; i <= end; i++){
            if(pre[i] > data)
            return i;
        }
        return -1;
    }

    Node* createBST(int pre[], int start, int end){
        if(start > end){
            return NULL;
        }
        Node* root = new Node(pre[start]);
        if(start == end){
            return root;
        }
        int pos = findLargest(pre, pre[start], start, end);
        root->left = createBST(pre, start+1, pos-1);
        root->right = createBST(pre, pos, end);
        return root;
    }
};

int main(){
    int n;
    cin>>n;
    int preorder[n];
    for(int i = 0; i < n; i++){
        cin>>preorder[i];
    }
    Solution obj;
    Node* root = obj.createBST(preorder, 0, n-1);
    Preorder(root);
}