#include "leetcode.h"

// 392. 判断子序列

// 动态规划法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto dp = vector(t.length() + 1, vector(26, -1));
        for (int i = t.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (j == t[i] - 'a') {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        int i = 0;
        for (char c: s) {
            if (dp[i][c - 'a'] == -1) {
                return false;
            } else {
                i = dp[i][c - 'a'] + 1;
            }
        }
        return true;
    }
};

int main() {
    string s = "axc", t = "ahbgdc";
    Solution().isSubsequence(s, t);
    return 0;
}
