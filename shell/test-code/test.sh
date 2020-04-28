#!/bin/bash
echo "Hello World!"
my_name="myron"
echo ${my_name}
readonly my_name
echo "print name ${my_name}"
string="runoob is great site"
echo ${string:2:4}
echo `expr index "$string" io`
array_name=(v0 v1 v2 v3 v4)
array_name[5]=v5
value=${array_name[2]}
echo $value
echo ${array_name[@]}
length_array=${#array_name[@]}
echo ${length_array}
#:<<EOF
echo "有没有注释"
#EOF
echo "shell 传递参数实例！";
echo "执行文件名：$0";
echo "First parameter: $1";
echo "Second parameter: $2";
echo "参数个数: $#\n所有脚本参数: $*====进程ID: $$\n所有脚本参数: $@\n当前选项: $-\n最后退出状态: $?";
for i in "$*";do
	echo $i
done
for i in "$@";do
	echo $i
done
a=10
b=20
val=`expr $a+$b`
echo $val

val=`expr $a + $b`
echo "a + b : $val"
if [ $a == $b ]
then
	echo "恒等"
fi
if [ $a != $b ]
then
	echo "不恒等"
fi
read name
echo "$name it is a test" > myfile
echo `date`
printf "%-10s %-8s %-4s\n" 姓名 性别 体重
wc -l users
wc -l < users

wc -l << EOF
	learning
	good
EOF
cat << EOF
hunayinghuanying
wwww
EOF
