class Solution {
public:
    map <string,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(0,s,wordDict);
    }
private:
    bool dfs(int c, string s, vector<string>& wordDict){

        if(mp.find(s.substr(c))!=mp.end())
            return mp[s];
        if(c==s.size())
            return true;
        for(int i=0;i<wordDict.size();i++){
            int j=wordDict[i].size();
            if(wordDict[i].size()<=s.size()-c && s.substr(c,j)==wordDict[i])
            {
                if(dfs(c+j,s,wordDict)){
                    mp[s.substr(c+j)]=true;
                    return true;
                }else{
                    mp[s.substr(c+j)]=false;
                }
            }

        }
        mp[s.substr(c)]=false;
        return false;
    }
};