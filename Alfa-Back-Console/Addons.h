#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <windows.h>
using namespace std;

template <typename Dauer, typename Func>
void timer(Dauer const & d, Func const & f)
{
	std::thread([d, f]() {
		std::this_thread::sleep_for(d);
		f();
	}).detach();
}


void pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void cls()
{
	pos(0, 0);
	for (int j = 0; j<100; j++)
		cout << string(100, ' ');
	pos(0, 0);

	void COUTFuncIntro();

}

void divider()
{
	const auto SCREEN_WIDTH = 80;
	cout << setfill('*') << setw(SCREEN_WIDTH) << "\n" << setfill(' ') << endl;
}

//timer(std::chrono::seconds(5), &hello);
//std::cout << "Launched\n";
//std::this_thread::sleep_for(std::chrono::seconds(10));