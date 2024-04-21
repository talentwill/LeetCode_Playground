#include "leetcode.h"

// 295. 数据流的中位数

class MedianFinder {
public:
    priority_queue<double, vector<double>, greater<double>> rsq;
    priority_queue<double, vector<double>, less<double>> lmq;

    void addNum(int num) {
        if (not rsq.empty() and num >= rsq.top()) {
            rsq.emplace(num);
        } else {
            lmq.emplace(num);
        }

        if (int(lmq.size()) - int(rsq.size()) > 1) {
            rsq.emplace(lmq.top());
            lmq.pop();
        }

        if (int(rsq.size()) - int(lmq.size()) > 1) {
            rsq.emplace(rsq.top());
            rsq.pop();
        }
    }
    double findMedian() {
        if (rsq.size() == lmq.size()) {
            return double(rsq.top() + lmq.top()) / 2;
        } else if (rsq.size() > lmq.size()) {
            return rsq.top();
        } else {
            return lmq.top();
        }
        return 0;
    }
};

void err_case1() {
    MedianFinder s;
    s.addNum(6);
    cout << s.findMedian();
    s.addNum(10);
    cout << s.findMedian();
    s.addNum(2);
    cout << s.findMedian();
    s.addNum(6);
    cout << s.findMedian();
}

void err_case2() {
    MedianFinder s;
    s.addNum(-1);
    cout << s.findMedian();
    s.addNum(-3);
    cout << s.findMedian();
    s.addNum(-4);
    cout << s.findMedian();
    s.addNum(-5);
    cout << s.findMedian();
}

void case1() {
    MedianFinder s;
    s.addNum(1);
    s.addNum(2);
    cout << s.findMedian();
    s.addNum(3);
    cout << s.findMedian();
}

void test_queue() {
    priority_queue<int, vector<int>, greater<int>> rsq;
    rsq.emplace(1);
    rsq.emplace(2);
    rsq.emplace(3);
    while (not rsq.empty()) {
        cout << rsq.top() << endl;
        rsq.pop();
    }
}

int main() {
    case1();
    err_case1();
    test_queue();
    return 0;
}
