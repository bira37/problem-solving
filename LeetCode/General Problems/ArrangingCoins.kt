class Solution {
    fun arrangeCoins(n: Int): Int {
        var ans : Long = -1
        var l : Long = 1
        var r : Long = Int.MAX_VALUE.toLong()
        while(l <= r){
            var m : Long = (l+r) shr 1
            var cnt : Long = ((m+1)*m)/2
            if(cnt <= n){
                ans = m
                l = m+1
            } else {
                r = m-1
            }
        }
        return maxOf(0, ans.toInt())
    }
}
