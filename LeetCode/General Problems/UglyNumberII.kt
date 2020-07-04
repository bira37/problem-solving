class Solution {
    fun nthUglyNumber(n: Int): Int {
        var arr : MutableList<Long> = mutableListOf<Long>()
        var s : SortedSet<Long> = sortedSetOf<Long>()
        s.add(1)
        while(s.size > 0 && arr.size < n){
            var current = s.first()
            s.remove(current)
            arr.add(current)
            s.add(current*2)
            s.add(current*3)
            s.add(current*5)
        }
        return arr.last().toInt()
    }
}
