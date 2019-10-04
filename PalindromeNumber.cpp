class Solution {
public:
    bool isPalindrome(int x) {
        int length = 0, operand = x;
        bool result = false;
        
        if (x < 0)
        {
            return false;
        }
        
        while (operand)
        {
            length += 1;
            operand /= 10;
        }
        
        operand = x;
        int reverse = 0;
        for (int i = length-1; i >= 0; i--)
        {
            reverse += (operand % 10)*pow(10,i);
            operand /= 10;
        }
        
        return (x == reverse);
    }
};