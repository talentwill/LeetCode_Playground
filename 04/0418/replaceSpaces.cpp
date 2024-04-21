#include "leetcode.h"


string& replaceSpaces(string& S, int length) {
    int count = std::count(S.begin(), next(S.begin(), length), ' ');
    int count2= std::count(S.begin(), S.end()-1, ' ');
    S.resize(length + std::count(S.begin(), next(S.begin(), length), ' ') * 2);
    auto it = S.rbegin();
    for (int i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {
            *it++ = '0';
            *it++ = '2';
            *it++ = '%';
        } else {
            *it++ = S[i];
        }
    }
    return S;
}

int main() {
    string S = "Mr John Smith    ";
    cout << replaceSpaces(S, 13) << endl;
    return 0;
}