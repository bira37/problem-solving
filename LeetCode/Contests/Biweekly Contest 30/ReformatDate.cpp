class Solution {
public:
    string reformatDate(string date) {
        string a,b,c;
        int p = 0;
        while(date[p] != ' ' && p < date.size()) a += date[p++];
        p++;
        while(date[p] != ' ' && p < date.size()) b += date[p++];
        p++;
        while(date[p] != ' ' && p < date.size()) c += date[p++];
        p++;
        string v[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        map<string, string> m;
        for(int i=1; i<=12; i++){
            m[v[i-1]]= i <= 9 ? "0" + to_string(i) : to_string(i);
        }
        string wtf;
        //cout << a  << endl;
        for(char q : a){
            if(q >= '0' && q <= '9') wtf+=q;
        }
        if(wtf.size() ==1) wtf = "0" + wtf;
        //cout << wtf<< endl;
        return c + "-" + m[b] + "-" + wtf;
    }
};
