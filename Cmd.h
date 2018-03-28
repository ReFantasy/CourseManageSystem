#ifndef __CMD_H__
#define __CMD_H__
enum CourseCmd
{
    // 打印命令帮助信息
    Cmd_PrintHelp,

    // 打印课程信息
    Cmd_PrintCourse,

    // 打印课程数量
    Cmd_PrintCourseNum ,

    // 打印最长的课程名称
    Cmd_PrintLongName,

    // 添加课程：指定课程名称添加课程
    Cmd_AddCourse,

    // 添加项目课程
    Cmd_ProjectCourse,    

    // 删除最后一个课程
    Cmd_RemoveLastCourse,

    // 保存文件
    Cmd_Save,

    // 清屏
    Cmd_ClearScreen,
    
    // 退出程序
    Cmd_Exit
};
#endif