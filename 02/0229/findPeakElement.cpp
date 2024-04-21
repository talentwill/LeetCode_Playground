
#include "leetcode.h"


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 3 种特殊情况先判断
        int n = nums.size();
        if (nums.size() == 1 or nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        // 左右边界缩小一位
        int left = 1, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1]) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};


int main() {
    vector<int> v1 { 1, 2, 1, 3, 5, 6, 4 };
    Solution().findPeakElement(v1);
    return 0;
}
