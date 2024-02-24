import java.util.*;


class Solution {

    int[] groups;

    private void initializeGroups(int n, int firstPerson) {
        groups = new int[n];
        for (int i = 0; i < n; i++) {
            groups[i] = i;
        }
        groups[firstPerson] = 0;
    }

    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        initializeGroups(n, firstPerson);

        // time 순으로 재정렬하기
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[2], b[2]));

        int timeIndex = 0;
        while (timeIndex < meetings.length) {
            timeIndex = traversalCurrentMettingTime(meetings, timeIndex);
        }

        List<Integer> result = new ArrayList<>();
        for (int person = 0; person < n; person++) {
            // 0 이면 비밀을 알고 있는 것.
            if (isKnowSecret(person)) {
                result.add(person);
            }
        }

        return result;
    }

    private int traversalCurrentMettingTime(int[][] meetings, int timeIndex) {
        List<Integer> temp = new ArrayList<>();
        int currentTime = meetings[timeIndex][2];

        while (timeIndex < meetings.length) {
            // 현재 시간과 같은 시간이 아니면 종료
            if (meetings[timeIndex][2] != currentTime) {
                break;
            }

            int g1 = find(meetings[timeIndex][0]);
            int g2 = find(meetings[timeIndex][1]);
            this.groups[Math.max(g1, g2)] = Math.min(g1, g2);

            temp.add(meetings[timeIndex][0]);
            temp.add(meetings[timeIndex][1]);
            timeIndex++;
        }

        initialNoKnowSecretPerson(temp, timeIndex);
        return timeIndex;
    }

    private void initialNoKnowSecretPerson(List<Integer> temp, int timeIndex) {
        for (int index : temp) {
            if (isKnowSecret(index) == false) {
                this.groups[index] = index;
            }
        }
    }

    private int find(int index) {
        // 0 0 0 0
        // index = 3 groups[3] = 0
        // index = 0 -> return 0
        while (index != this.groups[index]) {
            index = this.groups[index];
        }
        return index;
    }

    private boolean isKnowSecret(int index) {
        if (find(index) == 0) {
            return true;
        }
        return false;
    }





    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
        testcase4();
    }

    public static void checkAnswer(List<Integer> result, List<Integer> answer) {
        System.out.println("Result: " + result.toString());
        System.out.println("Answer: " + answer.toString());

        if (result.equals(answer)) {
            System.out.println("Testcase1 is Passed!");
        } else {
            System.out.println("@@@@@ Testcase1 is Failed! @@@@@");
        }
        System.out.println();
    }

    public static void testcase1() {
        int n = 6;
        int[][] meetings = {{1,2,5},{2,3,8},{1,5,10}};
        int firstPerson = 1;

        List<Integer> result = new Solution().findAllPeople(n, meetings, firstPerson);
        List<Integer> answer = new ArrayList<>(
            Arrays.asList(0, 1, 2, 3, 5)
        );

        checkAnswer(result, answer);
    }

    public static void testcase2() {
        int n = 4;
        int[][] meetings = { { 3,1,3 },{ 1,2,2 },{ 0,3,3 } };
        int firstPerson = 3;

        List<Integer> result = new Solution().findAllPeople(n, meetings, firstPerson);
        List<Integer> answer = new ArrayList<>(
            Arrays.asList(0, 1, 3)
        );

        checkAnswer(result, answer);
    }

    public static void testcase3() {
        int n = 5;
        int[][] meetings = { { 3,4,2 },{ 1,2,1 },{ 2,3,1 } };
        int firstPerson = 1;

        List<Integer> result = new Solution().findAllPeople(n, meetings, firstPerson);
        List<Integer> answer = new ArrayList<>(
            Arrays.asList( 0,1,2,3,4 )
        );

        checkAnswer(result, answer);
    }

    public static void testcase4() {
        int n = 6;
        int[][] meetings = { { 0,2,1 },{ 1,3,1 },{ 4,5,1 } };
        int firstPerson = 1;

        List<Integer> result = new Solution().findAllPeople(n, meetings, firstPerson);
        List<Integer> answer = new ArrayList<>(
            Arrays.asList( 0,1,2,3 )
        );
        checkAnswer(result, answer);
    }

}