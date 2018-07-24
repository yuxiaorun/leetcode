# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.nestedList = nestedList
        self.newList = []

        def helper(nestedList, newList):
            for nestedNode in nestedList:
                if nestedNode.getInteger() is not None:
                    newList.append(nestedNode.getInteger())
                else:
                    helper(nestedNode.getList(), newList)

        helper(self.nestedList, self.newList)
        print(self.newList)
        self.i = 0

    def next(self):
        """
        :rtype: int
        """
        r = self.newList[self.i]
        self.i += 1
        return r

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.i == len(self.newList):
            return False
        else:
            return True


            # Your NestedIterator object will be instantiated and called as such:
            # i, v = NestedIterator(nestedList), []
            # while i.hasNext(): v.append(i.next())