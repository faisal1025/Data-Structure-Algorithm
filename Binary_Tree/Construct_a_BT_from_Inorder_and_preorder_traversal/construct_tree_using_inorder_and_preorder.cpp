 #include<bits/stdc++.h>
 
 using namespace std;


 struct Node{
     int data;
     struct Node * left;
     struct Node* right;
     Node(int val){
         data = val;
         left = NULL;
         right = NULL;
     }
 };
/*======================================================================*/
// void Inorder(Node* root, vector<int> &in){
//     if(!root) return ;

//     Inorder(root->left, in);
//     in.push_back(root->data);
//     Inorder(root->right, in);
// }
// void preorder(Node* root, vector<int> &pre){
//     if(!root) return ;

//     pre.push_back(root->data);
//     preorder(root->left, pre);
//     preorder(root->right, pre);
// }
/*=========================================================================*/
int search(int in[], int start, int end, int curr){
    for(int i = start; i <= end; i++){
        if(in[i] == curr){
            return i;
        }
    }
    return -1;
}

void printInorder(Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout<<node->data<<" ";

	/* now recur on right child */
	printInorder(node->right);
}

Node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder
	traversal using preIndex
	and increment preIndex */
	Node* tNode = new Node(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
    //cout<<tNode->data<<endl;
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal, construct left and
	right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}


Node* constructTree(int in[], int pre[], int n){
    Node* head = buildTree(in, pre, 0, n-1);
    return head;
    
}

 int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);
    /*
                8
              /   \
             3     10
           /     /   \
          1     6    14
              /  \   /
             4    7 13

        Inorder : 1 3 8 4 6 7 10 13 14
        Preorder: 8 3 1 10 6 4 7 14 13
        
    */
    int in[] = { 1, 3, 8, 4, 6, 7, 10, 13, 14};
	int pre[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };

    int len = sizeof(in) / sizeof(int);

    Node* head = constructTree(in, pre, len);

    printInorder(head);
    
 }  