#pragma once

#include "Header.h"

class Piece
{
protected:
	PieceType mPieceType;
	int mRotationCount;
	int mWidth = 0;
	int mHeight = 0;

	vector<vector<vector<char>>> mField;

public:
	Piece (PieceType type, int rotationCount, vector<vector<char>>&& field);
	~Piece ();

	PieceType GetPieceType ();
	int GetRotationCount ();
	int GetWidth ();
	int GetHeight ();
	Field GetRotationField (Rotation rotation);
	bool CheckOverlay (DeltaPly* ply, Field gameField);

private:
	void CalculateDimensions ();
	void PopulateRotations ();
};

