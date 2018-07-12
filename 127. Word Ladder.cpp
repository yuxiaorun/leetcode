//
// Created by yxr on 2018/7/12.
//
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> pool;
        set<string> visit;
        pool.push(make_pair(beginWord, 1));
        bool has=false;
        for(auto i:wordList)if(i==endWord)has=true;
        if(!has)return 0;
        visit.insert(beginWord);
        while(!pool.empty()){
            pair<string, int> cur=pool.front();
            pool.pop();
            if(cur.first==endWord)return cur.second;
            vector<string> next=return_next(cur.first, wordList);
            for(int i=0;i<next.size();i++){
                if(visit.find(next[i])==visit.end()){
                    pool.push(make_pair(next[i], cur.second+1));
                    visit.insert(next[i]);
                }
            }
        }
        return 0;
    }

private:
    vector<string> return_next(string word, vector<string> wordList){
        vector<string> result;
        for(int i=0; i<wordList.size(); i++){
            int dif=0;
            for(int j=0;j<word.size();j++){
                if(word[j]!=wordList[i][j])
                    dif+=1;
            }
            if(dif==1)result.push_back(wordList[i]);
        }
        return result;
    }

};
