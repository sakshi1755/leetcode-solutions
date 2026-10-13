class Solution(object):
    def sumOfSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum=0
        n=len(nums)
        for i in range(n):
            if(n%(i+1)==0):
                sum=sum+(nums[i])*(nums[i])
        return sum

        