#include<bits/stdc++.h>

using namespace std;

vector<int> xorQuery(vector<vector<int>> &queries)
{
    vector<int> arr;
    for(int i = 0; i < queries.size(); i++){
        if(queries[i][0] == 1){
            arr.push_back(queries[i][1]);
        }else if(queries[i][0] == 2){
            for(int j = 0; j < arr.size(); j++){
                arr[j] = (arr[j]^queries[i][1]);
            }
        }
    }
    return arr;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        vector<vector<int> > queries(q, vector<int> (2));
        for(int i = 0; i < q; i++){
            for(int j = 0; j < 2; j++){
                cin>>queries[i][j];
            }
        }

        vector<int> arr = xorQuery(queries);
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

}