class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        v=['a','e','i','o','u','A','E','I','O','U']
        is_v=[]
        vs=""
        for c in s:
            if c in v:
                is_v.append(True)
                vs+=c
            else:
                is_v.append(False)
        vs=vs[::-1]
        r=""
        j=0
        print(vs)
        print(is_v)
        for i in range(len(s)):
            if(is_v[i]):
                r+=vs[j]
                j+=1
            else:
                r+=s[i]
        return r