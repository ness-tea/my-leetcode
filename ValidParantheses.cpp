class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
        {
            return true;
        }
        
        if (s.length() == 1)
        {
            return false;
        }
        
        unordered_map<char,int> open = 
        {
            {'(',1},
            {'[',1},
            {'{',1}
        };
        
        unordered_map<char,int> close =
        {
            {')','('},
            {']','['},
            {'}','{'}
        };
        
        stack<char> para;  
        
        for (int i = 0; i < s.length(); i++)
        {
            if (open.count(s[i]) != 0)
            {
                para.push(s[i]);
            }
            else if (!para.empty() && para.top() == close[s[i]]) 
            {
                para.pop();
            }
            else
            {
                para.push(s[i]);
            }
        }
        
        return para.empty() ? true : false;
    }
};