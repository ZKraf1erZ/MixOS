//#include <windows.h>
//#include <cstring>
//#include <cstdlib>                   //�� ��������� ��������
//// ������ � ���� emulate.cpp ���     //� ���� � ��� ������ ������, �� �� �������?
//// ������� 3 ��� � ������
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
//
//
//
//HWND MENUMENUMENU;
//HWND MENUMENUMENU1;
//HWND MENUMENUMENU2;
//HWND MENUMENUMENU3;
//HSTREAM YOUTUBER;
////HWND eMp3;
////int skins;
////HANDLE bmpwall;
////HANDLE bmpwall1;
////HWND hwall;
////TCHAR StrT[MAX_PATH];
//static COLORREF acrCustClr[16];
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//
//HDC hdc;
//PAINTSTRUCT ps;
//HBRUSH hBrush = CreateSolidBrush(RGB(76,0 ,153));
//HWND hTrack;
//HINSTANCE hInst;
//HICON progicon;
//
//const TCHAR progname[] = "��������� ����� � ����� ver 1.11 SP1";
//
////������ ��� ����� =)
//static DWORD rgbCurrent = RGB(76,0,153);
//DWORD rgbTextColor = RGB(255, 255, 255);
//
//bool bIsWallpaperSet;
//HBITMAP hWallpaperBitmap;
//BITMAP bm;
//HDC hCompatibleDC;
//RECT rcClient;
//
//NOTIFYICONDATA nid;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//        //eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//        int a = 140;
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColorYT = CreateMenu();
//
//
//        
//        ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
//
//
//
//
//        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
// 
//
//        nid.cbSize = sizeof(nid);
//        nid.hWnd = hWnd;
//        nid.uID = 1;          // ����� ��������� ����� �������������, �� ����� ������ ������ ����
//        nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        nid.uCallbackMessage = WM_USER_SHELLICON;
//        nid.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        nid.uVersion = NOTIFYICON_VERSION;
//        
//   /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
//        strcpy(nid.szTip, "��������� ����� � Youtube");
//
//        Shell_NotifyIcon(NIM_ADD, &nid);
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColorYT, "������� ����");
//
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("������� ����� � Youtube"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//
//
//        BASS_Init(-1, 44100, 0, 0, NULL); 
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
//        AppendMenu(hColorYT, MF_STRING, COLORYT, "��� ����");
//        AppendMenu(hColorYT, MF_STRING, TEXT_COLOR, "������� ���� ������");
//        AppendMenu(hColorYT, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColorYT, MF_STRING, SETBKG, "��� ����");
//        AppendMenu(hColorYT, MF_STRING, CLEARSKIN, "������ ����");
//        AppendMenu(hColorYT, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColorYT, MF_STRING, polupon, "�������� ����������������");
//        AppendMenu(hColorYT, MF_STRING, polupoff, "��������� ����������������");
//        AppendMenu(hColorYT, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColorYT, MF_STRING, MAKE_TOP_MOST_WINDOW, "������ ��������� ����");
//        AppendMenu(hColorYT, MF_STRING, MAKE_TOP_WINDOW, "�� ������� ��������� ����");
//
//
//
//        SetMenu(hWnd, hMenubar); 
//
//
//        BASS_Start();     //��� ����� ������� � �������� ���. �� ���� ������ ������ ������ ������ ����� ������� �� ������ ������. ��� ���� ����� ����� �������� ��������
//        // ����� ��� ��� �����    //��, �� �� �������, ������ �������� � ������ ������ ���� ���? �������� ������, ��� ��� ������ � ������ ������ �� ������. �� ����� ������ � ������ ���������� ���� ���? ���� ��� emulate.cpp ����������.
//        // ������ ��� � �� ����� ������� ����
//        // � ��������� � ��������� �� �������� ����� ��� ������ 
//        YOUTUBER = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Youtube.mp3", 0, 0, 0);
//        BASS_ChannelPlay(YOUTUBER, false);// ��� ������ ��� �������� ��������. � ��� ���� ��?
//        // ��������������� ���� � ������     ��� �� ���.... �������. �� ������ ��� ��������� ��������.
//        // � ����� ����� �����???  ��� � ������ ��� �������� ���� ���� ���������� �� ������� �� ������ ������. �� ��� ��� ��������� ����� ��������� ����� �������. ���
//
//        GetClientRect(hWnd, &rcClient);
//
//        break;
//    }
//    case WM_COMMAND:
//            //������ ����� ����� �� ��������, � ���� �����������....
//    {
//
//        if (LOWORD(wParam) == CLEARSKIN) {
//            if (hWallpaperBitmap != NULL) {
//                DeleteObject(hWallpaperBitmap);
//                hWallpaperBitmap = NULL;
//            }
//            if (bIsWallpaperSet == true) bIsWallpaperSet = false;
//            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
//        }
//
//        if (LOWORD(wParam) == MAKE_TOP_MOST_WINDOW)
//            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        if (LOWORD(wParam) == MAKE_TOP_WINDOW)
//            SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        if (LOWORD(wParam) == TEXT_COLOR) {
//            CHOOSECOLOR cc;
//            static COLORREF acrCustClr[16]; // ������ ���. ������
//
//            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//            cc.lStructSize = sizeof(CHOOSECOLOR);
//            cc.hwndOwner = hWnd;
//            cc.lpCustColors = (LPDWORD)acrCustClr;
//            cc.rgbResult = rgbTextColor;
//            cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//
//            if (ChooseColor(&cc) == TRUE) {
//                //hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbTextColor = cc.rgbResult;
//                //InvalidateRect(hWnd, NULL, FALSE);
//                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
//            }
//        }
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
//
//            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//            SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);
//        }
//
//
//
//
//
//
//
//
//        int len90;                                                                                                              
//        TCHAR video[1200];
//        len90 = GetWindowText(MENUMENUMENU, video, 1200);
//        if (LOWORD(wParam) == MENUMAKER)
//        {
//            int a = 140;   //���, ������ ������ ����� ��� ���. ������ ������. ���� �������� ������ ��������� �� ��� ������������, ��� ������������ ����. =) ��� Youtube.cpp Emulate.cpp, quest.cpp.  �� ����� ����� ���� ��� ����� ����������. ����� �������, �� �����, ��� ��� ����� ��� ��� ������ ���������.
//            // � ���� � ������ ��������???    //� � ������, ��� �������, ���� ��� ��� ���������, ��� �� ����� ��� ���� ������ ����� ����, �� ���� �� �������� ��������� �������������, �����-������, �� ������ ����� ������ ������������� ���� ��������� =).
//            //��
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL /*| ES_MULTILINE*/, 10, 500, 605, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            SendMessage(MENUMENUMENU, EM_SETCUEBANNER, FALSE, (LPARAM)L"������ �� ����� �� Youtube");
//            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("                 ����� ������� ����� ���� : \n\n1) �������� ������ �� ����� � ���� ��� �����.\n2) ������ ������ << ������� >> .\n\nP.S ����������, ��� �� �� �������� = )\n\nP.S.S ������ ���� ������ ����� = ) "), WS_VISIBLE | WS_CHILD, 150, 90, 325, 140, hWnd, (HMENU)text1, NULL, NULL);
//            //CreateWindow(TEXT("STATIC"), TEXT("\t����� ������� ����� ���� : \n\n1) �������� ������ �� ����� � ���� ��� �����.\n2) ������ ������ << ������� >> .\n\nP.S ����������, ��� �� �� �������� = )\n\nP.S.S ������ ���� ������ ����� = ) "), WS_VISIBLE | WS_CHILD, 150, 90, 325, 140, hWnd, (HMENU)text1, NULL, NULL);
//            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
//            SendMessage(hTrack, TBM_SETPOS, 0, 100);
//            SendMessage(hTrack, TBM_SETRANGEMAX, TRUE, 200);
//            CreateWindow(TEXT("STATIC"), TEXT("���������"), WS_VISIBLE | WS_CHILD, 130 + a, 290, 70, 18, hWnd, (HMENU)text1, NULL, NULL);
//                                            //PERFECT
//                                            // PROFIT     ������ ����� �� ������ � Emulate.cpp ������ ���� ��������� �������� ������� ��������� ������ �� 20
//        
//        }                              //��������� �����, ��� ������ ���� ������ ��������� =)
//        // ��� ����������� :)   �� ������ �������  �� ���� ����� ����� ��� � � Createwindowstext(static)
//
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "�����������: Captain Strannik. ��������: Z_Kraf1er_Z. ����� ����: Daniel Myslivets", progicon);
//            MessageBoxA(hWnd, "��� ��������� ��� ���������� ������� � Youtube.\n������� Daniel Myslivets �� ��������������� ���������� ����������, ��� ������� � ������ ������ ���� GUI", "�������", MB_ICONASTERISK);
//        
//        }
//
//        if (LOWORD(wParam) == SETBKG)
//        {
//
//
//            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
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
//                ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
//
//                ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
//
//                skins = GetWindowText(eMp3, StrT, MAX_PATH);
//                bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//
//                if (bmpwall != NULL);
//                {
//
//                    hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
//                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
//                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);
//
//                }*/
//
//                if (hWallpaperBitmap != NULL) {
//                    DeleteObject(hWallpaperBitmap);
//                    //hWallpaperBitmap = NULL;
//                }
//
//                hWallpaperBitmap = (HBITMAP)LoadImage(NULL, str1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                if (hWallpaperBitmap != NULL) {
//                    GetObject(hWallpaperBitmap, sizeof(bm), &bm);
//                    if (bIsWallpaperSet == false) bIsWallpaperSet = true;
//                    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
//                }
//
//                /*CreateWindow(TEXT("BUTTON"), TEXT("����������"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
//            }
//            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
//
//        }
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            
//            ofstream Proga;
//            string videos = video;
// 
//
//
//
//
//
//    
//
//            Proga.open("MusicPlayer\\Youtube\\bat.bat");
//            //Proga << "MusicPlayer\\Youtube\\yt-dlp.exe �format mp4 " << videos << endl;
//            Proga << "MusicPlayer\\Youtube\\yt-dlp.exe " << videos << endl;
//            Proga << "@echo Your video has been downloaded, and stay in MusicPlayer's directory" << endl;
//            //Proga << "pause" << endl;
//            Proga.close();
//            system("MusicPlayer\\Youtube\\bat.bat");
//            system("del MusicPlayer\\Youtube\\bat.bat");
//            MessageBox(hWnd, _T("���� ����� ���� �������!\n������ ��� ����� � ����� � �������"), _T("�����!"), MB_ICONASTERISK);
//    
//        }
//
//                if (LOWORD(wParam) == COLORYT)
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
//
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
//                    // �� �������� ������ ������. ������ ���� ����� �� �������� � ��������... � � �������... � ��� ����� ����...
//                }
//                break;
//
//        case WM_HSCROLL: {
//            if (hTrack == (HWND)lParam)
//            {
//                BASS_ChannelSetAttribute(YOUTUBER, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 0, 0) / 100.f);
//            }
//        } break;
//
//        case WM_PAINT: {
//            hdc = BeginPaint(hWnd, &ps);
//            
//            if (bIsWallpaperSet == true) {
//                hCompatibleDC = CreateCompatibleDC(hdc);
//
//                SelectObject(hCompatibleDC, hWallpaperBitmap);
//                SetStretchBltMode(hdc, HALFTONE);
//                SetBrushOrgEx(hdc, 0, 0, NULL);
//                StretchBlt(hdc, 0, 0, rcClient.right, rcClient.bottom, hCompatibleDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
//
//                DeleteDC(hCompatibleDC);
//            } else {
//                FillRect(hdc, &ps.rcPaint, hBrush);
//            }
//
//            EndPaint(hWnd, &ps);
//        } break;
//
//                case WM_CTLCOLORSTATIC:
//                {
//
//
//
//                    if (GetDlgCtrlID((HWND)lParam) == text1)
//                    {
//                        HDC hdcStatic = (HDC)wParam;
//                        // or obtain the static handle in some other way
//                        SetTextColor(hdcStatic, rgbTextColor); // text color
//
//                        SetBkColor(hdcStatic, rgbCurrent);
//
//                        return (LRESULT)GetStockObject(NULL_BRUSH);
//
//                    }
//                }
//                break;
//
//
//
//
//
//    case WM_DESTROY: {
//        BASS_Free();
//        if (bIsWallpaperSet == true) DeleteObject(hWallpaperBitmap);
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
//    return 0;
//    }   
//}  
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
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//    //op.hbrBackground = CreateSolidBrush(RGB(76,0 ,153));
//    RegisterClass(&op);
//
//
//    CreateWindowEx(0,op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}