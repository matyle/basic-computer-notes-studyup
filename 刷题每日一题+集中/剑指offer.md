

### 面试题15
二进制中1的个数
注意点：
- 移位操作
- 输入负数 （不要直接移位输入的数）,使用一个无符号数移动

方法二：一个整数减去1，然后再和原整数做与运算，会把该整数最右边的1变成0
利用 n = n & (n - 1)


### 面试题16 数值的整数次方
最简单的思路就是：
将指数作为循环的次数，每次乘基数

有两个问题：
- 指数为负数怎么办？
- 底数为0
