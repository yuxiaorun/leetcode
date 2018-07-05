class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        change = []
        for i in range(1, len(prices)):
            change.append(prices[i] - prices[i - 1])

        m1 = 0
        m2 = 0
        for i in change:
            if m2 + i > 0:
                m2 += i
            else:
                m2 = 0
            if m2 > m1:
                m1 = m2

        return m1