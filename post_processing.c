
void	post_processing(int *path, int *dup, int int_len)
{
	static int	p_index = 0;
	int			c_index;
	int			row;

	while (p_index < int_len)
	{
		row = 0;
		c_index = 0;
		if (5 <= path[p_index] && path[p_index] < 8)
		{
			while (path[p_index] == path[p_index + c_index])
				c_index++;
			row = c_index;
			c_index = 0;
			while (c_index < row &&
					(math(path[p_index]) == path[p_index + row + c_index]))
				c_index++;
			// c_index represents the number of "in a rows" that can be
			// replaced by rr or rrr. If 0, just copy over. Otherwise,
			// add the appropriate elements to dup and move p_index accordingly
			update(path, dup, c_index, &p_index);
		}
	}
}

// If the action is 5 or 7, it will be odd and will += 1.
// If even, it will be even and -= 1;
// odd will be 1 for odd and 0 for even numbers.
// even will be 1 for even and 0 for odd numbers. 
int	math(act)
{
	int odd;
	
	odd = act % 2;
	even = (1 - act % 2);
	add += odd - even;
}
