import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            List<Integer> indexList = map.get(nums[i]);
            if (indexList == null) {
                indexList = new ArrayList<>();
            }
            indexList.add(i);
            map.put(nums[i], indexList);
        }

        for (int key : map.keySet()) {
            int remainKey = target - key;
            List<Integer> remainValues = map.get(remainKey);

            if (remainValues == null) {
                continue;
            }
            if (remainKey == key) {
                return new int[]{map.get(key).get(0), map.get(key).get(1)};
            }

            return new int[]{map.get(key).get(0), remainValues.get(0)};

        }


        return null;
    }
}





class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
    }

    public static void checkAnswer(int[] result, int[] expected) {
        System.out.println("result: " + Arrays.toString(result));
        System.out.println("expected: " + Arrays.toString(expected));

        if (Arrays.equals(result, expected)) {
            System.out.println("Testcase is Passed!");
        } else {
            System.err.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        final int[] result = new Solution().twoSum(nums, target);
        final int[] expected = {0, 1};

        System.out.println("Hello TestCase1!");
        checkAnswer(result, expected);
    }

    public static void testcase2() {
        int[] nums = {3, 2, 4};
        int target = 6;

        final int[] result = new Solution().twoSum(nums, target);
        final int[] expected = {1, 2};

        System.out.println("Hello TestCase2!");
        checkAnswer(result, expected);
    }

    public static void testcase3() {
        int[] nums = {3, 3};
        int target = 6;

        final int[] result = new Solution().twoSum(nums, target);
        final int[] expected = {0, 1};

        System.out.println("Hello TestCase3!");
        checkAnswer(result, expected);
    }
}