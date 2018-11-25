from randy import rand,rand_arr,randomize,norm,norm_arr
from srbIo import printf
from reader import reader

args = reader()
if(len(args)==0):
    t_ = 10
else:
    t_ = int(args[0])


t = t_
print(t)

for test in range(t):
    """
    main test case loop
    """
    n = rand(20)
    k = rand(20)
    print(n,k)


