class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n2 < n1){
            swap(str1, str2);
        }
        string res = "";
        for(int i=1; i<=str1.size(); i++){
            string substr = str1.substr(0, i);
            int flag = 0;
            for(int j=0; j<str2.size(); j+=i){
                if(substr != str2.substr(j, i)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) continue;
            for(int k=0; k<str1.size(); k+=i){
                if(substr != str1.substr(k, i)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) res = substr;
        }
        return res;
    }
};