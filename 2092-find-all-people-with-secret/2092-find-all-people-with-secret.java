class Solution {

    int[] groups = new int[100000];

    private void initializeGroups(int n, int firstPerson) {
        for (int i = 0; i < n; i++) {
            groups[i] = i;
        }
        groups[firstPerson] = 0;
    }

    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        List<Integer> temp = new ArrayList<>();

        initializeGroups(n, firstPerson);

        // time 순으로 재정렬하기
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[2], b[2]));

        int timeIndex = 0;
        // System.err.println("ago   groups: " + Arrays.toString(groups));
        while (timeIndex < meetings.length) {
            int currentTime = meetings[timeIndex][2];
            temp.clear();

            while (timeIndex < meetings.length && meetings[timeIndex][2] == currentTime) {
                int g1 = find(groups, meetings[timeIndex][0]);
                int g2 = find(groups, meetings[timeIndex][1]);
                groups[Math.max(g1, g2)] = Math.min(g1, g2);

                temp.add(meetings[timeIndex][0]);
                temp.add(meetings[timeIndex][1]);
                ++timeIndex;
            }

            for (int j = 0; j < temp.size(); ++j) {
                if (find(groups, temp.get(j)) != 0) {
                    groups[temp.get(j)] = temp.get(j);
                }
            }
            // System.err.println("after groups: " + Arrays.toString(groups));
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (find(groups, i) == 0) result.add(i);
        }

        return result;
    }

    private int find(int[] groups, int index) {
        while (index != groups[index]) index = groups[index];
        return index;
    }


}