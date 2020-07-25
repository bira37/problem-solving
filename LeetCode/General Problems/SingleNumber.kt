class Solution {
    fun singleNumber(nums: IntArray): IntArray {
        var x = 0
        for(i in nums) x = x xor i
        
        var bt = 0
        for (b in 1 until 30){
            if((x and (1 shl b)) != 0){
                bt = b
                break
            }
        }
        val ans = IntArray(2) { 0 }
        for(i in nums){
            if((i and (1 shl bt)) == 0) ans[0] = ans[0] xor i
            else ans[1] = ans[1] xor i
        }
        return ans;
    }
}
