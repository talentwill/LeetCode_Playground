#include "leetcode.h"

class Solution {
public:
    string multiplies(int n, string str) {
        string result;
        while (n-- > 0) {
            result += str;
        }
        return result;
    }

    string decodeString(const string& s) {
        stack<int> num_stk;
        stack<string> str_stk;
        for (size_t i = 0; i < s.length(); i++) {
            if (char c = s[i]; std::isdigit(c)) {
                // 提取数字，数字后面必有一个'['
                int pos = s.find('[', i);
                int num = std::stoi(s.substr(i, pos - i));
                num_stk.push(num);
                str_stk.emplace(""); // 需要新建一个子串
                i = pos;
            } else if (std::isalpha(c)) {
                if (str_stk.empty()) {
                    // 处理开头就是字母的情况
                    str_stk.emplace("");
                }
                str_stk.top().push_back(c);
            } else if (c == ']') {
                // 数字和字母都读取完毕，做乘法
                string tmp = multiplies(num_stk.top(), str_stk.top());
                num_stk.pop();
                str_stk.pop();
                if (str_stk.empty()) {
                    str_stk.push(tmp);
                } else {
                    // 合并完，和之前的字符拼接
                    str_stk.top() += tmp;
                }
            }
        }
        return str_stk.top();
    }
};

int main() {
    vector<pair<string, string>> cases
            = { { "3[a]2[bc]", "aaabcbc" }, { "abc3[cd]xyz", "abccdcdcdxyz" } };
    for (auto t: cases) {
        ut::expect_eq(Solution().decodeString(t.first), t.second);
    }
    return 0;
}
