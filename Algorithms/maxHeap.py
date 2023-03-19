class MaxHeap:

    def __init__(self):
        self.heap = []
        self.len = 0

    def insert(self, i_val):
        self.heap.append(i_val)
        self.len += 1
        ix = self.len - 1
        while ix > 0:
            if self.heap[ix] > self.heap[(ix - 1) // 2]:
                self.heap[ix], self.heap[(ix - 1) // 2] = self.heap[(ix - 1) // 2], self.heap[ix]
                ix = (ix - 1) // 2
            else:
                break
        
    def sink(self, ix=0):
        left = 2 * ix + 1
        right = 2 * ix + 2
        if left < self.len and right < self.len:
            if self.heap[ix] < self.heap[left] or self.heap[ix] < self.heap[right]: 
                if self.heap[left] < self.heap[right]:
                    self.heap[ix], self.heap[right] = self.heap[right], self.heap[ix]
                    self.sink(right)
                else:
                    self.heap[ix], self.heap[left] = self.heap[left], self.heap[ix]
                    self.sink(left)
        elif right < self.len:
            if self.heap[ix] < self.heap[right]:
                self.heap[ix], self.heap[right] = self.heap[right], self.heap[ix]
                self.sink(right)
                    
        elif left < self.len:
            if self.heap[ix] < self.heap[left]:
                self.heap[ix], self.heap[left] = self.heap[left], self.heap[ix]
                self.sink(left)
        else:
            return

    def popMax(self):
        f = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.len -= 1
        self.sink()
        return f

    def __str__(self):
        return f"{self.heap}"


if __name__ == "__main__":
    ar = [-15,5,3,-17,-10,84,21,19,-6,0,-22,9,18,2,43,90,56,-1,21,36]
    print(f"sample array: {ar}")
    hp = MaxHeap()
    for x in ar:
        hp.insert(x)
    print("Extracing max values")
    for _ in range(len(ar)):
        print(f"{hp.popMax()} <- {hp}")
