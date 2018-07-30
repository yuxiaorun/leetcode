//
// Created by yxr on 2018/7/30.
//
class Solution {
public:
    int findMinStep(string board, string hand) {
        all=hand.size();
        vector<int> hands(5, 0);
        for(int i=0;i<hand.size();i++){
            hands[to_num(hand[i])]++;
        }
        dfs(hands, board);
        if(result==INT_MAX)return -1;
        return result;

    }
private:
    int all=0;
    int result=INT_MAX;
    void dfs(vector<int>& hands, string board){
        if(board==""){
            int s=0;
            for(int i=0;i<hands.size();i++){
                s+=hands[i];
            }
            result=min(result, all-s);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(hands[to_num(board[i])]>0){
                string n(board);
                n.insert(n.begin()+i, board[i]);
                hands[to_num(board[i])]--;
                while(n != update(n)){
                    n=update(n);
                }
                dfs(hands,n);
                hands[to_num(board[i])]++;
            }
        }
        return;

    }
    int to_num(char c){
        if(c=='R')return 0;
        else if(c=='Y')return 1;
        else if(c=='B')return 2;
        else if(c=='G')return 3;
        else if(c=='W')return 4;
        else return 1;
    }
    string update(string board){
        if(board.size()<3)return board;
        string ns="";
        int c=1;
        int i=1;
        while(i<board.size()){
            if(board[i]!=board[i-1]){
                c=1;
                i++;
                continue;
            }
            while(i<board.size() && board[i]==board[i-1]){
                c++;
                i++;
            }
            if(c>=3) return board.substr(0, i-c)+board.substr(i, board.size()-i);
        }
        return board;
    }
};
