class Solution {
    fun maxProfit(prices: IntArray): Int {
        var ans : Int = 0
        var lst : Int = Int.MAX_VALUE
        for(x in prices){
            ans += maxOf(0, x - lst)
            lst = x
        }
        return ans
    }
}
