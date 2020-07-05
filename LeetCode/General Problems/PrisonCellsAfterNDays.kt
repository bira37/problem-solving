class Solution {
    fun getAns(cell: Int): IntArray {
        var x = IntArray(8) { 0 }
        for (i in 1..8){
            if ((cell and (1 shl i)) > 0) x[i] = 1
        }
        return x
    }
    fun prisonAfterNDays(cells: IntArray, N: Int): IntArray {
        var cur = 0
        var s = sortedMapOf<Int,Int>()
        var cell = 0
        for(i in 0 until cells.size){
            if(cells[i] == 1) cell = cell or (1 shl i)
        }
        s.put(cell, 0)
        var ans : MutableList<Int> = mutableListOf<Int>()
        ans.add(cell)
        while(true){
            cur++;
            var newCell = 0
            for(i in 0 until cells.size){
                var cnt = 0
                if(i == 0 || i == cells.size-1) continue
                if((cell and (1 shl (i-1))) > 0){
                    cnt++
                } 
                if((cell and (1 shl (i+1))) > 0){
                    cnt++
                }
                if(cnt != 1) newCell = newCell or (1 shl i);
            }
            //println(getAns(newCell).joinToString())
            if(cur == N){
                return getAns(newCell)
            }
            if(!(s.containsKey(newCell))){
                s.put(newCell, cur)
                cell = newCell
                ans.add(newCell)
                continue
            }
            //print("out of loop")
            var idx = s.get(newCell)!!
            var n = N
            n  -= idx
            n = n % (cur - idx)
            return getAns(ans[idx + n])
        }
        return intArrayOf()
    }
}
