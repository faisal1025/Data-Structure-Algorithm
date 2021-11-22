#include<bits/stdc++.h>

using namespace std;

const int m = 60;
class Solution{
    public:
    int maxAnd(int N, vector<int> A){
        vector<bitset<m> > arr(N); 
        for(int i = 0; i < N; i++){
            bitset<m> b(A[i]);
            arr[i] = b;
        }
        
        for(int i = 0; i < N; i++){
            
            cout<<arr[i]<<"\n";
        }
        
        int cnt, ele, j, i;
        for(i = 59; i >= 0; i--){
            cnt = 0;
            for(j = 0; j < N; j++){
                if(arr[j][i] == 1){
                    cnt++;
                }else{
                    ele = j;
                }
            }
            if(N - cnt == 1){
                break;
            }
        }
        if(i != -1){
            int k = i-2, sum = 2;
            if(i == 0)sum = 1;
            else if(i == 1)sum = 2;
            while(k > 0){
                sum *= 2;
                k--;
            }
            sum = abs(sum - A[ele]);
            A[ele] += sum;
        }
        
        int ans = A[0];
 
        for (int i = 0; i < N; i++){
            ans = (ans&A[i]);
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n; i++){
        cin>>A[i];
    }
    Solution obj;
    cout<<obj.maxAnd(n, A)<<"\n";
}