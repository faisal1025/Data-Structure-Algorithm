// Time Complexity = O(N*M*26)
// using BFS for finding shortest path in the case of graph
// space Compexity = N for unordered_set + N for queue string + N for queue len
//                 = O(N+N+N)


#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    void matchWord(string word, int len, unordered_set<string> &wordSet, queue<pair<string, int>> &q){
        // 1 <= word.length() <= 10
        // let M = word.length
        for(int i = 0; i < word.length(); i++){
            char tar = word[i];
            // 26 times
            // overall TC of function = O(M * 26) 
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(wordSet.find(word) == wordSet.end()) continue;
                q.push({word, len+1});
                wordSet.erase(word);
            }
            word[i] = tar;
        }
    }
    
    int ladderBfs(string beginWord, string endWord, unordered_set<string> wordSet){

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        // 1 <= wordSet.size() <= 5000
        // let N = wordSet.size()
        // overall Time Complexity = O(N*M*26)
        while(!q.empty()){
            auto curr = q.front();
            string word = curr.first;
            int len = curr.second;
            q.pop();
            if(word == endWord)
                return len;
            matchWord(word, len, wordSet, q); // Time Complexity of function O(M*26) 
        }
        return 0;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

            unordered_set<string> wordSet; // using unordered_set to perform search
                                            //  in word list dictionary in O(1)
            for(int i = 0; i < wordList.size(); i++){
                wordSet.insert(wordList[i]);
            }
            if(wordSet.find(endWord) == wordSet.end())
                return 0;
            else
                return ladderBfs(beginWord, endWord, wordSet);
            
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
    cout<<obj.ladderLength(beginWord, endWord, wordList); // Time Complexity : O(N*M*26)
}