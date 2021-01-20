#include "../include/11_CanWinNim.h"
//题目： Nim 游戏
//思路：只要不是4的倍数，都可以赢得游戏，换句话说就是对手拿完石子以后，还剩四颗石子，则必输
bool CanWinNim(int n) {
	if (n % 4 != 0) {
		return true;
	}
	return false;
}