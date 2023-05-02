#include "pch.h"
#include <processthreadsapi.h>
#include "LinkFrontAndBack.h"
using namespace std;

void launchGame(const char* path) {
    STARTUPINFO startinfo;
    PROCESS_INFORMATION processinfo;
    ZeroMemory(&startinfo, sizeof(startinfo));
    ZeroMemory(&processinfo, sizeof(processinfo));

    // Key components to creating process.
    //char* game_path = &path[0];
    BOOL bScucces = CreateProcessA(NULL, (LPSTR)path,
        NULL, NULL, FALSE, 0, NULL, NULL, &startinfo, &processinfo);


    // Error handling
    if (bScucces == FALSE) {
        cout << "Create Process Failed & Error No - " << GetLastError() << endl;
    }
    cout << "Create Process Success" << endl;

    // Terminal will help us track the proccess and thread
    cout << "Process ID ->" << processinfo.dwProcessId << endl;
    cout << "Thread ID ->" << processinfo.dwThreadId << endl;
    // cout<<"GetProcessID ->"<<GetProcessId(processinfo.hProcess)<<endl;
    // cout<<"GetThreadID _> ->"<<GetThreadId(processinfo.hThread)<<endl;

    // Wait for process to go down then close when finished
    WaitForSingleObject(processinfo.hProcess, INFINITE);
    CloseHandle(processinfo.hThread);
    CloseHandle(processinfo.hProcess);
    //system("PAUSE");
}