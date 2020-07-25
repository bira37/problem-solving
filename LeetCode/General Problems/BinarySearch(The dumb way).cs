using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int Search(int[] nums, int target) {
		SortedSet<Tuple<int,int>> s = new SortedSet<Tuple<int,int>>();
		int mx = nums.Max();
		
		for(int i=0; i<nums.Length; i++) s.Add(new Tuple<int,int>(nums[i], i));
		
        int x = target;
        if(x > mx){
            return -1;
        } else {
            Tuple<int,int> ans = s.GetViewBetween(new Tuple<int,int>(x, 0), new Tuple<int,int>(mx, nums.Length+1)).DefaultIfEmpty(new Tuple<int,int>(-1,-1)).FirstOrDefault();
            if(ans.Item1 == x) return ans.Item2;
            else return -1;
        }
    }
}
