
import java.util.ArrayDeque;
import java.util.Deque;

public class Solution_Two {

    public String processStr(String s) {
        Boolean flag = true;
        Deque<Character> dq = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            final Character ch = s.charAt(i);

            switch (ch) {
                case '#' ->
                    dq.addAll(dq.stream().toList());
                case '%' ->
                    flag = !flag;
                case '*' -> {
                    if (!dq.isEmpty()) {
                        if (flag) {
                            dq.removeLast();
                        } else {
                            dq.removeFirst();
                        }
                    }
                }
                default -> {
                    if (flag) {
                        dq.addLast(ch);
                    } else {
                        dq.addFirst(ch);
                    }
                }

            }
        }

        final String res = dq.stream().map(String::valueOf).collect(java.util.stream.Collectors.joining());

        return flag ? res : new StringBuilder(res).reverse().toString();
    }
}
