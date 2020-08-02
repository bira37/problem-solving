public class Solution {
    public bool DetectCapitalUse(string word) {
        bool first = (word[0] >= 'A' && word[0] <= 'Z');
        int capital = 0;
        for(int i=1; i<word.Length; i++){
            if(word[i] >= 'A' && word[i] <= 'Z') capital++;
        }
        
        if(capital == 0) return true;
        if(first && capital == word.Length-1) return true;
        return false;
    }
}
