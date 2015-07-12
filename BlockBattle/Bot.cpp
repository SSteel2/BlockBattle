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

		// Updates parsing
		if (tokens[0] == "update")
		{
			Settings::ParseUpdate (tokens[1], tokens[2], tokens[3]);
		}
		// Action request
		else if (tokens[0] == "action")
		{
			Settings::ParseAction (tokens[1], tokens[2]);
			MakeAction ();
		}
		// Settings parsing
		else if (tokens[0] == "settings")
		{
			Settings::ParseSetting (tokens[1], tokens[2]);
		}
	}
}


void Bot::MakeAction ()
{

}