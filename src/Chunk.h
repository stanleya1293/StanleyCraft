#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"

class Chunk {
public:
	Chunk();
	void render();
private:
	Block m_chunk_data[16][16][16];
};


#endif
