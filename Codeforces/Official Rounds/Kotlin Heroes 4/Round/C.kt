private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve(){
  var (n, k, x, y) = readInts()
  var a : MutableList<Long> = readLine()!!.split(" ").map({it.toLong()}).toMutableList()

  a.sort()
  a.reverse()

  var cur : Long = a.size.toLong()
  var cst : Long = 0
  var sum : Long = 0

  for(item in a){
    sum += item
  }

  var ans : Long = 2000000000000

  for(item in a){
    if(item <= k) ans = Math.min(ans, cst)
    if(((sum + cur-1)/cur) <= k) ans = Math.min(ans, cst + y)
    if((sum/cur) <= k){
      var ans2 = cst + y + x*(sum % cur)
      ans = Math.min(ans, ans2)
    }
    // even tryout
    var ev_max = ((sum + cur-1)/cur) //make even +y
    var sum_without = sum - ev_max // remove one max elem +x
    var new_ev = ((sum_without + cur - 1)/cur) // make even +y
    if(new_ev <= k) ans = Math.min(ans, cst + y + x + y)
    cst += x
    sum -= item
  }
  var ans2 : Long = (x*n).toLong()
  ans = Math.min(ans, ans2);
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
