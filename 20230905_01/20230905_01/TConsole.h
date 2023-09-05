/* --------------------------------------------------------------------------------------

	class TConsole - General class library for Windows console application

	Programmed by Eddie

	Version 1.0 - 2007/06/28

	1. First release

-------------------------------------------------------------------------------------- */

#ifndef TCONSOLE_H
#define TCONSOLE_H

namespace tvision {

	// Predefined color set
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define PURPLE			5
#define BROWN			6
#define LIGHTGRAY		7
#define GRAY			8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define LIGHTPURPLE		13
#define YELLOW			14
#define WHITE			15

/*
Attribute						Meaning
-----------------------------------------------------------------------------
FOREGROUND_BLUE					Text color contains blue.
FOREGROUND_GREEN				Text color contains green.
FOREGROUND_RED					Text color contains red.
FOREGROUND_INTENSITY			Text color is intensified.
BACKGROUND_BLUE					Background color contains blue.
BACKGROUND_GREEN				Background color contains green.
BACKGROUND_RED					Background color contains red.
BACKGROUND_INTENSITY			Background color is intensified.
COMMON_LVB_LEADING_BYTE			Leading byte.
COMMON_LVB_TRAILING_BYTE		Trailing byte.
COMMON_LVB_GRID_HORIZONTAL		Top horizontal.
COMMON_LVB_GRID_LVERTICAL		Left vertical.
COMMON_LVB_GRID_RVERTICAL		Right vertical.
COMMON_LVB_REVERSE_VIDEO		Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE			Underscore.
*/

	enum CursorMode
	{
		CURSOR_ON,		// Normal cursor
		CURSOR_OFF,		// No cursor
		CURSOR_BIG		// Big solid cursor
	};

	class TConsole
	{
	public:
		static TConsole& GetConsole();

		// Title
		int SetTitle(const char* title);

		// Cursor functions
		int SetCursor(CursorMode mode);
		int WhereX() const;
		int WhereY() const;
		int GotoXY(const int x, const int y);

		// Window related functions
		int GetMaxX() const;				// Maximum window size including buffer
		int GetMaxY() const;
		int GetDisplayX() const;			// Display window size
		int GetDisplayY() const;
		int GetBufferSizeX() const;			// Console buffer size
		int GetBufferSizeY() const;

		int SetWindowSize(const int width, const int height);
		int SetScreenFufferSize(const int width, const int height);

		// Color functions
		int SetColor(const WORD color);
		int SetColor(const WORD textcolor, const WORD bkcolor);
		int SetBkColor(const WORD color);
		int SetTextColor(const WORD color);
		int SetHighIntensity(bool high = true);	// For text only

		// Output text & drawing functions
		void ClearScreen(const WORD color = BLACK);
		void TextOut(int x, int y, char* text);
		void ClearArea(int x1, int y1, int x2, int y2);

		// Utilities
		void Delay(DWORD ms);

		//swtFontSize
		void setFontSize(int size);


	protected:
		static TConsole theInstance;

	private:
		HANDLE hConsole;							// Handle of console window
		TConsole();									// Hide constructor & desctructor
		~TConsole();
	};

}
#endif	// TCONSOLE_H

#ifdef COMPLIED_CONSOLE
namespace tvision {
	TConsole& TConsole::GetConsole()
	{
		return theInstance;
	}

	void TConsole::TextOut(int x, int y, char* text)
	{
		GotoXY(x, y);
		std::cout << text;
	}

	void TConsole::ClearArea(int x1, int y1, int x2, int y2)
	{
		int i, j;
		int x = WhereX();
		int y = WhereY();
		GotoXY(x1, y1);
		for (j = y1; j <= y2; j++)
		{
			for (i = x1; i <= x2; i++)
			{
				GotoXY(i, j);
				std::cout << (" ");
			}
		};
		GotoXY(x, y);
	}

	int TConsole::SetScreenFufferSize(const int width, const int height)
	{
		COORD coords = { static_cast<short>(width), static_cast<short>(height) };
		return SetConsoleScreenBufferSize(hConsole, coords);
	}

	int TConsole::SetWindowSize(const int width, const int height)
	{
		//if ( width <= 0 || width > GetBufferSizeX() ||
		//	height <= 0 || height > GetBufferSizeY() )
		//{
		//SetScreenFufferSize(width, height);	
		//}

		SMALL_RECT rect;

		rect.Left = 0;
		rect.Right = width - 1;
		rect.Top = 0;
		rect.Bottom = height - 1;

		return SetConsoleWindowInfo(hConsole, TRUE, &rect);
	}

	int TConsole::SetCursor(CursorMode mode)
	{
		CONSOLE_CURSOR_INFO cursorInfo;

		switch (mode)
		{
		case CURSOR_OFF:
			cursorInfo.bVisible = FALSE;
			cursorInfo.dwSize = 10;
			break;
		case CURSOR_ON:
			cursorInfo.bVisible = TRUE;
			cursorInfo.dwSize = 10;
			break;
		case CURSOR_BIG:
			cursorInfo.bVisible = TRUE;
			cursorInfo.dwSize = 100;
			break;
		}

		return SetConsoleCursorInfo(hConsole, &cursorInfo);
	}

	int TConsole::GetMaxX() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwMaximumWindowSize.X;
	}

	int TConsole::GetMaxY() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwMaximumWindowSize.Y;
	}

	int TConsole::GetBufferSizeX() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwSize.X;
	}

	int TConsole::GetBufferSizeY() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwSize.Y;
	}

	int TConsole::GetDisplayX() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return (screenInfo.srWindow.Right - screenInfo.srWindow.Left + 1);
	}

	int TConsole::GetDisplayY() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return (screenInfo.srWindow.Bottom - screenInfo.srWindow.Top + 1);
	}

	int TConsole::WhereX() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwCursorPosition.X;
	}

	int TConsole::WhereY() const
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return screenInfo.dwCursorPosition.Y;
	}

	int TConsole::GotoXY(const int x, const int y)
	{
		COORD coords = { static_cast<short>(x), static_cast<short>(y) };
		return SetConsoleCursorPosition(hConsole, coords);
	}

	int TConsole::SetColor(const WORD color)
	{
		return SetConsoleTextAttribute(hConsole, color);
	}

	int TConsole::SetHighIntensity(bool high)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		if (high)
			return SetColor(screenInfo.wAttributes | 0x0008);
		else
			return SetColor(screenInfo.wAttributes & 0xFFF7);
	}

	int TConsole::SetColor(const WORD textcolor, const WORD bkcolor)
	{
		return SetColor(bkcolor << 4 | textcolor);
	}

	int TConsole::SetBkColor(const WORD color)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return SetColor((screenInfo.wAttributes & 0xFF0F) | (color << 4));
	}

	int TConsole::SetTextColor(const WORD color)
	{
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		return SetColor((screenInfo.wAttributes & 0xFFF0) | color);
	}

	void TConsole::ClearScreen(const WORD color)
	{
		static const COORD topLeftCorner = { 0, 0 };

		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		GetConsoleScreenBufferInfo(hConsole, &screenInfo);

		SMALL_RECT screenSize;
		screenSize.Left = 0;
		screenSize.Top = 0;
		screenSize.Right = screenInfo.dwSize.X - 1;
		screenSize.Bottom = screenInfo.dwSize.Y - 1;

		_CHAR_INFO* buffer = new _CHAR_INFO[screenInfo.dwSize.X * screenInfo.dwSize.Y];
		_CHAR_INFO charInfo = { ' ', color << 4 };
		for (int i = 0; i < screenInfo.dwSize.X * screenInfo.dwSize.Y; i++)
		{
			buffer[i] = charInfo;
		}

		COORD bufferSize = { screenInfo.dwSize.X, screenInfo.dwSize.Y };

		WriteConsoleOutput(hConsole,
			buffer,
			bufferSize,
			topLeftCorner,
			&screenSize);

		delete[] buffer;
		GotoXY(0, 0);
		SetColor(screenInfo.wAttributes);
	}

	int TConsole::SetTitle(const char* title)
	{
		return SetConsoleTitle(title);
	}

	void TConsole::Delay(DWORD ms)
	{
		Sleep(ms);
	}

	void TConsole::setFontSize(int size)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}


	TConsole::TConsole()
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (INVALID_HANDLE_VALUE == hConsole)
		{
			std::cout << "Fatal error : hConsole is INVALID_HANDLE_VALUE" << std::endl;
			std::cout << "Program aborted." << std::endl;
			exit(1);
		}
	}

	TConsole::~TConsole()
	{
	}

}	// namespace tvision
#endif


