import java.util.*;

class RandomizedSet {

    // 아... Set을 못쓴다.. Set으로는 Random한 값을 O(1) 안에 리턴할 수 없다.
    // HashSet<Integer> set;

    // 해시맵을 사용해 argument로 들어온 값을 키를 저장하고,
    // value에는 해당 키가 담긴 리스트의 인덱스를 저장한다.
    HashMap<Integer, Integer> map;
    // 랜덤 값을 O(1) 안에 리턴하기 위해 리스트를 추가로 사용한다.
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
        // map에 추가할 때, list의 인덱스를 저장한다.
        // 추가되는 리스트의 인덱스는 list의 사이즈이다. (항상 마지막에 추가되기 때문에)
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
            // 중간 항목을 삭제해버리면 남은 항목들의 인덱스를 모두 업데이트 해줘야 하므로
            // 제거할 때 O(n) 시간이 발생한다.
            // 따라서 편법을 사용,
            // 마지막 인덱스의 항목과 삭제할 인덱스의 항목을 교체 및 map에 저장된 마지막 인덱스를 삭제할 인덱스로 교체하고,
            // 마지막 인덱스를 삭제한다.
            // 이렇게 하면 O(1) 시간에 삭제가 가능하다.
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

