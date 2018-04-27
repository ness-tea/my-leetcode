class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int temp1;
        int temp2;
        int first;
        int next;
        
        for (int i = 0; count < nums.size(); i++) {
            first = i;
            temp1 = nums[first];
            do {
                next = (first + k) % nums.size();
                temp2 = nums[next];
                nums[next] = temp1;
                temp1 = temp2;
                first = next;
                count++;
            } while(first != i);
        }
        
    }
};
