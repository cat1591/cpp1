#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;  // 矩形的长
    double width;   // 矩形的宽
    
public:
    // 构造函数 - 用来初始化矩形的长和宽
    Rectangle(double l, double w) 
    {
        length = l;
        width = w;
    }
    
    // 计算矩形的面积
    double area() {
        return length * width;
    }
    
    // 重载 > 运算符，比较两个矩形的面积
    bool operator>(Rectangle other) 
    {
        if (this->area() > other.area()) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }
    
    // 显示矩形的信息
    void display() {
        cout << "长: " << length << ", 宽: " << width;
    }
};

int main() 
{
    double l1, w1, l2, w2;
    
    // 输入第一个矩形
    cout << "请输入第一个矩形的长和宽: ";
    cin >> l1 >> w1;
    
    // 输入第二个矩形
    cout << "请输入第二个矩形的长和宽: ";
    cin >> l2 >> w2;
    
    // 创建两个矩形对象
    Rectangle rect1(l1, w1);
    Rectangle rect2(l2, w2);
    
    // 比较哪个矩形的面积更大
    cout << "\n比较结果:" << endl;
    cout << "矩形1: ";
    rect1.display();
    cout << ", 面积: " << rect1.area() << endl;
    
    cout << "矩形2: ";
    rect2.display();
    cout << ", 面积: " << rect2.area() << endl;
    
    cout << "\n面积较大的矩形是: ";
    if (rect1 > rect2) 
    {
        rect1.display();
    } 
    else 
    {
        rect2.display();
    }
    
    return 0;
}