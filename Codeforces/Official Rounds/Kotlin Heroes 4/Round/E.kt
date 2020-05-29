private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun solve(){
  var (n,m,k) = readInts()

  var dp = IntArray(n) {10000000}
  dp[k-1] = 0

  for(i in 1..m){
    var (a,b) = readInts()
    a--
    b--
    var dpa = dp[a]
    var dpb = dp[b]
    dp[a] = Math.min(dpa + 1, dpb)
    dp[b] = Math.min(dpb+1, dpa)
  }

  println(dp.joinToString(" ") {(if(it == 10000000) -1 else it).toString()})
}

fun main(args: Array<String>){
  var tt = 1
  for(i in 1..tt){
    solve();
  }
}

// Remember to use alias:
// alias ktc='kotlinc -include-runtime -d main.jar'
// alias run='java -jar main.jar'
// alias create='cp template.kt'
