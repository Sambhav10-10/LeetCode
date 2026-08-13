class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0;
       int j=height.size()-1;
       int area;
       int maxa=-1e6;
     
       while(j>i){
        area=min(height[i],height[j])*(j-i);
        maxa=max(maxa,area);
        if(height[i]<height[j]){
            i++;

        }
        else if(height[i]>=height[j]){
            j--;
        }
       } 
       return maxa;
    }
};