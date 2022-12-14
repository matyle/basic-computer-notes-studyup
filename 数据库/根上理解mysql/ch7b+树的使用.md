## 索引的代价

空间的代价：b+树索引的空间



时间的代价：增，删，改的过程中的对树调整的时间代价





## B+树适用的条件

b+树为啥不是万能的？

什么时候用不上索引？就没必要建立索引

### 全值匹配

搜索条件列和联合索引的列一致，称为全值匹配

查询顺序无关：优化器

### 匹配左边列

什么时候无法使用联合索引？

为什么搜索条件必须出现左边的列，才能使用b+树索引

搜索条件各个列必须是联合索引中从最左边连续的列

- (a,b,c)的索引，如果搜索条件是b，那么无法使用这个联合索引，因为b本身是在a相同的基础上排序，而a不同时b很可能是无序的



### 匹配列前缀

字符串的比较是按前缀一个一个比较

使用%搜索时，如果是as%可以使用索引，因为是按前缀排序，而如果是%as%则只能全表扫描了



### 匹配范围值

由于是排序，因此查找范围也很方便

注意联合索引进行范围查找

- 如果有多个条件列，只能用上联合索引最左边的索引。
- 因为联合索引右边的列，要在左边列相等的基础上才有序，因此范围查找并不能使用



### 精确匹配某一列并范围匹配领一列

联合索引(a,b,c)

- 精确匹配最左边的列a， 此时右边的列b在左边相等的情况是有序的，因此可以使用索引
- 而c的条件不能用使用索引，因为b是范围查找



### 索引用于排序

在mysql中，内存中或者磁盘的排序方式统称为文件排序（如果在磁盘排序那么就是更慢了）。



注意事项：

- order by列的顺序必须和联合索引顺序相同

不可使用索引排序的集中情况



### 索引用于分组



## 回表的代价

使用二级索引查找之后，需要查找其他列此时需要回表（通过聚簇索引去查）

访问非聚簇索引使用顺序IO（有序），而回表访问聚簇索引为随机IO（性能更差）

- 回表的记录越多，性能越差

什么时候该使用二级索引？什么时候还不如直接全表扫描？

- 当查询记录过多的时候 例如使用select \*取全表数据，而没用使用limit，此时还不如全表扫描

### 覆盖索引

为了告别回表的代价，少用select \* ,尽量选择只包含索引列的数据

这样可以使用到覆盖索引

## 如何挑选索引

### 只为搜索，排序和分组的列创建索引

### 考虑列的基数

列的基数是指：某一列中不重复的数据的个数

- 列的基数越大（越分散），说明不重复的数据越多，此时索引效果较好

- 列的基数越小（越集中），说明重复数据多，此时索引效果可能不好

  例如基数=1，全部值都一样，索引自然没用，都是一样的没办法快速查找



### 索引列的类型尽量小

这也是使用自增ID的原因之一，自增ID类型小，且插入时用有序，不会造成页分裂调整



### 索引字符串的前缀

为了减少字符串类型索引的内存占用以及匹配速度，只使用前缀

前缀对排序的映像

### 让索引列在比较表达式单独出现

如果my_col是索引,

1. my_col * 2 < 4 使用不了索引
2. my_clo < 4 / 2 可以使用索引

### 主键插入顺序

最好让主键使用auto_increment,自动生成主键，而不是我们手动插入（避免主键忽大忽小）



### 冗余和重复的索引





 

