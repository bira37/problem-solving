class BrowserHistory {
public:
    vector<string> v;
    int pointer = -1;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        pointer++;
    }
    
    void visit(string url) {
        while(pointer+1 < v.size()) v.pop_back();
        v.push_back(url);
        pointer++;
    }
    
    string back(int steps) {
        while(steps > 0 && pointer > 0){
            pointer--;
            steps--;
        }
        return v[pointer];
    }
    
    string forward(int steps) {
        while(steps > 0){
            pointer++;
            if(pointer == v.size()) pointer--;
            steps--;
        }
        return v[pointer];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
