//
// Created by yxr on 2018/7/23.
//
class Solution {
private:
    bool isValid(int m, int n, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int getShortestDistance(int m, int n, int x, int y, vector<vector<int>>& distance) {
        int result = distance[x][y];

        if (isValid(m, n, x, y + 1) && distance[x][y + 1] != INT_MAX) {
            result = min(result, 1 + distance[x][y + 1]);
        }
        if (isValid(m, n, x, y - 1) && distance[x][y - 1] != INT_MAX) {
            result = min(result, 1 + distance[x][y - 1]);
        }
        if (isValid(m, n, x + 1, y) && distance[x + 1][y] != INT_MAX) {
            result = min(result, 1 + distance[x + 1][y]);
        }
        if (isValid(m, n, x - 1, y) && distance[x - 1][y] != INT_MAX) {
            result = min(result, 1 + distance[x - 1][y]);
        }
        return result;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> visit;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    distance[i][j] = 0;
                    visit.push(make_pair(i, j + 1));
                    visit.push(make_pair(i, j - 1));
                    visit.push(make_pair(i + 1, j));
                    visit.push(make_pair(i - 1, j));
                }
            }
        }

        while (!visit.empty()) {
            pair<int, int> cur = visit.front();
            visit.pop();
            int x = cur.first;
            int y = cur.second;

            if (isValid(m, n, x, y)) {
                int shortestD = getShortestDistance(m, n, x, y, distance);
                if (shortestD < distance[x][y]) {
                    distance[x][y] = shortestD;
                    visit.push(make_pair(x, y + 1));
                    visit.push(make_pair(x, y - 1));
                    visit.push(make_pair(x + 1, y));
                    visit.push(make_pair(x - 1, y));
                }
            }
        }
        return distance;
    }
};
