public class Solution {
    public int FindMin(int[] nums) {
        int ans = nums[0];
        for(int i=0; i<nums.Length; i++) ans = Math.Min(ans, nums[i]);
        return ans;
    }
}
