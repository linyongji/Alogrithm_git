#include "../include/11_CanWinNim.h"
//��Ŀ�� Nim ��Ϸ
//˼·��ֻҪ����4�ı�����������Ӯ����Ϸ�����仰˵���Ƕ�������ʯ���Ժ󣬻�ʣ�Ŀ�ʯ�ӣ������
bool CanWinNim(int n) {
	if (n % 4 != 0) {
		return true;
	}
	return false;
}