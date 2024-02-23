import java.util.*;

class Distance {
    public int node;
    public int price;

    public Distance(int node, int price) {
        this.node = node;
        this.price = price;
    }
}

class Distances {
    private List<Distance> distances;

    public Distances() {
        this.distances = new ArrayList<>();
    }

    public Distances(Distance dist) {
        this.distances = new ArrayList<>();
        add(dist);
    }

    public Distances(int node, int price) {
        this.distances = new ArrayList<>();
        add(node, price);
    }

    public void add(Distance dist) {
        this.distances.add(dist);
    }

    public void add(int node, int price) {
        Distance dist = new Distance(node, price);
        this.distances.add(dist);
    }

    public Distance get(int index) {
        try {
            return this.distances.get(index);
        } catch (IndexOutOfBoundsException e) {
            return null;
        }
    }

    public List<Distance> getAll() {
        return this.distances;
    }
}

class DistancePriceSaver {
    private int[] distPriceSaver;

    public DistancePriceSaver(int n) {
        this.distPriceSaver = new int[n];
        Arrays.fill(this.distPriceSaver, Integer.MAX_VALUE);
    }

    public void set(int index, int value) {
        this.distPriceSaver[index] = value;
    }

    public int get(int index) {
        return this.distPriceSaver[index];
    }

    public int getRefine(int index) {
        if (this.distPriceSaver[index] == Integer.MAX_VALUE) {
            return -1;
        }
        return this.distPriceSaver[index];
    }
}

class Solution {
    private HashMap<Integer, Distances> map;
    private Queue<Distance> queue;
    private DistancePriceSaver saver;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        map = new HashMap<>();
        queue = new LinkedList<>();
        saver = new DistancePriceSaver(n);

        for (int[] flight : flights) {
            if (map.containsKey(flight[0])) {
                map.get(flight[0]).add(flight[1], flight[2]);
                continue;
            }
            Distances dists = new Distances(flight[1], flight[2]);
            map.put(flight[0], dists);
        }

        saver.set(src, 0);
        queue.offer(new Distance(src, 0));
        int via_plane_count = 0;

        while (queue.isEmpty() == false && via_plane_count <= k) {
            via_plane_count++;
            int size = queue.size();
            while (size > 0) {
                size--;

                Distance current = queue.poll();

                if (map.containsKey(current.node) == false) {
                    continue;
                }

                addAdjacent(current);
            }
        }

        return saver.getRefine(dst);
    }

    private void addAdjacent(Distance current) {
        Distances dists = this.map.get(current.node);
        for (Distance distance : dists.getAll()) {
            int adjacent = distance.node;
            int price = distance.price;
            int neighbor_price = price + current.price;

            if (neighbor_price < this.saver.get(adjacent)) {
                this.saver.set(adjacent, neighbor_price);
                Distance tmp = new Distance(adjacent, neighbor_price);
                this.queue.offer(tmp);
            }
        }
    }
}

