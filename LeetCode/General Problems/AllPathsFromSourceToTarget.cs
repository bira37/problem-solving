public class Solution {
    IList<int> cur = new List<int>();
    private void go(int u, IList<IList<int>> paths, int[][] graph){
        if(u == graph.Length-1){
            paths.Add(new List<int>(cur));
            return;
        }
        foreach(int x in graph[u]){
            cur.Add(x);
            go(x, paths, graph);
            cur.RemoveAt(cur.Count-1);
        }
    }
    public IList<IList<int>> AllPathsSourceTarget(int[][] graph) {
        IList<IList<int>> ans = new List<IList<int>>();
        cur.Add(0);
        go(0, ans, graph);
        return ans;
    }
}
