//
// Created by yxr on 2018/7/17.
//
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        map<int,vector<int>> pos;
        vector<int> results;
        vector<int> leaves;
        vector<bool> delet(n,false);
        if(n==1){results.push_back(0); return results;}
        for(int i=0;i<edges.size();i++){
            pos[edges[i].first].push_back(edges[i].second);
            pos[edges[i].second].push_back(edges[i].first);
        }
        while(n-leaves.size()>2){
            vector<int> to_delete;
            for(int i=0; i<n; i++){
                if(delet[i])continue;
                if(adjacent(i, pos, delet)==1){
                    pos[i].clear();

                    to_delete.push_back(i);
                }

            }
            for(int i=0; i<to_delete.size(); i++){
                delet[to_delete[i]]=true;
                leaves.push_back(to_delete[i]);
            }

        }
        cout<<"finish"<<endl;
        for(int i=0;i<n;i++){
            if(!delet[i])results.push_back(i);
        }

        return results;
    }
private:
    int adjacent(int i, map<int,vector<int>>& pos, vector<bool>& delet){
        int n=0;
        for(int j=0;j<pos[i].size();j++){
            if(delet[pos[i][j]]){
                continue;
            };
            n++;
        }
        return n;

    }



};
