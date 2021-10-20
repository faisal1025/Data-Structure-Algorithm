// Time Complexity : O(N^N)
// where N = wordList.size()

#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool matchWord(string wordList, string beginWord){
        int cnt = 0;
        for(int j = 0; j < beginWord.length(); j++){
            if(wordList[j] != beginWord[j])
                cnt++;
        }
        if(cnt == 1) return true;
        return false;
    }
    
    void ladderDfs(string beginWord, string endWord, vector<string>& wordList, int ans, bool &is_ladder, int &min, map<string, bool> &visited){
        
        visited[beginWord] = true;
        if(endWord == beginWord){
            if(min > ans){
                is_ladder = true;
                min = ans;
            }
            visited[beginWord] = false;
            return;
        }
        for(int i = 0; i < wordList.size(); i++){
            if( !visited[wordList[i]] and matchWord(wordList[i], beginWord))
                ladderDfs(wordList[i], endWord, wordList, ans+1, is_ladder, min, visited);
        }
        visited[beginWord] = false;
        return;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            bool is_ladder = false;
            int min = INT_MAX;
            map<string, bool> visited;
            ladderDfs(beginWord, endWord, wordList, 1, is_ladder, min, visited);
            if(is_ladder)
                return min;
            return 0;
    }
};

int main(){
    string beginWord, endWord;
    vector<string> wordList;
    int n;
    cin>>n;
    cin>>beginWord>>endWord;
    for(int i = 0; i < n; i++){
        string tempWord;
        cin>>tempWord;
        wordList.push_back(tempWord);
    }
    Solution obj;
    cout<<obj.ladderLength(beginWord, endWord, wordList);
}