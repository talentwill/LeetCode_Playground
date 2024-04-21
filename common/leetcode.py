class ListNode:
    def __init__(self, x=0, y=None):
        self.val = x
        self.next = y

    @staticmethod
    def create_from_list(nums: list[int]):
        head = cur = ListNode()
        for x in nums:
            cur.next = ListNode(x)
            cur = cur.next
        return head.next

    def print(self):
        cur = self
        while cur:
            print(cur.val, end="->")
            cur = cur.next
        print()


def create_linked_list(nums: list[int]) -> ListNode | None:
    if not nums:
        return None
    head = ListNode(0)
    cur = head
    for x in nums:
        cur.next = ListNode(x)
        cur = cur.next
    return head.next


def print_linked_list(head: ListNode | None) -> None:
    if not head:
        print("None")
        return
    cur = head
    while cur:
        print(cur.val, end="->")
        cur = cur.next
    print()


if __name__ == "__main__":
    ListNode.create_from_list([1, 2, 3, 4, 5]).print()
