import java.util.*;

class RandomizedSet {

    // 아... Set을 못쓴다.. Set으로는 Random한 값을 O(1) 안에 리턴할 수 없다.
    // HashSet<Integer> set;

    HashMap<Integer, Integer> map;
    List<Integer> randList;
    Random rand = new Random();

    public RandomizedSet() {
        this.map = new HashMap<>();
        this.randList = new ArrayList<>();
    }

    public boolean insert(int val) {
        if (this.map.containsKey(val)) {
            return false;
        }
        this.map.put(val, this.randList.size());
        this.randList.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (this.map.containsKey(val) == false) {
            return false;
        }

        int listIndex = this.map.get(val);
        if (listIndex < this.randList.size() - 1) {
            changeIndex(listIndex);
        }

        this.map.remove(val);
        this.randList.remove(this.randList.size() - 1);
        return true;
    }

    private void changeIndex(int listIndex) {
        // 마지막 인덱스를 삭제할 인덱스로 교체하고 마지막 인덱스를 삭제함.
        int lastVal = this.randList.get(this.randList.size() - 1);
        this.randList.set(listIndex, lastVal);
        this.map.put(lastVal, listIndex);
    }


    public int getRandom() {
        int randInt = rand.nextInt(this.randList.size());
        return this.randList.get(randInt);

    }
}

