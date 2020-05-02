import java.math.BigInteger; 
import java.math.*;
import java.util.*;
import java.io.*;

public class Solution{
  public static ArrayList<BigInteger> unique(ArrayList<BigInteger> v){
    ArrayList<BigInteger> w = new ArrayList<BigInteger>();
    w.add(v.get(0));
    for(int i=1; i<v.size(); i++){
      if(w.get(w.size()-1).compareTo(v.get(i)) != 0) w.add(v.get(i));
    }
    return w;
  }
  public static void main(String[] args){
    int t;
    BigInteger n;
    int l;
    Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    t = sc.nextInt();
    for(int tst = 1; tst <= t; tst++){
      
      n = sc.nextBigInteger();
      l = sc.nextInt();
      ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
      for(int i=0; i<l; i++){
        BigInteger x = sc.nextBigInteger();
        arr.add(x);
      }
      ArrayList<BigInteger> v = new ArrayList<BigInteger>();
      int mark = 0;
      for(int i=0; i<l-1; i++){
        BigInteger g = arr.get(i).gcd(arr.get(i+1));
        if(g.compareTo(arr.get(i)) != 0){
          mark = i;
          break;
        }
      }
      BigInteger g = arr.get(mark).gcd(arr.get(mark+1));
      v.add(g);
      v.add(arr.get(mark).divide(g));
      for(int i=mark-1; i>=0; i--){
        v.add(arr.get(i).divide(v.get(v.size()-1)));
      }
      v.add(arr.get(mark+1).divide(g));
      for(int i=mark+2; i<l; i++){
        v.add(arr.get(i).divide(v.get(v.size()-1)));
      }
      Collections.sort(v);
      v = unique(v);
      //System.out.println(v);
      char[] dummy = new char[l+1];
      dummy[mark] = (char)('A' + Collections.binarySearch(v, arr.get(mark).divide(g)));
      dummy[mark+1] = (char)('A' + Collections.binarySearch(v, g));
      dummy[mark+2] = (char)('A' + Collections.binarySearch(v, arr.get(mark+1).divide(g)));
      BigInteger last = arr.get(mark).divide(g);
      for(int i=mark-1; i>=0; i--){
        BigInteger val = arr.get(i).divide(last);
        last = val;
        dummy[i] = (char)('A' + Collections.binarySearch(v, val));
      }
      last = arr.get(mark+1).divide(g);
      for(int i=mark+2; i<l; i++){
        BigInteger val = arr.get(i).divide(last);
        last = val;
        dummy[i+1] = (char)('A' + Collections.binarySearch(v, val));
      }
      System.out.println("Case #" + tst + ": " + String.valueOf(dummy));
    }
  }
}
    
