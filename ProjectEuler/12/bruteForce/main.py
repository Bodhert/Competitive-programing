import math

def total_divisors(n) : 
    count = 0
    for i in range(1, int(math.sqrt(n) + 1)) : 
          
        if (n % i == 0) : 
            
            # Check if divisors are equal 
            if (n / i == i) : 
                count +=1
            else : 
                count += 2
    return count

def main():
    divisors = 1
    i = 1
    while divisors < 500:
        num = (i * (i+1)) // 2
        divisors = total_divisors(num)
        i+=1
        print(i,num,divisors)
    print(i)


main()
