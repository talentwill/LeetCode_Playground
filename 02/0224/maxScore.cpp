#include "leetcode.h"

class Solution {
public:
    struct Item {
        int sum = 0;
        int min = 0;

        // 这里不能用 >= ，会出现堆栈错误,
        // 也就是会出现排序的时候内存不够的情况，非常奇怪，但是很难发现。
        auto operator<(const Item& o) const { return min > o.min; }
    };
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<Item> v;
        v.reserve(nums1.size());

        for (int i = 0; i < nums1.size(); i++) {
            // v.push_back({ nums1[i], nums2[i] }); // c++17
            v.emplace_back(nums1[i], nums2[i]); // c++20
        }

        sort(v.begin(), v.end(), [](auto a, auto b) { return a.min > b.min; });

        priority_queue<int, vector<int>, greater<>> pq;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += v[i].sum;
            pq.push(v[i].sum);
        }

        for (int i = k - 1; i < v.size(); i++) {
            sum += v[i].sum;
            ans = max(ans, sum * v[i].min);
            sum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};

vector<int> v1 { 2, 8, 7, 7, 9, 7, 4, 7, 1, 3 };

tuple<vector<int>, vector<int>, int, int> case1
        = { { 4, 3, 7, 3, 5, 4, 4, 3, 7, 7 }, { 5, 1, 1, 4, 6, 9, 1, 7, 8, 2 },
              5, 115 };

int main() {
    cout << Solution().maxScore(
            std::get<0>(case1), std::get<1>(case1), get<2>(case1));
    return 0;
}
