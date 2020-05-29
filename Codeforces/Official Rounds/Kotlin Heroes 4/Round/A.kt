private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve(){
  var (n, k) = readInts()

  var ksum = 1 + k + k*k + k*k*k

  var n1 = n / ksum
  var n2 = k*n1
  var n3 = k*n2
  var n4 = k*n3

  println("$n1 $n2 $n3 $n4")
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
