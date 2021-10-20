#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<int> rightView(Node* root){
    vector<int> ans;
    queue<Node*> q;
    if(root == NULL) return ans;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            if(i == 0){
                ans.push_back(q.front()->data);
            }
            Node* curr = q.front();
            q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
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

        right view: 4 2 1 7
    */
   vector<int> ans = rightView(root);
   for(int i = 0; i < ans.size(); i++){
       cout<<ans[i]<<" ";
   }
}