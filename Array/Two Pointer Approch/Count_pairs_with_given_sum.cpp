#include<iostream>
#include<algorithm>

using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        for(int i = 0; i < n; i++)cout<<arr[i]<<" ";
        cout<<endl;
        int i = 0;
        int j = n-1;
        int cnt = 0;
        
        while(i < j){
            if(arr[i]+arr[j] == k){
                cnt++;
                if(arr[i+1]+arr[j] == k){
                    i++;
                }else if(arr[i]+arr[j-1] == k){
                    j--;
                }else{
                    i++;
                    j--;
                }
            }else if(arr[i]+arr[j] < k){
                i++;
            }else if(arr[i]+arr[j] > k){
                j--;
            }
        }
        return cnt;
    }
};

int main(){
    int n, k;
    cin>>n;
    cin>>k;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }


    Solution obj;
    cout<<obj.getPairsCount(arr, n, k);


}