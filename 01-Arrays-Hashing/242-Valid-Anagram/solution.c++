#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;
        
        int alphabet[26] = {0};

        for(int i = 0; i < s.size(); i++){
        int index = s[i] - 'a';
        alphabet[index]++;
        }
        for(int i = 0; i < t.size(); i++){
            int index = t[i] - 'a';
            alphabet[index]--;
        }
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] != 0)
                return false;
        }
        return true;
    }
};