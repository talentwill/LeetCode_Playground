#include "leetcode.h"

struct Solution { };

auto test = [](auto args...) {
    Solution solution;
    return 0;
};

void case1() { ut::expect_eq(0, test(1)); }
void err_case1() { ut::expect_eq(0, test(1)); }

int main() {
    case1();
    return 0;
}
