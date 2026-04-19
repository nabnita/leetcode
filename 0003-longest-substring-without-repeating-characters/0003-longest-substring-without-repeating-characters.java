class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max=0;
        int left = 0;
        Set<Character> freq = new HashSet<>();
        for(int right =0; right<s.length();right++){
            char c = s.charAt(right);
        while(freq.contains(c)){
            freq.remove(s.charAt(left));
            left++;
        }
        freq.add(c);
        max=Math.max(max,right-left+1);
        }
        return max;
    }
}