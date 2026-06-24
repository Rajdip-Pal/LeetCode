
public class SolutionOne {

    private static long value = 1;

    static {
        for (int i = 0; i < 20; i++) {
            value = value * 3;
        }
    }

    public boolean isPowerOfThree(int n) {
        return n > 0 && value % n == 0;
    }

    public static void main(String[] args) {
        System.out.println(value);
        System.out.println(value % 45);

    }
}
