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
