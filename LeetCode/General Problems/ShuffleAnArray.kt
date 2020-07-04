class Solution(var nums: IntArray) {

    /** Resets the array to its original configuration and return it. */
    fun reset(): IntArray {
        return nums
    }

    /** Returns a random shuffling of the array. */
    fun shuffle(): IntArray {
        var shuffled = nums.copyOf().toMutableList()
        shuffled.shuffle()
        return shuffled.toIntArray()
    }

}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
