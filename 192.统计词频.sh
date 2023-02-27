#!/bin/bash

###
 # @Author: jklash
 # @Description: 统计词频
 # @Date: 2021-12-09 11:13:30
 # @LastEditors: jklash
 # @LastEditTime: 2021-12-09 13:41:04
### 

# @lc app=leetcode.cn id=192 lang=bash
#
# [192] 统计词频
#

# @lc code=start
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n'| sort | uniq -c | sort -r | awk '{print $2, $1}'
# @lc code=end

