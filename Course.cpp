#include "Course.h"

// 初始化静态成员变量
int Course::_currentId = 1;

// 课程类构造函数
Course::Course()
{
    // 将currentId当前值赋值给id，再将currentID自增
    _id = Course::_currentId++;

    // 默认课程名称为空字符串
    _name = "";

    _courseType = TypeCourse;
}

// 课程拷贝构造函数
Course::Course(const Course &course)
{
    _id = course._id;
    _name = course._name;
}

// 打印课程信息
void Course::PrintInfo(std::ostream &os)const
{
    os << "Course: " << _id << " , " << _name;
}

// 友元函数：操作符<<重载函数，当cout<<输出课程信息时使用
std::ostream &operator<<(std::ostream &os, const Course& course)
{
    course.PrintInfo(os);
    return os;
}
