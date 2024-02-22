import java.util.HashMap;
import java.util.Map;

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
    private HashMap<Integer, JudgeChecker> trustMap;

    public void initHashMap() {
        trustMap = new HashMap<>();
    }

    public void setTrustSomeone(int srcTrustPerson) {
        if (trustMap.containsKey(srcTrustPerson) == false) {
            JudgeChecker checker = new JudgeChecker(1, true);
            trustMap.put(srcTrustPerson, checker);
        } else {
            trustMap.get(srcTrustPerson).setTrustSomeone();
        }
    }

    public void increaseBeTrusted(int beTrustedPerson) {
        if (trustMap.containsKey(beTrustedPerson) == false) {
            JudgeChecker checker = new JudgeChecker(1);
            trustMap.put(beTrustedPerson, checker);
        } else {
            trustMap.get(beTrustedPerson).incraseBeTrusted();
        }
    }

    public int checkJudge(int n) {
        for (Map.Entry<Integer, JudgeChecker> entry : trustMap.entrySet()) {
            if (entry.getValue().isJudge(n)) {
                return entry.getKey();
            }
        }
        return -1;
    }


    public int findJudge(int n, int[][] trust) {

        if (n == 1 && trust.length == 0) {
            return 1;
        }

        initHashMap();
        for (int[] t : trust) {
            setTrustSomeone(t[0]);
            increaseBeTrusted(t[1]);
        }
        return checkJudge(n);
    }
}

