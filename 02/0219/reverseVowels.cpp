#include "leetcode.h"

class Solution {
public:
    bool is_vowel(char c) {
        c = std::tolower(c);
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (not is_vowel(s[i])) {
                i++;
            }
            if (not is_vowel(s[j])) {
                j--;
            }
            if (i < j and is_vowel(s[i]) and is_vowel(s[j])) {
                cout << s[i] << ":" << s[j] << endl;
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
int main() {
    char c = tolower('.');
    string str = "a.b,.";
    cout << Solution().reverseVowels(str);
    return 0;
}
