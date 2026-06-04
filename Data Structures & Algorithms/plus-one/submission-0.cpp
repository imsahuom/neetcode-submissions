class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, sum;
        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if (carry == 0) return digits;
        reverse(digits.begin(), digits.end());
        digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};