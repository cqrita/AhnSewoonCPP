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

	//���� ����
	//Swap * 100000�� �ݺ�
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
	// ������� �����

	// 5x5�� �̷���� ���� ��
	// 5x5�� �̷���� ��ǻ�� ��
	// �� �����Ǿȿ��� 1~25������ ���ڰ� �������.

	// ���� -> ����� -> ���� -> ����� �ݺ�

	// ���� ���϶�, ���ڸ� �ϳ� �θ���.
	// �θ� ���ڴ� ���ڷ� ǥ��ȵǰ� #���� ǥ���.

	//��¿���
	//�� : 
	// 7 6 15 20 #
	// 1 5 3  7  2
	// ...
	// ...
	// ...

	//��� : 
	// 1 5 3  7  2
	// 7 6 15 20 #
	// ...
	// ...
	// ...

	// ���� �ϼ��Ǹ� �ش� �÷��̾� �¸�.



	// �����ڵ�
	// 1.
	// ���� ���� myBoard��� �θ���.
	// ���� ���� 1~25������ ���ڷ� �ʱ�ȭ�Ѵ�.
	// ���� ���� ���´�.

	// 2.
	// ��ǻ���� ���� comBaord��� �θ���.
	// ��ǻ���� ���� 1~25�� ���ڷ� �ʱ�ȭ�Ѵ�.
	// ��ǻ���� ���� ���´�.

	// 3. myBoard�� ����Ѵ�.
	// 4. comBoard�� ����Ѵ�.

	// 5. �Ʒ� ������ �ݺ��Ѵ�.
	// ���ڸ� �ϳ� �Է¹޴´�.
	// �Է¹��� �� ���ڸ� input�̶�� �θ���
	// myBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.
	// comBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.

	// 6.  ���ڸ� �ϳ� �������� �̾ƿ´�.
	// �Է¹��� �� ���ڸ� input�̶�� �θ���
	// myBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.
	// comBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.


	// 1.
	// ���� ���� myBoard��� �θ���.
	// ���� ���� 1~25������ ���ڷ� �ʱ�ȭ�Ѵ�.
	// ���� ���� ���´�.

	//�迭�ʱ�ȭ�� �׻� for���̶� �Բ�.
	InitilizeBoard(_myBoard);

	// 2.
	// ��ǻ���� ���� comBaord��� �θ���.
	// ��ǻ���� ���� 1~25�� ���ڷ� �ʱ�ȭ�Ѵ�.
	// ��ǻ���� ���� ���´�.
	InitilizeBoard(_comBoard);


	while (true)
	{
		system("cls");
		// 3. myBoard�� ����Ѵ�.
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
		cout << "�� ���� : " << endl;
		PrintBoard(_myBoard);

		cout << "��ǻ�� ���� : " << endl;
		PrintBoard(_comBoard);

		// 5. �Ʒ� ������ �ݺ��Ѵ�.
		// ���ڸ� �ϳ� �Է¹޴´�.
		// �Է¹��� �� ���ڸ� input�̶�� �θ���
		// myBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.
		// comBoard�� �迭�� ��� ��ȸ�ϸ鼭 input�� ���� ���� ������ ���� -1�� �ٲ��ش�.

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

//���� 2.
// ���� �ϼ�