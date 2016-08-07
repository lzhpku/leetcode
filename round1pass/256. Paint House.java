There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

public class Solution {
    public int minCost(int[][] costs) {
        if(costs.length == 0)
            return 0;
        int dppr = costs[0][0], dppb = costs[0][1], dppg = costs[0][2];
        int dpr = costs[0][0], dpb = costs[0][1], dpg = costs[0][2];
        int len = costs.length;
        for(int i = 1; i < len; i ++) {
            dpr = Math.min(dppb, dppg) + costs[i][0];
            dpb = Math.min(dppr, dppg) + costs[i][1];
            dpg = Math.min(dppb, dppr) + costs[i][2];
            dppr = dpr;
            dppb = dpb;
            dppg = dpg;
        }
        return Math.min(dpr, Math.min(dpb, dpg));
    }
}