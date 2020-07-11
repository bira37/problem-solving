class Solution {
    fun hammingDistance(x: Int, y: Int): Int {
        var hammer = 0
        for(i in 0..31){
            var a = (x and (1 shl i))
            var b = (y and (1 shl i))
            if(a != b) hammer++
        }
        return hammer
    }
}
