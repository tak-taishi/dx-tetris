#include <DxLib.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
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
		if (CheckHitKeyAll() == 0) {
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
