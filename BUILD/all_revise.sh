#!/bin/bash
echo ""
echo "修改学生信息记录次数"
cat ../log/log.log | grep "修改学生" | wc -l
echo ""
echo "修改课程信息记录次数"
cat ../log/log.log | grep "修改课程" | wc -l
echo ""
