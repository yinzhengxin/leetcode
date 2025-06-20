import sys
from collections import deque

# 跟前面go语言不一样的地方是边读边计算。利用了全部 的 时间有序性。
def main():
    # 读数据
    data = sys.stdin.readline().split(' ')
    row = int(data[0])
    deq = deque([])
    cost = 0
    for _ in range(row):
        data = sys.stdin.readline().split(' ')
        typ, money, ts = int(data[0]), int(data[1]), int(data[2])
        if typ == 0:
            deq.append([money,ts])
            cost+=money
        elif typ == 1:
            flag = False
            while len(deq)!=0 and deq[0][1]+45 <ts:
                deq.popleft()
            for d in deq:
                if d[0] >= money:
                    d[0]=0
                    flag =True
                    break
            if flag==False:
                cost+=money
    print(cost)



if __name__=="__main__":
    main()
    # 1. 使用 sys.stdin.readline().split(' ') 读行的数据，split后是列表，且是string类型
    # 2. collections 库中 deque 有 popleft()函数