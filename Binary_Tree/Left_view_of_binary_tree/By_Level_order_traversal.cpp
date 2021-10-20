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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    if (root == NULL) return ans;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        ans.push_back(q.front()->data);
        while(sz--){
            Node* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
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