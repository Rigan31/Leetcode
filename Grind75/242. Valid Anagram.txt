class Solution {
public:
    bool isAnagram(string s, string t) {
        int occur[26];
        for(int i = 0; i < 26; i++){
            occur[i] = 0;
        }

        for(int i = 0; i < s.size(); i++){
            occur[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            occur[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(occur[i] != 0){
                return false;
            }
        }
        return true;

    }
};