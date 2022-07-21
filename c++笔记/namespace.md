### 命名空间

命名空间会增加名称冲突的可能性。

```c++
namespace Jack
{
    double fetch = 30;
    double hill = 10;
    double check;
}
using Jack::hill; // 这里放到外面，则变为全局的变量，同理

//double hill = 2;
double fetch = 2;
void test_namespace(void)
{
//    double fetch;
    using Jack::fetch; // using 声明将名称添加到局部声明区域中，因此该实例避免了将另外一个局部变量也命名
    // 为相同变量，和局部变量一样,也会覆盖同名的全局变量。
}

using namespace Jack; // 使用这个之后，全部里面的值都可以放外面。

using jack::fetch;
using jill::fetch; // using 声明就像普通声明一样，可能会引出二义性。

// 但是当使用 using namespace命名编译指令时，可以被后面其他变量所覆盖。
using namespace Jack;
double check;

```

调用

```c++
namespace Jack
{
    double fetch = 30;
    double hill = 10;
    double check = 40.0;
}
double check = 30.0; //

int main() {
    double check = 50.0;
    using namespace Jack;
    std::cout << check << std::endl;
    std::cout << ::check << std::endl;
    std::cout << Jack::check << std::endl;
}
// 使用namespace，无论using namespace在前还是在后。如果和后面局部重复了，后面以局部覆盖。


namespace myth
{
    using Jill::fetch; // 嵌套
}
using namespace myth::fetch;

```

未命名的命名空间
就是类似编译指令一样，里面的变量可以被覆盖。因为没有名称，所以类似static不会被其他的文件所使用。

```c++

namespace
{
    int ice;
    int cc;
}

```

