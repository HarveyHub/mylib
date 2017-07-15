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
		MSG("denomination " << i << " needs " << table[i] << "coins");
	
	}

	return table[total];
	
}

// longest increasing subsequence
//d(i) = max{d(j)+1, 1} 1<=j<=i<=len， 其中d(j)+1
unsigned lis(int *ptr_ints, unsigned len)
{
	int *table = new int[len];
	table[0] = 1;
	unsigned max_len = 1;
	for(unsigned i = 0; i < len; i++)
	{
		table[i] = 1;
		for(unsigned j = 0; j < i; j++)
		{
			if(ptr_ints[j] <= ptr_ints[i] && table[i] < table[j] + 1)
				table[i] = table[j] + 1;
		}
		if(max_len < table[i])
			max_len = table[i];
	}
	delete table;
	return max_len;

}
