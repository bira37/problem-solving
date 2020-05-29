fun main(args: Array<String>) {
  var (t) = readLine()!!.split(' ').map({it.toInt()});
  while(t > 0){
    t--;
    var (a, b) = readLine()!!.split(' ').map({it.toInt()});
    println(a+b);
  }

}

