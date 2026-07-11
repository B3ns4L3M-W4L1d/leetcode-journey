#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    
    if (strlen(s) != strlen(t))
        return false;

    int alphabet[26] = {0};

    for(int i = 0; i < strlen(s); i++){
        int index = s[i] - 'a';
        alphabet[index]++;
    }
    for(int i = 0; i < strlen(t); i++){
        int index = t[i] - 'a';
        alphabet[index]--;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0)
            return false;
    }
    return true;
}