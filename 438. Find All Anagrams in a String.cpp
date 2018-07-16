//
// Created by yxr on 2018/7/16.
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int p_size=p.size();
        if(p_size>s.size())return result;
        for(int i=0;i<s.size()-p_size+1;i++){
            string c=s.substr(i,p_size);

            map<char,int>tmp;
            for(int i=0;i<p.size();i++)
                tmp[p[i]]+=1;

            for(int j=0;j<c.size();j++){
                tmp[c[j]]-=1;
            }
            auto it=tmp.begin();
            while(it != tmp.end()){
                if(it->second!=0)
                    break;
                it++;
            }
            cout<<endl;
            if(it==tmp.end())
                result.push_back(i);

        }
        return result;
    }

};
