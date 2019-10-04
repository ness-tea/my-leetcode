class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addOne = digits.back();
        digits.pop_back();
        int numOfZeroes = 0;
        
        if (addOne != 9) {
            addOne++;
            digits.push_back(addOne);            
        } else {
            numOfZeroes++;
            digits.pop_back();
            plusOne(digits);
        }
        
        for (int i = 0; i < numOfZeroes; ++i) {
            digits.push_back(0);
        }
        
        return digits;
    }
};
