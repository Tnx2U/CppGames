#include <iostream>
#include <time.h>

using namespace std;

int main() {
	
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i+1;
	}

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	int iBingo = 0;
	int iStar1 = 0, iStar2 = 0;

	while (true) {
		system("cls"); // �ܼ�ȭ�� ����
		

		//���ڸ� 5*5�� ���
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j) 
			{
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			
			cout << "\n";
		}
		cout << "Bingo : " << iBingo << endl;

		if (iBingo >= 5)
			break;

		cout << "���ڸ� �Է��ϼ��� (0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		if (iInput > 25 || iInput < 1) {
			cout << "0~24 ���ڸ� �Է��ϼ��� : ";
				continue;
		}
		
		bool acc = true;//�ߺ��Է� üũ, �⺻�� �ߺ�(true)

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i])
			{
				acc = false;
				iNumber[i] = INT_MAX;
				break;
			}
		}
		//acc�� true�̸� �ߺ��̹Ƿ� �ٽ� �Է¹ް� �Ѵ�.
		if(acc)
			continue;

		iBingo = 0;

		iStar1 = 0, iStar2 = 0;
		for (int i = 0; i< 5; ++i)
		{
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX)
					iStar1++;

				if (iNumber[j * 5 + i] == INT_MAX)
					iStar2++;
			}
			if (iStar1 == 5) {
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}
		}
		//�밢�� ����üũ
		iStar1 = 0;
		for (int i = 0; i < 25; i+=6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		iStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
	}
}

/*void doShuffle(int array) {
	int temp, idx1, idx2;
	srand((unsigned int)time(0));

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % array.size();
	}
}*/