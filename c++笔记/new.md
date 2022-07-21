#

##

### 函数定义

不要将函数定义或变量声明放在头文件中，因为当其他文件include该函数时，会对该函数重复定义或该变量声明两次，将出错，除非是内联函数。

头文件中：

- 函数原型
- 使用#define或const定义的符号常量
- 结构声明（并不会真正的创建变量）
- 类声明
- 模版声明
- 内联函数（定义可以放到头文件中）



### 存储持续、作用域和链接性

存储持续：

- 自动存储：函数定义中声明的变量，在开始执行所属的函数或代码块时被创建。使用完毕被释放
- 静态存储：在函数定义外定义的变量和使用关键字static定义的变量，它们在程序整个运行过程中存在，即使该static在某一个局部声明，也同样是。
- 线程存储：
- 动态存储：使用new运算符分配的，一直存在直到delete运行结束。

作用域：函数中定义的函数只能在函数中使用。在函数之外定义的变量可以在函数间共享。

链接：链接性为外的可以在文件间共享，为内的只能在本文间函数共享。


### 静态持续性、内部链接性

> 将static限定符用于作用域为整个文件的变量时，该变量的链接性将为内部的。在多文件中，内部链接性和外部链接性之间差别很重要。

链接性为内部的变量只能在所属文件中使用。但常规外部变量都具有外部链接性，即可在其他文件中使用。 

静态在局部函数中时，假如在函数中初始化了该变量，则第二次调用该函数时，该变量不会再次初始化。

### cv:c-const,v-volatile

- mutable, 即使某个成员为const，也可以被修改。
- volatile：不让他防到
- const：c++中const的全局变量链接为内部的，就像static一样。

c++的全局变量链接为内部的，也就是说把const全局变量放到源文件之后，当多个文件include该头文件之后，所有的源文件都会有这样的定义：

```c++
const int fingers = 10;

```

假设该变量为外部的，多次这样定义便会出错，因为全局变量智能定义一次，其他必须extern外部引入。也就是说const的全局变量每一份文件也有。

函数存储为静态的，链接性为外部的。
static的函数，链接性为内部的，只能在当前文件中使用，

### 语言的链接性

```c++

extern "C" void spiff(int); // 使用c风格的函数
extern void spoff(int); // 默认使用c++
extern "C++" void spaff(int);
```





















### 动态分配

> 之前的c++在new失败之后，会返回空指针，目前会返回std::bad_alloc

- 常规动态分配：这种括号类的也可以用于有构造函数的类。

```c++

int *pi = new int(6);
double *pd = new double(99.99); //

```

- 对于结构或数组：需要使用大括号进行列表初始化。c++11中可以这样。

```c++

struct where {double x; double y; double z;};
where *one = new where{2.5, 3.6, 4.7};
int *ar = new int[4]{2, 4, 6, 7};

// 初始化值 c++11
int *pin = new int {6};
double *pd = new double {99.99};

```

new和new[]分别调用

```c++

void *operator new(std::size_t);
void *operator new[](std::size_t);

```

定位问题，定位可以申请内存至一段内存之内。


```c++
const int N = 5;
const int BUF = 512;
char buffer[BUF]; // 静态内存

double *p1, *p2;
cout << "Calling new and placement new:" << endl;
p1 = new double [N];
p2 = new (buffer) double [N];

delete []p1;
    
// delete []p2; // delete 不能用来释放定位的运算符，该地方的内存为静态内存。
```

