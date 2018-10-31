s = raw_input()
ca = 0
cb = 0
cc = 0
st =0
st2 = 0
done = 0
for i in s:
    if i=='a' and st==0:
        ca+=1
    elif i=='b' and ca>0 and st==0:
        st =1
        cb+=1
    elif i=='b' and st==1:
        cb+=1
    elif i=='c' and cb>0 and st==1:
        cc+=1
        st=2
    elif i=='c' and st==2:
        cc+=1
    else:
        done = 1
        break

# print ca,cb,cc

if done==0:
    if (cc==ca or cc==cb) and ca>0 and cb>0:
        print "YES"
    else:
        print "NO"
else:
    print "NO"
