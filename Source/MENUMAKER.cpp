//#include <windows.h>
//#include <cstring>
//#include <cstdlib> //��� ������ system
//#include <cstdio> 
//#include <tchar.h> 
//#include <wchar.h>
//#include "resource.h"
//#include"targetver.h"
//#include "framework.h"
//#include "targetver.h"
//#include <conio.h>
//#include <shlobj.h>
//#include <ks.h>
//#include <string>
//#include<mciapi.h>  
//#include<Mmsystem.h>
//#include "Names.h"
//#include "bass.h"
//#include <fstream>
////#include <uxtheme.h>
////#include <vssym32.h>
//
////#pragma comment(lib, "uxtheme.lib")
//
//HSTREAM NOTEDO;
//HSTREAM NOTERE;
//HSTREAM NOTEMI;
//HSTREAM NOTEFA;
//HSTREAM NOTESOL;
//HSTREAM NOTELA;
//HSTREAM NOTESI;
//
//HSTREAM NOTEDODI;
//HSTREAM NOTEREDI;
//HSTREAM NOTEFADI;
//HSTREAM NOTESOLDI;
//HSTREAM NOTELADI;
//HSTREAM NOTEDO2;
//HWND MENUMENUMENU;
//HWND MENUMENUMENU1;
//HWND MENUMENUMENU2;
//HWND MENUMENUMENU3;
////HWND eMp3;
////int skins;
////HANDLE bmpwall;
////HANDLE bmpwall1;
////HWND hwall;
////TCHAR StrT[MAX_PATH];
//
//bool bIsWallpaperSet;
//HBITMAP hWallpaperBitmap;
//BITMAP bm;
//HDC hCompatibleDC;
//RECT rcClient;
//
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//
//HDC hdc; //������ �������� ����������
//PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������
//
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 139, 139));
//
//const TCHAR progname[] = "������������������ ver 1.0 SP1 Update";
//HICON progicon;
//
//static COLORREF acrCustClr[16]; // ������ ���. ������
//static DWORD rgbCurrent;        // ��������� ��������� ����
//
//NOTIFYICONDATA nid;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//
//
//        
//        
//        ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
//
//
//
//
//
//
//        nid.cbSize = sizeof(nid);
//        nid.hWnd = hWnd;
//        nid.uID = 1;          // ����� ��������� ����� �������������, �� ����� ������ ������ ����
//        nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        nid.uCallbackMessage = WM_USER_SHELLICON;
//        nid.hIcon = progicon;
//        nid.uVersion = NOTIFYICON_VERSION;
//
//        /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
//        strcpy(nid.szTip, progname);
//
//        Shell_NotifyIcon(NIM_ADD, &nid);
//
//
//
//
//        int a = 140;
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColor = CreateMenu();
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
//        //eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//        CreateWindow(TEXT("BUTTON"), TEXT("������� ��"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, hWnd, (HMENU)BREAKPC, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("������� �������� ����"), WS_VISIBLE | WS_CHILD, 430, 10, 190, 25, hWnd, (HMENU)BOMB, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("�������� ������� � Windows 8-11"), WS_VISIBLE | WS_CHILD, 170, 10, 250, 25, hWnd, (HMENU)SPY, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("�������� � UA"), WS_VISIBLE | WS_CHILD, 210 + a, 75, 100, 25, hWnd, (HMENU)UA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("�� ������ ����"), WS_VISIBLE | WS_CHILD, 120 + a, 103, 105, 25, hWnd, (HMENU)DONTTOUCHME, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("������� ���� ����������� ����"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("������� ���� ����������� ����"), WS_VISIBLE | WS_CHILD, 45 + a, 130+40, 240, 25, hWnd, (HMENU)DELMAKE, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), _T("��������� �������"), WS_VISIBLE | WS_CHILD, 45+a, 130+40+40, 240, 25, hWnd, (HMENU)TURNOFF, NULL, NULL);
//        
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//   
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "���������");
//
//        AppendMenu(hColor, MF_STRING, COLORMENUMAKE, "��� ����");
//        AppendMenu(hColor, MF_STRING, SETBKG, "��� ����");
//        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColor, MF_STRING, polupon, "�������� ����������������");
//        AppendMenu(hColor, MF_STRING, polupoff, "��������� ����������������");
//        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColor, MF_STRING, MAKE_TOP_MOST_WINDOW, "������ ��������� ����");
//        AppendMenu(hColor, MF_STRING, MAKE_TOP_WINDOW, "�� ������� ��������� ����");
//
//
//        SetMenu(hWnd, hMenubar);
//
//
//        GetClientRect(hWnd, &rcClient);
//
//    
//        break;
//    }
//    case WM_COMMAND: 
//
//    {
//
//        ofstream Strannik;
//        int len5;
//        int len6;
//        int len7;
//        int len8;
//        TCHAR Name[1200];
//        TCHAR NameName[1200];
//        TCHAR EXECUTION[1200];
//        TCHAR IconName[1200];
//        len8 = GetWindowText(MENUMENUMENU3, IconName, 1200);
//        len7 = GetWindowText(MENUMENUMENU2, Name, 1200);
//        len5 = GetWindowText(MENUMENUMENU, NameName, 1200);    //��������
//        len6 = GetWindowText(MENUMENUMENU1, EXECUTION, 1200);  //��������
//
//
//
//
//
//
//
//
//
//        if (LOWORD(wParam) == polupon)
//        {
//            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_LAYERED);
//            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
//        }
//        if (LOWORD(wParam) == polupoff)
//        {
//            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//            SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);
//        }
//
//
//
//
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "�����������: Captain Strannik, ��������: Z_Kraf1er_Z", progicon);
//            MessageBoxA(hWnd, "��� ���������� ��������� ������\n��� ���� ��������� ����������� ����\n� Windows. ����� �� ������� �������\n���� ������ ������������ ����", "������������������", MB_ICONASTERISK);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("��� �� ������!"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 110, 25, hWnd, (HMENU)DONTTOUCHME1, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME1)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME1), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("����� ������!"), WS_VISIBLE | WS_CHILD, 10, 110, 120, 25, hWnd, (HMENU)DONTTOUCHME2, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME2)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME2), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("��� ����������!"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 110, 25, hWnd, (HMENU)DONTTOUCHME3, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME3)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME3), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("� ���!"), WS_VISIBLE | WS_CHILD, 115, 10, 50, 25, hWnd, (HMENU)DONTTOUCHME4, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME4)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME4), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("������������"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 130, 25, hWnd, (HMENU)DONTTOUCHME5, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME5)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME5), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("���"), WS_VISIBLE | WS_CHILD, 115, 10, 50, 25, hWnd, (HMENU)BREAKPC1, NULL, NULL);
//            system("start https://www.youtube.com/c/dan55800");
//        }
//        if (LOWORD(wParam) == BREAKPC)
//        {
//            int a = 140;
//            MessageBoxA(hWnd, "��� ����� ������� ������� �����. � ����� BSOD ����� ��� ������ ������� �� ��� ������!!!", "��������!!!", MB_ICONINFORMATION);
//            ShowWindow(GetDlgItem(hWnd, BREAKPC), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("������� ��!"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, hWnd, (HMENU)BREAKPC1, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == BREAKPC1)
//        {
//            //system("powershell wininit");
//            HANDLE hToken;
//            OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
//
//            LUID luid;
//            LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luid);
//
//            TOKEN_PRIVILEGES tp;
//            tp.PrivilegeCount = 1;
//            tp.Privileges[0].Luid = luid;
//            tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
//
//            AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
//
//            typedef LPVOID* PUNICODE_STRING;
//            typedef ULONG_PTR HARDERROR_RESPONSE_OPTION;
//            typedef ULONG_PTR HARDERROR_RESPONSE;
//            typedef HARDERROR_RESPONSE* PHARDERROR_RESPONSE;
//
//            typedef NTSTATUS(NTAPI* LPFN_NTRAISEHARDERROR)(
//                IN NTSTATUS             ErrorStatus,
//                IN ULONG                NumberOfParameters,
//                IN PUNICODE_STRING      UnicodeStringParameterMask OPTIONAL,
//                IN PVOID* Parameters,
//                IN HARDERROR_RESPONSE_OPTION ResponseOption,
//                OUT PHARDERROR_RESPONSE Response);
//
//            HARDERROR_RESPONSE resp;
//
//            LPFN_NTRAISEHARDERROR lpfnNtRaiseHardError = (LPFN_NTRAISEHARDERROR)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtRaiseHardError");
//
//            lpfnNtRaiseHardError(STATUS_FLOAT_MULTIPLE_FAULTS, 0, NULL, NULL, 6, &resp);
//        }
//        if (LOWORD(wParam) == SPY)
//        {
//            system("start MusicPlayer\\Progs\\SHUTUP\\KILLSPY.exe");
//            return 0;
//        }
//        if (LOWORD(wParam) == BOMB)
//        {
//            system("start MusicPlayer\\Progs\\REVO\\RevoUnin.exe");
//        }
//        if (LOWORD(wParam) == MENUMAKER) 
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DELMAKE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TURNOFF), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 10, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU1 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 315, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//
//            SendMessage(MENUMENUMENU2, EM_SETCUEBANNER, 0, (LPARAM)L"����� �������� ������� �� �������");
//            SendMessage(MENUMENUMENU3, EM_SETCUEBANNER, 0, (LPARAM)L"���� � icon(�������� C:\\\\windows\\\\icon.ico");
//            SendMessage(MENUMENUMENU, EM_SETCUEBANNER, 0, (LPARAM)L"�������� �������� ������ ����");
//            SendMessage(MENUMENUMENU1, EM_SETCUEBANNER, 0, (LPARAM)L"�������,�������� C:\\\\windows\\\\explorer.exe");
//            
//        }
//        if (LOWORD(wParam) == DELMAKE)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DELMAKE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TURNOFF), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            SendMessage(MENUMENUMENU2, EM_SETCUEBANNER, 0, (LPARAM)L"�������� ���������� ������� �� �������");
//            // MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), TEXT("���� � icon(�������� C:\\\\windows\\\\icon.ico)"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//           // MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("�������� �������� ������ ����"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            //MENUMENUMENU1 = CreateWindow(TEXT("EDIT"), TEXT("�� �������, ��� �� �������"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 315, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)DELMAKE1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("������� ������ ��������� ����"), WS_VISIBLE | WS_CHILD, 45 + a, 130 , 240, 25, hWnd, (HMENU)MAKEMAKENAMES, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == DELMAKE1)
//        {
//            ofstream Proga;                                        
//            string text2 = Name;
//            string text9 = NameName;
//            string text = EXECUTION;
//            string text3 = IconName;
//            Proga.open("MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            Proga << "Windows Registry Editor Version 5.00" << endl << endl;
//            Proga << "[-HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\" << Name << "]" << endl;
//            Proga.close();
//            system("regedit /f MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            system("del MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//        }
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            ofstream Proga;
//            string text2 = Name;
//            string text9 = NameName;
//            string text = EXECUTION;
//            string text3 = IconName;
//            Proga.open("MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            Proga << "Windows Registry Editor Version 5.00" << endl << endl; 
//            Proga << "[HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\" << Name << "]" << endl;
//            Proga <<"\"\MUIVerb\"=" <<"\"" << NameName << "\"" << endl;
//            Proga << "\"\Icon\"=" << "\"" << IconName << "\"" << endl;
//            Proga << endl;
//            Proga << "[HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\"<<Name<<"\\command]" << endl;
//            Proga << "@" << "=" << "\""  << EXECUTION << "\"" << endl;
//            Proga.close();
//            system("regedit /f MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            system("del MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//        }
//
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            ofstream SPISOK;
//            string text2 = Name;
//            SPISOK.open("MusicPlayer\\MENUMAKER\\tmp\\SPISOK.txt",ios::app);
//            SPISOK<<"Name of section which you have wroten : "<<Name << endl;
//            SPISOK << "Command which you have wroten: "<<EXECUTION << endl;
//            SPISOK<<"\n";
//            SPISOK.close();
//
//
//        }
//        if (LOWORD(wParam) == MAKEMAKENAMES)
//        {
//            system("start notepad MusicPlayer\\MENUMAKER\\tmp\\SPISOK.txt");
//        }
//                if (LOWORD(wParam) == COLORMENUMAKE)
//                {
//                    
//                    CHOOSECOLOR cc;
//        
//                    ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//                    cc.lStructSize = sizeof(CHOOSECOLOR);
//                    cc.hwndOwner = hWnd;
//                    cc.lpCustColors = (LPDWORD)acrCustClr;
//                    cc.rgbResult = rgbCurrent;
//                    cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//        
//                    if (ChooseColor(&cc) == TRUE) {
//                        if (hWallpaperBitmap != NULL) {
//                            DeleteObject(hWallpaperBitmap);
//                            hWallpaperBitmap = NULL;
//                        }
//                        if (bIsWallpaperSet == true) bIsWallpaperSet = false;
//        
//                        hBrush = CreateSolidBrush(cc.rgbResult);
//                        rgbCurrent = cc.rgbResult;
//        
//                        InvalidateRect(hWnd, NULL, FALSE);
//                    }
//                    //else
//                    //{
//        
//                    //    /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                    //       SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
//                    //    hBrush = CreateSolidBrush(RGB(0, 76, 153));
//                    //    rgbCurrent = RGB(0, 76, 153);
//                    //    return 0;
//                    //};
//        
//        
//                    
//        
//                      // �� �������� ������ ������. ������ ���� ����� �� �������� � ��������... � � �������... � ��� ����� ����...
//                }
//
//
//
//
//                if (LOWORD(wParam) == SETBKG)
//        {
//            
//          
//            //ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
//            OPENFILENAME ofnn;
//
//            ZeroMemory(&ofnn, sizeof(OPENFILENAME));
//            ofnn.lStructSize = sizeof(OPENFILENAME);
//            ofnn.hwndOwner = hWnd;
//            ofnn.lpstrFile = str1;
//            ofnn.nMaxFile = sizeof(str1);
//            
//            ofnn.nFilterIndex = 1;
//            ofnn.lpstrFileTitle = NULL;
//            ofnn.nMaxFileTitle = 0;
//            //ofn.lpstrInitialDir = ".";
//            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXMENU";
//            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //���� ������ ���!  � � ���� ������.
//
//            if (GetOpenFileName(&ofnn) == TRUE)
//            {
//                /*SetWindowText(eMp3, str1);
//
//                DestroyWindow(hwall);
//                DestroyWindow(GetDlgItem(hWnd, INSTBKG));
//                ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);*/
//
//                //ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
//
//                //skins = GetWindowText(eMp3, StrT, MAX_PATH);
//                //bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                //bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//
//                //if (hWallpaperBitmap != NULL) {
//                //    DeleteObject(hWallpaperBitmap);
//                //    //hWallpaperBitmap = NULL;
//                //}
//
//                //hWallpaperBitmap = (HBITMAP)LoadImage(NULL, str1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//
//                //if (hWallpaperBitmap != NULL);
//                //{
//                //    
//                //    
//
//                //    //hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
//                //    //SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
//                //    //SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);
//
//                //    GetObject(hWallpaperBitmap, sizeof(bm), &bm);
//
//                //    if (bIsWallpaperSet == false) bIsWallpaperSet = true;
//                //    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
//                //}
//
//                if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
//                hWallpaperBitmap = (HBITMAP)LoadImage(NULL, str1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                if (hWallpaperBitmap != NULL) {
//                    GetObject(hWallpaperBitmap, sizeof(bm), &bm);
//                    if (bIsWallpaperSet == false) bIsWallpaperSet = true;
//                    //InvalidateRect(NULL, NULL, NULL);
//                    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
//                }
//
//                /*CreateWindow(TEXT("BUTTON"), TEXT("����������"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
//            }
//            //ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
//            
//        }
//
//
//
//        if (LOWORD(wParam) == TURNOFF) {
//            SendMessage(hWnd, WM_SYSCOMMAND, SC_MONITORPOWER, 2);
//            SetTimer(hWnd, POWER_ON_TIMER, 5000, NULL);
//            
//        }
//
//        if (LOWORD(wParam) == MAKE_TOP_MOST_WINDOW)
//            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        if (LOWORD(wParam) == MAKE_TOP_WINDOW)
//            SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        break;
//    }
//
//    case WM_PAINT: {
//        hdc = BeginPaint(hWnd, &ps);
//        if (bIsWallpaperSet == true) {
//            hCompatibleDC = CreateCompatibleDC(hdc);
//
//            SelectObject(hCompatibleDC, hWallpaperBitmap);
//            SetStretchBltMode(hdc, HALFTONE);
//            SetBrushOrgEx(hdc, 0, 0, NULL);
//            StretchBlt(hdc, 0, 0, rcClient.right, rcClient.bottom, hCompatibleDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
//
//            DeleteDC(hCompatibleDC);
//        } else {
//            FillRect(hdc, &ps.rcPaint, hBrush);
//        }
//        EndPaint(hWnd, &ps);
//    } break;
//
//    case WM_TIMER: {
//        if (wParam == POWER_ON_TIMER) {
//            // ������ ������� �� �������� ������� � Windows 8
//            //SendMessage(hWnd, WM_SYSCOMMAND, SC_MONITORPOWER, -1);
//            // ������� ����� ������������ �������� ����
//            mouse_event(MOUSEEVENTF_MOVE, 0, 1, 0, NULL);
//            Sleep(40);
//            mouse_event(MOUSEEVENTF_MOVE, 0, -1, 0, NULL);
//            KillTimer(hWnd, POWER_ON_TIMER);
//        }
//    } break;
//    
//    case WM_DESTROY: {
//        if (hWallpaperBitmap != NULL) DeleteObject(hWallpaperBitmap);
//        DeleteObject(hBrush);
//        Shell_NotifyIcon(NIM_DELETE, &nid);
//        PostQuitMessage(0);
//
//        break;
//
//    } 
//
//
//    default:
//        return DefWindowProc(hWnd, uMsg, wParam, lParam);
//    }
//                   return 0;
//    }
//  
// 
//int WINAPI main()
//{
//    //SetThreadLocale(MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), SORT_DEFAULT));
//    SetThreadUILanguage(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA));
//    //SetProcessDPIAware();
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\menumaker.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//    RegisterClass(&op);
//
//    CreateWindowEx(0,op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}