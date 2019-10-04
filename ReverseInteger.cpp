class Solution {
public:
    int reverse(int x) {
        int numDigits = 0;
        int operand = x;
        while (operand)
        {
            operand /= 10;
            numDigits += 1;
        }
        
        int reverse = 0, prev_reverse = 0;
        operand = x; 
        
        for (int i = numDigits-1; i >=0; i--)
        {
            reverse += (operand % 10) * (pow(10,i));
            
            if (prev_reverse != (reverse - (operand % 10) * (pow(10,i))))
            {
                return 0;
            }
            
            prev_reverse = reverse;
            operand /= 10;
        }
        
        return  reverse;    
    }
};