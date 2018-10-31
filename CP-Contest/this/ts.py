import random

lis = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
for i in range(15):
    n = random.randint(1, 26);
    l = []
    while(len(l) < n):
        j = lis[random.randint(1,26) - 1]
        if j not in l:
            l.append(j)
    f = open(("input" + str(i) + ".txt"),"w")
    f.write(str(n) + "\n")
    for j in l:
        f.write(j + "\n")
    f.close
