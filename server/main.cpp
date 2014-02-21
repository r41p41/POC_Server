#define _WIN32_WINNT 0x501

#include "resource.h"
#define PORT 10009

HINSTANCE hInst;
HWND dlg;
void newinst()
{
            WSADATA wsa;
			WSAStartup(0x0202,&wsa);
			struct sockaddr_in client;
			int fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			if(fd!=(int)INVALID_SOCKET)
			{
				int newfd=0;
				client.sin_family=AF_INET;
				client.sin_addr.s_addr=htonl(INADDR_ANY);
				client.sin_port=htons(PORT);		//port to listen on
				if(bind(fd,(struct sockaddr*)&client,sizeof(client))==0)
				{
					int len = sizeof(client);
					while(1)
					{
						listen(fd,5);
						newfd=accept(fd,(struct sockaddr*)&client,&len);
						if(newfd!=(int)INVALID_SOCKET)
						WSAAsyncSelect(newfd,dlg,WM_USER+1020,FD_CLOSE|FD_READ|FD_WRITE);
					}
				}
			}
			return ;
}
BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    char arr[1024];	//1024 byte buffer on stack used for transferring text on sockets
					//lightweight in nature
    switch(uMsg)
    {
        case WM_INITDIALOG:
            dlg = hwndDlg;
            CreateThread(0,0,(LPTHREAD_START_ROUTINE)newinst,0,0,0);
            return TRUE;

        case WM_CLOSE:
            ExitProcess(0);
            return TRUE;
        case (WM_USER+1020):
            switch(WSAGETSELECTEVENT(lParam))
            {
				case FD_WRITE:
				//do some work with arr here
				send(wParam,arr,1024,0);
				break;

                case FD_READ:
                recv(wParam,arr,1024,0);
				//do some work with arr here
                break;

                case FD_CLOSE:
                closesocket((SOCKET)wParam);
                break;
            }
            return 1;
    }

    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    HWND window=CreateDialog(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
	if(window==0)
	return 0;
    ShowWindow(window,SW_HIDE);
	MSG msg;
	while(GetMessage(&msg,window,0,0)==TRUE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 1;
}
