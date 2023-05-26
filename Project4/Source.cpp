#include <iostream>
#include <Windows.h>

using namespace std;

// Can only be used on 32Bits games.
//This is only for educational purposes.



int main()
{
	//int newval = 1337;                            
	int readtest;
	HWND hwnd = FindWindowA(NULL, "AssaultCube"); // Finding Targeted process
	DWORD pid; //pid meaning process id
	if (hwnd == NULL)
	{
		cout << "Error! Process not found!";
		Sleep(3000);   //checking if "hwnd" returns NULL. if it does, the program will display an error message and exit after 3 seconds
		DWORD pid;
		exit(-1);
	}   
	GetWindowThreadProcessId(hwnd, &pid); // getting process id
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); // getting handle and opening the process.

	ReadProcessMemory(handle, (LPVOID*)0x029AA2A0,&readtest, sizeof(readtest), 0);// reading memory and storing it in variable "readtest". Note: This can only be used on dynamic address
	                                                                               // this will not work with an offsets!
	
																				   
	 //WriteProcessMemory(handle, (LPVOID*)0x29AA2A0, &newval, sizeof(newval), 0) <- an example of how to write process memory
	while (1 == 1)
	{
		cout << readtest << '\n';
		system("cls");
		
	}
	getchar();
}