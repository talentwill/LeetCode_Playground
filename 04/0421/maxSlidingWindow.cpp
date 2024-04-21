#include <cassert>
#include "leetcode.h"

// 239. 滑动窗口最大值

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i], i);
        }
        vector<int> ans { pq.top().first };
        for (int i = k; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
            while (pq.top().second < i - k + 1) {
                pq.pop();
            }
            ans.emplace_back(pq.top().first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        auto enqueue = [&](int x) {
            while (dq.size() > 0 and dq.back() < x) {
                dq.pop_back();
            }
            dq.emplace_back(x);
        };

        auto dequeue = [&](int x) {
            if (dq.size() > 0 and dq.front() == x) {
                dq.pop_front();
            }
        };

        for (int i = 0; i < k; i++) {
            enqueue(nums[i]);
        }

        vector<int> ans { dq.front() };
        for (int i = 1; i <= nums.size() - k; i++) {
            enqueue(nums[i + k - 1]);
            dequeue(nums[i - 1]);
            ans.emplace_back(dq.front());
        }
        return ans;
    }
};

auto test = [](auto... args) { return Solution().maxSlidingWindow(args...); };

void err_case1() {
    auto v = vector { -7, -8, 7, 5, 7, 1, 6, 0 };
    auto k = 4;
    test(v, k);
}

void err_case2() {
    vector v { 7, 2, 4 };
    int k = 2;
    auto r = test(v, k);
    auto e = vector { 7, 4 };
    assert(e == r);
}


int main() {
    // auto v = vector { 1, 3, -1, -3, 5, 3, 6, 7 };
    // int k = 3;
    // test(v, k);
    err_case1();
    err_case2();
    return 0;
}
