#include <iostream>
#include <Windows.h>
using namespace std;
enum eDrawTtpe
{
	EPOINT,
	ELINE,
	ERECT,
	ECIRCLE,
	END
};
struct Point
{
	int x;
	int y;
};
void main()
{
	// double array
	int arr[25] = { 0, };
	int arr2[25][20] = { 0, };
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr2[i][j] = 0;
		}
	}

	char board[25][25] = {};
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			board[i][j] = '#';
		}
	}
	cout << "print" << endl;
	//clean
	system("cls");
	//wait input
	system("pause");
	while (true)
	{

		system("cls");

		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				board[i][j] = '#';
			}
		}
		cout << "select drawing (0 POINT 1 LINE 2 RECT 3 CIRCLE)" << endl;
		int drawType = 0;
		cin >> drawType;
		switch (drawType)
		{
		case EPOINT:
			Point point;
			cout << "x coord";
			cin >> point.x;
			cout << "y coord";
			cin >> point.y;
			board[point.y][point.x] = 'q';
			break;
			//
			// 4 cases
			// x1>x2 y1>y2
			// x1<x2 y1>y2
			// x1>x2 y1<y2
			// x1<x2 y1<y2
			// for i
			//  for j 
			//  loop 
			//
		case ERECT:
			Point point1;
			cout << "x1 coord ";
			cin >> point1.x;
			cout << "y1 coord ";
			cin >> point1.y;
			Point point2;
			cout << "x2 coord ";
			cin >> point2.x;
			cout << "y2 coord ";
			cin >> point2.y;
			if (point1.x <= point2.x && point1.y <= point2.y)
			{
				for (int i = point1.x; i <= point2.x; i++)
				{
					for (int j = point1.y; j <= point2.y; j++)
					{
						board[j][i] = 'q';
					}
				}
			}
			else if (point1.x <= point2.x && point1.y >= point2.y)
			{
				for (int i = point1.x; i <= point2.x; i++)
				{
					for (int j = point2.y; j <= point1.y; j++)
					{
						board[j][i] = 'q';
					}
				}
			}
			else if (point1.x >= point2.x && point1.y <= point2.y)
			{
				for (int i = point2.x; i <= point1.x; i++)
				{
					for (int j = point1.y; j <= point2.y; j++)
					{
						board[j][i] = 'q';
					}
				}
			}
			else if (point1.x >= point2.x && point1.y >= point2.y)
			{
				for (int i = point2.x; i <= point1.x; i++)
				{
					for (int j = point2.y; j <= point1.y; j++)
					{
						board[j][i] = 'q';
					}
				}
			}
			break;
		// 4 cases
		// i-j=x-y
		// 

		case ELINE:
			Point point3;
			cout << "x1 coord ";
			cin >> point3.x;
			cout << "y1 coord ";
			cin >> point3.y;
			Point point4;
			cout << "x2 coord ";
			cin >> point4.x;
			cout << "y2 coord ";
			cin >> point4.y;
			if (point3.x <= point4.x && point3.y <= point4.y)
			{
				for (int i = point3.x; i <= point4.x; i++)
				{
					for (int j = point3.y; j <= point4.y; j++)
					{
						if (i-j== point3.x-point3.y)
						{
							board[j][i] = 'q';
						}
					}
				}
			}
			else if (point3.x <= point4.x && point3.y >= point4.y)
			{
				for (int i = point3.x; i <= point4.x; i++)
				{
					for (int j = point4.y; j <= point3.y; j++)
					{
						if (i - j == point3.x - point3.y)
						{
							board[j][i] = 'q';
						}
					}
				}
			}
			else if (point3.x >= point4.x && point3.y <= point4.y)
			{
				for (int i = point4.x; i <= point3.x; i++)
				{
					for (int j = point3.y; j <= point4.y; j++)
					{
						if (i - j == point3.x - point3.y)
						{
							board[j][i] = 'q';
						}
					}
				}
			}
			else if (point3.x >= point4.x && point3.y >= point4.y)
			{
				for (int i = point4.x; i <= point3.x; i++)
				{
					for (int j = point4.y; j <= point3.y; j++)
					{
						if (i - j == point3.x - point3.y)
						{
							board[j][i] = 'q';
						}
					}
				}
			}
			break;

		// x*x+y*y= z*z
		case ECIRCLE:
			Point point5;
			cout << "x1 coord ";
			cin >> point5.x;
			cout << "y1 coord ";
			cin >> point5.y;
			int radius;
			cin >> radius;
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					if ((i - point5.x) * (i - point5.x) + (j - point5.y) * (j - point5.y) < radius * radius)
					{
						board[j][i] = 'q';

					}
				}
			}
		}
		system("pause");
		//homework line rect
	}
}