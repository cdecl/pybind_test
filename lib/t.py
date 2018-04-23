
from sbind import *

t = Item()
t.set(10)
print("public get(): {}".format(t.get()))

t.s = 'test'
print("std::string : {}".format(t.s))

arr = [1,2,3]
t.v = arr
print("vector<int> : {}".format(t.v))


