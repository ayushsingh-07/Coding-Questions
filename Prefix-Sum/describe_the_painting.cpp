// URL = "https://leetcode.com/problems/describe-the-painting/"

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();

        set<int>st;
        for(auto & curr : segments){
            st.insert(curr[0]);st.insert(curr[1]);
        }

        int idx = 0;
        map<int, int>mp;
        for(auto& i : st){
            mp[i] = idx;
            idx++;
        }

        vector<long long>wall(idx, 0);
        for(int i=0; i<n;i++){
            int idx1 = mp[segments[i][0]];
            int idx2 = mp[segments[i][1]];
            wall[idx1] += segments[i][2];
            wall[idx2] -= segments[i][2];
        }

        for(int i=1;i<idx;i++){
            wall[i]+=wall[i-1];
        }

        vector<int>a(st.begin(),st.end());

        vector<vector<long long>> ans;
        for(int i=0;i<a.size()-1; i++){
            if(wall[i]==0){
                continue;
            }
            ans.push_back({a[i], a[i+1], wall[i]});
        }
        return ans;
    }
};



// Notes

// 1. Since there are many different overlapping points, we want to deal with only those which are unique 
//    ie. where the values are changing.
// 2. Store them in a set and map their respective indexes based on the their values
// 3. Now create the diff array (wall here) based on indexes created in the previous step 
// 4. Then use them according to the problem statement which here is to give the summation from a to b(excluding)