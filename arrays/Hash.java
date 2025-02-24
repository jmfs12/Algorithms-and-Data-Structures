import java.util.*;
public class Hash {
    class Solution {
        public int firstUniqChar(String s) {
            Map<Character, Integer> hash = new HashMap<>();
            char[] c = s.toCharArray();
            for(char letter : c){
                if(hash.containsKey(letter))
                    hash.put(letter, hash.get(letter)+1);
                else{
                    hash.put(letter, 1);
                }
            }
            int ans = 0;
            if(hash.containsValue(1)){
                for(Map.Entry<Character, Integer> entry : hash.entrySet()){
                    if(entry.getValue().equals(1)){
                        return ans;
                    }
                    ans++;
                }
            }
            return -1;
        }
    }
    public static void main(String[] args) {
        Hash h = new Hash();
        Hash.Solution s = h.new Solution();
        String str = "loveleetcode";
        System.out.println(s.firstUniqChar(str));
    }
}
