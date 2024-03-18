#include "Header.h"
#include <iomanip>
#include <iostream>
#include<cstdlib>
#include <locale.h>
using namespace std;
char board[100] = { '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-', '-', '-' };//ìàññèâ ïîëÿ ýòî áóêâû!!!!!!!!!!!!!!
void print_board(int n, int turn)
{
	cout << "Èãðîâîå ïîëå\n";
	int stroka, stolbec;
	for (stolbec = 0; stolbec < n; stolbec++) {
		for (stroka = 0; stroka < n; stroka++) {
			cout << "|-" << board[stroka + n * stolbec] << "-|";
		}
		cout << "\n";
	}
	if (turn < n) {
		if (turn % 2 == 0) { cout << "Õîä ÷åòíîãî èãðîêà:\n"; }
		else { cout << "Õîä íå÷åòíîãî èãðîêà:\n"; }
	}
}
void podschet(int n, int turn) {
	int intboard[100];
	for (int i = 0; i < n * n; i++) { intboard[i] = board[i] - '0'; }
	int chet = 0; int nechet = 0;
	int stolb[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int sb = 0; sb < n; sb++) {
		for (int i = sb; i < (n * n); i += n) {
			stolb[sb] += intboard[i];
		}
	}
	int stroki[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int st = 0; st < n; st++) {
		for (int i = st * n, j = 0; (i < (n * n)) && (j < n); i++, j++) {
			stroki[st] += intboard[i];
		}
	}
	int glavdiag = 0, pobdiag = 0;
	for (int i = 0; i < n; i++) {
		glavdiag += intboard[i + n * i];
		pobdiag += intboard[(n - 1) * (i + 1)];
	}
	for (int i = 0; i < n; i++) {
		if (stolb[i] % 2 == 0) { chet += 1; }
		else { nechet += 1; }
		if (stroki[i] % 2 == 0) { chet += 1; }
		else { nechet += 1; }
	}
	print_board(n, turn);
	if (glavdiag % 2 == 0) { chet += 1; }
	else { nechet += 1; }
	if (pobdiag % 2 == 0) { chet += 1; }
	else { nechet += 1; }
	cout << "Êîëè÷åñòâî íå÷åòíûõ ñóìì ðàâíî  " << nechet << "\n";
	cout << "Êîëè÷åñòâî ÷åòíûõ ñóìì ðàâíî  " << chet << "\n";
	if (chet > nechet) { cout << "Âûèãðàë ÷åòíûé èãðîê "; }
	if (chet == nechet) { cout << "Íè÷üÿ"; }
	if (nechet > chet) { cout << "Âûèãðàë íå÷åíòûé èãðîê"; }
}

int get_move(int n, int turn)
{
	system("cls");
	setlocale(0, "ru");
	//ïîäñêàçêà
	int stroka, stolbec;
	cout << "Óïðàâëåíèå\n";
	for (stolbec = 0; stolbec < n; stolbec++) {
		for (stroka = 1; stroka <= n; stroka++) {
			cout << "|-" << setw(2) << stroka + n * stolbec << setw(2) << "-|";
		}
		cout << "\n";
	}
	cout << endl;
	print_board(n, turn);
	int move;
	cin >> move;
	while (move > n * n || move < 1 || board[move - 1] != '-') //ïðîâåðêà ââåä¸ííîãî ÷èñëà
	{
		cout << "Âåäèòå ïðàâèëüíîå ÷èñëî (1-" << n * n << "), ñëåäèòå, ÷òîáû ïîëå áûëî ñâîáîäíûì. \n";
		cin >> move;
	}
	return move;

}

char play(int n)
{

	int turn = 0;
	while (turn < n * n)
	{
		if (turn % 2 == 0)
		{
			int sostoyanie = get_move(n, turn);
			board[sostoyanie - 1] = '0';
		}
		else
		{
			int sostoyanie = get_move(n, turn);
			board[sostoyanie - 1] = '1';
		}

		turn++;
	}
	podschet(n, turn);
	return 'D';
}
