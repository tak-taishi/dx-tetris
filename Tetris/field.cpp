#include <DxLib.h>

int stage[21][12] = { 0 };

int field[21][12] = { 0 };

int block[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 0, 0, 0 }
};

void UpdateFiled()
{

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
				DrawBox(20 * j, 20 * i, 20 * j + 20, i * 20 + 20, GetColor(0x00, 0x00, 0xFF), TRUE);
				break;
			case 9:
				DrawBox(20 * j, 20 * i, 20 * j + 20, i * 20 + 20, GetColor(0xFF, 0xFF, 0xFF), TRUE);
				break;
			default:
				break;
			}

		}
	}
}