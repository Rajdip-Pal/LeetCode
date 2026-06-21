class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1

        if k == 1:
            return 1

        length: int = 1
        remainder = 1
        past_remainders: set[int] = set()

        while remainder != 0:
            past_remainders.add(remainder)
            length += 1
            remainder = (remainder * 10 + 1) % k

            if remainder in past_remainders:
                return -1

        return length


'''
    Now if the remainder becomes 0, it means we have found a repunit number divisible by k.

    now we can skip checking in an array always
    for the result it should be return in fast k loops
    becaus if any reminder repeats loop will continue more than k times

    Time complexity: O(k)
    Space complexity: O(1)
'''
