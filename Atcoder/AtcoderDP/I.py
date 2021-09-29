def bar(x):
    return 1-x

n = int(input())
coins = list(map(float, input().split()))



ans1 = [0 for i in range(n+1)]
ans2 = [0 for i in range(n+1)]

tails = 1
heads = 1
for i in range(1,n+1):
    for j in range(0,i+1):
        #first case,update ans1
        if(i%2==1):
            if(j==0):
                tails = tails*bar(coins[i-1])
                ans1[j] = tails
            elif(j==i):
                heads = heads*coins[i-1]
                ans1[j] = heads
            else:
                ans1[j] = coins[i-1]*ans2[j-1] + bar(coins[i-1])*ans2[j]
        #second case, update ans2
        else:
            if(j==0):
                tails = tails*bar(coins[i-1])
                ans2[j] = tails
            elif(j==i):
                heads = heads*coins[i-1]
                ans2[j] = heads
            else:
                ans2[j] = coins[i-1]*ans1[j-1] + bar(coins[i-1])*ans1[j]

fans = 0
for i in range(int((n+1)/2),n+1):
    fans = fans + ans1[i]

print(fans)
