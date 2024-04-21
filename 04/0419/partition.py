from common.leetcode import *

# 面试题 02.04. 分割链表
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode | None:
        if not head:
            return None
        last = head
        dummy = ListNode(0, last)
        cur = head.next
        last.next = None
        while cur:
            tmp = cur.next
            if cur.val < x:
                # 头插法
                cur.next = dummy.next
                dummy.next = cur
            else:
                cur.next = None
                last.next = cur
                last = cur
            cur = tmp
        return dummy.next


if __name__ == '__main__':
    case1 = [1, 4, 3, 2, 5, 2]
    ans = Solution().partition(ListNode.create_from_list(case1), 3).print()
