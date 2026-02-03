```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*
    1.Handle separately the case of ascending and descending
    2.don't use left and right directly as they can be modified during the peak so use other variable like peak and n
*/
class Solution {
public:
    int binarySearch(int l, int r, int target, MountainArray &mountainArr, bool ascending) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal == target) return mid;

            if (ascending) {
                if (midVal > target) r = mid - 1;
                else l = mid + 1;
            } else {
                if (midVal < target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n-1;

        while(left < right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1)) right = mid;
            else left = mid+1;
        }
        
        int peak = left;
        if(mountainArr.get(peak) == target) return peak;

        int idx = binarySearch(0, peak-1, target, mountainArr, true);
        
        if(idx != -1) return idx;

        return binarySearch(peak+1, n-1, target, mountainArr, false);
    }
};
```