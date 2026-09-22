class Solution:
    def checkDistances(self, s: str, distance: list[int]) -> bool:
        mp = {}

        for i in range(len(s)):
            if s[i] not in mp:
                mp[s[i]] = []
            mp[s[i]].append(i)

        for ch, pos in mp.items():
            diff = pos[1] - pos[0] - 1

            if diff != distance[ord(ch) - ord('a')]:
                return False

        return True