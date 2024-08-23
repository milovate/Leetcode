class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hm = defaultdict(int) 
        for idx, n in enumerate(nums): 
            if hm.get(n) != None:
                if abs(hm[n] - idx) <= k:
                    return True
            hm[n] = idx
        return False