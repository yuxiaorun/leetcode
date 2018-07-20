class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def inBound(x, y):
            if 0 <= x < len(board) and 0 <= y < len(board[0]):
                return True
            else:
                return False
        def countLives(x, y):
            lives = 0
            if inBound(x - 1, y - 1):
                lives += board[x - 1][y - 1] % 2
            if inBound(x - 1, y):
                lives += board[x - 1][y] % 2
            if inBound(x, y - 1):
                lives += board[x][y - 1] % 2
            if inBound(x - 1, y + 1):
                lives += board[x - 1][y + 1] % 2
            if inBound(x, y + 1):
                lives += board[x][y + 1] % 2
            if inBound(x + 1, y - 1):
                lives += board[x + 1][y - 1] % 2
            if inBound(x + 1, y):
                lives += board[x + 1][y] % 2
            if inBound(x + 1, y + 1):
                lives += board[x + 1][y + 1] % 2
            return lives
        for i in range(len(board)):
            for j in range(len(board[0])):
                lives = countLives(i, j)
                if board[i][j] == 1:
                    if lives < 2:
                        board[i][j] = 3
                    if 2 <= lives <= 3:
                        board[i][j] = 1
                    if lives > 3:
                        board[i][j] = 3
                if board[i][j] == 0:
                    if lives == 3:

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 2:
                    board[i][j] = 1
                if board[i][j] == 3:
                    board[i][j] = 0

