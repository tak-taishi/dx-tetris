#include <DxLib.h>

#include "block.h"

int stage[21][12] = { 0 };

int field[21][12] = { 0 };

int wall_offset_x = 0;
int wall_offset_y = 0;

void DrawWall(int x, int y);
void ClearField();

void UpdateFiled(int count)
{
	ClearField();

	UpdateBlock(count);

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			field[i][j] = stage[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			field[i][j] = block[i][j];
		}
	}

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			field[i][0] = 9;
			field[i][11] = 9;
			field[20][j] = 9;
		}
	}
}

void DrawField()
{
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			switch (field[i][j]) {
			case 0:
				break;
			case 1:
				DrawBlock(j, i);
				break;
			case 9:
				DrawWall(j, i);
				break;
			default:
				break;
			}

		}
	}
}

void DrawWall(int x, int y)
{
	int posX = 20 * x + wall_offset_x;
	int posY = 20 * y + wall_offset_y;
	DrawBox(posX, posY, posX + 20, posY + 20, GetColor(0xFF, 0xFF, 0xFF), TRUE);
}

void ClearField()
{
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			field[i][j] = 0;
		}
	}
}