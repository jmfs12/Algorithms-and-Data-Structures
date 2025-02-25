public class WaterContainer {

    public static int ans(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int ans = 0;
        while (l < r) {
            int temp;
            if (height[l] < height[r]) {
                temp = height[l] * Math.abs(l - r);
                if (temp > ans)
                    ans = temp;
                l++;
            } else if (height[l] > height[r]) {
                temp = height[r] * Math.abs(l - r);
                if (temp > ans)
                    ans = temp;
                r--;
            } else {
                temp = height[r] * Math.abs(l - r);
                if (temp > ans)
                    ans = temp;
                l++;
            }
        }
        return ans;
    }

    public static void main(String[] args){
        int[] arr = {1,1};
        System.out.println(ans(arr));
    }
}


