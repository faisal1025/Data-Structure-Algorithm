#include<bits/stdc++.h>

using namespace std;
#define size 100

class searching{
    private:
    int find;
    public:
    //parameterized constructor
    searching(int n){
        find = n;
    }
    //recursive binary search
    int binary_search(int *arr, int i, int j){
        if(i <= j){
            int mid;
            mid = (i+j)/2;
            if(arr[mid] == find){
                return mid+1;
            }
            if(find < arr[mid]){
                return binary_search(arr, i, mid-1);
            }
            else if(arr[mid] < find){
                return binary_search(arr, mid+1, j);
            }
        }
        return 0; 
    }
    //destructor
    ~searching(){
        cout<<"searching finished successfully"<<"\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[size], x, index;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cin>>x;
    searching ans(x);
    index = ans.binary_search(arr, 0, n-1);
    if (index)
        cout<<"Position = "<<index<<"\n";
    else
        cout<<"Element not found!!!";   
    return 0;                                    
}