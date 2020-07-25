class Solution {
    fun reverseWords(s: String): String {
        var arr : MutableList<String> = s.trim().split("\\s+".toRegex()).toMutableList()
        arr.reverse()
        return arr.joinToString(" ")
    }
}
