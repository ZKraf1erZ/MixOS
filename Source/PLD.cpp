//#include <windows.h>
//#include <cstring>
//#include <cstdlib>
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
//#include "LoveInQuest.h"
//#include <urlmon.h>
//#pragma comment (lib, "urlmon.lib")
//
//#define STRANNI 90     
//
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//
//int len;
//TCHAR StrB[1200];
//
//
//using namespace std;
//char str1[1024];
//HSTREAM QUEST_THEME;
//
//HICON progicon;
//int skins;
//TCHAR StrT[MAX_PATH];
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;
//static COLORREF acrCustClr[16];
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 100, 204));
//static DWORD rgbCurrent = RGB(0, 100, 204);
//DWORD rgbTextColor = RGB(255, 255, 255);
//HWND hTrack;
//HDC hdc;
//PAINTSTRUCT ps;
//const TCHAR progname[] = _T("Загрузчик плагинов для MixOS ver. 1.0");
//HWND tardis;
////bool key_pressed = false;
//HINSTANCE hInst;
//HSTREAM UASSAULT;
//HWND LOVE;
//HWND LOVE1;
//HWND LOVE2;
//HWND LOVE3;
//HWND LOVE4;
//
//HWND hwndProgressBar;
////HWND hwndProgressText;
////HPEN hWhitePen;
//
////bool fPBMaxValIsSet;
////ULONG ulPrevProgress;
//
//class CDownloadProgress : public IBindStatusCallback
//{
//public:
//    HRESULT __stdcall QueryInterface(const IID &, void **)
//    {
//        return E_NOINTERFACE;
//    }
//
//    ULONG STDMETHODCALLTYPE AddRef(void)
//    {
//        return 1;
//    }
//
//    ULONG STDMETHODCALLTYPE Release(void)
//    {
//        return 1;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding *pib)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG *pnPriority)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved)
//    {
//        return S_OK;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown* punk)
//    {
//        return E_NOTIMPL;
//    }
//
//    virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
//    {
//        SendMessage(hwndProgressBar, PBM_SETRANGE32, 0, ulProgressMax);
//        SendMessage(hwndProgressBar, PBM_SETPOS, ulProgress, 0);
//        return S_OK;
//    }
//};
//
//CDownloadProgress DownloadProgress;
//
//NOTIFYICONDATA nid;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//        
//        ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
//
//
//        nid.cbSize = sizeof(nid);
//        nid.hWnd = hWnd;
//        nid.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
//        nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        nid.uCallbackMessage = WM_USER_SHELLICON;
//        nid.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        nid.uVersion = NOTIFYICON_VERSION;
//
//        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
//        strcpy(nid.szTip, "Загрузчик плагинов для MixOS");
//
//        
//        Shell_NotifyIcon(NIM_ADD, &nid);
//        
//
//
//        HMENU hMenubar = CreateMenu();
//        HMENU hAbout = CreateMenu();
//        HMENU hOptions = CreateMenu();
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//
//        AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
//        AppendMenu(hOptions, MF_STRING, TEXT_COLOR, "Сменить цвет текста");
//        AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hOptions, MF_STRING, PLAY, "Включить музыку");
//        AppendMenu(hOptions, MF_STRING, PAUSE1, "Выключить музыку");
//        AppendMenu(hOptions, MF_SEPARATOR, 0, NULL);
//        AppendMenu(hOptions, MF_STRING, polupon, "Включить полупрозрачность");
//        AppendMenu(hOptions, MF_STRING, polupoff, "Выключить полупрозрачность");
//        AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hOptions, MF_STRING, MAKE_TOP_MOST_WINDOW, "Поверх остальных окон");
//        AppendMenu(hOptions, MF_STRING, MAKE_TOP_WINDOW, "На уровень остальных окон");
//        
//
//       
//
//
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
//        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//
//        CreateWindow(TEXT("STATIC"), TEXT("Какие плагины для MixOS хотите установить?"), WS_VISIBLE | WS_CHILD, 200, 20, 310, 20, hWnd, (HMENU)text1, NULL, NULL);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Конвертер Валют"), WS_VISIBLE | WS_CHILD, 170, 55, 150, 20, hWnd, (HMENU)PLUGCONVERT, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Convert.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGCONVERT), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Старые версии MixOS"), WS_VISIBLE | WS_CHILD, 330, 55, 210, 20, hWnd, (HMENU)PLUGMIX, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGMIX), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Список эмуляторов"), WS_VISIBLE | WS_CHILD, 170, 85, 150, 20, hWnd, (HMENU)PLUGEMULATE, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Emulate.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGEMULATE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Сборник игры из моего детства <<Urban Assault>>"), WS_VISIBLE | WS_CHILD, 170, 115, 370, 20, hWnd, (HMENU)PLUGUA, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Ghor.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGUA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Все мои утилиты для MixOS"), WS_VISIBLE | WS_CHILD, 170, 145, 370, 20, hWnd, (HMENU)PLUGALL, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGALL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Удалить всё"), WS_VISIBLE | WS_CHILD, 170, 175, 370, 20, hWnd, (HMENU)PLUGDEL, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\delete.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGDEL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Программы от подписчиков"), WS_VISIBLE | WS_CHILD, 330, 85, 210, 20, hWnd, (HMENU)PLUGSUBS, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Win8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, PLUGSUBS), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("STATIC"), TEXT("Прогресс:"), WS_VISIBLE | WS_CHILD, 170, 225, 70, 20, hWnd, (HMENU)text1 /*PLD_PROGRESS_TEXT*/, NULL, NULL);
//        hwndProgressBar = CreateWindowEx(NULL, PROGRESS_CLASS, NULL, WS_VISIBLE | WS_CHILD, 170, 245, 370, 25, hWnd, NULL, NULL, NULL);
//
//        //hWhitePen = (HPEN)GetStockObject(WHITE_PEN);
//        
//        BASS_Stop();
//        BASS_Start();
//        UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Skellige.mp3", 0, 0, 0);
//        BASS_ChannelPlay(UASSAULT, false);
//
//        break;
//
//
//    }
//    case WM_COMMAND: {
//
//        if (LOWORD(wParam) == PLUGCONVERT)
//        {
//            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
//            if (MessageBoxA(hWnd, "Размер этого архива 222 КБ", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1GaZh8_L6MWy2o34QB8qfeA6ixTc-UfYx", "MusicPlayer\\Convert.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\Convert.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Конвертер валют установлен", "Внимание", MB_ICONASTERISK);
//            }
//        }
//        else if (LOWORD(wParam) == PLUGEMULATE)
//        {
//            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
//            if (MessageBoxA(hWnd, "Этот архив весит более 1 ГБ, так что качаться будет относительно долго!\nКогда скачается и установится вам придёт уведомление", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=10nypgMPXwJP3iyXprG9HUAcsdsJjZ2Ck", "MusicPlayer\\Emulate.zip", 0, &DownloadProgress);
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1IJzP1W8YFHJJ9hBdj2QsqkF6_HuiZ5XD", "MusicPlayer\\Music.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\Emulate.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Список эмуляторов успешно скачался и установился =)", "Внимание", MB_ICONASTERISK);
//            }
//        }
//    
//        else if (LOWORD(wParam) == PLUGSUBS)
//        {
//            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
//            if (MessageBoxA(hWnd, "Этот архив весит 300 МБ, так что качаться будет относительно долго!\nКогда скачается и установится, вам придёт уведомление", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=18LIVItWYt7m3J2kHAjK3YhbBulKFxTOg", "MusicPlayer\\Viewer.zip", 0, &DownloadProgress);
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1XVht4aatv9a60EbLzZLIJ0IJUGRNTt2i", "MusicPlayer\\SUBS.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\SUBS.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Программы от подписчиков успешно установлены", "Внимание", MB_ICONASTERISK);
//            }
//        }
//
//        else if (LOWORD(wParam) == PLUGMIX)
//        {
//            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
//            if (MessageBoxA(hWnd, "Этот архив весит 820 МБ, так что качаться будет относительно долго!\nКогда скачается вам придёт уведомление", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1lcYSrZIA-_UoEXRfMZ0WCAZw5xg1uGJZ", "MusicPlayer\\OLD.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\OLD.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Старые версии MixOS успешно были скачаны и установлены", "Внимание", MB_ICONASTERISK);
//            }
//        }
//
//        else if (LOWORD(wParam) == PLUGUA)
//        {
//            if (MessageBoxA(hWnd, "Этот архив весит 500 МБ, так что качаться будет относительно долго!\nКогда скачается вам придёт уведомление", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=10r0C0dTVdDt2ukUB18ReNli8uyOQPH4a", "MusicPlayer\\UA.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\UA.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Urban Assault для MixOS был установлен", "Внимание", MB_ICONASTERISK);
//            }
//        }
//
//
//        else if (LOWORD(wParam) == PLUGALL)
//        {
//            if (MessageBoxA(hWnd, "Это основные программы для MixOS от пианино и квеста до загрузчика роликов с Youtube и Терминала", "Внимание", MB_OKCANCEL | MB_ICONASTERISK) == IDOK)
//            {
//                //fPBMaxValIsSet = false;
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1WMcHZA-wSkntqDcPkvtHI2YGUgkgAjhc", "MusicPlayer\\ALLMYUTILITIES.zip", 0, &DownloadProgress);
//                URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1UNGNc57-UPIp6zh9Q4dCLgNTkasMeUmR", "MusicPlayer\\WIN3.zip", 0, &DownloadProgress);
//                system("MusicPlayer\\All.bat");
//                SendMessage(hwndProgressBar, PBM_SETPOS, 0, 0);
//                MessageBoxA(hWnd, "Все основные плагины для MixOS были успешно установлены", "Внимание", MB_ICONASTERISK);
//            }
//        }
//
//        else if (LOWORD(wParam) == PLUGDEL)
//        {
//            if (MessageBoxA(hWnd, "Это удалит все плагины для MixOS и превратит его в плеер!", "Внимание", MB_OKCANCEL | MB_ICONWARNING) == IDOK)
//            {
//                system("MusicPlayer\\del.bat");
//                MessageBoxA(hWnd, "Все плагины были успешно удалены!", "Внимание", MB_ICONASTERISK);
//            }
//        }
//
//        else if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
//        }
//
//
//
//        else if (LOWORD(wParam) == MYCOLOR)
//        {
//
//            CHOOSECOLOR cc;
//
//            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//            cc.lStructSize = sizeof(CHOOSECOLOR);
//            cc.hwndOwner = hWnd;
//            cc.lpCustColors = (LPDWORD)acrCustClr;
//            cc.rgbResult = rgbCurrent;
//            cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//
//            if (ChooseColor(&cc) == TRUE) {
//                hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbCurrent = cc.rgbResult;
//                InvalidateRect(hWnd, NULL, FALSE);
//            }
//
//            // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//        }
//
//        else if (LOWORD(wParam) == PLAY) {
//            BASS_ChannelFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_SampleFree(UASSAULT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Skellige.mp3", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//
//        else if (LOWORD(wParam) == PAUSE1) {
//            BASS_ChannelFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_SampleFree(UASSAULT);
//            BASS_Stop();
//            BASS_Start();
//        }
//
//        else if (LOWORD(wParam) == polupon) {
//            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_LAYERED);
//            SetLayeredWindowAttributes(hWnd, NULL, 220, LWA_ALPHA);
//        }
//        else if (LOWORD(wParam) == polupoff) {
//            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//            SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);
//        }
//
//        else if (LOWORD(wParam) == MAKE_TOP_MOST_WINDOW)
//            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        else if (LOWORD(wParam) == MAKE_TOP_WINDOW)
//            SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
//
//        else if (LOWORD(wParam) == TEXT_COLOR) {
//            CHOOSECOLOR cc;
//            static COLORREF acrCustClr[16]; // массив доп. цветов
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
//    case WM_HSCROLL:
//    {
//        if (hTrack == (HWND)lParam)
//        {
//            BASS_ChannelSetAttribute(QUEST_THEME, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
//        }
//    } break;
//
//
//    case WM_CTLCOLORSTATIC:
//    {
//        if (GetDlgCtrlID((HWND)lParam) == text1)
//        {
//            HDC hdcStatic = (HDC)wParam;
//            // or obtain the static handle in some other way
//            SetTextColor(hdcStatic, rgbTextColor); // text color
//
//            SetBkColor(hdcStatic, rgbCurrent);
//
//            return (LRESULT)GetStockObject(NULL_BRUSH);
//
//        }
//        //else if (GetDlgCtrlID((HWND)lParam) == PLD_PROGRESS_TEXT)
//        //{
//        //    HDC hdcStatic = (HDC)wParam;
//        //    // or obtain the static handle in some other way
//        //    SetTextColor(hdcStatic, rgbTextColor); // text color
//
//        //    SetBkColor(hdcStatic, rgbCurrent);
//
//        //    return (LRESULT)GetStockObject(NULL_BRUSH);
//
//        //}
//        else if (GetDlgCtrlID((HWND)lParam) == LENMUSIC)
//        {
//            HDC hdcStatic = (HDC)wParam;
//            // or obtain the static handle in some other way
//            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//            SetBkColor(hdcStatic, RGB(255, 255, 255));
//
//
//            return (LRESULT)(COLOR_WINDOW + 1);
//
//        }
//
//    }break;
//
//    case WM_PAINT: {
//        hdc = BeginPaint(hWnd, &ps);
//        //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
//        FillRect(hdc, &ps.rcPaint, hBrush);
//        /*SelectObject(hdc, hWhitePen);
//        MoveToEx(hdc, 0, 220, NULL);
//        LineTo(hdc, 720, 220);*/
//        /*SetBkMode(hdc, TRANSPARENT);*/
//
//        //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);
//
//        EndPaint(hWnd, &ps);
//        //return 0;
//
//    } break;
//
//        //case WM_KEYDOWN:
//        //    switch (lParam)
//        //    {
//        //        case VK_NUMPAD5:
//        //            if (key_pressed == false)
//        //            {
//        //                ShowWindow(tardis, SW_SHOW);
//        //                key_pressed = true;
//        //            }
//        //            else if (key_pressed == true)
//        //            {
//        //                ShowWindow(tardis, SW_HIDE);
//        //                key_pressed = false;
//        //            };
//        //            break;
//        //    }
//        //    break;
//
//    case WM_DESTROY: {
//        //DeleteObject(hWhitePen);
//        BASS_Free();
//        DeleteObject(hBrush);
//        Shell_NotifyIcon(NIM_DELETE, &nid);
//        PostQuitMessage(0);
//        //return 0;
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
//}
//
//int WINAPI main()
//{
//    SetThreadLocale(MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), SORT_DEFAULT));
//    //CoInitialize(NULL);
//
//    //SetProcessDPIAware();
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//
//    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Загрузчик плагинов для MixOS", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 720) / 2,
//        (GetSystemMetrics(SM_CYSCREEN) - 360) / 2, 720, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//    //CoUninitialize();
//    return 0;
//}