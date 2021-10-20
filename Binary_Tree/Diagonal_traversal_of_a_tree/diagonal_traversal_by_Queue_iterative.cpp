#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void print(vector<Node*> slop){
    for(auto i = 0; i < slop.size(); i++){
        cout<<slop[i]->data<<" ";
    }
}

void diagonalTraversal(Node* root, queue<pair<Node*, int> > q){
    vector<Node*> main_slop;
    queue<pair<Node*, int> > l;
    if(!root) return;
    main_slop.push_back(root);
    Node* current = root->right;
    int currPos = 1;
    while(current){
        main_slop.push_back(current);
        if(q.front().second == currPos){
            main_slop.push_back(q.front().first);
            q.pop();
        }
        if(current->left) l.push({current->left, currPos});
        current = current->right;
        currPos++;
    }
    while(!q.empty()){
        main_slop.push_back(q.front().first);
        q.pop();
    }
    print(main_slop);
    cout<<"\n";
    diagonalTraversal(root->left, l);
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
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    /*
                1
               /  \
              2    3
            /  \  /  \
           4    5 6   7

           diagonal traversal:
           1 3 7
           2 5 6
           4
    */
   queue<pair<Node*, int> > q;
   diagonalTraversal(root1, q);
    return 0;
}