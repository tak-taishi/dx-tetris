#include <DxLib.h>

#include "field.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char KeyBuf[256];
	unsigned int GameCount = 0;

	if (ChangeWindowMode(TRUE)) {
		return 1;
	}

	if (DxLib_Init()) {
		return 2;
	}

	if (SetDrawScreen(DX_SCREEN_BACK)) {
		return 3;
	}

	while (ProcessMessage() == 0) {
		// Preprocess
		if (ClearDrawScreen()) {
			break;
		}

		// Main
		GameCount++;

		UpdateFiled(GameCount);
		DrawField();
		GetHitKeyStateAll(KeyBuf);
		if (KeyBuf[KEY_INPUT_C] == 1) {
			break;
		}


		// Postprocess
		if (ScreenFlip()) {
			break;
		}
	}

	DxLib_End();
	return 0;
}
