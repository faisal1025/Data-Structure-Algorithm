#include<iostream>
#define MAXSIZE 10000
using namespace std;

class queue{
    private:
        int rare, front;
        int count;
        int arr[MAXSIZE];
    public:
        queue(){
            rare = -1;
            front = 0;
            count = 0;
        }

        //to insert element in queue
        void enqueue(int val){
            arr[++rare] = val;
            count++;
        }

        //to see element of queue
        int dequeue(){
            count--;
            if(count == 0){
                rare = -1;
                front = 0;
            }

            return arr[front++];
        }

        //to see number of elements in queue
        int size(){
            return count;
        }

        //to check is queue is empty
        bool empty(){
            return rare<front;
        }

};

int main(){
    queue q;
    int n;
    if(q.empty()){
        cout<<"queue is empty ...please enter number of element to enqueue: ";
        cin>>n;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            q.enqueue(x);
        }
    }
    cout<<"fetching elements: ";
    cout<<q.dequeue()<<"\t";
    cout<<q.dequeue()<<"\t";
    cout<<q.dequeue()<<"\t";
    cout<<"size of queue after removing: "<<q.size()<<endl;
    if (q.empty()){
        cout<<"yes, it become empty"<<endl;
    }
    else{
        cout<<"NO, it is not empty";
    }
}