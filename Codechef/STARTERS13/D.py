t = int(input())
for _ in range(t):
    # a, b= map(int,input().split())
    # a = int(input())
    # b = int(input())
    s = input()
    arr = s.split()
    a = int(arr[0])
    b = int(arr[1])
    temp  = b
    pos = True
    for i in range(50):
        if(temp % a == 0):
            pos = False
            break
        temp = temp * b

    if(pos):
        print("NO")
    else:
        print("YES")
