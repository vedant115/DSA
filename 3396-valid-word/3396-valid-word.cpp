class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        int vowels = 0, consonants = 0;
        for(char c : word) {
            if(isdigit(c)) continue;
            if(!isalpha(c)) return false;
            char lower = tolower(c);
            if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        }
        return vowels > 0 && consonants > 0;
    }
};