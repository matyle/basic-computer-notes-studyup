1.局部变量的指针和局部指针变量是两个不同概念

2.局部变量在函数体结束后生命期也结束，它的指针（即它的地址）是无效变量的地址，所以函数不能返回这种地址值
3，局部指针变量在函数结束后生命期也结束，但它指向的变量或函数或任何存储实体的生命期没有结束，函数返回的指针（地址）就是有效的
例1：
```c
int *func()
{
   int x;
   ...
   return &x;/*返回局部变量的地址--无效*/
}
例2.
int *max(int a[],int n)
{
   int *p=a[0];
   int i;
   for(i=1;i<n;i++)
   {
       if(*p<a[i])
            p=&a[i];/*p指向更大的数*/
   ｝
   return p;
}/*尽管p变量生命期结束了，但函数返回它的值，是实参数组中最大元素的地址，这个地址--有效*/
```

补充：

```cpp
int *example(int b)
{
     int c = 5;
     b += c;
     return &b;   //hi出错的。b是被调用函数的局部变量，是实参的副本。它的地址在调用结束后是无效的。这个不同于上面形参为数组的例子。
 }

char* get_str()
{
    char *str = {"abcd"};   //可以，因为"abcd"是一个字符串常量，它并不在一个栈空间上，而是在静态存储区上，程序结束后由系统释放。
    //char str[] = {"abcd"};   //错误,结果不确定，str指向的是栈空间上内存。会在调用完后变为无效。注意和char*的区别。
    return str;
}
```


全局变量和静态变量放在全局区（静态存储区），程序结束后由系统释放。
局部变量放在栈区，由编译器自动分配释放。
动态申请的内存在堆区，一般由程序员分配释放。
