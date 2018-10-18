#!/bin/bash
echo ""
read -p "请输入学号：" num
line=`cat ../log/log.log | grep "修改学生$num" |wc -l`
if [ 0 -eq $line ]
then
	echo "无"
else
	cat ../log/log.log | grep "修改学生$num"
fi
echo ""
