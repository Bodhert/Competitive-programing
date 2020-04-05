def main():
    for tc in range(int(input())):
        schedule = []
        for n in range(int(input())):
            start, end =  map(int,input().split(' '))
            schedule.append((n, start, end))
        
        schedule.sort(key=lambda x: x[1])
            
        ans = []
        c_lastpos = -1
        j_lastpos = -1
        # print(schedule)
        for activity in schedule:
                if c_lastpos <= activity[1]:
                    ans.append(('C',) + activity)
                    c_lastpos = activity[2]
                elif j_lastpos <= activity[1]:
                    ans.append(('J',) + activity) 
                    j_lastpos = activity[2]
        
    
        if len(ans) == len(schedule):
            organize_out = [None] * len(ans)
            for char, pos, _ , _ in ans:
                # print(char)
                organize_out[pos] = char
            # print(organize_out)
            print('Case #{0}: {1}'.format(tc+1,''.join(organize_out)))
        else:
            print('Case #{0}: {1}'.format(tc+1,'IMPOSSIBLE'))
main()
