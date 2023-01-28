class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int occur[26];
        for(int i = 0; i < 26; i++){
            occur[i] = 0;
        }

        for(int i = 0; i < magazine.size(); i++){
            occur[magazine[i]-'a']++;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            occur[ransomNote[i]-'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(occur[i] < 0){
                return false;
            }
        }
        return true;
    }
};