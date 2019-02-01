from code_tester import rand, show, reader, randomize

debug = False

amax = int(10000)
n = rand(5,1000)
q = rand(5,100000)

if(debug):
    amax = 20
    n = 10
    q = 20

print(n,q)

for i in range(n):
    print(rand(amax),end=' ')
print()

for test in range(q):
    """
    main test case loop
    """
    t = rand(0,2)
    a = rand(1,n-3)
    if(t==0):
        b = rand(a,n)
        print(t,a,b)
    if(t==1):
        b = rand(0,amax)
        print(t,a,b)
    if(t==2):
        b = rand(a,n)
        c = rand(1,2)
        print(t,a,b,c)
