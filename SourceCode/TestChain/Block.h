#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block
{
public:
	string Hash;
	string PrevHash;

	Block(uint32_t nIndexIn, const string& sDataIn);

	string GetHash();
	void MineBlock(uint32_t nDifficulty);

private:
	string data;
	string hash;
	uint32_t index;
	int64_t nonce;
	time_t workingTime;

	string CalculateHash() const;
};
