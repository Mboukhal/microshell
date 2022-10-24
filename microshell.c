#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	int start = 0;
	int end = 0;
	int size = 0;
	char next = 'e';
	char *cmd;
	char *eCmd;


} t_data;

int getNext(t_data *d)
{
	if (start)
		free(d->eCmd);
	d->eCmd = malloc((start - end + 1) * sizeof(char));
	while (d->start < d->end)
	{
		d->cmd[d->start] = d->eCmd[d->start];
		d->start++;
	}
	if (d->start == d->size)
		return 1;
	return 0;
}

void dataInit(t_data *data, char *av)
{
	while (av[data->size])
			data->size++;
	data->cmd = malloc((data->size + 1) * sizeof(char));
	int i = 0;
	while (av[i])
	{
		data->cmd[i] = av[i];
		i++;
	}
	data->cmd[i] = '\0';
}

int cheakNext(t_data *d)
{
	return 0;
}

void execute(t_data *d)
{

}

int main ( int ac, char **av, char **env )
{
	t_data data;
	dataInit(data, av);
	while (cheakNext(&data))
	{
		if (getNext(&data))
			break;
		execute(&data);
	}
	execute(&data);
	free(data.cmd);

	return 0;
}
