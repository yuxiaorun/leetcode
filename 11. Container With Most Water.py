class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) < 2:
            return
        l, r = [], []
        m = 0
        m1, m2 = 0, 0
        for i in range(len(height)):
            if height[i] > m1:
                m1 = height[i]
                l.append(i)
        for i in range(len(height) - 1, -1, -1):
            if height[i] > m2:
                m2 = height[i]
                r.append(i)

        for i in (l):
            for j in (r):
                if j > i:
                    m = max(m, min(height[i], height[j]) * (j - i))
                else:
                    break

        return m