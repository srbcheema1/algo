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

def get_str():
    l = rand(7)
    string = "1"
    for a in range(l-1):
        b = rand(2)
        if(b==1):
            string +="0"
        else:
            string +="1"
    return string

for test in range(t):
    """
    main test case loop
    """
    n = 5
    q = 3
    print(n,q)
    for _ in range(n):
        string = get_str()
        print(string)

    for _ in range(q):
        l = rand(n-2)
        r = rand(l,n)
        string = get_str()
        print(l,r,string)

