class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        i, j=0, len(matrix[0])-1
        if target < matrix[0][0] or target > matrix[-1][-1]:
            return False
        while i < len(matrix) and j >= 0 :
            if target == matrix[i][j]:
                return True
            if target > matrix[i][j]:
                i+=1
                continue
            if target < matrix[i][j]:
                j-=1
        return False