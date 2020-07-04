class Solution {
    fun check(x : Long, k : Long, n : Long) : Int {
        var acc : Long = 1
        var cur : Long = 1
        for(i in 1..k-1){
            if(acc > (1e18.toLong()+x-1)/x) return 1
            acc *= x
            if(cur + acc > 1e18.toLong()) return 1
            cur += acc
        }
        if(cur < n) return -1
        else if(cur > n) return 1
        else return 0
    }
    
    fun smallestGoodBase(n: String): String {
        var nn : Long = n.toLong()
        for(k in 59 downTo 1 step 1){
            var l : Long = 2
            var r : Long = 1e18.toLong()
            
            while(l <= r){
                var m : Long = (l+r) shr 1
                var ans : Int = check(m, k.toLong(), nn)
                if(ans < 0) l = m+1
                else if(ans > 0) r = m-1
                else return m.toString()
            }
        }
        return (n.toLong()-1).toString()
    }
}
