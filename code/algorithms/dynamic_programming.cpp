#include "comm.h"


unsigned min_cnt_coin(unsigned *ptr_coin, unsigned denomination_cnt, unsigned total)
{
	unsigned *table = new unsigned[total+1];
	table[0] = 0;

	for(unsigned i = 1; i <= total; i++)
	{
		table[i] = i;
		for(unsigned j = 0; j < denomination_cnt; j++)
		{
			if(j <= i && table[i-ptr_coin[j]] + 1 < table[i])
			{
					table[i] = table[i-ptr_coin[j]] + 1;
			}
		}
	
	}

	return table[total];
	
}
