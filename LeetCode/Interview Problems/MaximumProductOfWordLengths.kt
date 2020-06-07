class Solution {
    fun maxProduct(words: Array<String>): Int {
        var ans : Int = 0
        var bitset : IntArray = IntArray(words.size)
        for(i in 0 until words.size){
            for(c in words[i]) bitset[i] = bitset[i] or (1 shl (c.toInt() - 'a'.toInt()))
        }
        for(i in 0 until words.size){
            for(j in i+1 until words.size) 
                if(bitset[i] and bitset[j] == 0) ans = maxOf(ans, words[i].length*words[j].length)
        }
        return ans
    }
}
