public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        int ans = 0;
        int t=  0;
        int[] cnt = new int[26];
        int[] lst = new int[26];
        
        for(int i=0; i<26; i++){
            lst[i] = -500;
            cnt[i] = 0;
        }
        
        foreach(int x in tasks) cnt[x - 'A']++;
        
        int current = -1;
        int elapsed = 0;
        while(true){
            if(current != -1) elapsed++;
            if(elapsed == 1){
                lst[current] = t;
                current = -1;
                elapsed = 0;
            }
            ans++;
            int[] v = new int[26];
            for(int i=0; i<26; i++) v[i] = i;
            Array.Sort(v, delegate(int x, int y){
                if(cnt[x] < cnt[y]) return 1;
                else if(cnt[x] > cnt[y]) return -1;
                else return 0;
            });
            bool exists = false;
            for(int i=0; i<26; i++){
                if(current != v[i] && cnt[v[i]] > 0 && t - lst[v[i]] >= n){
                    current = v[i];
                    cnt[v[i]]--;
                    break;
                }
                if(cnt[v[i]] > 0) exists = true;
            }
            if(!exists && current == -1) break;
            t++;
        }
        return t;
    }
}
