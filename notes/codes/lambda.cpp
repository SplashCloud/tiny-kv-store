#include<iostream>

/**
 * @brief 介绍Lambda表达式的使用方式和注意事项
 * 
 * 1. 尽量不使用默认捕获方式，而使用显式捕获方式
 *      C++11: [var] / [&var]
 *      C++14: [inner_var = var] / [&inner_var = var]
 * 2. 想在Lambda表达式的参数列表中使用auto指定参数类型时(C++14引入)
 *      1) 使用通用引用 auto&&
 *      2) 使用 decltype() 来推导类型参数 和 std::forward 来转发参数
 */


// 本质上，lambda表达式就是一个实现了operator()函数的类的实例化对象
// 这个类叫做闭包类，由编译器生成；实例化出来的对象叫做闭包
// lambda表达式中的[]所捕获的变量就是闭包类的成员变量
class SimpleLambdaClass {
  public:
    SimpleLambdaClass(int factor) : _factor(factor) {}

    template<typename T>
    auto operator()(T x) {
        return x * this->_factor;
    }

  private:
    int _factor;
};


template<typename... T>
void special_function(T&&... param);


class AutoParaLambdaClass {
  public:
    
    template<typename... T>
    auto operator()(T&&... params) {
        special_function(std::forward<decltype(params)>(params)...);
    }
};


int main() {
    int factor = 5;
    // 1、lambda表达式
    auto func = [factor](auto x) { return x * factor; };
    // 2、支持调用的自定义类
    SimpleLambdaClass simple_lambda_class(factor);
    auto x = 2.5;
    std::cout << func(x) << std::endl;
    std::cout << simple_lambda_class(x) << std::endl;

    /**
     * 1. 如果要使用auto来指定参数类型，最好的写为auto&&，这样不管传递进来的是左值还是右值都可以正确处理
     * 2. 如果在lambda表达式内部需要将参数传递给其他函数，需要使用完美转发：std::forward<T>(...)
     * 3. forward中的类型使用 decltype 进行推导
     */
    auto func0 = [](auto&&... x) { special_function(std::forward<decltype(x)>(x)...); };
}