fun main(args: Array<String>) {
  var (t) = readLine()!!.split(' ').map({it.toInt()});
  while(t > 0){
    t--;
    
    readLine()!!

    var arr : MutableList<Int> = readLine()!!.split(' ').map({it.toInt()}).toMutableList();

    var l = 0;
    var r = arr.size - 1;

    var plays = 0;
    var a = 0; 
    var b = 0;
    var la = 0;
    var lb = 0;
    var side = true;

    while(l <= r){
      if(side){
        var cnt = 0;
        while(l <= r && cnt <= lb){
          a += arr[l];
          cnt += arr[l];
          l++;
        }
        la = cnt;
      } else {
        var cnt = 0;
        while(l <= r && cnt <= la){
          b += arr[r];
          cnt += arr[r];
          r--;
        }
        lb = cnt;
      }
      plays++;
      side = !side;
    }
    print("${plays} ${a} ${b}\n");
  }

}

