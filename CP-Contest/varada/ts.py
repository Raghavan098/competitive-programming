import random

for ts in range(21, 30):
    n = 100000
    q = 100000
    l = []
    for i in range(n):
        l.append(random.randint(10000, 20000))
    k = []
    for i in range(q):
        k.append(random.randint(500000000, 1000000000))
    f = open(("input" + str(ts) + ".txt"),"w")
    f.write(str(n) + " " + str(q) + "\n")
    for j in l:
        f.write(str(j) + " ")
    f.write("\n")
    for j in k:
        f.write(str(j) + " ")
    f.write("\n")
    f.close
