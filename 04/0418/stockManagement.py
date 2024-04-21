
from typing import List

class Solution:

    @staticmethod
    def stockManagement(self, stock: List[int]) -> int:
        if not stock:
            return 100000
        if len(stock) == 1:
            return stock[0]
        s = stock[0]
        e = stock[-1]
        if s < e:
            return s
        l = 0
        r = len(stock) - 1
        while l < r:
            m = l + (r - l) // 2
            x = stock[m]
            # print(l, r, m)
            if x == e and x == s:
                return min(self.stockManagement(stock[l:m]), self.stockManagement(stock[m+1:r+1]))
            if x <= e:
                r = m
            elif x > e:
                l = m + 1


        return stock[l]


# x = Solution().stockManagement([10,1,10,10,10])
# print(x)

    @static
    def stockManagement(self, stock: List[int]) -> int:
        l = 0
        r = len(stock) - 1
        while l < r:
            if stock[l] < stock[r]:
                return stock[l]
            m = l + (r - l) // 2
            x = stock[m]
            if x == stock[l] and x == stock[r]:
                return min(stock[: r + 1])
            if x <= e:
                r = m
            elif x > e:
                l = m + 1

        return stock[l]

