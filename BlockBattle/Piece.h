#pragma once

#include "Header.h"

class Piece
{
protected:
	PieceType mPieceType;
	int mRotationCount;
	int mWidth = 0;
	int mHeight = 0;

	vector<Field> mField;

public:
	Piece (PieceType type, int rotationCount, Field&& field);
	~Piece ();

	PieceType GetPieceType ();
	int GetRotationCount ();
	int GetWidth ();
	int GetHeight ();
	Field GetRotationField (Rotation rotation);
	bool CheckOverlay (DeltaPly* ply, Field gameField);
	bool CheckOverlay (Position position, Rotation rotation, Field gameField);

private:
	void CalculateDimensions ();
	void PopulateRotations ();
};

