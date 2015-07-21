#pragma once

#include "Header.h"

class Piece;

class DecisionTreeNode
{
protected:
	vector<DeltaPly*> mChildren;

public:
	DecisionTreeNode ();
	DecisionTreeNode (vector<DeltaPly*> children);
};

class Bot
{
protected:
	vector<Piece*> mPieces;
	DecisionTreeNode mDecisionRoot;

public:
	Bot ();
	~Bot ();

	void Run ();

protected:
	void InitializePieces ();

	void MakeAction ();
	void PopulateDecisionTree ();
	void EvaluatePositions ();

	Piece* GetPiece (PieceType type);
	DecisionTreeNode GetPossibleMoves (PieceType pieceType, vector<DeltaPly*> queuedMoves);
};

