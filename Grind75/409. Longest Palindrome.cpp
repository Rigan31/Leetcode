class Solution
{
public:
    int longestPalindrome(string s)
    {
        int freq[52];
        for (int i = 0; i < 52; i++)
        {
            freq[i] = 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                freq[26 + s[i] - 'A']++;
            }
            else
            {
                freq[s[i] - 'a']++;
            }
        }

        int length = 0;
        bool hasOdd = false;
        for (int i = 0; i < 52; i++)
        {
            if (freq[i] & 1)
            {
                hasOdd = true;
                length += freq[i] - 1;
            }
            else
            {
                length += freq[i];
            }
        }

        return hasOdd ? length + 1 : length;
    }
};