class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        stack = []
        result = [0 for x in range(n)]
        last_time = self.parseLog(logs[0])[2]
        for i in range(len(logs)):
            infos = self.parseLog(logs[i])
            time = infos[2] - last_time
            if infos[1] == "start":
                if len(stack) > 0:
                    last = stack[len(stack) - 1]
                    result[last] += time
                stack.append(infos[0])
                last_time = infos[2]
            else:
                stack.pop()
                time += 1
                result[infos[0]] += time
                last_time = infos[2] + 1

        return result

    def parseLog(self, log):
        l = log.split(':')
        l[0] = int(l[0])
        l[2] = int(l[2])
        return l