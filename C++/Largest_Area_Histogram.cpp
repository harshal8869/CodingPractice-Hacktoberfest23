// Largest Area Histogram Problem , Solution in C++

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>left,right;
        stack<pair<int, int>> s,s2;
        int pseudoidx=-1;
        for(int i=0;i<n;i++){
            if(s.size()==0){
            left.push_back(pseudoidx);
            }
            else if(s.size()> 0 && s.top().first<arr[i]){
            left.push_back(s.top().second);
        }
            else if(s.size() > 0 && s.top().first>=arr[i]){
                while(s.size() > 0 && s.top().first>=arr[i]){
                s.pop();
            }
                if(s.size() == 0){
                left.push_back(pseudoidx);
            }
                else{
                left.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
       int pseudoidx2=n;
        for(int i=n-1;i>=0;i--){
            if(s2.size()==0){
            right.push_back(pseudoidx2);
        }
            else if(s2.size()>0 && s2.top().first<arr[i]){
            right.push_back(s2.top().second);
            }
            else if(s2.size() > 0 && s2.top().first >= arr[i]){
                while(s2.size() > 0 && s2.top().first>=arr[i]){
                s2.pop();
            }
                if(s2.size()==0){
                right.push_back(pseudoidx2);
                }
                else{
                right.push_back(s2.top().second);
            }
            }
            s2.push({arr[i],i});
        }
        reverse(right.begin(), right.end());
        int ans=0;
      for(int i=0;i<n;i++){
          ans=max(ans, arr[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
