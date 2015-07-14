#pragma once

#include "Header.h"

class Bot
{
protected:
	vector<Piece*> mPieces;

public:
	Bot ();
	~Bot ();

	void Run ();
	void MakeAction ();

	Piece* GetPiece (PieceType type);

public:
	void InitializePieces ();

};

