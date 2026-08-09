class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        int n=heights.size();
        stack<int> st;
        vector<int> leftboundary(n,-1);
        vector<int> rightboundary(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                rightboundary[st.top()]=i;
                st.pop();
            }
            if(!st.empty()){
                leftboundary[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int width=rightboundary[i]-leftboundary[i]-1;
            int area=heights[i]*width;
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};