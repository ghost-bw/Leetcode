class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        n=len(points)
        if n==0:
            return 0
        points.sort()
        count=1
        prevs,preve=points[0][0],points[0][1]
        for bal in points[1:]:
            if bal[0]>preve:
                count+=1
                prevs=bal[0]
                preve=bal[1]
            else:
                prevs=max(prevs,bal[0])
                preve=min(preve,bal[1])
        return count