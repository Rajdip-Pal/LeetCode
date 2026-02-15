class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        rook, bishop, queen = [a, b], [c, d], [e, f]

        def isInSameLine(*points):
            if len(points) == 2:
                p1, p2 = points
                x1, y1 = p1
                x2, y2 = p2

                # same row or same column or same diagonal
                return (y1 == y2) or (x1 == x2)

            if len(points) == 3:
                p1, p2, p3 = points
                x1, y1 = p1
                x2, y2 = p2
                x3, y3 = p3

                # check same row
                if y1 == y2 == y3:
                    return min(x1, x3) <= x2 <= max(x1, x3)

                # check same column
                if x1 == x2 == x3:
                    return min(y1, y3) <= y2 <= max(y1, y3)

                return False

            raise ValueError("Only 2 or 3 points allowed")

        def isInSameDiagonal(*points):
            if len(points) == 2:
                p1, p2 = points
                x1, y1 = p1
                x2, y2 = p2

                # same row or same column or same diagonal
                return (abs(x1 - x2) == abs(y1 - y2))

            if len(points) == 3:
                p1, p2, p3 = points
                x1, y1 = p1
                x2, y2 = p2
                x3, y3 = p3

                # same diagonal
                if abs(x1 - x3) == abs(y1 - y3):
                    if abs(x1 - x2) == abs(y1 - y2) and abs(x2 - x3) == abs(y2 - y3):
                        return min(x1, x3) <= x2 <= max(x1, x3) and min(y1, y3) <= y2 <= max(y1, y3)

                return False

            raise ValueError("Only 2 or 3 points allowed")

        if isInSameLine(rook, bishop, queen) or isInSameDiagonal(bishop, rook, queen):
            return 2

        if isInSameLine(rook, queen) or isInSameDiagonal(bishop, queen):
            return 1

        return 2


ans = Solution()

print(
    ans.minMovesToCaptureTheQueen(
        0, 0, 5, 5, 8, 8
    )
)
