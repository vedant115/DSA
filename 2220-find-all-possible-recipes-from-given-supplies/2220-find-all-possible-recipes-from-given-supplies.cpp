class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supply) {
        unordered_set<string> supplies(supply.begin(), supply.end());
        unordered_map<string, vector<string>> DAG;
        unordered_map<string, int> inDegree;
        
        for(auto& recipe : recipes){
            inDegree[recipe] = 0;
        }

        for(int i=0; i<recipes.size(); i++){
            for(int j=0; j<ingredients[i].size(); j++){
                if(supplies.find(ingredients[i][j]) == supplies.end()){
                    DAG[ingredients[i][j]].push_back(recipes[i]);
                    inDegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(auto& recipe : inDegree){
            if(recipe.second == 0) q.push(recipe.first);
        }

        vector<string> res;
        while(!q.empty()){
            string ingredient = q.front();
            q.pop();
            res.push_back(ingredient);
            for(auto& recipe : DAG[ingredient]){
                inDegree[recipe]--;
                if(inDegree[recipe] == 0) q.push(recipe);
            }
        }

        return res;
    }
};