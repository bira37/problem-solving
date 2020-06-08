class Solution {
    fun change(amount: Int, coins: IntArray): Int {
        var dp : MutableList<Int> = MutableList<Int>(amount+1) {0}
        dp[0] = 1
        for(c in coins){
            for(j in 0..amount-c){
                dp[j+c] += dp[j]
            }
        }
        return dp[amount]
    }
}
