#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int currLevel;

int height(Node* root){
    if(root == NULL) return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight)+1;
}

vector<int> preorder(Node* root, int h, int l, vector<int> v){
    
    vector<int> empty_v;
    if(currLevel == l){
        v.push_back(root->data);
        currLevel = l+1;
    }
    if(root->left){
        vector<int> ans = preorder(root->left, h, l+1, empty_v);
        v.insert(v.end(), ans.begin(), ans.end());
    }
    if(root->right){
        vector<int> ans = preorder(root->right, h, l+1, empty_v);
        v.insert(v.end(), ans.begin(), ans.end());
    }  
    return v;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    currLevel = 0;
    vector<int> v;
    int h = height(root);
    vector<int> ans = preorder(root, h, 0, v);
    return ans;
}


int main(){
    Node* root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(1);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    /*
              4
            /   \
           5     2
                / \
               3   1
              / \
             6   7

        Ans: 4 5 3 6
    */
    Node* node = new Node(1);
    node->left = new Node(3);
    node->right = new Node(2);
    /*
            1
          /   \
         3     2
        
        Ans: 1 3
    */
    vector<int> ans = leftView(root);
    for(int i = 0; i < ans.size(); i++){
       cout<<ans[i]<<" ";
    }
    cout<<"\n";
    ans = leftView(node);
    for(int i = 0; i < ans.size(); i++){
       cout<<ans[i]<<" ";
    }
    return 0;
}