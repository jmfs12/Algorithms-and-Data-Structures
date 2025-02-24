import java.util.*;
public class SlidingWindow {
    public int maximumLengthSubstring(String s) {
        Map<Character, Integer> counter = new HashMap<>();
        int l = 0, r = 0;
        int len = s.length();
        char[] st = s.toCharArray();
        counter.put(st[0], 1);
        int max = 1;

        while(r < len-1){
            r++;
            if(counter.containsKey(st[r]))
                counter.put(st[r], counter.get(st[r])+1);

            else
                counter.put(st[r],1);
            while(counter.get(st[r]) == 3){
                counter.put(st[l], counter.get(st[l])-1);
                l++;
            }
            max = Math.max(max, r-l+1);
        }

        return max;
    }
}

