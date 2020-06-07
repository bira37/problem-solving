class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var t : Int = 0
        for(i in 1..nums.size-1){
            if(nums[i] != nums[t]){
                t++;
                nums[t] = nums[i];
            }
        }
        return t+1;
    }
}
