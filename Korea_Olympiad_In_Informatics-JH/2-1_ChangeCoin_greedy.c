#include <stdio.h>

int main(){
	int set[4] = { 50, 12, 5, 1 };
	int count[4] = { 0, 0, 0, 0 };
	int sum = 0, charge = 15;
	int flag = 0, i = 0;

	do{
		sum += set[i];
		if (sum > charge){
			sum -= set[i];
			i++;
		}
		else if (sum < charge) count[i] += 1;
		else if (sum == charge){
			count[i] += 1;
			flag = 1;
			break;
		}
	} while (i < 4);

	if (flag == 1){
		printf("<used coin>\n");
		for (i = 0; i<4; i++)
		{
			if (count[i]>0)
				printf("%d Won--> %d\n", set[i], count[i]);
		}
	}
	else printf("impossible");

	return 0;
}