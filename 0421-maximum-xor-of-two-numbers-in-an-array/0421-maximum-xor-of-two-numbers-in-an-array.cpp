struct TrieNode {
    TrieNode* links[2];

    TrieNode(){
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    void set(int bit, TrieNode* node){
        links[bit] = node;
    }

    TrieNode* get(int bit){
        return links[bit];
    }
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(int num){
            TrieNode* node = root;
            for(int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->set(bit, new TrieNode());
                }
                node = node->get(bit);
            }
        }

        int calcMaxXOR(int num){
            TrieNode* node = root;
            int res = 0;
            for(int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(1 - bit)){
                    res = res | 1 << i;
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return res;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;

        for(int num : nums){
            obj.insert(num);
        }

        int maxXOR = 0;
        for(int num : nums){
            maxXOR = max(maxXOR, obj.calcMaxXOR(num));
        }

        return maxXOR;
    }
};