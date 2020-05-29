import kotlin.math.abs

fun main(args: Array<String>) {
  var (t) = readLine()!!.split(' ').map({it.toInt()});
  while(t > 0){
    t--;
    
    var (n) = readLine()!!.split(' ').map({it.toInt()});

    var arr : MutableList<Int> = mutableListOf<Int>();

    for(i in n downTo 1 step 1){
      if(i % 2 == 0) arr.add(i);
    }

    if(arr.size >= 2){
      val temp = arr[arr.size-1];
      arr[arr.size-1] = arr[arr.size-2];
      arr[arr.size-2] = temp;
    }

    for(i in 1..n){
      if(i % 2 == 1) arr.add(i);
    }

    var ok = true;

    var last = -1;

    for(item in arr){
      if(last == -1){
        last = item;
      } else {
        if(abs(item - last) < 2 || abs(item - last) > 4) ok = false;
        last = item;
      }
    }

    if(!ok) println(-1);
    else println(arr.joinToString(" "));
  }

}

