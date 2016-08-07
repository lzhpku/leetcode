/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    private HashMap<Integer, UndirectedGraphNode> map = new HashMap<>();
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null)
            return null;
        if(map.containsKey(node.label))
            return map.get(node.label);
        UndirectedGraphNode c = new UndirectedGraphNode(node.label);
        map.put(c.label, c);
        for (UndirectedGraphNode neighbor : node.neighbors) {
            c.neighbors.add(cloneGraph(neighbor));
        }
        return c;
    }
}