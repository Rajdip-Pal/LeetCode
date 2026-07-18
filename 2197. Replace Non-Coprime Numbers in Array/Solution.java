
import java.util.ArrayList;
import java.util.List;

class MyStack {

    private final int capacity;
    private int size;
    private final int[] array;

    public MyStack(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        this.array = new int[capacity];
    }

    void push(int a) {
        if (size < capacity) {
            array[size++] = a;
        }
    }

    int pop() {
        if (size > 0) {
            return array[--size];
        }
        return Integer.MIN_VALUE;
    }

    int size() {
        return size;
    }

    List<Integer> toList() {
        List<Integer> list = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            list.add(array[i]);
        }
        return list;
    }
}

class Solution {

    static int gcd(int a, int b) {
        while (b != 0) {
            b = a % (a = b);
        }
        return a;
    }

    static boolean isNonCoPrime(int a, int b) {
        return gcd(a, b) > 1;
    }

    static int lcm(int a, int b) {
        int gcd = gcd(a, b);
        return a * (b / gcd);
    }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        final int n = nums.length;
        final MyStack stack = new MyStack(n);

        int i = 0;
        while (i < n) {
            stack.push(nums[i]);
            while (stack.size() > 1) {
                int a = stack.pop();
                int b = stack.pop();

                if (isNonCoPrime(a, b)) {
                    int lcm = lcm(a, b);
                    stack.push(lcm);
                } else {
                    stack.push(b);
                    stack.push(a);
                    break;
                }
            }
            i++;
        }

        return stack.toList();
    }
}
