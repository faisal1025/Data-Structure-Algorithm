#include<bits/stdc++.h>
using namespace std;

// template of a node of a graph having three constructor of this class.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Solution class for making clone of a given graph 
class Solution {
private:
    // making clone of a graph through dfs
    Node* cloneGraphHelper(Node* node, map<Node*, Node*> &visited){
        if(!node)
            return node;
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for(auto adjNode : node->neighbors){
            if(visited.find(adjNode) != visited.end())
                newNode->neighbors.push_back(visited[adjNode]);
            else{
                Node* newAdj = cloneGraphHelper(adjNode, visited);
                newNode->neighbors.push_back(newAdj);    
            }
            
        }
        return newNode;
    }
public:
    // Return a cloned graph node reference (callable function through main)
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;
        Node* finalNode = cloneGraphHelper(node, visited);
        return finalNode;
    }
};

// Function to print a graph
void printGraph(Node* node, map<int, int> &visited){
    cout<<node->val<<" ";
    visited[node->val] = 1;
    for(auto adjNode : node->neighbors){
        if(!visited[adjNode->val])
            printGraph(adjNode, visited);
    }

}

int main(){
    // creating a graph hard code
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    // calling Solution class function cloneGraph to clone the given graph
    Solution obj;
    Node* newNode = obj.cloneGraph(node1);

    //printing the new referenced with starting node(newNode) cloned graph
    map<int, int> visited;
    printGraph(newNode, visited);
    return 0;

}