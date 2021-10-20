#include<iostream>

using namespace std;

struct Node{
    struct Node *pre;
    int value;
}*top = NULL;

typedef struct Node node;

class stack {
    private:
        int count;
        node *temp;
    public:
        stack(){
            count = 0;
        }

        //to check it is empty 
        bool empty(){
            return top == NULL;
        }

        //to insert an element
        void push(int item){
            temp = new node;
            temp->value = item;
            temp->pre = top;
            top = temp;
            count++;
        }

        //to delete an element
        int pop(){
            node *temp = top;
            int data = top->value;
            top = top->pre;
            count--;
            delete temp;
            return data;
        }

        //to see the top element 
        int peak(){
            return top->value;
        }

        //to see the size of the stack
        int size(){
            return count;
        }

};

int main(){
    stack st;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    cout<<"this is peak function"<<st.peak()<<"\n";
    cout<<"this is pop function"<<st.pop()<<"\n";
    cout<<"this is peak function"<<st.peak()<<"\n";
    cout<<"this is pop function"<<st.pop()<<"\n";
    cout<<"this is peak function"<<st.peak()<<"\n";
    cout<<"this is pop function"<<st.pop()<<"\n";
    cout<<"this is peak function"<<st.peak()<<"\n";
    cout<<"this is size function"<<st.size();

}
