class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        int temp = nums[0];
        int temp2;
        int j;
        
        for (int i = 0; i < n; i++) {
        	j = (i+k) % n;
        	temp2 = nums[j];
        	nums[j] = temp;
        	temp = temp2;
        }
    }
}
