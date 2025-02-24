public class ExponentialSearch {
    public static int Esearch(int[] arr, int target){
        if(arr[0] == target){
            return -1;
        }
        int n = arr.length;
        int i = 1;
        int l = arr[0];
        while (i < n && arr[i] < target ){
            l = i;
            i = i*2;
        }
        if(arr[Math.min(i, n-1)] == target) return i;
        else {
            return Bsearch.search(arr, l + 1, Math.min(i, n - 1), target);
        }
    }

    public static void main(String[] args) {
        long start = System.nanoTime(); // ou System.currentTimeMillis()
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
        int target = 32;
        System.out.println(Bsearch.search(arr, 0, arr.length-1, target));
        long end = System.nanoTime(); // ou System.currentTimeMillis()
        System.out.println("Tempo de execução: " + (end - start) / 1_000_000.0 + " ms");
    }
}
