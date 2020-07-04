class Solution {
    fun findLUSlength(strs: Array<String>): Int {
        strs.sort()
        var ans = -1
        for (s in strs){
            var cnt = 0
            for(x in strs){
                var pt = 0
                for(c in x){
                    if(pt < s.length && s[pt] == c) pt++
                }
                if(pt == s.length) cnt++
            }
            if(cnt <= 1) ans = maxOf(ans, s.length.toInt())
        }
        return ans
    }
}
