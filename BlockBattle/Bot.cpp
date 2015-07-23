#include "Bot.h"


DecisionTreeNode::DecisionTreeNode () : mChildren ()
{
}


DecisionTreeNode::~DecisionTreeNode ()
{
	delete mMove;
}


DecisionTreeNode::DecisionTreeNode (DeltaPly* ply) : mChildren ()
{
	mMove = ply;
}


DecisionTreeNode::DecisionTreeNode (vector<DeltaPly*> children)
{
	mMove = new DeltaPly ();
	AddChildren (children);
}


void DecisionTreeNode::AddChildren (vector<DeltaPly*> children)
{
	for each (auto child in children)
	{
		mChildren.push_back (new DecisionTreeNode (child));
	}
}


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
		vector<string> tokens { istream_iterator<string> {stream}, istream_iterator<string> {} };

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
	PopulateDecisionTree ();
	EvaluatePositions ();
}


Piece* Bot::GetPiece (PieceType type)
{
	for each (auto piece in mPieces)
		if (piece->GetPieceType () == type)
			return piece;
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


void Bot::PopulateDecisionTree ()
{
	// TODO: Populate first 2 levels of tree
	// Currently only one is being generated
	mDecisionRoot = GetPossibleMoves (Settings::CurrentPiece, vector<DeltaPly*> ());
}


DecisionTreeNode Bot::GetPossibleMoves (PieceType pieceType, vector<DeltaPly*> queuedMoves)
{
	Piece* currentPiece = GetPiece (pieceType);
	vector<DeltaPly*> possibleMoves (currentPiece->GetRotationCount () * 9);

	for (int rotation = 0; rotation < currentPiece->GetRotationCount (); rotation++)
	{
		auto pieceField = currentPiece->GetRotationField ((Rotation)rotation);
		for (int i = 0; i < Settings::FieldWidth - (i % 2 == 0 ? currentPiece->GetWidth () : currentPiece->GetHeight ()) + 1; i++)
		{
			// TODO: This should be optimized

			// Find bottommost open cell in column
			int index = -1;
			for (int j = Settings::FieldHeight; j >= 0; j++)
			{
				if (Settings::HeroField[j][i] == 1)
				{
					index = j + 1;
				}
			}

			// Find position in which the piece fits
			for (int j = index; j < Settings::FieldHeight; j++)
			{
				// TODO: Should pass constructed game field
				if (!currentPiece->CheckOverlay (Position (i, j), (Rotation)rotation, Settings::HeroField))
				{
					possibleMoves.push_back (new DeltaPly (Position (i, j), pieceType, (Rotation)rotation, 0));
				}
			}

			// TODO: Shadow situations
		}
	}

	return DecisionTreeNode (possibleMoves);
}


void Bot::EvaluatePositions ()
{
	// Evaluates all positions and assigns them a value


}


