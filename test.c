int map_last(char *line, size_t counter)
{
	size_t counter2 = 0;

	while (counter > 0)
	{
		while (line[counter2] != '\n' && line[counter2] != '\0')
			counter2++;

		while (line[counter2] != '\n' && line[counter2] != '\0')
		{
			if (line[counter2] != '1')
			{
				printf("Last line invalid\n");
				return 0;
			}
			counter2++;
		}

		counter--;
	}
	return 1;
}

int map_first(char *line, size_t counter)
{
	t_map_check wall;

	wall.counter = 0;

	while (line[wall.counter] != '\n' && line[wall.counter] != '\0')
	{
		if (line[wall.counter] != '1')
		{
			printf("First line invalid\n");
			return 0;
		}
		wall.counter++;
	}
	return map_last(line, counter - 1);
}