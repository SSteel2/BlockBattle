#include "Bot.h"


Bot::Bot ()
{
	InitializePieces ();
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


Piece* Bot::GetPiece (PieceType type)
{
	for each (auto piece in mPieces)
	{
		if (piece->GetPieceType () == type)
			return piece;
	}
	return nullptr;
}


void Bot::InitializePieces ()
{
	mPieces.reserve (7);
	mPieces.push_back (new Piece (PieceType::I, 2, { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }));
	mPieces.push_back (new Piece (PieceType::J, 4, { { 1, 0, 0 }, { 1, 1, 1 }, { 0, 0, 0 } }));
	mPieces.push_back (new Piece (PieceType::L, 4, { { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 0 } }));
	mPieces.push_back (new Piece (PieceType::O, 1, { { 1, 1 }, { 1, 1 } }));
	mPieces.push_back (new Piece (PieceType::S, 2, { { 0, 1, 1 }, { 1, 1, 0 }, { 0, 0, 0 } }));
	mPieces.push_back (new Piece (PieceType::T, 4, { { 0, 1, 0 }, { 1, 1, 1 }, { 0, 0, 0 } }));
	mPieces.push_back (new Piece (PieceType::Z, 2, { { 1, 1, 0 }, { 0, 1, 1 }, { 0, 0, 0 } }));
}