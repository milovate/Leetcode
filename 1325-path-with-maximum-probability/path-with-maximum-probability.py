class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = defaultdict(list)
        for i, (s, e) in enumerate(edges):
            graph[s].append((e, succProb[i]))
            graph[e].append((s, succProb[i]))
        n = len(graph)
        heap = [(-1, start)]
        seen = set()
        while heap:
            prob, node = heapq.heappop(heap)
            if node == end:
                return -prob
            seen.add(node)
            for nextNode, weight in graph[node]:
                if nextNode in seen:
                    continue
                heapq.heappush(heap, (prob * weight, nextNode))
        return 0

        

        