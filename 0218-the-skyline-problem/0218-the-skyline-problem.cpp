class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (int i = 0; i < buildings.size(); i++) {
            events.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            events.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(events.begin(), events.end());
        multiset<int> heights;
        heights.insert(0);
        int prev = 0;
        vector<vector<int>> filteredAns;
        for (int i = 0; i < events.size(); i++) {
            int x = events[i].first;
            int h = events[i].second;
            if (h < 0) {
                heights.insert(-h);
            } else {
                multiset<int>::iterator it = heights.find(h);
                if (it != heights.end()) {
                    heights.erase(it);
                }
            }
            int current = *heights.rbegin();
            if (current != prev) {
                vector<int> point;
                point.push_back(x);
                point.push_back(current);
                filteredAns.push_back(point);
                prev = current;
            }
        }
        return filteredAns;
    }
};
