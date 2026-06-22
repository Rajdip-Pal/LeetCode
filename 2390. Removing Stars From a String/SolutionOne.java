
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class SolutionOne {

    public String removeStars(String s) {
        char[] str = s.toCharArray();
        Deque<Character> st = new ArrayDeque<>();

        for (char ch : str) {
            if (ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        StringBuilder res = new StringBuilder();

        while (!st.isEmpty()) {
            res.append(st.peek());
            st.poll();
        }

        return res.toString();
    }

    public static void main(String[] args) {
        Deque<Integer> dq = new ArrayDeque<>();

        dq.add(10);
        dq.add(20);
        dq.add(30);
        dq.add(40);

        System.out.println(Arrays.toString(dq.toArray()));

        dq.pop();
        System.out.println(Arrays.toString(dq.toArray()));

        dq.push(10);
        System.out.println(Arrays.toString(dq.toArray()));

        dq.poll();
        System.out.println(Arrays.toString(dq.toArray()));

        dq.offer(50);
        System.out.println(Arrays.toString(dq.toArray()));

        dq.poll();
        System.out.println(Arrays.toString(dq.toArray()));

        System.out.println(dq.peek());
        System.out.println(Arrays.toString(dq.toArray()));

        System.out.println(Arrays.toString(dq.toArray()));
        System.out.println(Arrays.toString(dq.toArray()));
    }
}
