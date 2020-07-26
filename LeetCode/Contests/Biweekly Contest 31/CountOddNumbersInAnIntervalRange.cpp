class Solution {
public:
    int countOdds(int low, int high) {
        if(low == 0) low = 1;
        int val = high-low+1;
        int even = high/2 - (low-1)/2;
        return (val - even);
    }
};
