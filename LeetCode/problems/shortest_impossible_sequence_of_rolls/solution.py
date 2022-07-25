class Solution(object):
    def shortestSequence(self, rolls, k):
        res = 1
        s = set()
        for a in rolls:
            s.add(a)
            if len(s) == k:
                res += 1
                s.clear()
        return res
        