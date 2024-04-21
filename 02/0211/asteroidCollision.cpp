#include "leetcode.h"

class Solution1 {
public:
    // 这个版本写起来费劲，还非常容易出错，放弃这种写法！
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int x: asteroids) {
            if (stk.empty()) {
                stk.push(x);
                continue;
            }
            while (not stk.empty()) {
                int y = stk.top();
                if (y > 0 and x < 0) {
                    if (y <= abs(x)) {
                        stk.pop();
                    }
                    if (y >= abs(x)) {
                        break;
                    }
                } else {
                    stk.push(x);
                    break;
                }
            }
        }

        vector<int> v(stk.size());
        for (int i = v.size() - 1; i >= 0; i--) {
            v[i] = stk.top();
            stk.pop();
        }
        return v;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int x: asteroids) {
            stk.push_back(x);
            while (stk.size() >= 2 and stk.back() and stk[stk.size() - 2] > 0) {
                int b1 = stk.back();
                stk.pop_back();
                int b2 = stk.back();
                stk.pop_back();
                if (abs(b1) != b2) {
                    stk.push_back(abs(b1) > b2 ? b1 : b2);
                }
            }
        }
        return stk;
    }
};

int main() {
    vector<int> v = { 1, -2, -2, -2 };
    cout << Solution().asteroidCollision(v);
    return 0;
}
