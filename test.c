#include <stdio.h>

int	*ft_attrib()
{
	return ((int[3]){1, 2, 3});
}

int main()
{
	int		*coco;

	coco = ft_attrib();
	printf("coco = %d\n%d\n%d\n", coco[0], coco[1], coco[2]);
	return (0);
}
