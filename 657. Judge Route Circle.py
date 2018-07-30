class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        u=moves.count('U')
        d=moves.count('D')
        l=moves.count('L')
        r=moves.count('R')
        if u==d and l==r:
            return True
        else:
            return False