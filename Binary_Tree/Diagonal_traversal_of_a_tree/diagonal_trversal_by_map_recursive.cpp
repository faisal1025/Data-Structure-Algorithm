#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void diagonalTraversal(Node* root, int curr_i, map<int, vector<int> > &mp){
    if(!root) return;

    mp[curr_i].push_back(root->data);

    diagonalTraversal(root->left, curr_i+1, mp);

    diagonalTraversal(root->right, curr_i, mp);

}

int main(){
    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);
    root1->left->right->left = new Node(4);
    root1->left->right->right = new Node(7);
    /*
                8
              /   \
             3     10
           /     /   \
          1     6    14
              /  \   /
             4    7 13

        diagonal traversal: 
        8 10 14
        3 6 7 13
        1 4
    */
   map<int, vector<int> > mp;
   diagonalTraversal(root1, 0, mp);
   for(auto it : mp){
       for(auto iter: it.second){
           cout<<iter<<" ";
       }
       cout<<endl;
   }
}