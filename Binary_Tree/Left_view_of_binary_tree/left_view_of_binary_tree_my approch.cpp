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

vector<int> v;
int flag ;

int height(Node* root){
    if(root == NULL) return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight)+1;
}

void lview(Node* root, int h, int l){
    if(l == h){
        flag = 1;
        return;
    }
    if(root->left || root->right){
        if(root->left){
            v.push_back(root->left->data);
            lview(root->left, h, l+1);
        }
        if(!root->left && root->right){
            v.push_back(root->right->data);
            lview(root->right, h, l+1);
        }
        if(root->left && root->right && flag == 0){
            lview(root->right, h, l+1);
        }
    }
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    v.clear();
    flag = 0;
    int h = height(root);
    v.push_back(root->data);
    lview(root, h, 1);
    return v;
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