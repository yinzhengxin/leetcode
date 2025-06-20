package main

import "sort"

func groupAnagrams(strs []string) [][]string {
	strsMap := make(map[string][]string)
	for idx := range strs {
		s := []byte(strs[idx])
		sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
		if _, ok := strsMap[string(s)]; !ok {
			strsMap[string(s)] = make([]string, 0)
		}
		strsMap[string(s)] = append(strsMap[string(s)], strs[idx])
	}
	res := make([][]string, 0)
	for _, val := range strsMap {
		res = append(res, val)
	}
	return res
}

func groupAnagrams1(strs []string) [][]string {
	strsMap := make(map[string]int)
	res := make([][]string, 0)
	index := 0
	for idx := range strs {
		s := []byte(strs[idx])
		sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
		sIdx, ok := strsMap[string(s)]
		if !ok {
			strsMap[string(s)] = index
			res = append(res, []string{strs[idx]})
			index++
		} else {
			res[sIdx] = append(res[sIdx], strs[idx])
		}
	}
	return res
}
