class Queue(object):
    def __init__(self):
        self.items=[]

    def isEmpty(self):
        return not bool(self.items)
    
    def enqueue(self ,item):
        self.items.insert(0,item)

    def dequeue(self):
        value = self.items.pop()
        if value is not None:
            return value
        else:
            print("queue is empty")

    def size(self):
        return len(self.items)
    def peek(self):
        if self.items:
            return self.items[-1]
        else:
            ("queue is empty")

    def __repr__(self):
        return repr(self.items)


if __name__ == "__main__":
    queue = Queue()
    print("Is Queue empty?".format(queue.isEmpty()))

    print("queue insert number 0~9")
    for i in range(10):
        queue.enqueue(i)
    print("queue size: {0}".format(queue.size()))
    print("peek".format(queue.peek()))
    print("dequeue".format(queue.dequeue()))
    print("peek".format(queue.peek()))
    print("Is Queue empty?".format(queue.isEmpty()))
    print("queue size: {0}".format(queue.size()))
    print(queue)
