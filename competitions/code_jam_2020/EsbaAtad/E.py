#!/usr/bin/env python3
import sys
queries = 0

def complement(num):
    if num == '0':
        return '1'
    else:
        return '0'

def query(num):
    print(num)
    sys.stdout.flush()
    ans = input()
    global queries
    queries += 1
    return ans

def main():
    tc, b_size_original = map(int, input().split(' '))
    for _ in range(tc):
        global queries
        queries = 0
        b = ['-1'] * (b_size_original)
        b.append('-1') # adjusting to one indexing
        b_size = b_size_original + 1
        same = ()
        diff = ()
        pos = 1
        while queries < 150 :
            bit = query(pos)
            b[pos] = bit
            if queries != 1 and queries % 10 == 1:
                if diff and not same:
                    diff_original_pos = diff[0]
                    diff_original_value = diff[1]
                    diff_new_value = query(diff_original_pos)
                    if diff_new_value != diff_original_value:
                        for i in range(1,pos+1):
                            b[i] = complement(b[i])
                            b[b_size-i] = complement(b[b_size-i])
                elif same and not diff:
                    same_original_pos = same[0]
                    same_original_value = same[1]
                    same_new_value = query(same_original_pos)
                    if same_original_value != same_new_value:
                        for i in range(1,pos+1):
                            b[i] = complement(b[i])
                            b[b_size-i] = complement(b[b_size-i]) 
                else:
                    diff_original_pos = diff[0]
                    same_original_pos = same[0]
                    diff_original_value = diff[1]
                    same_original_value = same[1]
                    diff_new_value = query(diff_original_pos)
                    same_new_value = query(same_original_pos) 
                    if same_new_value != same_original_value and diff_new_value != diff_original_value:
                        for i in range(1,pos+1):
                         b[i] = complement(b[i])
                         b[b_size-i] = complement(b[b_size-i]) 
                    elif same_new_value == same_original_value and diff_new_value != diff_original_value:
                     for i in range(1,pos+1):
                        b[i], b[b_size-i] = b[b_size-i] , b[i]
                    else:
                        for i in range(1,pos+1):
                            b[i], b[b_size-i] = b[b_size-i] , b[i]
                            b[i] = complement(b[i])
                            b[b_size-i] = complement(b[b_size-i])

            mirrowBit = query(b_size - pos)
            b[b_size-pos] = mirrowBit
            if not same and mirrowBit == bit:
                same = (pos,bit)
            if not diff and mirrowBit !=  bit:
                diff = (pos,bit)
            
            if b.count('-1') == 1:
                break

            pos += 1

        print(''.join(b[1::]))
        sys.stdout.flush() 
        judgeAns = input()
        if(judgeAns == 'N'): 
            return
        
main()
