from randy import rand,rand_arr,randomize,norm,norm_arr
from srbIo import printf
from reader import reader

args = reader()
if(len(args)==0):
    t_ = 1
else:
    t_ = int(args[0])


t = rand(t_)
# print(t)

for test in range(t):
    """
    main test case loop
    """
    n = rand(10)   
    k = rand(n)
    q = rand(20)
    print(n,q,k)
    for _ in range(n):
        a = rand(2)
        print(a%2,end=' ')
    print()
    string = ""
    for _ in range(q):
        a = rand(2)
        if(a%2):
            string+='!'
        else:
            string+='?'
    print(string)
