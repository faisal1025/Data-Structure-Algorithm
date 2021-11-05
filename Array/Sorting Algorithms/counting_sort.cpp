#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:
    int maxEle(int *arr, int n){
        int m = 0;
        for(int i = 0; i < n; i ++){
            m = max(m, arr[i]);
        }
        return m;
    }
    public:
    int * countingSort(int arr[], int s, int e){
        int m = maxEle(arr, e);
        int mp[m+1];
        int *feq = new int(m+1);
        for(int i = 0; i <= m; i++){
            mp[i] = 0;
        }

        // counting frequencies
        for(int i = 0; i < e; i++){
            mp[arr[i]]++;
        }

        for(int i = 0; i <= m; i++){
            feq[i] = mp[i];
        }

        // find the position
        for(int i = 1; i <= m; i++){
            mp[i] += mp[i-1];
        }


        int arr1[e];
        for(int i = e-1; i >= 0; i--){
            mp[arr[i]]--;
            // cout<<mp[arr[i]]<<" "<<feq[arr[i]]<<endl;
            arr1[mp[arr[i]]] = arr[i];
        }
        for(int i = 0; i < e; i++){
            arr[i] = arr1[i];
        }
        // for(int i = 0; i < e; i++){
        //     cout<<arr1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < e; i++){
        //     cout<<arr[i]<<" ";
        // }
        return feq; 
    }
};

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i = 0; i < n; i++){
        cin>>ar[i];
    }

    Solution obj;
    int *feq = obj.countingSort(ar, 0, n);

    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" "<<feq[ar[i]]<<"\n";
    }
    return 0;
}