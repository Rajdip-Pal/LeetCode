
class Solution {

    public int minimizedStringLength(String s) {
        int count = 0;
        int buff = 0, curr_buff;

        for (int i = 0; i < s.length(); i++) {
            curr_buff = buff | 1 << (s.charAt(i) - 'a');
            if (buff != curr_buff) {
                count++;
                buff = curr_buff;
            }
        }

        return count;
    }
}
