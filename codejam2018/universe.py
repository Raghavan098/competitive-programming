def get_damage(s,n):
    curr_d = 1
    curr_shoot = 0
    total = 0
    for i in range(n):
        if s[i]=='S':
            curr_shoot = curr_d
            total+=curr_d
        else:
            curr_d*=2

    return total

def do_something(s,n):
    s = list(s)
    ans = ""
    for i in s:
        ans+=i
    for i in range(n-1,0,-1):
        if s[i]=='S' and s[i-1]=='C':
            s[i],s[i-1] = s[i-1],s[i]
            ans = ""
            for j in s:
                ans+=j
            return ans
    return ans
t = input()
for t1 in range(1,t+1):
    d,s = raw_input().split()
    d = int(d)
    n = len(s)
    count = 0
    curr_d = get_damage(s,n)
    while curr_d>d:
        count+=1
        s = do_something(s,n)
        temp_damage = get_damage(s,n)
        if temp_damage==curr_d:
            break
        else:
            curr_d = temp_damage
    ti = "Case #"+str(t1)+":"
    if curr_d<=d:
        print ti,count
    else:
        print ti,"IMPOSSIBLE"
