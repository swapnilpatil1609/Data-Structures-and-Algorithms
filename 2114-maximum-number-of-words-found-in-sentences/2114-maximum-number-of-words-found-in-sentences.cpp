class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        return transform_reduce(sentences.begin(), sentences.end(), 0,
                        [](int a, int b){ return max(a, b); },
                        [](string &s){ return count(s.begin(), s.end(), ' ') + 1; });
    }
};