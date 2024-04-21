#include "cpplang.h"

// Print Helper
// template<typename T>
// std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
//     for (auto& x: vec) {
//         os << x << ' ';
//     }
//     return os;
// }

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& x: vec) { // 使用 const auto& 以避免不必要的拷贝
        os << x << ' ';
    }
    return os; // 在输出末尾可能希望删除最后一个空格或添加一个换行符
}


inline string toString(const vector<int>& v) {
    string res;
    for (const int x: v) {
        res += to_string(x) + ", ";
    }
    return res;
}

// ListNode

struct ListNode {
    int val = 0;
    ListNode* next = nullptr;

public:
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }

public:
    static ListNode* create(const vector<int>& nums) {
        ListNode dummy;
        ListNode* cur = &dummy;
        for (int x: nums) {
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return dummy.next;
    }

    static ListNode* create(int start = 1, int end = 10) {
        vector<int> v;
        for (int i = 0; i <= end; i++) {
            v.push_back(i);
        }
        return create(v);
    }

    vector<int> to_vector() {
        vector<int> res;
        ListNode* cur = this;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }

    string to_string() {
        string res;
        for (int x: to_vector()) {
            res += std::to_string(x) + " ";
        }
        res.resize(res.length() - 1);
        return res;
    }

    bool equals(const vector<int>& nums) { return to_vector() == nums; }

    void print() { cout << to_string(); }
};

namespace ut {

    bool expect_eq(auto a, auto b) {
        if (a != b) {
            cerr << "ERR: " << a << " != " << b << endl;
            return false;
        }
        return true;
    }
}