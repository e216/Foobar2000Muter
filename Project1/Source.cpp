#include <iostream>
#include <Windows.h>

using namespace std;


int main() {
	while (1) {
		char i;
		cout << "Type f as in \"fuckFoobar2000\" to mute or unmute F2K." << std::endl;
		cin >> i;
		if (i == 'f') {
			STARTUPINFO         siStartupInfo;
			PROCESS_INFORMATION piProcessInfo;

			memset(&siStartupInfo, 0, sizeof(siStartupInfo));
			memset(&piProcessInfo, 0, sizeof(piProcessInfo));

			siStartupInfo.cb = sizeof(siStartupInfo);


			if (CreateProcess("C:/PROGRA~2/foobar2000/foobar2000.exe",       // Application name
				("\ /command:mute"),                 // Additional application arguments
				NULL,
				NULL,
				FALSE,
				CREATE_DEFAULT_ERROR_MODE,
				NULL,
				NULL,
				&siStartupInfo,
				&piProcessInfo) == FALSE)
				// Could not start application

				// Wait until application has terminated
				WaitForSingleObject(piProcessInfo.hProcess, INFINITE);

			// Close process and thread handles
			::CloseHandle(piProcessInfo.hThread);
			::CloseHandle(piProcessInfo.hProcess);
		}
		else {
			"Press F for FUCKFOOBAR2000 to mute F2K.";
		}
	}
}

