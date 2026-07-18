class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        return count_if(operations.begin(), operations.end(), [](string s){ return s[1] == '+'; }) * 2 - operations.size();
    }
};