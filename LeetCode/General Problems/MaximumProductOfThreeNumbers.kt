class Solution {
    fun maximumProduct(nums: IntArray): Int {
        nums.sort()
        nums.reverse()
        var len = nums.size
        return maxOf(nums[0]*nums[1]*nums[2], nums[len-1]*nums[len-2]*nums[0])
    }
}
