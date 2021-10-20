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

queue<Node*> reverse(queue<Node*> q){
    stack<Node*> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

vector <int> zigzagTraversal(Node* root)
{
	vector<int> ans;
	if(!root) return ans;
	queue<Node*> q;
	q.push(root);
	bool zigzag = false;
	while(!q.empty()){
	    int sz = q.size();

	    if(zigzag) zigzag = false;
	    else zigzag = true;
	    
        //Push the queue value in ans vector 
	    queue<Node*> q_copy = q;
	    while(!q_copy.empty()){
	        ans.push_back(q_copy.front()->data);
	        q_copy.pop();
	    }

        //Function to reverse() an queue
	    q = reverse(q);

	    for(int i = 0; i < sz; i++){
    	    Node* curr = q.front();
    	    q.pop();
    	    if(zigzag){
    	        if(curr->right) q.push(curr->right);
    	        if(curr->left) q.push(curr->left);
    	    }
    	    else{
    	        if(curr->left) q.push(curr->left);
    	        if(curr->right) q.push(curr->right);
    	    }
	    }
	}
    return ans;
}

int main(){
    Node* root = new Node(7);
    root->left = new Node(9);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(9);
    /*
    
                    7
                  /   \
                9       7
              /   \    /   
             8     8   6
           /   \
         10     9
              

        Zigzag traversal : 7 7 9 8 8 6 9 10
           
    */
   vector<int> res = zigzagTraversal(root);
   for(int i = 0; i < res.size(); i++){
       cout<<res[i]<<" ";
   }

}