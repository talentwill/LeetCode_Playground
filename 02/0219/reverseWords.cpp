#include "leetcode.h"

class Solution {
public:
    void reverse(string& s, int begin, int end) {
        end--;
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }

    void strim(string& s) {
        int begin = s.find_first_not_of(' ');
        int end = s.find_last_not_of(' ');
        int i = 0;
        for (int j = begin; j <= end; j++) {
            if (s[j] == ' ') {
                if (i > 0 and s[i - 1] != ' ') {
                    s[i++] = ' ';
                }
            } else {
                s[i++] = s[j];
            }
        }
        s.resize(i);
    }
    string reverseWords(string s) {
        strim(s);
        int n = s.length();
        int i = 0;
        int j = 0;
        while (j < n) {
            j = s.find(' ', i);
            if (j == string::npos) {
                j = n;
            }
            reverse(s, i, j);
            i = j + 1;
        }
        reverse(s, 0, n);
        return s;
    }
};
int main() {
    string str = " a good   example  ";
    cout << Solution().reverseWords(str);
    return 0;
}
