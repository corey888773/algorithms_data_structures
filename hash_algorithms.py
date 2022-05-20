class HashTable:
    def __init__(self, table_size, method, func1=0, func2=0):
        self.table_size = table_size
        self.method_name = method
        self.func1 = func1
        self.func2 = func2

    def instantiate(self):
        if self.method_name == 1:
            return ChainMethod(self.table_size, self.h1)
        elif self.method_name == 2:
            return LinearMethod(self.table_size, self.h1)
        elif self.method_name == 3:
            return QuadraticMethod(self.table_size, self.h1)
        elif self.method_name == 4:
            return DoubleHashMethod(self.table_size, self.h1, self.h2)
        else:
            print("wrong type")

    def h1(self, element):
        return element % self.table_size

    def h2(self, element):
        return element % (self.table_size - 1) + 1


class ChainMethod:

    def __init__(self, table_size, func):
        self.table_size = table_size
        self.func = func
        self.table = self.table = [None for _ in range(table_size)]

    def insert(self, element):
        if self.table[self.func(element)] is None:
            self.table[self.func(element)] = element
            return
        if type(self.table[self.func(element)]) is list:
            self.table[self.func(element)].insert(0, element)
            return
        temp = self.table[self.func(element)]
        self.table[self.func(element)] = []
        self.table[self.func(element)].insert(0, temp)
        self.table[self.func(element)].insert(0, element)

    def search(self, element):
        if type(self.table[self.func(element)]) is list and element in (self.table[self.func(element)]):
            return self.func(element)
        if element == self.table[self.func(element)]:
            return self.func(element)
        return None

    def delete(self, element):
        if element in (self.table[self.func(element)]):
            self.table[self.func(element)].remove(element)

    def print(self):
        print(self.table)


class LinearMethod:
    def __init__(self, table_size, func):
        self.table_size = table_size
        self.func = func
        self.table = self.table = [None for _ in range(table_size)]

    def insert(self, element):
        i = self.func(element)
        while self.table[self.func(i)] is not None:
            i += 1
        self.table[self.func(i)] = element

    def search(self, element):
        i = self.func(element)
        while self.table[self.func(i)] != element:
            i += 1
            if self.table[self.func(i)] is None:
                return None
        return self.func(i)

    def delete(self, element):
        i = self.func(element)
        while self.table[self.func(i)] != element:
            if self.table[self.func(i)] is None:
                return
            i += 1
        self.table[self.func(i)] = "Deleted"

    def print(self):
        print(self.table)


class QuadraticMethod:
    def __init__(self, table_size, func):
        self.table_size = table_size
        self.func = func
        self.table = self.table = [None for _ in range(table_size)]

    def insert(self, element):
        i = self.func(element)
        j = 0
        while self.table[self.func(i)] is not None:
            j += 1
            i = self.func(element) + j * (j+1)
            if j > 10:
                return
        self.table[self.func(i)] = element

    def search(self, element):
        i = self.func(element)
        j = 0
        while self.table[self.func(i)] != element:
            if self.func(i) is None:
                return None
            j += 1
            i = self.func(element) + j*(j+1)
        return self.func(i)

    def delete(self, element):
        i = self.func(element)
        j = 0
        while self.table[self.func(i)] != element:
            if self.func(i) is None:
                return
            j += 1
            i = self.func(element) + j*(j+1)
        self.table[self.func(i)] = "Deleted"

    def print(self):
        print(self.table)


class DoubleHashMethod:
    def __init__(self, table_size, func1, func2):
        self.table_size = table_size
        self.func1 = func1
        self.func2 = func2
        self.table = self.table = [None for _ in range(table_size)]

    def insert(self, element):
        i = self.func1(element)
        while self.table[self.func1(i)] is not None:
            i += self.func2(element)
        self.table[self.func1(i)] = element

    def search(self, element):
        i = self.func1(element)
        while self.table[self.func1(i)] != element:
            if self.table[self.func1(i)] is None:
                return None
            i += self.func2(element)
        return self.func1(i)

    def delete(self, element):
        i = self.func1(element)
        while self.table[self.func1(i)] != element:
            if self.table[self.func1(i)] is None:
                return
            i += self.func2(element)
        self.table[self.func1(i)] = "Deleted"

    def print(self):
        print(self.table)


def input_manager():
    input_string = input()
    input_string = input_string.strip().split()
    table_size = int(input_string.pop(0))
    table_type = int(input_string.pop(0))
    elements = input_string

    table = HashTable(table_size, table_type).instantiate()
    for element in elements:
        table.insert(int(element))
    table.print()

    my_input = input().strip().split()

    while not my_input:
        my_input = input().strip().split()

    my_list = [int(element) for element in my_input]
    x = int(my_list.pop(0))

    while x != -1:
        element = my_list.pop()
        if x == 0:
            table.insert(int(element))
            table.print()
        elif x == 1:
            print(table.search(int(element)))
        else:
            table.delete(int(element))
            table.print()
        my_input = input().strip().split()

        while not my_input:
            my_input = input().strip().split()
        my_list = [int(element) for element in my_input]
        x = my_list.pop(0)


input_manager()
