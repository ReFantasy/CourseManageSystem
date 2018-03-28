#include "CmdManager.h"
#include <fstream>
using namespace std;
int main()
{
    // 创建命令管理对象
    CmdManager cmdManager;
    cmdManager.Init();
    // 打印帮助信息
    cmdManager.PrintAllHelp();

    cout << "New Command:";

    // 进入主循环并处理输入信息
    int cmd;
    while (cin >> cmd)
    {
        if (cin.good())
        {
            bool exitCode = cmdManager.HandleCmd((CourseCmd)cmd);
            if (!exitCode)
                return 0;
        }

        cout << "-------------------------" << endl;
        cout << "New Command:";

        // 清理输入流，避免刚才流中的字符影响后续输入
        cin.clear();
        cin.ignore();
    }

    fstream file;
    file.open("./test.dat", ios::out|ios::binary);
    string a("hello");
    string b;
    file.write(reinterpret_cast<char*>(&a),sizeof(a));
    file.close();
}