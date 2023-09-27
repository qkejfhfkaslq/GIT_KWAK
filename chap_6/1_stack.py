class Stack(object):
    def __init__(self):
        self.items=[]

    def isEmpty(self):
        return not bool(self.items)
    
    def push(self,value):
        self.items.append(value)

    def pop(self):
        value = self.items.pop()
        if value is not None:
            return value
        else:
            print("Stack is Empty")

    def size(self):
        return len(self.items)
    
    def peek(self):
        if self.items:
            return self.items[-1]
        else:
            print("Stack is Empty")


    def __repr__(self):
        return repr(self.items)


if __name__=="__main__":
    stack = Stack()
    print("is stack empty?{0}".format(stack.isEmpty()))
    print("stack import 0~9")

    for i in range(10):
        stack.push(i)

    print("stack size:{0}".format(stack.size()))
    print("peek:{0}".format(stack.peek()))
    print("pop:{0}".format(stack.pop()))
    print("peek:{0}".format(stack.pop()))
    print("is stack empty?{0}".format(stack.isEmpty()))

    print(stack)

