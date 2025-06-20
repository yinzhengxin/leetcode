package main

import (
	"fmt"
	"sort"
)

type Record struct {
	Typ   int
	Money int
	Time  int
	Used  bool // 优惠券是否使用
}

// 这里其实考虑不按顺序。而且是先把数据读完之后，再进行计算。
func intputRecord() (subway []Record, bus []Record) {
	// 读取行数
	row := 0
	fmt.Scanf("%d\n", &row)
	// 读取数据
	for i := 0; i < row; i++ {
		var typ, money, ti int
		fmt.Scanf("%d %d %d\n", &typ, &money, &ti)
		switch typ {
		case 0:
			subway = append(subway, Record{Typ: typ, Money: money, Time: ti, Used: false})
		case 1:
			bus = append(bus, Record{Typ: typ, Money: money, Time: ti})
		}
	}
	sort.Slice(subway, func(i, j int) bool { return subway[i].Time < subway[j].Time })
	sort.Slice(bus, func(i, j int) bool { return bus[i].Time < bus[j].Time })
	return subway, bus
}

func main() {
	// 输入 数据
	subway, bus := intputRecord()
	//fmt.Println(subway, bus)
	// 逻辑计算 money
	money := 0
	begin := 0
	for i := 0; i < len(bus); i++ {
		moneyFlag := false
		logicFlag := false
		for j := begin; j < len(subway); j++ {
			// 公交时间 小于 遍历的地铁最小时间
			if bus[i].Time < subway[j].Time {
				//fmt.Println("直接付钱 bus:", bus[i])
				moneyFlag = true
				money += bus[i].Money
				break
			}
			// 找到了满足时间的  地铁
			if bus[i].Time-subway[j].Time >= 0 && bus[i].Time-subway[j].Time <= 45 {
				// 首次找到的时候，设置一下flag 和 begin，使下一次bus的遍历变少
				if !logicFlag {
					logicFlag = true
					begin = j
				}
				// 满足条件则进行 money计算
				if !subway[j].Used && bus[i].Money <= subway[j].Money {
					// 用优惠券
					//fmt.Println("使用优惠卷：", subway[j])
					moneyFlag = true
					subway[j].Used = true
					break
				}
			}
			// 遍历到 不满足时间的 地铁记录。提前结束循环
			if logicFlag && bus[i].Time-subway[j].Time > 45 {
				moneyFlag = true
				money += bus[i].Money
			}
		}
		if !moneyFlag {
			money += bus[i].Money
		}
	}
	for i := 0; i < len(subway); i++ {
		money += subway[i].Money
	}
	fmt.Println(money)
}
