#include<bits/stdc++.h>

using namespace std;

int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

//Calculate the suffix Array
int *getPrefixArray(int *arr, int n)
{
    int productTillNow = 1;

    int *prefixArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        prefixArray[i] = productTillNow;
        productTillNow = multiply(productTillNow, arr[i]);
    }

    return prefixArray;
}

//Calculate the prefix Array
int *getSuffixArray(int *arr, int n)
{
    int productTillNow = 1;

    int *suffixArray = new int[n];

    for (int i = n - 1; i >= 0; i--)
    {
        suffixArray[i] = productTillNow;
        productTillNow = multiply(productTillNow, arr[i]);
    }

    return suffixArray;
}

int *getProductArrayExceptSelf(int *arr, int n)
{
    //Array storing the product of all elements before the current element
    int *prefixArray = getPrefixArray(arr, n);

    //Array storing the product of all elements after the current element
    int *suffixArray = getSuffixArray(arr, n);
	
    //Array to store the answer
    int *answerArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        //Answer is the product of all elements before and after the current element.
        answerArray[i] = multiply(suffixArray[i], prefixArray[i]);
    }

    delete prefixArray;
    delete suffixArray;

    //Return the answer
    return answerArray;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int * res = getProductArrayExceptSelf(arr, n);
        for(int i = 0; i < n; i++){
            cout<<*(res+i)<<" ";  
        }
        cout<<"\n";
    }
}