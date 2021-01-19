#include "../include/11_CanWinNim.h"

bool CanWinNim(int n) {
	if (n % 4 != 0) {
		return true;
	}
	return false;
}