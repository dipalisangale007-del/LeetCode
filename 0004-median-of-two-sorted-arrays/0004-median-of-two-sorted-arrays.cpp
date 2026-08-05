class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m+n;

        int medianIndex2 = totalLength / 2;
        int medianIndex1 = (totalLength - 1) / 2;

        int i=0,j=0;
        int count =0;
        int median1=0;
        int median2=0;

        while(count<=medianIndex2){
            int currentNum;
            if(i<m && (j>=n || nums1[i] <= nums2[j])){
                currentNum = nums1[i++];
            }else{
                currentNum = nums2[j++];
            }

            if(count == medianIndex1){
                median1= currentNum;
            }

            if(count == medianIndex2){
                median2 = currentNum;
                break;
            }
            count++;

        }
        return (median1 +median2) / 2.0;
    }
};