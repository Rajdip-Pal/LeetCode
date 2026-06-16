
import java.util.ArrayList;
import java.util.List;

class Solution {

    public String processStr(String s) {

        List<Character> vec = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '#' ->
                    vec.addAll(vec);
                case '%' ->
                    vec = vec.reversed();
                case '*' -> {
                    if (!vec.isEmpty()) {
                        vec.removeLast();
                    }
                }
                default ->
                    vec.add(s.charAt(i));
            }
        }

        return vec.stream().map(String::valueOf).collect(java.util.stream.Collectors.joining());
    }
}
