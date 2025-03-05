class Solution {
public:
    long long coloredCells(int n) {
        long long doubleEdgeCnt = 0;
        long long facesOcc = 0;
        long long faces = 4;
        long long res = 1;
        int i = 1;
        while(i < n){
            res += (faces - doubleEdgeCnt);
            doubleEdgeCnt+=4;
            facesOcc += (faces*2);
            faces = (res*4)-(facesOcc);
            i++;
        }
        return res;
    }
};