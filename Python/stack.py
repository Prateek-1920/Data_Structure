class Stack:
    def __init__(self):
        self.items = []

    def push(self,item):
        self.items.append(item)

    def pop(self):
        if self.items is not None:
            return self.items.pop()
        else:
            print("Empty stack")

    def show(self):
        for i in self.items:
            print(i)


if __name__=='__main__':
    s = Stack()
    s.push(10)
    s.push(20)
    s.push(30)
    s.push(40)
    s.show()

