
#include "leetcode.h"

// 2024-02-11
class Solutionv1 {
public:
    // 自己写的版本太复杂 v1
    string predictPartyVictory(string senate) {
        // 原来的R和D的个数
        int r_cnt = 0, d_cnt = 0;
        // 记录，需要抵消的敌人的个数
        int r_ban = 0, d_ban = 0;
        queue<char> p, q;
        // 统计两个阵营的个数
        for (char c: senate) {
            if (c == 'D') {
                d_cnt++;
            } else {
                r_cnt++;
            }
            p.push(c);
        }

        while (true) {
            char x = p.front();
            p.pop();
            if (x == 'D') {
                // 是否有D需要被抵消？
                if (d_ban > 0) {
                    d_ban--;
                    d_cnt--;
                } else {
                    // 去抵消一个R
                    r_ban++;
                    q.push(x);
                }
            } else {
                if (r_ban > 0) {
                    r_ban--;
                    r_cnt--;
                } else {
                    d_ban++;
                    q.push(x);
                }
            }
            if (r_cnt == 0 and d_cnt > 0) {
                return "Dire";
            } else if (d_cnt == 0 and r_cnt > 0) {
                return "Radiant";
            }
            // 如果队列为0，一轮结束，交换队列
            if (p.empty()) {
                p.swap(q);
            }
        }
    }
};

// 2024-02-11
class Solutionv2 {
public:
    // 自己写的版本太复杂 v2，使用一个queue就可以了
    string predictPartyVictory(string senate) {
        // 原来的R和D的个数
        int r_cnt = 0, d_cnt = 0;
        // 记录，需要抵消的敌人的个数
        int r_ban = 0, d_ban = 0;
        queue<char> p;
        // 统计两个阵营的个数
        for (char c: senate) {
            if (c == 'D') {
                d_cnt++;
            } else {
                r_cnt++;
            }
            p.push(c);
        }

        while (true) {
            char x = p.front();
            p.pop();
            if (x == 'D') {
                // 是否有D需要被抵消？
                if (d_ban > 0) {
                    d_ban--;
                    d_cnt--;
                } else {
                    // 去抵消一个R
                    r_ban++;
                    p.push(x);
                }
            } else {
                if (r_ban > 0) {
                    r_ban--;
                    r_cnt--;
                } else {
                    d_ban++;
                    p.push(x);
                }
            }
            if (r_cnt == 0 and d_cnt > 0) {
                return "Dire";
            } else if (d_cnt == 0 and r_cnt > 0) {
                return "Radiant";
            }
        }
    }
};

// 2024-02-11
class Solution {
public:
    // 参考官方的题解，自己写了一遍
    // 有2个注意点，
    // 队列里面存的是下标的索引
    // while 循环里面，需要判断r和d两个队列都为空，才可以进行笔记
    //
    string predictPartyVictory(const string& senate) {
        queue<int> rad, dir;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'D') {
                dir.push(i);
            } else {
                rad.push(i);
            }
        }
        int n = senate.length(); // n 代表一轮的个数
        while (not rad.empty() and not dir.empty()) {
            int r_id = rad.front();
            rad.pop();
            int d_id = dir.front();
            dir.pop();
            if (r_id < d_id) {
                rad.push(r_id + n); // 序号+n 或者n++，都可以
            } else {
                dir.push(d_id + n);
            }
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    ut::expect_eq(Solution().predictPartyVictory("RD"), "Radiant"s);
    ut::expect_eq(Solution().predictPartyVictory("RDD"), "Dire"s);
    return 0;
}
