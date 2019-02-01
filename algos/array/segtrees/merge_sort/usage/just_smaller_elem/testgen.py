from code_tester import rand,randomize,reader

args = reader()
if(len(args)==0):
    t_ = 1
    n_ = 10
    q_ = 10
    a_ = 20
else:
    t_ = int(args[0])


t = rand(t_)
# print(t)

for test in range(t):
    """
    main test case loop
    """
    n = rand(n_)
    q = rand(q_)
    print(n,q)
    for _ in range(n):
        print(rand(a_),end=' ')
    print()
    for _ in range(q):
        if(n==1):
            a = rand(1)
        else:
            a = rand(n-1)
        b = rand(a,n)
        k = rand(a_+1)
        print(a,b,k)
