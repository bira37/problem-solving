class Solution {
    fun freqAlphabets(s: String): String {
        var i = 0
        var ans : String = ""
        while(i < s.length){
            if(i+2 < s.length && s[i+2] == '#'){
                var integ = 10*(s[i].toInt() - 48) + (s[i+1].toInt() - 48)
                var ch = ('a'.toInt() + integ - 1).toChar()
                ans += (ch)
                i += 3
            } else {
                var ch = ('a'.toInt() + (s[i].toInt() - 48) - 1).toChar()
                ans += (ch)
                i += 1
            }
        }
        return ans
    }
}
