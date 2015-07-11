#include "Bot.h"


Bot::Bot ()
{
}


Bot::~Bot ()
{
}


void Bot::Run ()
{
	string line;

	while (getline (cin, line))
	{
		if (line.length () == 0)
			continue;

		stringstream stream (line);
		vector<string> tokens{ istream_iterator < string > {stream}, istream_iterator < string > {} };

		if (tokens[0] == "settings")
		{
			
		}
	}
}