#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	int w = atoi(av[1]), h = atoi(av[2]), it = atoi(av[3]);
	char *b = calloc(w * h, 1), *n = calloc(w * h, 1), c;
	int x = 0, y = 0, pen = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 0) y--;
		else if (c == 's' && y < h - 1) y++;
		else if (c == 'a' && x > 0) x--;
		else if (c == 'd' && x < w - 1) x++;
		else if (c == 'x') pen = !pen;
		if (pen)
			b[y * w + x] = 1;
	}
	while (it-- > 0)
	{
		for (y = 0; y < h; y++)
			for (x = 0; x < w; x++)
			{
				int k = 0;
				for (int dy = -1; dy <= 1; dy++)
					for (int dx = -1; dx <= 1; dx++)
						if ((dx || dy) && y + dy >= 0 && y + dy < h && x + dx >= 0 && x + dx < w)
							k += b[(y + dy) * w + x + dx];
				n[y * w + x] = (k == 3 || (k == 2 && b[y * w + x]));
			}
		char *t = b; b = n; n = t;
	}
	for (y = 0; y < h; y++)
	{
		for (x = 0; x < w; x++)
			putchar(b[y * w + x] ? 'O' : ' ');
		putchar('\n');
	}
	free(b);
	free(n);
	return 0;
}
