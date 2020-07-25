class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        var tops = Array(nums.size+1) { mutableListOf<Int>() }
        var cnt = mutableMapOf<Int,Int>()
        for(x in nums){
            if(cnt.containsKey(x)) cnt[x] = cnt[x]!!+1
            else cnt[x] = 1
        }
        for((key,v) in cnt){
            tops[v].add(key)
        }
        var ans = IntArray(k) { 0 }
        var pt = 0
        for(x in nums.size downTo 1 step 1){
            for(y in tops[x]){
                if(pt < k) ans[pt++] = y
            }
        }
        return ans
    }
}
