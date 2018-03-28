#ifndef __COURSE_H__
#define __COURSE_H__
#include <iostream>
#include <string>

enum CourseType
{
    TypeCourse = 0,
    TypeProjectCourse
};

// 基类
class Course
{
    // 友元函数：读取输入创建新的课程
    friend void read(std::istream &inputStream, Course &course);

    // 友元函数：操作符<<重载函数，当cout<<输出课程信息时使用
    friend std::ostream& operator<<(std::ostream &out, const Course &course);
    
public:
    // 无参数构造函数
    Course();

    // 课程类构造函数：根据课程名称创建课程对象
    Course(const std::string &name):Course(){_name = name;}

    // 课程拷贝构造函数
    Course(const Course &course);

    // 打印课程信息
    virtual void PrintInfo(std::ostream &os)const;

    // 返回课程名称
    inline std::string GetName()const {return _name;}

    // 设置课程名称
    inline void SetName(const std::string &new_name){_name = new_name;}

    // 返回课程ID
    inline const int GetId()const{return _id;}

    //返回课程类型
    inline const enum CourseType GetType() const { return _courseType;}

public:
    // 设置静态变量来生成唯一的ID值
    static int _currentId; 

protected:
    //课程ID
    int _id; 
    //课程名称
    std::string _name;
    //课程类型
    enum CourseType _courseType;
};

// 继承的子类
class ProjectCourse:public Course
{
public:
    ProjectCourse(){_courseType = TypeProjectCourse; }
    ProjectCourse(const std::string &name):Course(name){}
    // 设置标签
    inline void SetTag(const std::string &new_tag){ _tag = new_tag;}

    //返回标签
    inline std::string GetTag(){ return _tag;}

    // 打印课程信息
    void PrintInfo(std::ostream &os)const override
    {
        os << "ProjectCourse: " << _id << " , " << _name << " , " <<_tag;
    }

private:
    std::string _tag;
};


#endif