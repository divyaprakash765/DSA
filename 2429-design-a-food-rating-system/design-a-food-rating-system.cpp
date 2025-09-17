class FoodRatings {
public:
    // food -> rating
    unordered_map<string,int> rated_food;
    // food -> cuisine
    unordered_map<string,string> food_cuisines;
    // cuisine -> ordered set of { -rating, food }
    unordered_map<string, set<pair<int,string>>> cuisine_sets;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            rated_food[foods[i]] = ratings[i];
            food_cuisines[foods[i]] = cuisines[i];
            cuisine_sets[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = food_cuisines[food];
        int oldRating = rated_food[food];
        
        // remove old record
        cuisine_sets[c].erase({-oldRating, food});
        
        // update rating
        rated_food[food] = newRating;
        
        // insert new record
        cuisine_sets[c].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // first element in set = highest rating, lexicographically smallest
        return cuisine_sets[cuisine].begin()->second;
    }
};
