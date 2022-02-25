#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int guess = 1234;		//猜的
int answer = 1234;		//答案
int zxw[4];				//答案(陣列裡)
int zzz[4];				//猜的(陣列裡)
int A = 0;				//位子跟數字對
int B = 0;				//數字對
void split()		//把四位數放進陣列
{
	zzz[0] = guess / 1000;
	zzz[1] = (guess / 100) % 10;
	zzz[2] = (guess / 10) % 10;
	zzz[3] = guess % 10;
}
bool HasZero()		//有沒有0
{
	if (zzz[0] * zzz[1] * zzz[2] * zzz[3] == 0)
		return true;
	else
		return false;
}
bool IsRepeat()		//有沒有重複
{
	if ((zzz[0] == zzz[1]) || (zzz[0] == zzz[2]) || (zzz[0] == zzz[3]) || (zzz[1] == zzz[2]) || (zzz[1] == zzz[3]) || (zzz[2] == zzz[3]))
		return true;
	else
		return false;
}
void AB()			//幾A幾B
{
	A = 0;
	B = 0;
	for (int a = 0; a < 4; a++)
	{
		if (zxw[a] == zzz[a])
			A++;
	}
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (zxw[a] == zzz[b] && a != b)
				B++;
		}
	}
}
int main()
{
  cout<<"1102028"<<endl;
  cout<<"徐啟赫"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  srand(time(0));
	int stop = 0;
	while (stop == 0)
	{
		guess = rand() % (9999 - 1000 + 1) + 1000;		
		split();
		if (HasZero() || IsRepeat())
			;
		else
			stop++;
	}
	for (int a = 0; a < 4; a++)
		zxw[a] = zzz[a];
	for (int a = 0; a < 4; a++)
		cout << zxw[a];
	cout << endl;
	stop = 0;
	while (stop == 0)
	{
		guess = rand() % (9999 - 1000 + 1) + 1000;
		split();
		if (HasZero() || IsRepeat())
			;
		else
		{
			AB();
			for (int a = 0; a < 4; a++)
				cout << zzz[a];
			cout << " " << A << "A" << " " << B << "B" << endl;
			if (A == 4)
				stop++;
		}
	}
  return 1;
}
