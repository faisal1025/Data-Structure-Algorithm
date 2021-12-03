#include<bits/stdc++.h>

using namespace std;

/*
   
    Time Complexity : O(N * Q * Q)
    Space Complexity : O(N)

    where 'N' is the length of the fence
    and 'Q' is the number of painters.
*/

int paintTheFence (vector<vector<int>>& ranges, int n, int q)
{

    /*
    	Array denotes the number of painters
    	that can paint section[i].
    */
    vector<int> section(n+1, 0);

    for (int i = 0; i < q; i++)
    {
        int u = ranges[i][0];
        int v = ranges[i][1];

        for (int j = u; j <= v; j++)
        {
            section[j]++;
        }
    }

    int maxPainted = -1e9;

    /*
    	Array to count the number of painters that can paint
    	i-th section after removing a pair of painters.
    */
    vector<int> painted(n+1, 0);

    for (int i = 0; i < q; i++)
    {
        int u = ranges[i][0];
        int v = ranges[i][1];

        painted = section;

        for (int k = u; k <= v; k++)
        {
            painted[k]--;
        }

        for (int j = i+1; j < q; j++)
        {
            /*
            	Count denotes the total number of sections that
            	can be painted by removing painters i and j.
            */
            int count = 0;

            int a = ranges[j][0];
            int b = ranges[j][1];

            for (int z = a; z <= b; z++)
            {
                painted[z]--;
            }

            for (int z = 1; z <= n; z++)
            {
                if (painted[z] > 0)
                {
                    count++;
                }
            }

            for (int z = a; z <= b; z++)
            {
                painted[z]++;
            }

            maxPainted = max(maxPainted, count);
        }
    }
    return maxPainted;
}

int main(){
    int n, q;
    cin>>n>>q;
    vector<vector<int> > ranges(q, vector<int>(2));
    for(int i = 0; i < q; i++){
        cin>>ranges[i][0];
        cin>>ranges[i][1];
    }
    cout<<paintTheFence (ranges, n, q)<<"\n";
}
