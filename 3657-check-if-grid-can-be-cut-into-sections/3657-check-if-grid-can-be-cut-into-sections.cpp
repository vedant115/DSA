class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> verticalGrps;
        vector<vector<int>> horizontalGrps;

        for (int i = 0; i < rectangles.size(); i++) {
            verticalGrps.push_back({rectangles[i][0], rectangles[i][2]});
            horizontalGrps.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(verticalGrps.begin(), verticalGrps.end(), compare);
        sort(horizontalGrps.begin(), horizontalGrps.end(), compare);

        int prevX = 0;
        int resX = 0;
        for(auto& arr : verticalGrps){
            if(arr[0] >= prevX) {
                resX++;
            }
            prevX = max(prevX, arr[1]);
            

        }
        cout<<"Res X -" <<resX;
        if(resX >= 3) return true;

        int prevY = 0;
        int resY = 0;
        for(auto& arr : horizontalGrps){
            if(arr[0] >= prevY) {
                resY++;
            }
            prevY = max(prevY, arr[1]);

        }
        cout<<"Res Y -" <<resY;
        if(resY >= 3) return true;

        return false;
    }
};