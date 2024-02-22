class JudgeChecker {
    private int be_trusted;
    private boolean trust_someone;


    public JudgeChecker() {
        this.be_trusted = 0;
        this.trust_someone = false;
    }

    public JudgeChecker(int be_trusted) {
        this.be_trusted = be_trusted;
        this.trust_someone = false;
    }

    public JudgeChecker(int be_trusted, boolean trust_someone) {
        this.be_trusted = be_trusted;
        this.trust_someone = trust_someone;
    }

    public void incraseBeTrusted() {
        be_trusted++;
    }

    public void setTrustSomeone() {
        trust_someone = true;
    }

    public boolean isJudge(int personNumber) {
        if (be_trusted == personNumber - 1 && trust_someone == false) {
            return true;
        }
        return false;
    }


}

class Solution {
    public int findJudge(int n, int[][] trust) {

        if (n == 1 && trust.length == 0) {
            return 1;
        }

        HashMap<Integer, JudgeChecker> trustMap = new HashMap<>();
        for (int[] t : trust) {
            if (trustMap.containsKey(t[0]) == false) {
                trustMap.put(t[0], new JudgeChecker(1, true));;
            } else {
                trustMap.get(t[0]).setTrustSomeone();
            }

            if (trustMap.containsKey(t[1]) == false) {
                trustMap.put(t[1], new JudgeChecker(1));
            } else {
                trustMap.get(t[1]).incraseBeTrusted();
            }
        }

        for (Map.Entry<Integer, JudgeChecker> entry : trustMap.entrySet()) {
            if (entry.getValue().isJudge(n)) {
                return entry.getKey();
            }
        }

        return -1;
    }
}

