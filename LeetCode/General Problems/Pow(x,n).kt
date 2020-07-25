class Solution {
    fun exp(x : Double, k : Int) : Double{
        if(k == 1) return x
        if(k == 0) return 1.toDouble()
        var ax = exp(x, k/2)
        ax = ax*ax
        if(k % 2 == 1) ax = ax*x
        return ax
    }
    fun myPow(x: Double, n: Int): Double {
        if(n < 0) return 1.toDouble()/(exp(x, -(n+1))*x)
        else return exp(x, n)
    }
}
