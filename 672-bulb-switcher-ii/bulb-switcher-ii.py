class Solution:
    def flipLights(self, n: int, presses: int) -> int:

        all_ones, evens, odds, three = 0, 0, 0, 0
        for i in range(n):
            all_ones = (all_ones << 1) + 1
            evens = (evens << 1) + (1 if (i+1) % 2 == 0 else 0)
            odds = (odds << 1) + (1 if (i+1) % 2 == 1 else 0)
            three = (three << 1) + (1 if (i+1) % 3 == 1 else 0)

        state = all_ones

        level = {state}
        for i in range(presses):
            next_level = set()
            for state in level:
                states = [state ^ all_ones,
                          state ^ evens,
                          state ^ odds,
                          state ^ three]
                for next_state in states:
                    next_level.add(next_state)
            level = next_level

        return len(level)