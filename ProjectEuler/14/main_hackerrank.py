MAXN = 5000003

def calculate_collatz(hash_memory, num):
    if num < MAXN and hash_memory[num] != 0 :
        return hash_memory[num]

    result = 0
    if num % 2 == 0:
        result = 1 + calculate_collatz(hash_memory, num // 2)
    else:
        result = 2 + calculate_collatz(hash_memory, (3*num+1)//2)
    if num < MAXN:
        hash_memory[num] = result

    return result

def main():
    hash_memory = [0] * MAXN
    hash_memory[1] = 1
    result_max = [0] * MAXN
   
    for i in range(2, MAXN):
        calculate_collatz(hash_memory, i)

    curr_max  = -1
    curr_max_num = -1
    for i in range(1,MAXN):
        if hash_memory[i] >= curr_max:
            curr_max = hash_memory[i]
            curr_max_num = i
        result_max[i] = curr_max_num 

    for i in range(int(input())):
        n =  int(input())
        print(result_max[n])
main()
