class Solution {
private:
    long long atLeastK(string word, int k){
        int n = word.size();
        unordered_map<char, int> vowel;
        set<char> st = {'a', 'e', 'i', 'o','u'};

        int left = 0, right = 0;
        long long res = 0;
        int nonVowel = 0;
        for(; right < n; right++){
            if(st.find(word[right]) != st.end()){
                vowel[word[right]]++;
            }
            else{
                nonVowel++;
            }

            while(vowel.size() == 5 && nonVowel >= k){
                res += (n - right);
                if(st.find(word[left]) != st.end()){
                    vowel[word[left]]--;
                    if(vowel[word[left]] == 0) vowel.erase(word[left]);
                }
                else{
                    nonVowel--;
                }
                left++;
            }
        }
        return res;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k+1);
    }
};