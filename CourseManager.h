#ifndef __COURSEMANAGER_H__
#define __COURSEMANAGER_H__
#include "Course.h"
#include <vector>
#include <fstream>
// 课程管理类
class CourseManager
{
public:
    // 默认构造函数
    CourseManager() = default;

    // 构造函数：根据课程vector创建CourseManager
    CourseManager(std::vector<Course*> &courseVect);

    // 析构函数：释放内存
    ~CourseManager();
    // 获取课程列表长度
    inline int GetCourseNum(){ return _courseList.size();}

    //添加新的课程
    void AddCourse(Course *course);

    // 删除课程：删除最后一个课程
    void RemoveLast();

    // 删除课程：删除指定名称的课程
    void RemoveByName(const std::string &name);

    // 删除课程：删除指定ID的课程
    void RemoveById(int id);

    // 打印课程列表信息
    void PrintAllCourse();

    // 打印课程：答应指定名称的课程
    void PrintCourse(const std::string &name);

    // 打印课程：打印指定ID的课程
    void  PrintCourse(int id);

    // 打印名称最长的课程
    void PrintLongestNameCourse();

    // 保存数据
    void SaveToFile();

    // 加载数据
    void LoadFromFile();
private:
    // 查找课程，返回课程的索引
    int FindCourse(int id);
    int FindCourse(const std::string &name);
private:
    // 存储课程列表
    std::vector<Course*> _courseList;
};
#endif