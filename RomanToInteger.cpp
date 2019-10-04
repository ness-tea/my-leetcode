class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char,int> mapping;
        
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
        
        result = mapping[s[s.length()-1]];
        for (int i = s.length()-2; i >= 0; i--)
        {
            if (mapping[s[i]] >= mapping[s[i+1]])
            {
                result += mapping[s[i]];
            }
            else
            {
                result -= mapping[s[i]];
            }
        }
        
        return result;
    }
};