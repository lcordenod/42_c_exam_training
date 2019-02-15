
#include <stdlib.h>

unsigned char reverse_bits(unsigned char octet)
{
	int i;
	unsigned char rev;

	i = 8;
	rev = 0;
	while (i--)
		if ((1 << i) & octet)
			rev += 128 / (1 << i);
	return (rev);
}

void print_bits(unsigned char octet)
{
	unsigned char comp;

	comp = 128;
	while (	comp >= 1)
	{
		if (comp & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		comp /= 2;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_bits(reverse_bits(atoi(av[1])));
	return (0);
}
