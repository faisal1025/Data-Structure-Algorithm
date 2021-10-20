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

vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int> > q;
        if(!root) return ans;
        q.push({root, 0});
        while(!q.empty()) {
            if(mp.find(q.front().second) == mp.end()){
                mp[q.front().second] = q.front().first->data;
            }
            Node* curr = q.front().first;
            int i = q.front().second;
            if(curr->left){
                q.push({curr->left, --i});
            }
             
            i = q.front().second;
            if(curr->right){
                q.push({curr->right, ++i});
            }
            q.pop();
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
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
   Node* node = new Node(1);
   node->left = new Node(2);
   node->right = new Node(3);
   /*
            1
          /   \
         2     3

         top view: 2 1 3
   */

   vector<int> res = topView(root);
   for(int i = 0; i < res.size(); i++){
       cout<<res[i]<<" ";
   }
}