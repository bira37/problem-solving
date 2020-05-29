private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve(){
  var (n, k1, k2) = readInts()
  var (s) = readStrings()

  var v = mutableListOf<Int>()

  var ans : Int = 0
  for(i in 0..n-1){
    var can : Int = k1
    if(i-1 >= 0) can = Math.min(can, k2 - v[i-1])
    if(s[i] == '0') can = 0
    ans += can
    v.add(can)
  }
  println("$ans")
}

fun main(args: Array<String>){
  var tt: Int = readInt();
  // var tt = 1
  for(i in 1..tt){
    solve();
  }
}

// Remember to use alias:
// alias ktc='kotlinc -include-runtime -d main.jar'
// alias run='java -jar main.jar'
// alias create='cp template.kt'
