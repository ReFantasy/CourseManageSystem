#include "CourseManager.h"

// 构造函数：根据课程vector创建CourseManager
CourseManager::CourseManager(std::vector<Course*> &courseVect)
{
    _courseList = courseVect;
}

// 析构函数：释放内存
CourseManager::~CourseManager()
{
    for(auto p:_courseList)
        delete p;
}

//添加新的课程
void CourseManager::AddCourse(Course *course)
{
    _courseList.push_back(course);
}

// 删除课程：删除最后一个课程
void CourseManager::RemoveLast()
{
    if(!_courseList.empty())
    {
        auto p = _courseList.back();
        delete p;
        _courseList.pop_back();
    }
}

// 删除课程：删除指定名称的课程
void CourseManager::RemoveByName(const std::string &name)
{
    int index = FindCourse(name);
    if(index != -1)
    {
        delete _courseList[index];
        auto iter = _courseList.begin()+index;
        _courseList.erase(iter);
    }
}

// 删除课程：删除指定ID的课程
void CourseManager::RemoveById(int id)
{
    int index = FindCourse(id);
    if(index != -1)
    {
        delete _courseList[index];
        auto iter = _courseList.begin()+index;
        _courseList.erase(iter);
    }
}

// 打印课程列表信息
void CourseManager::PrintAllCourse()
{
    for(auto &e:_courseList)
        std::cout<<*e<<std::endl;
}

// 打印课程：答应指定名称的课程
void CourseManager::PrintCourse(const std::string &name)
{
    int index = FindCourse(name);
    std::cout << *_courseList[index] << std::endl;
}

// 打印课程：打印指定ID的课程
void  CourseManager::PrintCourse(int id)
{
    int index = FindCourse(id);
    std::cout << *_courseList[index] << std::endl;
}

// 打印名称最长的课程
void CourseManager::PrintLongestNameCourse()
{
    std::cout<<"error function"<<std::endl;
}

// 查找课程，返回课程的索引
int CourseManager::FindCourse(int id)
{
    int len = _courseList.size();
    for(int i=0; i<len; i++)
    {
        if(_courseList[i]->GetId() == id)
            return i;
    }
    return -1;
}

int CourseManager::FindCourse(const std::string &name)
{
    int len = _courseList.size();
    for(int i=0; i<len; i++)
    {
        if(_courseList[i]->GetName() == name)
            return i;
    }
    return -1;
}

// 保存数据文件
void CourseManager::SaveToFile()
{
    
}

void CourseManager::LoadFromFile()
{
  
}