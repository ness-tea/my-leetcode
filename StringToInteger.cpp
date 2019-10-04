class Solution {
public:
    int myAtoi(string str) {
        bool negative = false, digitsFinished = false;
        int integer = 0, prev_integer = 0, length = 0, sign = 0;

        unordered_map<string,int> intmappings;
        
        for (int i = 0; i < 10; i++)
        {
            intmappings[to_string(i)] = i;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (intmappings.count(string(1,str[i])) != 0 || str[i]=='-' || str[i]=='+')
            {       
                length += 1;
                
                if (intmappings.count(string(1,str[i+1])) != 1)
                {
                    break;
                }
            }
        }
        
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            else if (str[i]=='-')
            {
                if (intmappings.count(string(1,str[i+1])) != 1)
                {
                    return 0;
                }
                length -= 1;
                negative = true;
            }
            else if (str[i]=='+')
            {
                if (intmappings.count(string(1,str[i+1])) != 1)
                {
                    return 0;
                }
                length -=1;
            }
            else if (intmappings.count(string(1, str[i])) > 0)
            {
                integer += pow(10,length-1) * (intmappings[string(1, str[i])]);
                
                if (prev_integer != integer - (pow(10,length-1)*intmappings[string(1, str[i])]))
                {
                    if (negative)
                    {
                        return INT_MIN;
                    }
                    else
                    {
                        return INT_MAX;
                    }
                }
                
                if (intmappings.count(string(1,str[i+1])) != 1)
                {
                    break;
                }
                
                prev_integer = integer;
                length -= 1;
            }
            else
            {
                return 0;
            }
        }
        
        if (negative)
        {
            integer = integer*(-1);
        }
        
        return integer;
    }
};