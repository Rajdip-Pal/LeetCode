
import java.util.ArrayList;
import java.util.List;

public class SolutionOne {

    private static final List<Integer> SEQ_INTEGER_LIST;

    static {
        SEQ_INTEGER_LIST = new ArrayList<>();

        int num = 0;
        for (int i = 1; i < 10; i++) {
            num = num * 10 + i;
            SEQ_INTEGER_LIST.add(num);

            for (int j = 1; j < 10; j++) {
                if (j > i) {
                    num = num * 10 + j;
                    SEQ_INTEGER_LIST.add(num);
                }
            }
            num = 0;
        }

        SEQ_INTEGER_LIST.sort((a, b) -> a.compareTo(b));
    }

    public static List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();

        for (int num : SEQ_INTEGER_LIST) {
            if (num > high) {
                break;
            }

            if (num >= low && num <= high) {
                ans.add(num);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(sequentialDigits(10, 1000));
    }
}
