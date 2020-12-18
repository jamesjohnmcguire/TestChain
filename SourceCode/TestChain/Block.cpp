#include <time.h>
#include <vector>
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t indexIn, const string& dataIn)
	: index(indexIn), data(dataIn)
{
	nonce = -1;
	workingTime = time(nullptr);
}

string Block::GetHash()
{
	return hash;
}

void Block::MineBlock(uint32_t difficulty)
{
	size_t size = (size_t)difficulty + 1;
	vector<char> tempBuffer(size);

	for (uint32_t i = 0; i < difficulty; ++i)
	{
		tempBuffer[i] = '0';
	}
	tempBuffer[difficulty] = '\0';

	string testBuffer(tempBuffer.begin(), tempBuffer.end());
	string testHash;

	do
	{
		nonce++;
		hash = CalculateHash();
		testHash = hash.substr(0, difficulty);
	} while (testHash != testBuffer);

	cout << "Block mined: " << hash << endl;
}

inline string Block::CalculateHash() const
{
	stringstream streamBuffer;
	streamBuffer << index << workingTime << data << nonce << PrevHash;

	string buffer = streamBuffer.str();
	string hash = sha256(buffer);
	return hash;
}
