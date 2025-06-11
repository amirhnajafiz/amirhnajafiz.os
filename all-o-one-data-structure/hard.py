class AllOne:

    def __init__(self):
        self.map = {}   

    def inc(self, key: str) -> None:
        if not key in self.map:
            self.map[key] = 1
        else:
            self.map[key] += 1

    def dec(self, key: str) -> None:
        self.map[key] -= 1
        if self.map[key] == 0:
            del self.map[key]

    def getMaxKey(self) -> str:
        if len(self.map) == 0:
            return ""
        
        maxVal = max(self.map.values())
        for key in self.map.keys():
            if self.map[key] == maxVal:
                return key

    def getMinKey(self) -> str:
        if len(self.map) == 0:
            return ""
        
        minVal = min(self.map.values())
        for key in self.map.keys():
            if self.map[key] == minVal:
                return key

# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
