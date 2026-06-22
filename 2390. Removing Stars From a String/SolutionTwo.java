
class SolutionTwo {

    public String removeStars(String s) {
        char[] str = s.toCharArray();

        int j = 0;
        for (int i = 0; i < str.length; i++) {
            if (str[i] == '*') {
                j--;
            } else {
                str[j++] = str[i];
            }
        }

        return new String(str, 0, j);
    }

}
