class ListNode:
    def __init__(self, val: int):
        self.val: int = val
        self.next = None
        self.prev = None

class List:
    def __init__(self):
        self.head: Optional[ListNode] = None
        self.tail: Optional[ListNode] = None
        self.count: int = 0

    def addTail(self, node: ListNode):
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
        self.count += 1

    def add(self, val: int):
        node = ListNode(val)
        self.addTail(node)
        return node

    def removeHead(self) -> int | None:
        if self.head == None:
            return None
        temp: ListNode = self.head
        self.head = self.head.next
        self.head.prev = None
        self.count -= 1
        return temp.val

    def removeNode(self, node: ListNode):
        if node.prev == None:
            self.head = node.next
        else:
            node.prev.next = node.next

        if node.next == None:
            self.tail = node.prev
        else:
            node.next.prev = node.prev

        self.count -= 1

    def size(self) -> int:
        return self.count


# get 시 현재 node 정보를 알고 있어야 O(1) 만에 제거가 가능하다.
# 모를 경우 LRUList를 순회하며 제거해야 하기에 제거 시 O(n)이 걸린다.
class LRUData:
    def __init__(self, value: int, node: ListNode):
        self.value: int = value
        self.node: ListNode = node

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity: int = capacity
        self.CacheTable: Dict[int, LRUData] = {}
        self.lruList = List()


    def get(self, key: int) -> int:
        if key not in self.CacheTable:
            return -1

        removeNode: ListNode = self.CacheTable[key].node
        self.lruList.removeNode(removeNode)
        newNode: ListNode = self.lruList.add(key)
        self.CacheTable[key].node = newNode
        return self.CacheTable[key].value


    def put(self, key: int, value: int) -> None:
        # 이미 존재하는 경우 제거하고 다시 생성
        if key in self.CacheTable:
            self.lruList.removeNode(self.CacheTable[key].node)
            del self.CacheTable[key]

        node: ListNode =self.lruList.add(key)
        self.CacheTable[key] = LRUData(value, node)

        if self.lruList.size() <= self.capacity:
            return

        removeKey: int = self.lruList.removeHead()
        del self.CacheTable[removeKey]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


