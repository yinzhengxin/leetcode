package main

import "fmt"

type Record struct {
	Typ   int
	Money int
	Time  int
}

func intputRecord() (subway []Record, bus []Record) {
	// 读取行数
	row := 0
	fmt.Scanf("%d\n", &row)
	// 读取数据
	for range row {
		var typ, money, ti int
		fmt.Scanf("%d %d %d\n", typ, money, ti)
		switch typ {
		case 0:
			subway = append(subway, Record{Typ: 0, Money: money, Time: ti})
		case 1:
			bus = append(bus, Record{Typ: 1, Money: money, Time: ti})
		}
	}
	fmt.Println(subway, bus)
	return subway, bus
}

func main() {
	intputRecord()
}
