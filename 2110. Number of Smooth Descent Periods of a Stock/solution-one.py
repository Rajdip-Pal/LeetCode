from typing import List


class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        # Stores maximum length of current smooth descent period
        max_p_len: int = 1

        # Stores total number of smooth descent periods
        total_periods: int = 0

        # Iterate through prices to find smooth descent periods
        for i in range(1, len(prices)):

            if 1 == prices[i-1] - prices[i]:
                # Continue the current smooth descent period
                max_p_len += 1
            else:
                # End of current smooth descent period
                # Calculate number of smooth descent periods in the current period
                total_periods += (max_p_len * (max_p_len + 1)) // 2

                # Reset for the next potential smooth descent period
                max_p_len = 1

        # Account for the last smooth descent period
        total_periods += (max_p_len * (max_p_len + 1)) // 2
        # Return the total number of smooth descent periods
        return total_periods
