fun main(args: Array<String>) {
  var (t) = readLine()!!.split(' ').map({it.toInt()});
  while(t > 0){
    t--;
    var (a, b) = readLine()!!.split(' ').map({it.toInt()});
    var (c, d) = readLine()!!.split(' ').map({it.toInt()});
    
    if(b == d && a + c == d){
      println("Yes")
    } else if(a == c && b + d == a) {
      println("Yes")
    } else if(c == b && a + d == b){
      println("Yes")
    } else if(b+c == d && d == a){
      println("Yes")
    } else println("No")
  }

}

