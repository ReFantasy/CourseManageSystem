#ifndef __CMDMANAGER_H__
#define __CMDMANAGER_H__
#include "CourseManager.h"
#include "Cmd.h"
#include <map>
#include <string>
// 命令管理类
class CmdManager 
{
public:
    // 构造函数
    CmdManager() = default;

    // 初始化函数，初始化支持的命令及课程信息
    void Init();

    // 打印帮助信息
    void PrintAllHelp() const;

    // 根据命令查询帮助信息
    void PrintCmdHelp(const CourseCmd cmd) const;

    // 处理命令操作
    bool HandleCmd(const CourseCmd cmd);

    // 返回课程管理对象
    CourseManager& GetCourseManager() { return manager; }
private:
    // 课程管理对象
    CourseManager manager;

    // 使用map存储命令及帮助信息
    std::map<enum CourseCmd, std::string> cmdMap;
};

#endif