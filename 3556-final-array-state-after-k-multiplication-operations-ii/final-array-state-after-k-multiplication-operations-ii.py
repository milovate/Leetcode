class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        if multiplier == 1:
            return nums

        mod = (7 + 10 ** 9)
        heap = [[nums[i]%mod, i] for i in range(len(nums))]
        heapify(heap)
        max_num = max(nums)

        while k:
            n, idx = heappop(heap)
            heappush(heap, [n*multiplier, idx])
            k -= 1
            if max_num < n*multiplier:
                break

        total_round = k // len(nums)
        k %= len(nums)
            
        mm = pow(multiplier, total_round, mod)

        for i in range(len(heap)):
            heap[i][0] *= mm

        while k:
            n, idx = heappop(heap)
            heappush(heap, [n*multiplier, idx])
            k -= 1

        for n, idx in heap:
            nums[idx] = n%mod

        return nums