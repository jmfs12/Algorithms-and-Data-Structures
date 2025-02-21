class two_pointer {

    public static void main(String[] args) {
        int l = 0,r = 0;
        String s = "I am a student";
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

        System.out.println(String.valueOf(reversed));
    }
}
