n,d = map(int,raw_input().split())
l = map(int,raw_input().split())
p = l[n-1]
k = l[0]
if n==1 or n==2:
    print 0
else:
    i = 0
    j = n-1
    ans = 0
    while(l[j]-l[i]>d and j-i>1):
        i+=1
        if i>=n-1:
            break

    no = j-i-1
    # print no,i
    ans+=(no*(no+1))/2
    j-=1
    while(j>=2):
        while(i>0 and l[j]-l[i]<=d):
            i-=1
        if l[j]- l[i]>d:
            i+=1
        no = j-i-1
        # print no,i,j
        ans+=(no*(no+1))/2
        j-=1
    print ans


# while done==0:
#     for i in range(n-2,-1,-1):
#         print l[i],i,l[i]-p,p-l[i]>=d
#         if p-l[i]>=d:
#             temp = i
#             break
#     done  = 1
# print temp
# if temp==-1:
#     print ans
# else:
#     j = n-1
#     i = temp
#     no = j-i-1
#     no2 = n-2
#     k1= (no2*(no2+1))/2
#     k2 = ((no-1)*(no))/2
#     ans+=(k1-k2)
#     while(True):
#         j-=1
#         while(l[i]-l[j]<d):
#             i-=1
#             if i<0:
#                 break
#
#         if i<0:
#             break
#         no = j-i-1
#         no2 = j-1
#         k1= (no2*(no2+1))/2
#         k2 = ((no-1)*(no))/2
#         ans+=(k1-k2)
#     print ans
