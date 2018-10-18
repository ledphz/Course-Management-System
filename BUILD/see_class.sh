#!/bin/bash
echo ""
read -p "请输入课程号：" num
line=`cat ../log/log.log | grep "修改课程$num" |wc -l`
if [ 0 -eq $line ]
then
	echo "无"
else
	cat ../log/log.log | grep "修改课程$num"
fi
echo ""
