class Solution {
    fun reverseString(s: CharArray): Unit {
        var n : Int = s.size
        for(i in 0 until n / 2)
            s[i] = s[n - i - 1].also {s[n - i - 1] = s[i]}
    }
}
