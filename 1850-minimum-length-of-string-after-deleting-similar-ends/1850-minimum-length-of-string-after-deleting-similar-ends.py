class Solution:
    def minimumLength(self, s: str) -> int:
        Q = deque((k, len(list(v))) for k, v in groupby(s))
        while len(Q) > 2 and Q[0][0] == Q[-1][0]:
            Q.popleft(), Q.pop()
        return sum(q[1] for q in Q) if len(Q) > 1 else int(Q[0][1] == 1)