#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        queue<Node*> q;
        Node* current = node;
        q.push(current);
        while(!q.empty()){
            ans.push_back(current->data);
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
            q.pop();
            current = q.front();
        }
        return ans;
    }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(11);
    root->left->right = new Node(10);
    /*
            1
          /   \
         2     3
       /   \
      11   10
    */
    vector<int> ans = levelOrder(root);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}