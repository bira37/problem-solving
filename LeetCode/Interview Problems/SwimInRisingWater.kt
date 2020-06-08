class Solution {
    fun toValue(a: Int, b : Int, n : Int) : Int{
        return a*n + b
    }
    fun toCoord(x : Int, n : Int): Pair<Int,Int>{
        return Pair(x/n, x%n)
    }
    fun swimInWater(grid: Array<IntArray>): Int {
        var n = grid.size
        var q = sortedSetOf<Pair<Int,Int>>(Comparator<Pair<Int,Int>>{
            a, b ->
            when {
                a.first < b.first -> -1
                a.first == b.first && a.second < b.second -> -1
                a.first == b.first && a.second == b.second -> 0
                else -> 1
            }
        })
        var dist = Array(grid.size) {IntArray(grid.size) {100000}}
        dist[0][0] = grid[0][0]
        q.add(Pair(dist[0][0], 0))
        while(q.size > 0){
            var cur = q.first()
            q.remove(cur)
            var (x, y) = toCoord(cur.second, n)
            var d = cur.first
            if(dist[x][y] < d) continue
            var dx = intArrayOf(0, 1, 0, -1)
            var dy = intArrayOf(-1, 0, 1, 0)
            for(k in 0..3){
                if(dx[k] + x >= 0 && x + dx[k] < n && dy[k] + y >= 0 && dy[k] + y < n && maxOf(d, grid[dx[k]+x][dy[k]+y]) < dist[dx[k]+x][dy[k]+y]){
                    dist[dx[k]+x][dy[k]+y] = maxOf(d, grid[dx[k]+x][dy[k]+y])
                    q.add(Pair(dist[dx[k]+x][dy[k]+y], toValue(dx[k]+x, dy[k]+y, n)))
                }
            }
        }
        return dist[n-1][n-1]
    }
}
