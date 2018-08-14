class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        d1 = map(int, str(num))
        d2 = d1[:]
        d2.sort(reverse=True)
        c = 0
        for i in range(len(d1)):
            if d1[i] != d2[i]:
                c = i
                break
        t = d1[c]
        d1[c] = d2[c]
        for i in range(len(d1) - 1, -1, -1):
            if d1[i] == d1[c]:
                d1[i] = t
                break

        return int("".join(map(str, d1)))
