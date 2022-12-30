[1.如何实现线程安全](#1-C++如何实现线程安全)

[2.需要一个指针,指向一个"元素类型为int"的vector](#2.一个指针指向"元素类型为int" 的vector)







# 1. C++如何实现线程安全

实现线程安全通常有一下集中方法:

1. 使用互斥锁(mutex) : 互斥锁是一种用于保护临界区的同步对象, 它可以防止多个线程同时访问临界区. C++中的互斥锁可以使用 `std::mutex`或者`std::lock_guard`来实现

2. 使用信号量(semaphore): 信号量是一种用于保护临界区的同步对象,它能限制线程对临界区的访问次数.C++中的信号量可以使用`std::semaphore`来实现.

3. 使用读写锁(reader-writer lock) : 读写锁是一种用于保护临界区的同步对象, 它允许多个线程同时读写临界区, 但只允许一个线程写入临界区.C++中的读写锁可以使用`std::shared_mutex`或`std::shared_lock`来实现

4. 使用原子操作(atomic operation): 原子操作是一种在单个操作内完成的操作, 它不会被其他线程打断. C++的原子操作可以使用`std::atomic`来实现.

   

#  2.一个指针指向"元素类型为int" 的vector

````C++
vector<int> *pv  = 0;
pv = &fibonacci;
```
pv = &lucas;
// 这种赋值方式会牺牲程序的透明性
````

另一种方案将每个数列的内存地址存入某个vector中,可以通过索引的方式,透明的访问这些数

```c++
const int seq_cnt = 6;

// 一个指针数组, 大小为seq_cnt
//每个指针都指向vector<int>对象
vector<int> *seq_addres[ seq_cnt ] ={
	&fibonacci, &lucas, &pell , 
	&triangular, &square, &pentagonal
}
```

这样`seq_addrs[0]`所持有的`fibonacci  vector`的地址, `seq_addrs[1]`的值是`lucas vector`的地址

```C++
vector <int> * current_vec = 0;
// ````

for(int ix = 0; ix < seq_cnt; ++ ix){
    current_vec = seq_addrs[ix];
    //要显示的元素都通过current_vec间接访问到
}
```

