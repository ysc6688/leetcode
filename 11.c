int maxArea(int height[], int n) {
    int k,left,right,max,area,low;
    
    left = 0;
    right = n-1;
    max = -1;
    while(left < right)
    {
        low = (height[left] > height[right]) ? height[right] : height[left];
        area = (right-left) * low;
        if(area > max)
            max = area;
        if(height[left] > height[right])
        {
            k = right-1;
            while(height[k]<height[right])
                k--;
            right = k;
        }
        else
        {
            k = left + 1;
            while(height[k]<height[left])
                k++;
            left = k;
        }
    }
    return max;
}
