from code_tester import rand, show, reader, randomize

amax = int(10000)

n = rand(5,1000)
q = rand(5,100000)
print(n,q)

for i in range(n):
    print(rand(amax),end=' ')
print()

for test in range(q):
    """
    main test case loop
    """
    t = rand(0,1)
    a = rand(1,n-3)
    if(t==0):
        b = rand(a,n)
    else:
        b = rand(1,amax)
    print(t,a,b)
