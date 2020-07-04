class Solution {
    fun isNStraightHand(hand: IntArray, W: Int): Boolean {
        var s = mutableMapOf<Int, Int>().toSortedMap()
        
        for(x in hand){
            if(s.containsKey(x)) s[x] = s[x]!! +1
            else s[x] = 1
        }
        
        while(s.size > 0){
            var cur = s.firstKey()
            for(i in cur until cur+W){
                if(!s.containsKey(i)){
                    return false
                }
                s[i] = s[i]!! -1
                if(s[i] == 0) s.remove(i)
            }
        }
        return true
    }
}
