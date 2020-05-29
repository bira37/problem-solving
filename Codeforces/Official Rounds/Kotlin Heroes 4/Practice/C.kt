fun main(args: Array<String>) {
  var (t) = readLine()!!.split(' ').map({it.toInt()});
  while(t > 0){
    t--;
    
    var (a) = readLine()!!.split(' ').map({it.toInt()});

    var arr : MutableList<Int> = mutableListOf<Int>() ;

    var pot = 1;

    while(a > 0){
      var md = a % 10;
      if(md > 0){
        arr.add(md*pot);
      }
      pot *= 10;

      a /= 10;
    }

    println(arr.size);
    println(arr.joinToString(" "));
  }

}

