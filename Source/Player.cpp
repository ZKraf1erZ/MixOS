#include <windows.h>
#include<winuser.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include "resource.h"       
#include "resource1.h"
#include "resource2.h"
#include"targetver.h"
#include "framework.h"
#include "targetver.h"
#include <conio.h>
#include <shlobj.h>
#include <ks.h>
#include <string>
#include<mciapi.h>
#include<Mmsystem.h>
#include <mmeapi.h>
#include<mmdeviceapi.h>
#include "Names.h"
#include "bass.h"
#include "wingdi.h"
#include <commdlg.h>
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include "Commctrl.h"
//#include <dwmapi.h>
//
//#pragma comment(lib, "dwmapi.lib")

//#include <shlwapi.h> 
//#include <filesystem>

#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
//#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "comctl32.lib")

using namespace std;
//HWND eMp3;
HWND SKIN;
HWND okno;
HWND ERRORs;
char str1[MAX_PATH];

HSTREAM stro;
//HSTREAM MORNING;
//HSTREAM UFO;
//HSTREAM SAMPLEADV;
//HSTREAM DNO;
//HSTREAM VISTA;
//HSTREAM EYES;
//HSTREAM LONELY;
//HSTREAM GIRL;
//HSTREAM START;

HDC hdc; //создаём контекст устройства
HDC hcdc;
PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода   
LOGFONT lf;
RECT r;
HPEN hPen;
HBRUSH hBrush = CreateSolidBrush(RGB(0, 76, 153)); // 0 118 236
//HBRUSH hLightBlueBrush = CreateSolidBrush(RGB(0, 191, 255));
HFONT hFont;
HWND hTrack;
HWND hTrack1;
HWND FOR6COMPOSIT;
HWND hTrack2;
HWND FOR6COMPOSIT1;

HWND sbar;
HWND playlist;
//char str2[MAX_PATH];
HWND eSearch;
//char strs[MAX_PATH];

int skins;
TCHAR StrT[MAX_PATH];
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;

TCHAR progname[] = _T("MixOS Beta 2.4 SP1");
HICON progicon;
HINSTANCE hInst;

static COLORREF acrCustClr[16]; 
static DWORD rgbCurrent1 = RGB(0, 76, 153);        
static DWORD rgbCurrent = RGB(0, 76, 153);
static DWORD rgbTextColor = RGB(255, 255, 255); // 193 209 240

inline void free_samples_all();

NOTIFYICONDATA notifyIconData;

HBITMAP hWallpaperBitmap;
BITMAP bm;
HDC hCompatibleDC;
bool bIsWallpaperSet = false;

RECT rcClient;

//bool IsTopMost = false;

//typedef NTSYSAPI NTSTATUS (NTAPI *LPFN_RTLGETVERSION)(
//    OUT PRTL_OSVERSIONINFOW lpVersionInformation
//);

static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {
        /*DWMNCRENDERINGPOLICY renderingPolicy = DWMNCRP_DISABLED;
        BOOL allowNCPaint = TRUE;

        DwmSetWindowAttribute(hWnd, DWMWA_NCRENDERING_POLICY, &renderingPolicy, sizeof(renderingPolicy));
        DwmSetWindowAttribute(hWnd, DWMWA_ALLOW_NCPAINT, &allowNCPaint, sizeof(allowNCPaint));*/

        notifyIconData.cbSize = sizeof(notifyIconData);
        notifyIconData.hWnd = hWnd;
        notifyIconData.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
        notifyIconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        notifyIconData.uCallbackMessage = WM_USER_SHELLICON;
        notifyIconData.hIcon = progicon;
        notifyIconData.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
        strcpy(notifyIconData.szTip, progname);

        /*rgbCurrent1 = RGB(255, 255, 255);*/

        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);

        Shell_NotifyIcon(NIM_ADD, &notifyIconData);

        SetBkMode(hdc, OPAQUE);
        BASS_Init(-1, 44100, 0, 0, NULL);

        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        CreateWindow(TEXT("STATIC"), TEXT("Что желаете запустить?"), WS_VISIBLE | WS_CHILD, 550, 20, 160, 15, hWnd, (HMENU)text1, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("Плеер (2)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 200, 500, 300, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
        SendMessage(GetDlgItem(hWnd, ID_BUTTON), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Эмуляторы (5)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 200, 500, 300, hWnd, (HMENU)Emulators, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Emulate.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, Emulators), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Контекстменюмейкер (3)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 530, 500, 100, hWnd, (HMENU)MENUMAKER, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\menumaker.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, MENUMAKER), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Квест (6)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 530, 500, 100, hWnd, (HMENU)QUEST, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, QUEST), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);     //Иконка нормально смотрится теперь..


        CreateWindow(TEXT("BUTTON"), TEXT("Пианино (4)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 80, 500, 100, hWnd, (HMENU)PIANINO, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\piano.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PIANINO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Терминал (1)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 80, 500, 100, hWnd, (HMENU)TERMINAL, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\terminal.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, TERMINAL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ролик с Youtube (7)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 650, 1030, 25, hWnd, (HMENU)YOUTUBE, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\youtube.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, YOUTUBE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll); // а ты в войс впустишь?   да щас поговорю и продолжим кодить. я щас.

        BASS_Start();
        stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Mozart.mp3", 0, 0, 0);
        BASS_ChannelPlay(stro, false);

        hTrack1 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS /*| LVS_EX_TRANSPARENTBKGND*/ | WS_VISIBLE | TBS_ENABLESELRANGE, 10, 20, 100, 20, hWnd, (HMENU)LENMUSIC4, NULL, NULL);
        /*ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_SHOW);*/
        SendMessage(hTrack1, TBM_SETPOS, 0, 1);
        SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, 100);
        CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 25, 60 - 20, 70, 18, hWnd, (HMENU)text11, NULL, NULL);

        /*eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD|WS_VISIBLE , 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
        ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
        SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до картинки BMP, например MusicPlayer\\BMP\\st.bmp");*/

        CreateWindow("BUTTON", "Установить скин", WS_VISIBLE | WS_CHILD, 120, 80 - 30 - 30, 150, 20, hWnd, (HMENU)SETBKG, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, SETBKG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow("BUTTON", "Установить полупрозрачность", WS_VISIBLE | WS_CHILD, 120, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)polupon, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\desktop.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, polupon), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow("BUTTON", "Выключить полупрозрачность", WS_CHILD, 120, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)polupoff, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\computer.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, polupoff), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        //Че это? это описание функции для генерации документации   а ок
        CreateWindow("BUTTON", "Удалить скин", WS_VISIBLE | WS_CHILD, 120 + 150 + 20, 80 - 30 - 30, 150, 20, hWnd, (HMENU)CLEARSKIN, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\delete.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, CLEARSKIN), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow("BUTTON", "Сменить цвет", WS_VISIBLE | WS_CHILD, 830, 80 - 30 - 30, 320, 20, hWnd, (HMENU)MYCOLOR, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Color.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, MYCOLOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        /*CreateWindow("BUTTON", "Загрузить плагины", WS_VISIBLE | WS_CHILD, 830, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)LOADDLL, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, LOADDLL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);*/
        CreateWindow("BUTTON", "Сменить цвет текста", WS_VISIBLE | WS_CHILD, 830, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)TEXT_COLOR, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\textcolor.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, TEXT_COLOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        //SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);

        //SendMessage(hWnd, WM_COMMAND, ID_BUTTON, 0);

        //AnimateWindow(hWnd, 200, AW_ACTIVATE | AW_SLIDE | AW_VER_NEGATIVE);

        GetClientRect(hWnd, &rcClient);
    }

                  break;

    case WM_COMMAND: {

        switch (LOWORD(wParam)) {
            
            case ID_BUTTON:
        {
            SetWindowText(hWnd, "MixPlayer из MixOS Beta 2.4 SP1");

            HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
            HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            DestroyWindow(GetDlgItem(hWnd, SETBKG));
            DestroyWindow(GetDlgItem(hWnd, CLEARSKIN));
            DestroyWindow(GetDlgItem(hWnd, polupoff));
            DestroyWindow(GetDlgItem(hWnd, polupon));
            DestroyWindow(GetDlgItem(hWnd, /*LOADDLL*/ TEXT_COLOR));
            DestroyWindow(GetDlgItem(hWnd, MYCOLOR));
            //DestroyWindow(GetDlgItem(hWnd, SKINSSTRO));
            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            DestroyWindow(GetDlgItem(hWnd, LENMUSIC4));
            DestroyWindow(GetDlgItem(hWnd, SEARCH));                     //Главное правило инженера: Работает - не трогай!  =)
            //ShowWindow(GetDlgItem(hWnd, SEARCH), SW_HIDE);
            //ShowWindow(eMp3, SW_HIDE);
            //skins = GetWindowText(eMp3, StrT, MAX_PATH);

            ShowWindow(GetDlgItem(hWnd, text11), SW_HIDE);
            BASS_SampleFree(stro);
            BASS_ChannelFree(stro);
            BASS_StreamFree(stro);
            BASS_Stop();
            BASS_Start();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Vista.mp3", 0, 0, 0);
            BASS_ChannelPlay(stro, false);


            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_HIDE);


            HMENU hMenubar = CreateMenu();
            HMENU hFile = CreateMenu();
            HMENU hAbout = CreateMenu();
            HMENU hCreator = CreateMenu();
            HMENU hHelp = CreateMenu();
            HMENU hUtils = CreateMenu();
            HMENU hInstall = CreateMenu();
            HMENU hRasvl = CreateMenu();
            HMENU hOptions = CreateMenu();
            HMENU hChangeFont = CreateMenu();
            HMENU hChangeColor = CreateMenu();
            HMENU hWhat = CreateMenu();

            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile, "Файл");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCreator, "О разработчике");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hHelp, "Шашнахме");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hUtils, "Системные утилиты");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hInstall, "Установка полезного софта");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hRasvl, "Развлечения");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hWhat, "С чего начиналась разработка?");


            //AppendMenu(hOptions, MF_STRING, SAVEINI, "Сохранить настройки");





            //SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            AppendMenu(hFile, MF_STRING, IU_STR, "Выход");
            AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hFile, MF_STRING /*| MF_OWNERDRAW*/, MENUMENUMENUMENU, "Вернуться в меню");

            AppendMenu(hFile, MF_STRING, SOURCE, "Исходный код");
            AppendMenu(hFile, MF_STRING, FASTRESTART, "Быстрая перезагрузка Windows");

            AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
            //AppendMenu(hAbout, MF_SEPARATOR, 0, NULL);
            //AppendMenu(hAbout, MF_STRING, INFORMATION_FROM_Z_KRAF1ER_Z, "Информация от Z_Kraf1er_Z");


            AppendMenu(hCreator, MF_STRING, WOZRAST, "Возраст");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, WEIGHT, "Вес");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, ROSTE, "Рост");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, DUSHA, "Душа");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, POL, "Пол");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hCreator, MF_STRING, ABOUTDEV, "О процессе разработки");

            AppendMenu(hHelp, MF_STRING, HELP, "Помощь");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, QUEST, "Поиграть в шашнахме квест");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, PIANINO, "Поиграть на пианино");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, TERMINAL, "Открыть терминал");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, CONVERTER, "Открыть конвертер валют");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hHelp, MF_STRING, MENUMAKER, "Открыть контекстменюмейкер для Windows");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, YOUTUBE, "Открыть загрузчик видосов с ютуба");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, ERTOR, "Открыть генератор случайных чисел");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, VIDEO, "Открыть видеоплеер");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, PHOTOVIEWER, "Открыть просмотрщик фотографий");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, TRANSLATE, "Открыть руингтранслит");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            //AppendMenu(hHelp, MF_STRING, RADIO, "Открыть радио");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            //AppendMenu(hHelp, MF_STRING, SELFUP, "Открыть помощник по повышению самооценки (для девушек).");

            AppendMenu(hUtils, MF_STRING, NOTEPAD, "Открыть блокнот");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, RSTRUI, "Открыть восстановление системы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, DEFRAG, "Открыть дефрагментацию диска");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, TASKMGR, "Открыть диспетчер задач");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, DEVICES, "Открыть диспетчер устройств");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, CALC, "Открыть калькулятор");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, RESMON, "Открыть монитор ресурсов");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, CLEANMGR, "Открыть очистку диска");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, PANEL, "Открыть панель управления");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, PERSONALIZE, "Открыть персонализацию");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hUtils, MF_STRING, GPEDIT, "Открыть редактор групповых политик");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, REGEDIT, "Открыть редактор реестра");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, SYSTEMA, "Открыть свойства системы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, COMPMGMT, "Открыть управление компьютером");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSCONFIG, "Открыть msconfig");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSINFO32, "Открыть msinfo32");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSPAINT, "Открыть paint");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, VERIFIER, "Открыть verifier");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MRT, "Открыть MRT");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, EVENTVWR, "Открыть просмотр событий");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, SERVICES, "Открыть службы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, TASKSCHD, "Открыть планировщик заданий");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MDSCHED, "Открыть средство проверки памяти Windows");
            AppendMenu(hUtils, MF_SEPARATOR, 0, NULL);
            AppendMenu(hUtils, MF_STRING, OPTIONALFEATURES, "Открыть компоненты Windows");



            AppendMenu(hInstall, MF_STRING, VISUAL, "Установить Visual C++ редисты");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, VISUALSTUDIO, "Установить Visual Studio 2022");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, OBS, "Установить OBS");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, VEGAS, "Открыть CPU-Z");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, HW, "Открыть HW monitor");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, BOMB, "Открыть Revo Uninstaller");



            AppendMenu(hRasvl, MF_STRING, EMULATE, "Эмуляторы");
            AppendMenu(hRasvl, MF_STRING, COMP4, "Компьютерная эволюция 4");


            AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
            /*AppendMenu(hOptions, MF_STRING, WHITE_TEXT_COLOR, "Сменить цвет текста на белый");
            AppendMenu(hOptions, MF_STRING, BLACK_TEXT_COLOR, "Сменить цвет текста на черный");*/
            AppendMenu(hOptions, MF_STRING, TEXT_COLOR, "Сменить цвет текста");
            //AppendMenu(hOptions, MF_STRING, MYFONT, "Сменить шрифт");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, SETBKG, "Сменить фон на картинку");
            AppendMenu(hOptions, MF_STRING, CLEARSKIN, "Убрать картинку");
            AppendMenu(hOptions, MF_STRING, SKIN1, "Картинка 1");
            AppendMenu(hOptions, MF_STRING, SKIN2, "Картинка 2");
            AppendMenu(hOptions, MF_STRING, SKIN3, "Картинка 3");
            AppendMenu(hOptions, MF_STRING, SKIN4, "Картинка 4");
            AppendMenu(hOptions, MF_STRING, SKIN5, "Картинка 5");
            AppendMenu(hOptions, MF_STRING, SKIN6, "Картинка 6");
            AppendMenu(hOptions, MF_STRING, SKIN7, "Картинка 7");
            AppendMenu(hOptions, MF_STRING, SKIN8, "Картинка 8");
            AppendMenu(hOptions, MF_STRING, SKIN9, "Картинка 9");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, polupon, "Включить полупрозрачность");
            AppendMenu(hOptions, MF_STRING, polupoff, "Выключить полупрозрачность");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, MAKE_TOP_MOST_WINDOW, "Поверх остальных окон");
            AppendMenu(hOptions, MF_STRING, MAKE_TOP_WINDOW, "На уровень остальных окон");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, /*WS_DISABLED|*/ MF_STRING | MF_DISABLED , LOADDLL, "Загрузить плагины...");
            /*AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, GET_WINDOWS_VERSION, "Узнать версию Windows");*/



            AppendMenu(hWhat, MF_STRING, OLDVER13, "MusicPlayer Beta 1.3");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER15, "MusicPlayer Beta 1.5");
            /*AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING | MF_DISABLED, OLDVER16, "MusicPlayer Beta 1.6");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER175, "MusicPlayer Beta 1.75");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER18, "MusicPlayer Beta 1.8");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER19, "MusicPlayer Beta 1.9");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER20, "MixOS Beta 2.0");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER21, "MixOS Beta 2.1");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER22, "MixOS Beta 2.2");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVERPRE23, "MixOS Pre Beta 2.3 (MixOS Lite)");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, MIXOSVER24, "MixOS Beta 2.4");*/

            SetMenu(hWnd, hMenubar);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TERMINAL), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PIANINO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, YOUTUBE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, QUEST), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("MixPlayer Version Beta 2.4. copyright ©StrannikCorp. All rights reserved. Service Pack 1 by Z_Kraf1er_Z"), WS_VISIBLE | WS_CHILD, 400 - 110, 20, 500 + 190, 25, hWnd, (HMENU)text1, NULL, NULL);

            CreateWindow(TEXT("STATIC"), TEXT("*************************************Привет, этот плеер проигрывает музыку в любых форматах*********************************************"), WS_VISIBLE | WS_CHILD, 200, 40, 899, 25, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Расширение указывать не нужно. За вас это сделает плейлист =)"), WS_VISIBLE | WS_CHILD, 480 - 25-50, 60, 450, 20, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Тут уже имеется пара композиций"), WS_VISIBLE | WS_CHILD, 500, 100, 230, 20, hWnd, (HMENU)text1, NULL, NULL);



            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Morning"), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)DEVUSHKA, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
            SendMessage(GetDlgItem(hWnd, DEVUSHKA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Captain Strannik - SeasonFlights"), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)LETO, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, LETO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Sample Adventures"), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)SHAG, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, SHAG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Above the Sky"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)SLOVO, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, SLOVO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Phasmaton - Heresy"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)PEREMEN, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, PEREMEN), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Lonely"), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)CIGARET, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, CIGARET), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow("BUTTON", ">", WS_VISIBLE | WS_CHILD, 770 + 300 + 20, 150 + 70 - 15, 40, 40, hWnd, (HMENU)NEXT, NULL, NULL);
            CreateWindow("BUTTON", "<", WS_CHILD, 90, 150 + 70 - 15, 40, 40, hWnd, (HMENU)BACK, NULL, NULL);


            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - In Your Eyes"), WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)MUSIC_7, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_7), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - UFO"), WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)MUSIC_8, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_8), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Waxie"), WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)MUSIC_9, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_9), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Моцарт - Турецкий марш"), WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)MUSIC_10, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_10), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Redhead Girl"), WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)MUSIC_11, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_11), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Captain Strannik - Hard Thing"), WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)MUSIC_12, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, MUSIC_12), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



            CreateWindow(TEXT("BUTTON"), TEXT("Остановить музыку "), WS_VISIBLE | WS_CHILD, 770, 500, 300, 70, hWnd, (HMENU)STOPS, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, STOPS), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), /*TEXT("Перейти к своим файлам")*/ TEXT("Открыть свой файл"), WS_VISIBLE | WS_CHILD, 150, 500, 300, 70, hWnd, (HMENU)FILEY2, NULL, NULL);

            //hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, FILEY2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Открыть свой файл"), WS_CHILD, 150, 500, 300, 70, hWnd, (HMENU)MIXPLAYER_OLD_PLAY_BUTTON, NULL, NULL);

            SendMessage(GetDlgItem(hWnd, MIXPLAYER_OLD_PLAY_BUTTON), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            /*  Слушай, как сделать так, чтобы текст был без фона белого?  */


            CreateWindow(TEXT("BUTTON"), TEXT("Продолжить"), /*WS_VISIBLE |*/ WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE2, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\play.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PAUSE2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Пауза"), /*WS_VISIBLE |*/ WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE1, NULL, NULL);


            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\pause.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PAUSE1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            //ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            // ShowWin
              //CreateWindow(TEXT("BUTTON"), TEXT("Очистить RAM"), WS_VISIBLE | WS_CHILD, 550, 600, 110, 20, hWnd, (HMENU)RAMRAM, NULL, NULL);


            /*eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 430, 1175 - 30, 20, hWnd, (HMENU)YOUMUSIC, NULL, 0);
            CreateWindow("BUTTON", "Поиск", WS_VISIBLE | WS_CHILD, 460, 500-80, 300, 70, hWnd, (HMENU)SEARCH, NULL, NULL);
            SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до вашей музыки, в любом формате =) (С расширением) Например:  MusicPlayer\\Violet S\\Lonely.mp3");*/
            //SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
            /*hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);*/



            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450 - 150 - 100, 590 - 220 /*+ 40*/, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
            SendMessage(hTrack, TBM_SETPOS, 0, 1);
            SendMessage(hTrack, TBM_SETRANGEMAX, TRUE, 100);


            hTrack2 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450 + 150 + 100, 590 - 220 /*+ 40*/, 320, 30, hWnd, (HMENU)LENMUSIC3, NULL, NULL);
            SendMessage(hTrack2, TBM_SETRANGE, 0, 0);

            FOR6COMPOSIT = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450-150-100, 590 - 220, 320, 30, hWnd, (HMENU)LENMUSIC2, NULL, NULL);
            SendMessage(FOR6COMPOSIT, TBM_SETPOS, 0, 1);
            SendMessage(FOR6COMPOSIT, TBM_SETRANGEMAX, TRUE, 100);

            FOR6COMPOSIT1 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE | WS_VISIBLE, 450+150+100, 590-220, 320, 30, hWnd, (HMENU)LENMUSIC5, NULL, NULL);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGE, 0, 0);

            //hTrack1 = CreateWindow(TRACKBAR_CLASS, "LENGTH", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 150, 390, 923, 30, hWnd, (HMENU)LENMUSIC1, NULL, NULL);
            //SendMessageA(hWnd, TBM_SETPOS, TRUE, 50);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_CHILD, 570 - 150 - 100, 590 - 240 + 50 /*+ 40*/, 70, 20, hWnd, (HMENU)VOLUMASTA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_CHILD, 570-150-100, 590 - 240+50, 70, 20, hWnd, (HMENU)VOLUMASTA1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Ползунок воспроизведения"), WS_CHILD, 515 + 150 + 100, 590 - 240 + 20 + 30 /*+ 40*/, 190, 20, hWnd, (HMENU)SOUNDMASTA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Ползунок воспроизведения"), WS_CHILD | WS_VISIBLE, 515+150+100, 590-240+20+30, 190, 20, hWnd, (HMENU)SOUNDMASTA1, NULL, NULL);

            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_SHOW);

            CreateWindow(TEXT("STATIC"), TEXT("Для файлов теперь работает Drag'n Drop"), WS_CHILD, 470, 100, 280, 20, hWnd, (HMENU)textdnd, NULL, NULL);

            sbar = CreateStatusWindow(WS_CHILD | WS_VISIBLE, NULL, hWnd, 0);
            //sbar = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE, 0, 643, 1280, 20, hWnd, NULL, NULL, NULL);

            CreateWindow(TEXT("STATIC"), TEXT("Плейлист"), WS_CHILD, 570, 130, 65, 18, hWnd, (HMENU)textpl, NULL, NULL);
            playlist = CreateWindow(/*WS_EX_NOACTIVATE,*/ "LISTBOX", NULL, WS_CHILD | LBS_HASSTRINGS | WS_HSCROLL | WS_VSCROLL, 150, 150, 920, 180, hWnd, NULL, NULL, NULL);
            SendMessage(playlist, LB_INITSTORAGE, 0x7FFF, MAX_PATH); // выделяем память для списка
            UpdateWindow(playlist);
            CreateWindow("BUTTON", "Выбрать/Проиграть" /*"Вставить файл"*/, WS_CHILD, (150 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLSEL, NULL, NULL);
            CreateWindow("BUTTON", "Добавить файл", WS_CHILD, (310 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLADD, NULL, NULL);
            CreateWindow("BUTTON", "Удалить файл", WS_CHILD, (470 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLDEL, NULL, NULL);
            /*eSearch = CreateWindow("EDIT", NULL, WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 630, 335, 310, 20, hWnd, NULL, NULL, NULL);
            SendMessageW(eSearch, EM_SETCUEBANNER, FALSE, (LPARAM)L"Поиск файла в плейлисте");
            CreateWindow("BUTTON", "Найти файл", WS_CHILD, 950, 330, 120, 30, hWnd, (HMENU)PLSEARCH, NULL, NULL);*/

            //CreateWindow("BUTTON", "Автоматическая сортировка", WS_CHILD | BS_CHECKBOX | BS_AUTOCHECKBOX, 630, 330, 205, 30, hWnd, (HMENU)PLSORT, NULL, NULL);

           //if (PathFileExistsA(str1))
           //{
           //    SetWindowText(eMp3, str1);
           //}

            //Ну вот это уже похоже на С++   =)
            // а как проверить наличие файла?       Нуууу
            // без winapi&        можно попробовать через else.  типа

            ShowWindow(GetDlgItem(hWnd, YOUMUSIC), SW_HIDE);

            rcClient.bottom -= GetSystemMetrics(SM_CYMENU);
            rcClient.bottom -= 23;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
        } break;
        
        //case GET_WINDOWS_VERSION) {
        //    /*OSVERSIONINFO osvi;
        //    ZeroMemory(&osvi, sizeof(osvi));
        //    osvi.dwOSVersionInfoSize = sizeof(osvi);
        //    GetVersionEx(&osvi);

        //    char szWindowsVersion[34];
        //    sprintf(szWindowsVersion, "%u.%u.%u", osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);

        //    MessageBox(hWnd, szWindowsVersion, "Версия Windows:", MB_OK | MB_ICONINFORMATION);*/

        //    RTL_OSVERSIONINFOW rtlosvi;
        //    ZeroMemory(&rtlosvi, sizeof(rtlosvi));
        //    rtlosvi.dwOSVersionInfoSize = sizeof(rtlosvi);

        //    HMODULE hNtosKrnl = LoadLibrary("ntoskrnl.exe");

        //    LPFN_RTLGETVERSION lpfnRtlGetVersion = (LPFN_RTLGETVERSION)(GetProcAddress(hNtosKrnl, "RtlGetVersion"));

        //    lpfnRtlGetVersion(&rtlosvi);

        //    FreeLibrary(hNtosKrnl);

        //    char szWindowsVersion[34];
        //    sprintf(szWindowsVersion, "%u.%u.%u", rtlosvi.dwMajorVersion, rtlosvi.dwMinorVersion, rtlosvi.dwBuildNumber);

        //    MessageBox(hWnd, szWindowsVersion, "Версия Windows:", MB_OK | MB_ICONINFORMATION);
        //}

        case NEXT: {
            ShowWindow(GetDlgItem(hWnd, NEXT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, MUSIC_7), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUSIC_8), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUSIC_9), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUSIC_10), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUSIC_11), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUSIC_12), SW_SHOW);
        } break;

        case BACK: {
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, NEXT), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, MUSIC_7), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_8), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_10), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_11), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_12), SW_HIDE);
        } break;

        case COMP4:
        {
            system("start C:\\WIN\\GAMES\\COMP4\\1.bat");


        } break;
        case TRANSLATE:
        {
            system("start MusicPlayer\\SUBS\\NBR\\ru4en.hta");


        } break;




        case polupon:
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_SHOW);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES | WS_EX_LAYERED);
            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        } break;

        case polupoff:
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_HIDE);
            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
        } break;





        case SETBKG:
        {


            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            OPENFILENAME ofnn;

            ZeroMemory(&ofnn, sizeof(OPENFILENAME));
            ofnn.lStructSize = sizeof(OPENFILENAME);
            ofnn.hwndOwner = hWnd;
            ofnn.lpstrFile = StrT;
            ofnn.nMaxFile = sizeof(StrT);

            ofnn.nFilterIndex = 1;
            ofnn.lpstrFileTitle = NULL;
            ofnn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXSKIN";
            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofnn) == TRUE) {
                ////SetWindowText(eMp3, str1);

                //DestroyWindow(hwall);
                //DestroyWindow(GetDlgItem(hWnd, INSTBKG));
                //ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);

                //ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);

                ////skins = GetWindowText(eMp3, StrT, MAX_PATH);
                //bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                //bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

                //if (bmpwall != NULL);
                //{

                //    hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                //    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                //    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

                //}

                if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
                hWallpaperBitmap = (HBITMAP)LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                if (hWallpaperBitmap != NULL) {
                    GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                    if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                    //InvalidateRect(NULL, NULL, NULL);
                    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
                }

                /*CreateWindow(TEXT("BUTTON"), TEXT("Установить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
            }
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);

        } break;


        case SKIN1:
        {
            /*DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }*/

            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN2:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN3:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN4:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        }
        case SKIN5:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN6:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        }break;
        case SKIN7:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN8:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case SKIN9:

        {
            if (hWallpaperBitmap != NULL) { DeleteObject(hWallpaperBitmap); hWallpaperBitmap = NULL; }
            hWallpaperBitmap = (HBITMAP)LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image9.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (hWallpaperBitmap != NULL) {
                GetObject(hWallpaperBitmap, sizeof(bm), &bm);
                if (bIsWallpaperSet == false) bIsWallpaperSet = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case CLEARSKIN:

        {
            if (hWallpaperBitmap != NULL) {
                DeleteObject(hWallpaperBitmap);
                hWallpaperBitmap = NULL;
                if (bIsWallpaperSet == true) bIsWallpaperSet = false;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }
        } break;
        case MYCOLOR:
        {

            CHOOSECOLOR cc;

            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = hWnd;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.rgbResult = rgbCurrent;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            // я просто в шоке. ты вообще понимаешь что ты делал?
            //if (ChooseColor(&cc) == TRUE) {
            //    bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            //    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);

            //    hBrush = CreateSolidBrush(cc.rgbResult);
            //    rgbCurrent = cc.rgbResult;


            //}
            //else
            //{

            //    /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            //       SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
            //    hBrush = CreateSolidBrush(RGB(0, 76, 153));
            //    rgbCurrent = RGB(0, 76, 153);
            //    return 0;
            //};

            if (ChooseColor(&cc) == TRUE) {
                if (hWallpaperBitmap != NULL) {
                    DeleteObject(hWallpaperBitmap);
                    hWallpaperBitmap = NULL;
                    if (bIsWallpaperSet == true) bIsWallpaperSet = false;
                }
                DeleteObject(hBrush);
                hBrush = CreateSolidBrush(cc.rgbResult);
                rgbCurrent = cc.rgbResult;

                InvalidateRect(hWnd, NULL, FALSE);
            }

            // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
        } break;

        case MIXPLAYER_OLD_PLAY_BUTTON:
        case PLSEL:
        {
            SendMessage(playlist, LB_GETTEXT, SendMessage(playlist, LB_GETCURSEL, 0, 0), (LPARAM)str1);
            //SetWindowText(eMp3, str2);
            free_samples_all();
            BASS_Stop();
            BASS_Start();

            int len;
            TCHAR *StrB = str1;
            //len = GetWindowText(eMp3, StrB, 1200);
            BASS_ChannelStop(stro);

            stro = BASS_StreamCreateFile(FALSE, StrB, 0, 0, 0);

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                          "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(hTrack2, TBM_SETPOS, TRUE, 0);
            SendMessage(hTrack2, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));
            
            //UpdateWindow(hTrack2);

            //SendMessage(hTrack1, TBM_SETRANGEMIN, TRUE, 0);
            //SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, BASS_ChannelGetPosition(stro, BASS_POS_BYTE));
            //BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, 1);
            //SendMessage(hTrack, TBM_SETLINESIZE, NULL, 100);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(hTrack2, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);


        } break;
        case PLADD:
        {
            
            OPENFILENAME ofn;

            ZeroMemory(&ofn, sizeof(OPENFILENAME));
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hWnd;
            ofn.lpstrFile = str1;
            ofn.nMaxFile = sizeof(str1);
            //ofn.lpstrFilter = "MP3\0.MP3\0WAV\0.WAV\0";
            //ofn.lpstrFilter = ".mp3\0.wav\0.mp4\0.ogg\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofn.lpstrInitialDir = "MusicPlayer\\Your";
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofn) == TRUE)
            {
               
                /*SetWindowText(eMp3, str1);
                GetWindowText(eMp3, str1, MAX_PATH);*/
                SendMessage(playlist, LB_ADDSTRING,  0, (LPARAM)str1);
            }
        } break;
        case PLDEL:
        {
            int curSel = SendMessage(playlist, LB_GETCURSEL, 0, 0);
            SendMessage(playlist, LB_DELETESTRING, curSel, 0);
            SendMessage(playlist, LB_SETCURSEL, (WPARAM)curSel - 1, 0);
        } break;
        /* case PLSEARCH)
         {
             GetWindowText(eSearch, strs, MAX_PATH);
             SendMessage(playlist, LB_SELECTSTRING, -1, (LPARAM)strs);

         }*/
         /*case PLSORT)
         {
             if (SendMessage(GetDlgItem(hWnd, PLSORT), BM_GETCHECK, 0, 0) == BST_CHECKED)
             {
                 SetWindowLongPtr(playlist, GWL_STYLE, WS_CHILD | LBS_HASSTRINGS | WS_HSCROLL | WS_VSCROLL | LBS_SORT | WS_VISIBLE);
             }
             else
             {
                 SetWindowLongPtr(playlist, GWL_STYLE, WS_CHILD | LBS_HASSTRINGS | WS_HSCROLL | WS_VSCROLL | WS_VISIBLE);
             }
         }*/


         //case SAVEINI)
         //{
         //    string rgb = to_string(rgbCurrent);

         //    // не удалять ни в коем случае
         //    //if (SHCreateDirectoryEx(NULL, Directory, NULL) ||
         //    //    GetLastError() == ERROR_ALREADY_EXISTS)

         //    //WritePrivateProfileSection("color", "test", "settings.ini");
         //    //WritePrivateProfileString("color", "selected", rgb.c_str(), "settings.ini");




   /*
             ofstream Proga;

             Proga.open("settings.cfg");
             Proga << rgb;
             Proga.close();*/









             //    //CloseHandle(hIni);
             //}
             //case MYFONT)
             //{
             //    CHOOSEFONT cf;
             //    static LOGFONT lf;        // структура логического шрифта
             //    static DWORD rgbCurrent;  // текущий цвет текста
             //    HFONT hfont, hfontPrev;
             //    DWORD rgbPrev;

             //    ZeroMemory(&cf, sizeof(CHOOSEFONT));
             //    cf.lStructSize = sizeof(CHOOSEFONT);
             //    cf.hwndOwner = hWnd;
             //    cf.lpLogFont = &lf;
             //    cf.rgbColors = rgbCurrent;
             //    cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

             //    if (ChooseFont(&cf) == TRUE)
             //    {
             //        hfont = CreateFontIndirect(cf.lpLogFont);
             //        hfontPrev = (HFONT)SelectObject(hdc, hfont);
             //        rgbCurrent = cf.rgbColors;
             //        rgbPrev = SetTextColor(hdc, rgbCurrent);
             //        SendMessage(hWnd, WM_SETFONT, (WPARAM)hfont, FALSE);
             //       
             //        // ладно
             //    }     
             //}
             //case MYFONT)
             //{
             //    HFONT hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
             //    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, NULL);
             //}
        case MENUMAKER:
        {
            system("start MusicPlayer\\MENUMAKER\\MENUMAKER.exe");

        } break;
        case ERTOR:
        {
            system("start MusicPlayer\\SUBS\\ERTOR\\gen.exe");

        } break;
        case PHOTOVIEWER:
        {
            system("start MusicPlayer\\PhotoViewer\\CreeperPhotoViewer.exe");
        } break;
        //case SELFUP:
        //{
        //    system("start MusicPlayer\\love\\helpup.exe");
        //} break;
        case YOUTUBE:
        {
            system("start MusicPlayer\\Youtube\\Youtube.exe");
        } break;
        case HW:
        {
            system("start MusicPlayer\\Install\\HW\\HW.exe");
        } break;

        case VEGAS:
        {
            system("start MusicPlayer\\Install\\CPUZ\\cpuz64.exe");
        } break;

        case OBS:
        {
            system("start MusicPlayer\\Install\\OBS\\OBS.exe");
        } break;

        case VISUALSTUDIO:
        {
            system("start MusicPlayer\\Install\\VisualStudio\\Setup.exe");
        } break;
        case BOMB:
        {
            system("start MusicPlayer\\Progs\\REVO\\RevoUnin.exe");
        } break;
        case SPY:
        {
            system("start MusicPlayer\\Progs\\SHUTUP\\KILLSPY.exe");
        } break;
        case PANEL:
        {
            system("start control");
        } break;
        case VISUAL:
        {
            MessageBoxA(hWnd, "После закрытия этого окна будут переустановлены все VISUAL C++ редисты, если вы не уверены, то отменить это можно чуть позже в консоли.", "Внимание", MB_ICONINFORMATION);
            system("start MusicPlayer\\Install\\Visual\\Visual.bat");
        } break;
        case OLDVER13:
        {
            MessageBoxA(hWnd, "Сейчас будет запущен плеер версии Beta 1.3. По сути это прадедушка MixOS. С него всё и началось.", "MusicPlayer Beta 1.3", MB_ICONINFORMATION);
            system("start MusicPlayer\\OLD\\1.3.bat");
        } break;
        case OLDVER15:
        {
            MessageBoxA(hWnd, "Сейчас будет запущен плеер версии Beta 1.5. Официально это первая графическая версия моего плеера.\nНеофициально это была Beta 1.4. ", "MusicPlayer Beta 1.5", MB_ICONINFORMATION);
            system("start MusicPlayer\\OLD\\1.5.bat");
        } break;
       /* case OLDVER16: {

        } break;*/
        //case OLDVER175: {
        //    //MessageBox(hWnd, "Версия 1.75. Первая версия, которая опубликована на GitHub. Так что я даю ссылку на скачивание.", "MusicPlayer Beta 1.75", MB_ICONINFORMATION);
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.1.75");
        //} break;
        //case OLDVER18: {
        //    //MessageBox(hWnd, "Версия 1.8. Исправления, добавления и обновления:\r\n1. Исправлен баг с неосвобождением памяти.\r\n2. Обновлен терминал.\r\n3. Добавлена сборка Windows 3.11, Minecraft 1.5.2 и другое.\r\n4. Графические обновления.\r\n5. Новые музыкальные композиции.\r\nТак что я даю ссылку на скачивание.", "MusicPlayer Beta 1.8", MB_ICONINFORMATION);
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.1.8");
        //} break;
        //case OLDVER19: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.1.9");
        //} break;
        //case OLDVER20: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.2.0");
        //} break;
        //case OLDVER21: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.2.1");
        //} break;
        //case OLDVER22: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.2.2");
        //} break;
        //case OLDVERPRE23: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.2.3LITE");
        //} break;
        //case MIXOSVER24: {
        //    system("start https://github.com/CaptainStrannik/MixOS/releases/tag/v0.2.4");
        //} break;
        case TERMINAL:
        {
            system("start MusicPlayer\\TERMINAL\\TERMINAL.EXE");

        } break;

        case PIANINO:
        {
            system("start MusicPlayer\\Piano\\piano.exe");

        } break;
        case CONVERTER:
        {
            system("start MusicPlayer\\CONVERT\\converter.exe");

        } break;
        case Emulators:
        case EMULATE:
        {

            system("start MusicPlayer\\Emulators\\Emulate.exe");
        } break;

        case DEVUSHKA:
        {
            BASS_Stop();

            BASS_Start();
         
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Headless Nick - Morning");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Morning.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case LETO:
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Captain Strannik - SeasonFlights");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SF.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case SHAG:
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Headless Nick - Sample Adventures.mp3");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Sample Adventures.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case SLOVO:
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(stro);
            BASS_ChannelFree(stro);
            BASS_StreamFree(stro);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Deteez - Above the Sky.mp3");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Above the Sky.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case CIGARET:
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Violet S - Lonely.mp3");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Lonely.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));
            
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case PEREMEN:
        {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Phasmaton - Heresy.mp3");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Phasmaton - Heresy.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_7: {
            BASS_Stop();

            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Violet S - In Your Eyes");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\In Your Eyes.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_8: {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Headless Nick - UFO");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\UFO.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_9: {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Violet S - Waxie");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Waxie.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_10: {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(stro);
            BASS_ChannelFree(stro);
            BASS_StreamFree(stro);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Моцарт - Турецкий марш");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Mozart.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_11: {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Violet S - Redhead Girl");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Redhead Girl.mp3", 0, 0, 0);


            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;
        case MUSIC_12: {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Captain Strannik - Hard Thing");
            free_samples_all();
            stro = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\HTM.mp3", 0, 0, 0);

            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
        } break;

        case STOPS:
        {
            //CreateWindow(TEXT("STATIC"), TEXT("Музыка выключена                                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Музыка выключена");
            //ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            free_samples_all();
            BASS_Stop();
            BASS_Start();

        } break;

        case WEIGHT:
        {
            MessageBoxA(hWnd, "А зачем вам знать? Вес штука сложная", "Вес", MB_ICONINFORMATION);
        } break;
        case WOZRAST:
        {
            MessageBoxA(hWnd, "Возраст? Так прям интересно? Ну переведите 10100 в десятичную систему\nА вообще, если вы шашнахме, то знайте, др у меня в хеллоуин", "Возраст 20", MB_ICONINFORMATION);
        } break;
        case ROSTE:
        {
            MessageBoxA(hWnd, "В какое время суток вам это нужно? Если утром, то зачем, а если вечером, то для чего?\nНу, утром я самый высокий, а ближе к ночи я карапуз.\nА так, шашнахме... Не знаю. Ну 190 СМ", "Рост", MB_ICONINFORMATION);
        } break;
        case DUSHA:
        {
            MessageBoxA(hWnd, "Душа у меня такая ранимая, а у вас?\nСомневаюсь, что такая же ранимая, как у меня.\nВедь я Шашнахме, а кость у вас видно толстая", "Душа", MB_ICONINFORMATION);
        } break;
        case POL:
        {
            MessageBoxA(hWnd, "Пол? А зачем вы спрашиваете? И так понятно, что пол штука плосская =). И где конкретно? Например дома \nу меня паркет и линолеум. А на даче древесина =).", "Пол", MB_ICONINFORMATION);
        } break;

        /*case INFORMATION_FROM_Z_KRAF1ER_Z: {
            MessageBox(hWnd, "", "Информация от Z_Kraf1er_Z", MB_OK | MB_ICONINFORMATION);
        } break;*/

        case STRANNIK:
        {
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
            MessageBoxA(hWnd, "Добро пожаловать в MixOS версии BETA 2.4.\nКоторая нужна для того, чтобы автор набрался опыта.\nЭто уже не просто плеер. Это больше похоже на свою ОС\nПравда без своего ядра (пока что).\nВсё что в ней есть это зеркало автора.\nТо есть, психологически, если углубляться, то можно понять, что MixOS это отражение всего что делает автор и как поступает. ", "О программе MixOS Beta 2.2", MB_ICONINFORMATION);

        } break;
        case HELP:
        {
            MessageBoxA(hWnd, "Если Вы шашнахме в моем плеере, то я вам щас все расскажу. Короче, есть кнопки, которые проигрывают музыку. Эти кнопки проигрывают конкретные песни моих друзей. Что написано, то и сыграется. Чтобы сыграть свою мелодию, просто впишите путь к ней с ее названием и нажмите кнопку <<Открыть свой файл>>. Если вдруг вы не знаете путь до музыки или если у вас толстая кость, просто нажмите кнопку <<Поиск>>. Если вы до сих пор хз как этим пользоваться, то че вы тут вообще делаете?", "Помощь", MB_OK);
            MessageBoxA(hWnd, "Также тут есть простой доступ к системным утилитам, попробуйте =)", "Помощь", MB_OK);
            MessageBoxA(hWnd, "И это, я вижу, у вас не толстая кость. Раз так, отожмитесь 10 раз. Чтобы проверить, толстая кость у вас или нет, я запущу шашнахме квест, который вы могли и без меня пройти =)", "Помощь", MB_ICONINFORMATION);
            system("start MusicPlayer\\Quest\\quest.exe");
        } break;

        case ABOUTDEV:
        {
            MessageBoxA(hWnd, "      Здравствуйте, это Strannik. И этот плеер нужен для того, для чего он нужен =). Я же - Создатель этого плеера. Мое имя Вам ни о чем не скажет. Но я расскажу вам историю о том, с чего начинался этот проект.                                                   Сидел я как-то вечером, за компом, и хотел уже наконец сделать что-то хорошее на с++, полезное. До этого, опыта в написании программ языке С++ у меня было мало. Конвертер валют и пара консольных программ. В итоге я решил: <<Почему бы не сделать музыкальный плеер?>>. Написание первой версии кода было ужасным времяпрепровождением. Я писал плохо, но со временем получалось лучше. И ура, я сделал первую версию плеера. Alpha 1.0. Она проигрывала только wav файлы и только конкретные 8 композиций, но начало уже было положено. На следующий день я выпустил версию beta 1.1, которая проигрывала около 20 wav композиций. Знания по функции PlaySound я отточил максимально тогда. Потом друзья мне сказали, что было бы неплохо добавить возможность проигрывать любые wav файлы. Так и сразу появилась beta 1.3. Как понимаете, тут у меня такая же история, как у microsoft =). Плеер уже умел проигрывать любую wav музыку, но это все было не то. Поэтому в версии Beta 1.4, которая вышла буквально позавчера (30.06.2021), Появился графический интерфейс, который работал даже на linux, но через wine. Самое главное чего мне не хватало это поддержки mp3. И я покопался в библиотеке bass, которую, к слову, используют все кому не лень, начиная с 90х годов 20 века. Также, чтобы было не так грустно, и, чтобы обновление было более глобальным, я добавил в плеер удобное меню, для запуска системных утилит. Вы спросите зачем? Ну так они ничего не жрут, занимают пару строк кода в программе. И самое главное, реально удобно! Попробуйте сами!                                                                                                           Сейчас (03.07.2021) Это версия beta 1.6, и в ней добавилась поддержка других форматов, при этом, для вашего удобства две строки ввода заменились на одну! Но, не без жертв, теперь музыку снова надо будет указывать с расширением. Но тут мои полномочия всё.                                           Всему виной библиотека bass.dll, которой надо скормить путь к мелодии и ее название с расширением. Пока не знаю, что с этим делать. Думаю, что до версии beta 1.8 уже точно додумаю =).", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Сейчас 22.10.2021. Прошло блин уже 3 месяца с создания версии 1.6. Много чего произошло у меня в жизни.\nЯ набрался опыта. И в целом, добавил просто ТОННУ возможностей в этот плеер.\nВ частности это Пианино, Терминал с пасхалками и командами. Практически полностью доделанный Шашнахме квест.\nНовые кнопки в стиле Windows 7.\nКонвертер валют. В общем, идем в ногу со временем\nТолько часики отстали лет на 15 =). ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 1.8. Выпущена 10.02.2022.\nДобавилось много всего интересного.\nВпервые я исправил баг с памятью.\nТеперь плеер почти ничего не ест.\nДобавил сюда кучу всего интересного, все пасхалки найдете сами. Их более 30 штук. =)", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 1.9. Привнесла достаточно много изменений, впрочем, это уже неважно, потому что вы используете как минимум версию 2.0", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.0. Я не помню, какие конкретно вещи были добавлены в 1.9.\nПоэтому назову всё то новое, что есть в 2.0,\nпо сравнению с 1.8. А добавлено:\n\n1) Терминал со своими командами\n2) Пианино\n3) Контекстменюмейкер\n5) Загрузчик роликов с youtube\n6) Эмуляторы приставок и компов с играми\n7) Различные программы и утилиты\n8) Смена цвета =). \n\n\nНа данный момент (15.06.2022)\nВпервые программа называется гордо: MixOS", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.1. Теперь это не плеер, а MixOS. Причем полноценно. Хотя пока что без своего ядра =).\nЧто нового:\n 1) Улучшен графический интерфейс и кастомизация цвета.\n2) Добавлены ползунки громкости.\n3) Генератор случайных чисел от The Ertor.\n4) Цифра в названии.\n5) Drag and drop.\n6) В контекстменюмейкере теперь можно также и удалять пункты меню.\n7) Скрытая команда для 18+ аудитории в терминале. Первая буква P, последняя N. Всего 4 буквы\n8) Исправление некоторых багов. (КОНЕЧНО БАГИ ЕСТЬ ЕЩЕ!).  ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.2. Интерфейс в MixOS был переработан глобально. Сложно представить более серъезный апдейт.\nЧто нового:\n1) Еще более скрупулёзное улучшение графического интерфейса.\nПолностью переработан дизайн и общая атмосфера программы.\n2) Обновлены: \nа) Пианино\nб) Контекстменюмейкер\nв) Терминал\nг) Список эмуляторов\nд) Загрузчик роликов с Youtube\n\rКонечно, я бы не справился так быстро, если бы не один мой подписчик: Z_Kraf1er_Z, который тоже приложил руку\nк этой версии MixOS.", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "    Было добавлено : \n1) Видеоплеер\n2) Просмотрщик фотографий\n3) Рандомайзер\n4) Старые версии MusicPlayer\n5) Компьютерная эволюция 4\n6) Руинтранслитор\n7) Прочие улучшения визуала. ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.3. Её код был основан на коде LITE версии.\nК сожалению, помощник Z_Krafter_Z более не участвует в проекте.\nЯ максимально не хотел ссориться, потому что как\nпрограммист он знает толк.\nНо как человек. В общем там отдельная история\nсвязанная с политикой. Но я думал и верил, что\nтворчество должно быть аполитичным.\nПоэтому я убрал всякое упоминание в коде о нём, чтобы не вспоминать. ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.3. Из нововведений здесь:\n 1) Мой сборник игры из детства, которую я перенёс на новый игровой движок.\n 2) Всё, что было в LITE версии, а именно плейлист", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.4. Мораль: <<Не судите про апдейт по обложке. Внешность обманчива>>. Теперь вы можете скачивать различные подпрограммы для MixOS", "О процессе разработки", MB_ICONINFORMATION);
        } break;
        case IU_STR:
        {
            if (MessageBox(hWnd, "Вы действительно хотите выйти из MixOS?", "Выход", MB_YESNO | MB_ICONWARNING) == IDYES)
                SendMessage(hWnd, WM_CLOSE, 0, 0);
        } break;
        case SOURCE:
        {
            MessageBoxA(hWnd, "Исходники лежат на гитхабе", "Исходный код", MB_OK);
            system("start https://github.com/CaptainStrannik/MixOS");

        } break;
        case PAUSE1:
        {
            //CreateWindow(TEXT("STATIC"), TEXT("Пауза                                                        \n                                      "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Пауза");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_SHOW);

            //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_HIDE);
            //ShowWindow(hTrack2, SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_HIDE);
            BASS_ChannelStop(stro);
            //пауза
        } break;
        case PAUSE2:   //продолжить
        {
            BASS_ChannelPlay(stro, false); //плей
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                                "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);


            //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            //ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            //ShowWindow(hTrack2, SW_SHOW);
            //ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);
        } break;
        case FILEY2:
        {

            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, textpl), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, textdnd), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA1), SW_HIDE);
            ShowWindow(FOR6COMPOSIT1, SW_HIDE);

            
            ShowWindow(GetDlgItem(hWnd, PAUSE1), /*SW_SHOW*/ SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);


            ShowWindow(hTrack2, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);
            ShowWindow(playlist, SW_SHOW);
            //ShowWindow(eSearch, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLSEL), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLADD), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLDEL), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MIXPLAYER_OLD_PLAY_BUTTON), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FILEY2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PLSEARCH), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, MUSIC_7), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_8), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_10), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_11), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUSIC_12), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, NEXT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);

            free_samples_all();
            BASS_Stop();
            BASS_Start();

            int argc = __argc;
            char **argv = __argv;

            if (argc > 1) {
                for (int i = 1; i < argc; i++) {
                    SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)argv[i]);
                }
            }

            //int len;
            //TCHAR *StrB = str1;
            //BASS_ChannelStop(stro);

            //stro = BASS_StreamCreateFile(FALSE, StrB, 0, 0, 0);

            ////CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                          "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            //SetWindowText(sbar, "Проигрывается ваша музыка)");
            //BASS_ChannelPlay(stro, false); // проигрывание файла
            //SendMessage(hTrack2, TBM_SETPOS, 0, 0);
            //SendMessage(hTrack2, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            //UpdateWindow(hTrack2);

            //SendMessage(hTrack1, TBM_SETRANGEMIN, TRUE, 0);
            //SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, BASS_ChannelGetPosition(stro, BASS_POS_BYTE));
            //BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, 1);
            //SendMessage(hTrack, TBM_SETLINESIZE, NULL, 100);
        } break;

        //case LOADDLL:
        //{
        //    /*if (MessageBox(hWnd, "Запустить от имени администратора?", "Загрузить плагины", MB_ICONQUESTION | MB_YESNO) == IDYES)
        //        ShellExecute(NULL, "runas", "MusicPlayer\\DWL\\MixDownload.exe", NULL, NULL, SW_SHOWDEFAULT);
        //    else*/
        //        system("start MusicPlayer\\DWL\\MixDownload.exe");
        //} break;

        case QUEST:
        {
            system("start MusicPlayer\\Quest\\quest.exe");
        } break;
        case VIDEO:
        {
            system("start MusicPlayer\\VideoPlayer\\VideoPlayer.exe");
        } break;
        case CALC:
        {
            system("start calc.exe");
        } break;
        case TASKMGR:
        {
            system("start taskmgr.exe");
        } break;
        case CLEANMGR:
        {
            system("start cleanmgr.exe");
        } break;
        case REGEDIT:
        {
            system("start regedit.exe");
        } break;

        // Deprecated by PLADD
        
        //case SEARCH)
        //{
        //    /*system("@echo off");
        //    system("explorer MusicPlayer");    */
        //    OPENFILENAME ofn;

        //    ZeroMemory(&ofn, sizeof(OPENFILENAME));
        //    ofn.lStructSize = sizeof(OPENFILENAME);
        //    ofn.hwndOwner = hWnd;
        //    ofn.lpstrFile = str1;
        //    ofn.nMaxFile = sizeof(str1);
        //    //ofn.lpstrFilter = "MP3\0.MP3\0WAV\0.WAV\0";
        //    //ofn.lpstrFilter = ".mp3\0.wav\0.mp4\0.ogg\0";
        //    ofn.nFilterIndex = 1;
        //    ofn.lpstrFileTitle = NULL;
        //    ofn.nMaxFileTitle = 0;
        //    //ofn.lpstrInitialDir = ".";
        //    ofn.lpstrInitialDir = "MusicPlayer\\Your";
        //    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

        //    if (GetOpenFileName(&ofn) == TRUE)
        //    {
        //        //SetWindowText(eMp3, str1);
        //      
        //        //GetWindowText(eMp3, str1, MAX_PATH);
        //        SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)str1);
        //    }
        //}

        case DEFRAG:
        {
            system("start dfrgui.exe");
        } break;
        case GPEDIT:
        {
            system("start gpedit.msc");
        } break;
        case PERSONALIZE:
        {
            system("explorer shell:::{ED834ED6-4B5A-4bfe-8F11-A626DCB6A921}");
        } break;
        case RSTRUI:
        {
            system("start rstrui.exe");
        } break;
        case SYSTEMA:
        {
            system("explorer shell:::{bb06c0e4-d293-4f75-8a90-cb05b6477eee}");
        } break;
        case DEVICES:
        {
            system("start devmgmt.msc");
        } break;
        case MSCONFIG:
        {
            system("start msconfig.exe");
        } break;
        case RESMON:
        {
            system("start resmon.exe");
        } break;
        case NOTEPAD:
        {
            system("start notepad.exe");
        } break;
        case MSINFO32:
        {
            system("start msinfo32.exe");
        } break;
        case COMPMGMT:
        {
            system("start compmgmt.msc");
        } break;
        case VERIFIER:
        {
            system("start verifier.exe");
        } break;
        case MSPAINT:
        {
            system("start mspaint.exe");
        } break;
        case MRT:
        {
            system("start MRT.exe");
            //WinExec("MRT.exe", SW_SHOW);
        } break;
        case EVENTVWR:
        {
            system("start eventvwr.msc");
        } break;
        case SERVICES:
        {
            system("start services.msc");
        } break;
        case TASKSCHD:
        {
            system("start taskschd.msc");
        } break;
        case MDSCHED:
        {
            system("start mdsched.exe");
        } break;

        case OPTIONALFEATURES: {
            system("start OptionalFeatures.exe");
        } break;

        case MENUMENUMENUMENU:
        {
            STARTUPINFO si = { sizeof(STARTUPINFO) };
            PROCESS_INFORMATION pi;
            CreateProcess(NULL, GetCommandLine(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
            CloseHandle(pi.hThread);
            CloseHandle(pi.hProcess);

            //system("start MixOS.exe");
            SendMessage(hWnd, WM_CLOSE, 0, 0);
        } break;
        case FASTRESTART:
        {
            if (MessageBox(hWnd, "Перед тем как перезагрузиться, обязательно закройте все программы!", "Внимание!", MB_OKCANCEL | MB_ICONWARNING) == IDOK)
                ExitWindowsEx(EWX_RESTARTAPPS, NULL);
        } break;

        case TEXT_COLOR: {
            CHOOSECOLOR cc;
            static COLORREF acrCustClr[16]; // массив доп. цветов

            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = hWnd;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.rgbResult = rgbTextColor;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            if (ChooseColor(&cc) == TRUE) {
//              hBrush = CreateSolidBrush(cc.rgbResult);
                rgbTextColor = cc.rgbResult;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
            }

            
        } break;

        /*case TEXT_COLOR: {
            rgbTextColor = RGB(255, 255, 255);
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
        } break;

        case BLACK_TEXT_COLOR: {
            rgbTextColor = RGB(0, 0, 0);
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
        } break;*/

        /*case MAKE_TOP_MOST_WINDOW: {
            if (IsTopMost == false) {
                SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
                ModifyMenu(GetMenu(hWnd), MAKE_TOP_MOST_WINDOW, MF_CHECKED, MAKE_TOP_MOST_WINDOW, NULL);
                IsTopMost = true;
            } else {
                SetWindowPos(hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
                ModifyMenu(GetMenu(hWnd), MAKE_TOP_MOST_WINDOW, MF_BYCOMMAND | MF_UNCHECKED, MAKE_TOP_MOST_WINDOW, NULL);
                IsTopMost = false;
            }
        } break;*/

        case MAKE_TOP_MOST_WINDOW:
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
            break;

        case MAKE_TOP_WINDOW:
            SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
            break;

        //case KORZINA:
        //{
        //    SHEmptyRecycleBin(hWnd, "C:\\MixOS\\Trash", /*SHERB_NOCONFIRMATION*/ NULL);
        //} break;

        /*case PRINTER:
        {


            HANDLE hLPT = CreateFile("LPT1", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hLPT != INVALID_HANDLE_VALUE)
            {
                char buffer[5];
                memset(buffer, 0, sizeof(buffer));
                strcpy(buffer, "АБОБА");
                DWORD dw;
                OVERLAPPED ov;
                while (true)
                    WriteFile(hLPT, buffer, sizeof(buffer), &dw, &ov);
                CloseHandle(hLPT);
            }
        } break; */
        }
        


        break;

    case WM_HSCROLL: {
        if (hTrack == (HWND)lParam /*&& wParam != 0*/)
            BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 0, 0));
        if (hTrack1 == (HWND)lParam)
            BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, SendMessage(hTrack1, TBM_GETPOS, 0, 0));
        if (hTrack2 == (HWND)lParam && LOWORD(wParam) == SB_THUMBPOSITION /*|| LOWORD(wParam) == SB_PAGELEFT || LOWORD(wParam) == SB_PAGERIGHT*/)
            BASS_ChannelSetPosition(stro, BASS_ChannelSeconds2Bytes(stro, SendMessage(hTrack2, TBM_GETPOS, 0, 0)), BASS_POS_BYTE);
        if (FOR6COMPOSIT == (HWND)lParam)
        {

            BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 0, 0));
        }
        if (FOR6COMPOSIT1 == (HWND)lParam && LOWORD(wParam) == SB_THUMBPOSITION /*|| LOWORD(wParam) == SB_PAGELEFT || LOWORD(wParam) == SB_PAGERIGHT*/)
        {
            BASS_ChannelSetPosition(stro, BASS_ChannelSeconds2Bytes(stro, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            //BASS_ChannelSetPosition(VISTA, BASS_ChannelSeconds2Bytes(VISTA, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
        }
    } break;

        //Цикл обработки сообщений
    case WM_DROPFILES: {

        DragQueryFile((HDROP)wParam, 0, str1, MAX_PATH);
        /*SetWindowText(eMp3, str1);
        GetWindowText(eMp3, str2, MAX_PATH);*/
        SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)str1);
    }
                     break;

    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
        
        if (bIsWallpaperSet == true) {
            hCompatibleDC = CreateCompatibleDC(hdc);

            SelectObject(hCompatibleDC, hWallpaperBitmap);
            SetStretchBltMode(hdc, HALFTONE);
            SetBrushOrgEx(hdc, 0, 0, NULL);
            StretchBlt(hdc, 0, 0, rcClient.right, rcClient.bottom, hCompatibleDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

            DeleteDC(hCompatibleDC);
        } else {
            FillRect(hdc, &ps.rcPaint, hBrush);
        }
        
        
        //FrameRect(hdc, &ps.rcPaint, hLightBlueBrush);
        /*SetBkMode(hdc, TRANSPARENT);*/

        //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);

        EndPaint(hWnd, &ps);
        //return 0;

    } break;


    case WM_KEYDOWN:
    {
        switch (LOWORD(wParam))
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        case VK_SPACE:
            SendMessage(hWnd, WM_COMMAND, SETBKG, 0);
            break;
        case VK_RETURN:
            SendMessage(hWnd, WM_COMMAND, FILEY2, 0);
            break;
        case '1':
            SendMessage(hWnd, WM_COMMAND, TERMINAL, 0);
            break;
        case '2':
        {   

            SendMessage(hWnd, WM_COMMAND, ID_BUTTON, 0);

                                                    //need to fix this bug
        }
            break;
        case '3':
            SendMessage(hWnd, WM_COMMAND, MENUMAKER, 0);
            break;
        case '4':
            SendMessage(hWnd, WM_COMMAND, PIANINO, 0);
            break;
        case '5':
            SendMessage(hWnd, WM_COMMAND, Emulators, 0);
            break;
        case '6':
            SendMessage(hWnd, WM_COMMAND, QUEST, 0);
            break;
        case '7':
            SendMessage(hWnd, WM_COMMAND, YOUTUBE, 0);
            break;
        case VK_NUMPAD1:
            SendMessage(hWnd, WM_COMMAND, SKIN1, 0);
            break;
        case VK_NUMPAD2:
            SendMessage(hWnd, WM_COMMAND, SKIN2, 0);
            break;
        case VK_NUMPAD3:
            SendMessage(hWnd, WM_COMMAND, SKIN3, 0);
            break;
        case VK_NUMPAD4:
            SendMessage(hWnd, WM_COMMAND, SKIN4, 0);
            break;
        case VK_NUMPAD5:
            SendMessage(hWnd, WM_COMMAND, SKIN5, 0);
            break;
        case VK_NUMPAD6:
            SendMessage(hWnd, WM_COMMAND, SKIN6, 0);
            break;
        case VK_NUMPAD7:
            SendMessage(hWnd, WM_COMMAND, SKIN7, 0);
            break;
        case VK_NUMPAD8:
            SendMessage(hWnd, WM_COMMAND, SKIN8, 0);
            break;
        case VK_NUMPAD9:
            SendMessage(hWnd, WM_COMMAND, SKIN9, 0);
            break;


        case VK_MBUTTON:
            SendMessage(hWnd, WM_COMMAND, MYCOLOR, 0);
            break;

        case VK_ADD:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_CHECKED, 0);
            break;



        case VK_SUBTRACT:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_UNCHECKED, 0);
            break;




        }

    }
    break;

    case WM_SETFOCUS:
        SetFocus(hWnd);
        break;

    /*case WM_ENTERSIZEMOVE:
        SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES | WS_EX_LAYERED);
        SetLayeredWindowAttributes(hWnd, NULL, 191, LWA_ALPHA);
        break;
        
    case WM_EXITSIZEMOVE:
        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
        SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
        break;*/

    /*case WM_NCPAINT:
    {
        HDC hdcnc = GetDCEx(hWnd, (HRGN)wParam, DCX_WINDOW | DCX_INTERSECTRGN);

        ReleaseDC(hWnd, hdc);
    }
    break;*/

    /*case WM_CLOSE:
        AnimateWindow(hWnd, 200, AW_HIDE | AW_SLIDE | AW_VER_POSITIVE);
        SendMessage(hWnd, WM_DESTROY, 0, 0);
        break;*/

    case WM_DESTROY:
        free_samples_all();
        BASS_Free();
        //SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
        //SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);
        Shell_NotifyIcon(NIM_DELETE, &notifyIconData);
        if (bIsWallpaperSet == true) DeleteObject(hWallpaperBitmap);
        DeleteObject(hBrush);
        PostQuitMessage(0);
        break;


    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;

        if (GetDlgCtrlID((HWND)lParam) == text1)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }

        if (GetDlgCtrlID((HWND)lParam) == text11)
        {
            hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == textdnd)
        {
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == textpl)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == LENMUSIC1)
        {
            
            // or obtain the static handle in some other way
           /* SetTextColor(hdcStatic, RGB(255, 255, 255));*/ // text color

            SetBkColor(hdcStatic, rgbCurrent1);

            return (LRESULT)GetStockObject(RGB(255, 255, 255));

        }

        if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA1)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA)
        {
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == SOUNDMASTA)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == SOUNDMASTA1)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }

        if (GetDlgCtrlID((HWND)lParam) == DEFDEF)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI2)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI3)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI4)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == CHB1)
        {
            
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, rgbTextColor); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(RGB(0, 76, 153));

        }

        //if ((HWND)lParam == sbar) {
        //    
        //    // or obtain the static handle in some other way
        //    SetTextColor(hdcStatic, rgbTextColor); // text color

        //    SetBkColor(hdcStatic, rgbCurrent);

        //    return (LRESULT)GetStockObject(NULL_BRUSH);
        //}





    }break;

    break;

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
                   return 0;
    }


}

inline void free_samples_all()
{
    BASS_ChannelFree(stro);
    BASS_StreamFree(stro);
    BASS_SampleFree(stro);
}

int WINAPI main(/*int argc, char* argv[]*/)
{
    //if (argc > 1)
    //{
    //    strcpy(str1, argv[2]);
    //} 

    //SetProcessDPIAware();

    //SetThreadLocale(MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), SORT_DEFAULT));
    //LCID lcid = MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), SORT_DEFAULT);
    //SetProcessPreferredUILanguages(MUI_LANGUAGE_ID, (PCZZWSTR)&lcid, NULL);
    SetThreadUILanguage(MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA));

    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(WNDCLASS));
    wc.lpfnWndProc = wnd_proc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MixOS";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    progicon = (HICON)LoadImage(wc.hInstance, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    wc.hIcon = progicon;
    //wc.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
    //wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    //wc.hbrBackground = CreateSolidBrush(RGB(0,76,153));    //0 76 153
    //wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    RegisterClass(&wc);


    CreateWindowEx(WS_EX_ACCEPTFILES /*| WS_EX_RIGHT*/ /*| WS_EX_LAYOUTRTL*/, wc.lpszClassName, progname, /*WS_POPUPWINDOW |*/ WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX  /*WS_OVERLAPPEDWINDOW*/ | WS_VISIBLE | WS_CLIPSIBLINGS, (GetSystemMetrics(SM_CXSCREEN) - 1280 + 2) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - 720 + 2) / 2, 1280 + 2, 720 + 2, NULL, NULL, wc.hInstance, NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    return 0;

}

