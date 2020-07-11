class Solution {
    var ans : MutableList<MutableList<Int>> =  mutableListOf<MutableList<Int>>()
    
    fun go(i: Int, nums: IntArray, cur: MutableList<Int>): Unit {
        if(i==nums.size){
            ans.add(cur)
            return
        }
        
        var put = mutableListOf<Int>()
        var dont = mutableListOf<Int>()
        for(x in cur){
            put.add(x)
            dont.add(x)
        }
        
        put.add(nums[i])
        go(i+1, nums, put)
        go(i+1, nums, dont)
        
    }
    fun subsets(nums: IntArray): List<List<Int>> {
        go(0, nums, mutableListOf<Int>())
        
        return ans;
    }
}
