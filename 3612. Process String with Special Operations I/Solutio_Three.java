
public class Solutio_Three {

    public String processStr(String s) {
        StringBuilder res = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            final char ch = s.charAt(i);

            switch (ch) {
                case '#' ->
                    res.append(res.toString());
                case '%' ->
                    res.reverse();
                case '*' -> {
                    if (res.length() > 0) {
                        res.deleteCharAt(res.length() - 1);
                    }
                }
                default ->
                    res.append(ch);
            }
        }

        return res.toString();
    }
}
