class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int N = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < N; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap; 
        int sumQuality = 0;
        double minCost = DBL_MAX;
       
        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;
            sumQuality += q;
            maxHeap.push(q);
            if (maxHeap.size() > K) {
                sumQuality -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == K) {
                double cost = sumQuality * ratio;
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
};
