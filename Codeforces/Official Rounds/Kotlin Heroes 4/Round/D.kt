private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun solve(){
  var (n, m) = readInts()
  var edges = mutableListOf<Triple<Int,Int,Int>>()
  var ans = MutableList<Int>(n) {0}

  for(i in 1..m){
    var (a,b,cst) = readInts()
    a--
    b--
    ans[a] = Math.max(ans[a], cst)
    ans[b] = Math.max(ans[b], cst)
    edges.add(Triple<Int,Int,Int>(a,b,cst));
  }

  for(ed in edges){
    if(Math.min(ans[ed.first], ans[ed.second]) != ed.third){
      println("NO")
      return
    }
  }

  println("YES")
  println(ans.joinToString(" "))
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
