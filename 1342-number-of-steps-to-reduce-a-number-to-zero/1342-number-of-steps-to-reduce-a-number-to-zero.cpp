class Solution {
public:
    int numberOfSteps(int num) {
    int ans = 0;
    while (num) ans++, num = num % 2 ? num - 1 : num / 2;
    return ans;
}
};