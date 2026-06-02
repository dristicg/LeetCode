class Solution {
public:
    long long solveDirection(vector<int>& startA,
                             vector<int>& durA,
                             vector<int>& startB,
                             vector<int>& durB) {

        int m = startB.size();

        vector<pair<long long,long long>> rides;
        for (int i = 0; i < m; i++)
            rides.push_back({startB[i], durB[i]});

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);
        vector<long long> prefDur(m);
        vector<long long> suffOpenPlusDur(m);

        for (int i = 0; i < m; i++)
            starts[i] = rides[i].first;

        prefDur[0] = rides[0].second;
        for (int i = 1; i < m; i++)
            prefDur[i] = min(prefDur[i - 1], rides[i].second);

        suffOpenPlusDur[m - 1] =
            rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffOpenPlusDur[i] =
                min(suffOpenPlusDur[i + 1],
                    rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)startA.size(); i++) {

            long long finishFirst =
                (long long)startA[i] + durA[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishFirst)
                - starts.begin() - 1;

            long long best = LLONG_MAX;

            // rides already open
            if (pos >= 0)
                best = min(best,
                           finishFirst + prefDur[pos]);

            // rides not yet open
            if (pos + 1 < m)
                best = min(best,
                           suffOpenPlusDur[pos + 1]);

            ans = min(ans, best);
        }

        return ans;
    }

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long ans1 =
            solveDirection(landStartTime, landDuration,
                           waterStartTime, waterDuration);

        long long ans2 =
            solveDirection(waterStartTime, waterDuration,
                           landStartTime, landDuration);

        return min(ans1, ans2);
    }
};