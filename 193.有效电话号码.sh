#!/bin/bash
###
 # @Author: jklash
 # @Description: 有效电话号码
 # @Date: 2021-12-09 14:02:41
 # @LastEditors: jklash
 # @LastEditTime: 2021-12-09 14:05:57
### 
# @lc app=leetcode.cn id=193 lang=bash
#
# [193] 有效电话号码
#

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.
grep -P '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt
# @lc code=end

