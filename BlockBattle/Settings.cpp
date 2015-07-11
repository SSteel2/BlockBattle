#include "Settings.h"


Settings::Settings ()
{
}


Settings::~Settings ()
{
}


void Settings::ParseSetting (string setting, string value)
{
	if (setting == "time_bank")
	{
		TimeBank = stoi (value);
	}
	else if (setting == "time_per_move")
	{
		TimePerMove = stoi (value);
	}
	else if (setting == "player_names")
	{
		int delimiterPosition = value.find (',');
		HeroName = value.substr (0, delimiterPosition);
		VillainName = value.substr (delimiterPosition + 1, string::npos);
	}
	else if (setting == "your_bot")
	{
		if (HeroName != value)
		{
			string temp = HeroName;
			HeroName = VillainName;
			VillainName = temp;
		}
	}
	else if (setting == "field_height")
	{
		FieldHeight = stoi (value);
	}
	else if (setting == "field_width")
	{
		FieldWidth = stoi (value);
	}
}
