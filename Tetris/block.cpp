#include <DxLib.h>

#include "block.h"

#define BLOCK_LENGTH (20)

int block[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 0, 0, 0 }
};

int block_offset_x = 0;
int block_offset_y = 0;

int block_left_limit = 0 + BLOCK_LENGTH;
int block_right_limit = 10 * BLOCK_LENGTH;
int block_low_limit = 16 * BLOCK_LENGTH;

void UpdateBlock(int count)
{
	if (block_offset_y > block_low_limit) {
		return;
	}

	if (count % 20 == 0) {
		block_offset_y += 20;
	}
}

void DrawBlock(int x, int y)
{
	int posX = BLOCK_LENGTH * x + block_offset_x;
	int posY = BLOCK_LENGTH * y + block_offset_y;
	DrawBox(posX, posY, posX + BLOCK_LENGTH, posY + BLOCK_LENGTH, GetColor(0x00, 0x00, 0xFF), TRUE);
}
