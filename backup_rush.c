#include <unistd.h>
#include <stdio.h>

#define BOX_SIZE 4

typedef struct isitValid {
	int found;
	int position[2];
} isitValid;


int arr[BOX_SIZE][BOX_SIZE];

isitValid check_is_valid(int row, int colum, int num)
{
	int	i;
	isitValid result = {1,{row, colum}};
	i = 0;
	while (i < BOX_SIZE)
	{
		if (arr[row][i] == num || arr[i][colum] == num)
		{
			result.found = 0;
			return (result);
		}
		i++;
	}
	return (result);
}

int	put_in_place(int row, int colum, int num)
{
	isitValid res = check_is_valid(row, colum, num);
	if (res.found == 0)
	{
		if (row == 3)
			return (0);
		if (colum == 3)
			put_in_place(row + 1, 0, num);
		else
			put_in_place(row , colum + 1, num);
	}

	arr[res.position[0]][res.position[1]] = num;
	return (1);
}

void print_sudoku() {
    for (int i = 0; i < BOX_SIZE; ++i) {
        for (int j = 0; j < BOX_SIZE; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int ac, char **av)
{
	int i = -1;
	int j = -1;
	(void)av;
	(void)ac;
	/* isitValid solution; */
	while (++i < 4)
		while (++j < 4)
			arr[i][j] = 0;
	i = 1;
	while (i <= 4)
	{
		put_in_place(0, 0, i);
		i++;
	}
	print_sudoku();
} 
