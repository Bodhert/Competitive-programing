import math

def main():
    num = int(input())
    if num <= 10:
        print(num)
    else:
        upper_bound = (int(str(num)[0]) + 1) * int('1' + ('0') * (len(str(num))-1) )
        lower_bound = num - int(str(num)[1::])
        # print(upper_bound, lower_bound)
        if upper_bound - num == abs(lower_bound-num):
            print(upper_bound)
        elif (upper_bound - num) < abs(lower_bound - num):
            print(upper_bound)
        else:
            print(lower_bound)
main()
