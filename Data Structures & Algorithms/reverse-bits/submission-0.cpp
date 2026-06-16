class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s1 = bitset<32>(n).to_string();
        reverse(s1.begin(), s1.end());
        // Use stoul instead of stoi to prevent overflow exceptions
        return static_cast<uint32_t>(stoul(s1, nullptr, 2));
    }
};
