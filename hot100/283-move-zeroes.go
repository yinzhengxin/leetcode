package main

// 找到非0的数，进行交换
func moveZeroes(nums []int){
	left,right := 0,0
	for right<len(nums){
		if nums[right] != 0{
			nums[right],nums[left] = nums[left],nums[right]
			left++
		}
		right++
	}
}


// 找到0的数，进行交换
func moveZeroes1(nums []int) {
	left, right := 0, 0
	for i := range nums {
		if nums[i] != 0 {
			continue
		}

		// 找到为0时的 index
		left = i
		if right < left {
			right = left
		}

		// left开始找到非0的数，进行交换
		for ; right < len(nums); right++ {
			if nums[right] != 0 {
				nums[left], nums[right] = nums[right], nums[left]
				break
			}
		}
	}
}
