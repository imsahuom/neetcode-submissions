class Solution {
public:
    vector<vector<int>> memo;
    int ops(string& s1, string& s, int i, int j){
        if(i >= s1.size() && j >= s.size()) return 0;
        else if(j >= s.size()){
            //we've covered whole s, need to delete extras from s1
            return s1.size()-i;
        }else if(i >= s1.size()){
            //we've finished with s1, need to insert some chars at back of s1
            return s.size()-j;
        }
        if(memo[i][j] != -1) return memo[i][j];
        //operation1 delete - (basically skipping this char from s1)     
        int ans;   
        if (s1[i] == s[j]){
            ans = ops(s1, s, i+1, j+1);//we don't need to perform any ops for this posn
        }else{           
            ans = 1 + ops(s1, s, i+1, j);
            //operation2 insert - (basically we've moved j+1 with inserting a char here)
            ans = min(ans, 1+ops(s1, s, i, j+1));
            //operation3 replace - (basically a mismatch to same char)
            ans = min(ans, 1 + ops(s1, s, i+1, j+1));

        }
        return memo[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        memo.assign(word1.size()+1, vector<int>(word2.size()+1, -1));
        return ops(word1, word2, 0, 0);
    }
};
