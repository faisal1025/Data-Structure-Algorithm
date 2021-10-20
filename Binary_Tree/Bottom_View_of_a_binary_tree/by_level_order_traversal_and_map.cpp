#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node*  right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root) return ans;
    queue<pair<Node*, int> > q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        mp[q.front().second] = q.front().first->data;
        Node* curr = q.front().first;
        int pos = q.front().second;
        if(curr->left) q.push({curr->left, --pos});
        pos = q.front().second;
        if(curr->right) q.push({curr->right, ++pos});
        q.pop();
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);
    /*
                1
              /   \
             2     3
                  / \
                 4   5
                /
                6

        Bottom view : 6 4 3 5
           
    */
   vector<int> res = bottomView(root);
   for(int i = 0; i < res.size(); i++){
       cout<<res[i]<<" ";
   }

}