#include <iostream>
using namespace std;

unsigned reverseBit(unsigned num)
{
	int len = sizeof(num)*8;
	for(int i = 0; i < len/2; i++)
	{
		bool left = (1 << i) & num;
		bool right = 1 << (len-1-i) & num;
		bool tem = left ^ right;
		if(tem)
		{
			num ^= 1 << i;
			num ^= 1 << (len-1-i);
		}
	}
	return num;

}


unsigned reverseBit(unsigned num)
{
	num = (num & 0x55555555) << 1 | (num & 0xaaaaaaaa) >> 1;
	num = (num & 0x33333333) << 2 | (num & 0xcccccccc) >> 2;
	num = (num & 0x0f0f0f0f) << 4 | (num & 0xf0f0f0f0) >> 4;
	num = (num & 0x00ff00ff) << 8 | (num & 0xff00ff00) >> 8;
	num = (num & 0x0000ffff) << 16 | (num & 0xffff0000) >> 16;
	return num;
}




