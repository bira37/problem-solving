public class Solution {
    private int f(int n){
        int cur = 0;
        while(n > 0){
            cur += n%10;
            n /= 10;
        }
        if(cur < 10) return cur;
        else return f(cur);
    }
    public int AddDigits(int num) {
        return f(num);
    }
}
