//if there are four frinds planing for a party after covid lockdown A, B, C, D they 
//could go either in a pair or alone find the total no of ways in which they could go
#include<bits/stdc++.h>

using namespace std;

int no_of_ways(int n){
    //we have to see the ways in which smallest no of friends can go for party
    //if there are 1 or 2 friends
    if(n == 1 || n == 2) return n;  //base case

    //see for one friend only, if A goes alone remaing frinds(n-1) ways they can go
    int first_way = no_of_ways(n-1);

    //if A goes in pair it can make pair in n-1 ways * no of ways remaining n-2 friends
    //can go
    int second_way = (n-1)*no_of_ways(n-2);

    //addind all ways
    return first_way+second_way;

}
int main(){
    cout<<no_of_ways(4);
}