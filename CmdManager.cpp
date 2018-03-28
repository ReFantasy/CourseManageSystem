#include "CmdManager.h"

// 初始化函数
void CmdManager::Init()
{
    // 初始化课程列表
    manager.LoadFromFile();

    // 初始化命令列表
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintHelp, "帮助信息"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintCourse, "打印课程信息"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintCourseNum, "打印课程数量"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintLongName, "打印最长的课程名称"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_RemoveLastCourse, "删除最后一个课程"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_AddCourse, "添加基础课程"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_ProjectCourse, "添加项目课程"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_ClearScreen, "清屏"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_Save, "保存文件"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_Exit, "退出程序"));
}

// 打印帮助信息
void CmdManager::PrintAllHelp() const
{
    std::cout<<"------------------简易课程管理系统------------------"<<std::endl;
    for (auto iter = cmdMap.begin(); iter != cmdMap.end(); iter++)
        std::cout << iter->first << ":" << iter->second << std::endl;
}

// 根据命令查询帮助信息
void CmdManager::PrintCmdHelp(const CourseCmd cmd) const
{
    // 查找命令是否支持
    auto iter = cmdMap.find(cmd);
    if(iter != cmdMap.end())
        std::cout << iter->first << ":" << iter->second << std::endl;
    else
        std::cout << "NOT FOUND" << std::endl;
}

// 处理命令操作
bool CmdManager::HandleCmd(const CourseCmd cmd)
{
    // 查找命令是否支持
    auto iter = cmdMap.find(cmd);

    // 如果命令不支持则打印NOTFOUND退出
    if (iter == cmdMap.end()) {
        std::cout << "NOT FOUND" << std::endl;
        return true;
    }

    // 根据命令值选择不同的操作
    switch(cmd) 
    {
        case Cmd_PrintHelp: PrintAllHelp(); break;
        case Cmd_PrintCourse: manager.PrintAllCourse(); break;
        case Cmd_PrintCourseNum: std::cout << manager.GetCourseNum() << std::endl; break;
        case Cmd_PrintLongName: manager.PrintLongestNameCourse(); break;
        case Cmd_RemoveLastCourse: manager.RemoveLast(); break;
        case Cmd_AddCourse: 
        {
            std::cout<<"输入课程名称：";
            std::string new_course;
            std::cin>>new_course;
            Course *p = new Course(new_course);
            manager.AddCourse(p); break;
        }
        case Cmd_ProjectCourse:
        {
            std::cout<<"输入课程名称：";
            std::string new_course;
            std::cin>>new_course;

            std::cout<<"输入课程标签：";
            std::string tag;
            std::cin>>tag;

            ProjectCourse *p = new ProjectCourse(new_course);
            p->SetTag(tag);
            manager.AddCourse(p); break;
        }
        case Cmd_Save:
        {
            manager.SaveToFile();
            break;
        }
        case Cmd_ClearScreen: system("clear");PrintAllHelp();break;
        // return false用来帮助外层的循环退出
        case Cmd_Exit: return false;
        default: break;
    }

    return true;
}