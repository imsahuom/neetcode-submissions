class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> v(m+n, 0);
        for(int i = n-1; i>=0; i--){
            int x = num1[i] - '0';
            for(int j=m-1; j>=0; j--){
                int y = num2[j] - '0';
                int m = x*y;
                v[i+j+1] += m%10;
                v[i+j] += m/10;
            }
        }
        int c = 0;
        for(int i=m+n-1; i>=0; i--){
            // cout << v[i] << " ";
            int sum = v[i] + c;
            v[i] = sum%10;
            c = sum/10;
        }
        // cout << endl;
        string ans = "";
        bool flag = true;
        for(auto& c: v){
            // cout << c <<  " ";
            if(c==0 && flag) continue;
            ans += to_string(c);
            flag = false;
        }
        if (ans == "") return "0";
        return ans;
    }
};