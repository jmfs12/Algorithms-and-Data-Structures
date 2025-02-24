public class Bsearch {
    public static int search(int[] arr, int l, int r, int n){
        int m = l+(r-l)/2;

        if(l <= r){
            if(arr[m] == n){
                return m;
            }
            else if(arr[m] > n){
                return search(arr, l, m-1, n);
            }
            else if(arr[m] < n){
                return search(arr, m+1, r, n);
            }
        }

        return -1;
    }
  
}
