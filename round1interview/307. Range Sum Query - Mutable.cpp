public class NumArray {
    
    public SegmentTreeNode root = null;
    
    public NumArray(int[] nums) {
        root = buildTree(nums, 0, nums.length - 1);
    }
    
    public SegmentTreeNode buildTree(int[] nums, int start, int end) {
        if(start > end)
            return null;
        SegmentTreeNode ret = new SegmentTreeNode(start, end);
        if(start == end)
            ret.sum = nums[start];
        else {
            int mid = (start + end) / 2;
            ret.left = buildTree(nums, start, mid);
            ret.right = buildTree(nums, mid + 1, end);
            ret.sum = ret.left.sum + ret.right.sum;
        }
        return ret;
    }

    void update(int i, int val) {
        update(root, i, val);
    }
    
    void update(SegmentTreeNode root, int i, int val) {
        if(root.start == root.end) {
            root.sum = val;
            return;
        }
        int mid = (root.start + root.end) / 2;
        if(i <= mid)
            update(root.left, i, val);
        else
            update(root.right, i, val);
        root.sum = root.left.sum + root.right.sum;
        return;
    }

    public int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
    
    public int sumRange(SegmentTreeNode root, int i, int j) {
        if(root.start == i && root.end == j)
            return root.sum;
        int mid = (root.start + root.end) / 2;
        if(j <= mid)
            return sumRange(root.left, i, j);
        else if(i >= mid + 1)
            return sumRange(root.right, i, j);
        else
            return sumRange(root.left, i, mid) + sumRange(root.right, mid + 1, j);
    }
}

class SegmentTreeNode {
    int start, end;
    SegmentTreeNode left, right;
    int sum;
    
    public SegmentTreeNode(int start, int end) {
        this.start = start;
        this.end = end;
        this.left = null;
        this.right = null;
        this.sum = 0;
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);