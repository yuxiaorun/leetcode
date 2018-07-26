//
// Created by yxr on 2018/7/26.
//
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        vector<vector<int>> graph(edges.size() + 1);
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> visited(edges.size() + 1, 0);
        //start dfs from node 1
        dfs(graph, visited, 1, 0);
        for (int i = edges.size() - 1; i >= 0; i--) {
            //if the visited[node] is odd, then it means the node is inside the cicle
            if (visited[edges[i][0]]%2 && visited[edges[i][1]]%2) {
                result = edges[i];
                break;
            }
        }
        return result;
    }
    //false means this node is in a circle, we want to keep the value to odd (most case would be 1)
    //true means this node is not in a circle, we want to keep the value to 2
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int parent) {
        if (visited[node] == 2) return true;
        if (visited[node] == 1) {
            // this node is the beginning node of the circle while traversing the graph, record it with 4 for the first time
            visited[node] = 4;
            return false;
        }
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); i++) {
            if (graph[node][i] != parent) {
                if (!dfs(graph, visited, graph[node][i], node)) {
                    if (visited[graph[node][i]] == 3) {//that children node graph[node][i] is the beginning of the circle
                        continue;
                    }
                    //if this node value becomes 4, then mark it to 3 and let it's parent
                    //node recognize that it is the beginning of a circle and continue bfs even if it returns false
                    if (visited[node] == 4)
                        visited[node] = 3;
                    return false;
                }
            }
        }
        visited[node] = 2;
        return true;
    }
};
