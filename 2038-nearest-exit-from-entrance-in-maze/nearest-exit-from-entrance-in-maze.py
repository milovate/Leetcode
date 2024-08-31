class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        # feels like bfs 
        m=len(maze)
        n=len(maze[0])

        m = len(maze)
        n = len(maze[0])

        queue = collections.deque()
        queue.append((entrance[0], entrance[1], 0))
        visited = set()
        visited.add((entrance[0], entrance[1]))
        dx=[0,0,1,-1]
        dy=[1,-1,0,0]

        while queue:
            for _ in range(len(queue)):
                r, c, level = queue.popleft()

                if [r, c] != entrance:
                    if r == 0 or r == m-1 or c == 0 or c == n-1:
                        return level

                for i in range(4):
                    nr=r+dx[i]
                    nc=c+dy[i]
                    if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited and maze[nr][nc] == '.':
                        queue.append((nr, nc, level + 1))
                        visited.add((nr, nc))

        return -1
        



        