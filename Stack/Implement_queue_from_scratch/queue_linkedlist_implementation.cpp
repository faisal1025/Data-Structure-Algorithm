#include<iostream>

using namespace std;

struct node{
    struct node *next;
    int data;
}*front = NULL, *rare = NULL;

typedef struct node node;

class queue{
    private:
        node *temp;
        int count;
    public:
        queue(){
            count = 0;
            temp = NULL;
        }

        //to enqueue
        void enqueue(int val){
            temp = new node;
            temp->data = val;
            temp->next = NULL;
            if(front == NULL){
                rare = front = temp;
            }else{
                rare->next = temp;
                rare = temp;
            }
            count++;
        }

        //to dequeue
        int dequeue(){
            temp = front;
            int value = front->data;
            front = front->next;
            count--;
            delete temp;
            return value;
        }

        //to check queue is empty
        bool empty(){
            return front == NULL;
        }

        //to check size
        int size(){
            return count;
        }
};

int main(){
    queue q;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }

    cout<<"size of queue before dequeue "<<q.size()<<endl;

    cout<<"order of element fetching in queue: "<<endl;
    for(int j = 0; j < n; j++){
        cout<<q.dequeue()<<endl;
    }

    cout<<"size of queue after dequeue "<<q.size()<<endl;

    if (q.empty()){
        cout<<"queue become empty";
    }else{
        cout<<q.size()<<" element left in queue";
    }
}