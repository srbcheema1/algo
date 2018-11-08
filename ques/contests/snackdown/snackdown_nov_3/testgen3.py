from randy import rand,rand_arr,randomize,norm,norm_arr
from srbIo import printf
from reader import reader

args = reader()
if(len(args)==0):
    t_ = 10
else:
    t_ = int(args[0])


t = rand(t_)
print(t)

for test in range(t):
    """
    main test case loop
    """
    i = rand(50)
    a = ""
    print(i)
    for _ in range(i):
        w = rand(2)
        if w == 2:
            a+='#'
        else:
            a+='.'
    print(a)


