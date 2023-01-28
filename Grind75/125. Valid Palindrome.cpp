class Solution {
public:

    string alphaNumericLower(string s){
        string result;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                result.push_back(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                result.push_back(s[i]);
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                result.push_back(tolower(s[i]));
            }

        }

        return result;
    }

    bool isPalindrome(string s) {
        string result = alphaNumericLower(s);
        int l = 0, r = result.size()-1;

        while(l <= r){
            if(result[l] != result[r]){
                return false;
            }
            l++;
            r--;
        }    
        return true;
    }
};