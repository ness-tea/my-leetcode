class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex = 0;
        int maxLength = 0;
        int strLength = 0;
        
        unordered_map<char,int> indices; // stores characters and last index appeared
        unordered_map<char,int> chars;  // stores characters and count
        
        for (int i = 0; i < s.size(); i++)
        {   
            if ( (chars.count(s[i]) < 1) ||
                 (strLength < i - indices[s[i]]) )
            {
                chars[s[i]] = 1;
                indices[s[i]] = i;
                strLength +=1;
            }
            else
            {
                if (strLength > maxLength)
                {
                    maxLength = strLength;
                }
                
                strLength = i - indices[s[i]];
                indices[s[i]] = i;
            }
        }
        
        if (strLength > maxLength)
        {
            maxLength = strLength;
        }
        
        return maxLength;
    }
};