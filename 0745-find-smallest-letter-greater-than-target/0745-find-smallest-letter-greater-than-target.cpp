class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ind = upper_bound(letters.begin(), letters.end(), target);
        return ind != letters.end() ? *ind : letters[0];
    }
};