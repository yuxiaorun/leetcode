//
// Created by yxr on 2018/8/8.
//
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> rights;
        vector<int> result;
        int n=asteroids.size();
        for(int i=0; i<n; i++){
            if(asteroids[i]>0){
                rights.push_back(asteroids[i]);
            }else{
                int left=asteroids[i];
                while(!rights.empty()){
                    int right=rights.back();
                    if(right> -1*left)break;
                    else if(right < -1*left) rights.pop_back();
                    else {
                        rights.pop_back();
                        left=0;
                        break;
                    }
                }
                if(rights.empty() && left!=0)result.push_back(asteroids[i]);
            }
        }
        for(int i=0; i<rights.size(); i++)result.push_back(rights[i]);
        return result;
    }
};
