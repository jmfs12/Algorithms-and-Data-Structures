class Solution {
    public static void Reverse(char[] s, char[] reversed, int l, int r){
        int e = r;
        int temp = l;
        r--;
        while(r >= temp){
            reversed[l] = s[r];
            l++; r--;
        }
        reversed[e] = ' ';
        l = e+1;
        r = l;
    }

    public String reverseWords(String s) {
        int l = 0,r = 0;
        int len = s.length();
        char[] characters= s.toCharArray();
        char[] reversed = new char[len];

        while(r < len){
            if(characters[r] != ' ')
                r++;
            else{
                int e = r;
                int temp = l;
                r--;
                while(r >= temp){
                    reversed[l] = characters[r];
                    l++; r--;
                }
                reversed[e] = ' ';
                l = e+1;
                r = l;
            }
        }
        int temp = l;
        r--;
        while(r >= temp){
            reversed[l] = characters[r];
            l++; r--;
        }

        return new String(reversed);
    }
}
