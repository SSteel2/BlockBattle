#include "Bot.h"

int main ()
{
	auto bot = new Bot ();
	bot->Run ();

	delete bot;
	return 0;
}