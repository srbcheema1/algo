from randy import rand,rand_arr,randomize,norm,norm_arr

t = 4
print(t)

for test in range(t):
    n = rand(10)
    print(n)
    for _ in range(n):
        print(rand(50),end = " ")
    print()


