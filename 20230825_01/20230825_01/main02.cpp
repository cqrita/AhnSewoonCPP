#include <iostream>
#define BINGO_SIZE 5
#define BOARD_SIZE (BINGO_SIZE*BINGO_SIZE)
using namespace std;
int _myBoard[BOARD_SIZE] = {};
int _comBoard[BOARD_SIZE] = {};
void InitilizeBoard(int board[])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board[i] = i + 1;
	}

	//섞는 로직
	//Swap * 100000번 반복
	for (int i = 0; i < 100000; i++)
	{
		/*int temp = a;
		a = b;
		b = temp;*/
		int num1 = rand() % BOARD_SIZE;
		int num2 = rand() % BOARD_SIZE;

		int temp = board[num1];
		board[num1] = board[num2];
		board[num2] = temp;
	}

}
void PrintBoard(int board[])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i % BINGO_SIZE == BINGO_SIZE - 1)
		{
			if (board[i] == -1)
			{
				cout << "#" << endl;
			}
			else
			{
				cout << board[i] << endl;
			}
		}
		else
		{
			if (board[i] == -1)
			{
				cout << "#" << "\t";
			}
			else
			{
				cout << board[i] << "\t";
			}
		}
	}

}
void MarkBoard(int input)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (input == _myBoard[i])
		{
			_myBoard[i] = -1;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (input == _comBoard[i])
		{
			_comBoard[i] = -1;
		}
	}

}
bool isCompleteBoard(int board[])
{
	// bingo line true
	// else false
	// 1.| 2. - 3. / 4. \
	
	// 1. temp 0
	// 2. if temp =-1 temp++
	// 3. if temp = bingo size true
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		int checkStartIndex = i * BINGO_SIZE;
		int temp = 0;
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			int checkIndex = checkStartIndex + j;
			if (board[checkIndex] == -1)
			{
				temp++;
			}
		}
		if (temp == BINGO_SIZE)
		{
			return true;
		}
	}
	//2. 
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		int checkStartIndex = i;
		int temp = 0;
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			int checkIndex = checkStartIndex + j*BINGO_SIZE;
			if (board[checkIndex] == -1)
			{
				temp++;
			}
		}
		if (temp == BINGO_SIZE)
		{
			return true;
		}
	}
	//3. \  
	int temp = 0;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		int checkIndex = i* BINGO_SIZE + i;
		if (board[checkIndex] == -1)
		{
			temp++;
		}
		if (temp == BINGO_SIZE)
		{
			return true;
		}
	}
	temp = 0;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		int checkIndex = i * BINGO_SIZE -i+BINGO_SIZE-1;
		if (board[checkIndex] == -1)
		{
			temp++;
		}
		if (temp == BINGO_SIZE)
		{
			return true;
		}
	}

	return false;
}
void main()
{
	// 빙고게임 만들기

	// 5x5로 이루어진 나의 판
	// 5x5로 이루어진 컴퓨터 판
	// 각 빙고판안에는 1~25까지의 숫자가 들어있음.

	// 내턴 -> 상대턴 -> 내턴 -> 상대턴 반복

	// 각자 턴일때, 숫자를 하나 부른다.
	// 부른 숫자는 숫자로 표기안되고 #으로 표기됨.

	//출력예시
	//나 : 
	// 7 6 15 20 #
	// 1 5 3  7  2
	// ...
	// ...
	// ...

	//상대 : 
	// 1 5 3  7  2
	// 7 6 15 20 #
	// ...
	// ...
	// ...

	// 빙고가 완성되면 해당 플레이어 승리.



	// 수도코드
	// 1.
	// 나의 판을 myBoard라고 부른다.
	// 나의 판을 1~25까지의 숫자로 초기화한다.
	// 나의 판을 섞는다.

	// 2.
	// 컴퓨터의 판을 comBaord라고 부른다.
	// 컴퓨터의 판을 1~25의 숫자로 초기화한다.
	// 컴퓨터의 판을 섞는다.

	// 3. myBoard를 출력한다.
	// 4. comBoard를 출력한다.

	// 5. 아래 내용을 반복한다.
	// 숫자를 하나 입력받는다.
	// 입력받은 이 숫자를 input이라고 부른다
	// myBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.
	// comBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.

	// 6.  숫자를 하나 랜덤으로 뽑아온다.
	// 입력받은 이 숫자를 input이라고 부른다
	// myBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.
	// comBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.


	// 1.
	// 나의 판을 myBoard라고 부른다.
	// 나의 판을 1~25까지의 숫자로 초기화한다.
	// 나의 판을 섞는다.

	//배열초기화는 항상 for문이랑 함께.
	InitilizeBoard(_myBoard);

	// 2.
	// 컴퓨터의 판을 comBaord라고 부른다.
	// 컴퓨터의 판을 1~25의 숫자로 초기화한다.
	// 컴퓨터의 판을 섞는다.
	InitilizeBoard(_comBoard);


	while (true)
	{
		system("cls");
		// 3. myBoard를 출력한다.
		/*cout << _myBoard[0] << "\t";
		cout << _myBoard[1] << "\t";
		cout << _myBoard[2] << "\t";
		cout << _myBoard[3] << "\t";
		cout << _myBoard[4] << endl;
		cout << _myBoard[5] << "\t";
		cout << _myBoard[6] << "\t";
		cout << _myBoard[7] << "\t";
		cout << _myBoard[8] << "\t";
		cout << _myBoard[9] << endl;*/
		cout << "내 보드 : " << endl;
		PrintBoard(_myBoard);

		cout << "컴퓨터 보드 : " << endl;
		PrintBoard(_comBoard);

		// 5. 아래 내용을 반복한다.
		// 숫자를 하나 입력받는다.
		// 입력받은 이 숫자를 input이라고 부른다
		// myBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.
		// comBoard의 배열을 모두 순회하면서 input과 같은 값이 있으면 값을 -1로 바꿔준다.

		int input;
		cout << "input num : ";
		cin >> input;
		MarkBoard(input);
		int comInput = rand() % 25+1;
		cout << "com num : " << comInput;
		MarkBoard(comInput);

		// if player bingo 
		//	win
		// else if com bingo 
		//	lose
		//


		if (true == isCompleteBoard(_myBoard))
		{
			cout << "win" << endl;
			return;
		}
		if (true == isCompleteBoard(_comBoard))
		{
			cout << "lose" << endl;
			return;
		}

		system("pause");
	}
}

//숙제 2.
// 빙고 완성