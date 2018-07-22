//
// Created by yxr on 2018/7/22.
//
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int>> edges;
        vector<int> result;
        for(int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        bool taken[numCourses];
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            taken[i]=false;
            if(edges[i].size()==0){
                q.push(i);
                result.push_back(i);
                taken[i]=true;
            }
        }
        edges.clear();
        for(int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> degrees(edges.size(), 0);
        for (auto neighbors : edges)
            for (auto neigh : neighbors)
                degrees[neigh]++;

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            result.push_back(cur);
            taken[cur]=true;
            for(auto i:edges[cur]){
                if (!--degrees[neigh])
                    q.push(neigh);
            }
        }
        vector<int> emp;
        for(int i=0;i<numCourses;i++){
            if(!taken[i])return emp;
        }
        return result;
    }
};
