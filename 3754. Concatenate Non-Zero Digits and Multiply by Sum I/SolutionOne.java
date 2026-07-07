
public class SolutionOne {

    private static long reverse(long n) {
        long tmp = 0;
        for (; n > 0; n /= 10) {
            tmp = tmp * 10 + n % 10;
        }
        return tmp;
    }

    public static long sumAndMultiply(int n) {
        long x = 0, sum = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit != 0) {
                x = x * 10 + digit;
                sum += digit;
            }
        }

        return reverse(x) * sum;
    }

    public static void main(String[] args) {
        System.out.println(sumAndMultiply(21));
    }
}
