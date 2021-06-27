/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:42:58 by bchytter          #+#    #+#             */
/*   Updated: 2021/06/27 18:50:39 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_space(char i)
{
    if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')
        return (1);
    return (0);
}

char	ft_last_word(char *s)
{
	int		iter;
	int		j;
	char	*p;
	int		z;

	z = 0;
	iter = 0;
	j = 0;	
	iter = ft_str_len(s);
	p = (char *)malloc(sizeof(char) * iter);;
	if (*s)
	{
		while (s[z] != '\0')
			z++;
		z--;
		while (ft_is_space(s[z]) && z > 0)
			z--;
		while (!(ft_is_space(s[z])))
			z--;
		z++;
		while (!((ft_is_space((s[z])))) && s[z] != '\0')
		{
			p[j] = s[z];
	  		z++;
			j++;
		}	
	}
	return (&p);
}


int ft_str_len(char *word)
{
	int	i;

	i = 0;
	while (word != '\0')
		i++;
	return (i);
}

void clean(char *var)
{
    int i = 0;
    while(var[i] != '\0')
	{
	    var[i] = '\0';
	    i++;
	}
}

char **write_on_mass(char **dict, char *file)        // печать по строчно в массиве
{
	char	*buffer;
	int		j;
	char	word[200];							//строка размера 200 для перевода туда строк файла//
	int		k;
	int		z;
	int		fd;
	char	test;
		// проблемма в цикле.
	j = 0;
	z = 0;
	fd = open(file, O_RDONLY);
	while((read(fd, &buffer, 1)))
	{
		word[z] = &buffer;
		write(1, &buffer, 1);
		if (word[z] == '\n')
		{
			//write(1, "OK\n", 3);	
			k = 0;
			*word = ft_last_word(&word);
			while(word[k] != '\0')
			{
				dict[j][k] = word[k];
				k++;
				z = 0;
			}
			j++;
			clean(word);
		}
		z++;
	}
	close(fd);
	return (dict);
}


char **write_dict_line(char **dict_mass) 					// печать заполнение линий пустыми массивами
{
	int		i;
	char	*line[200];

	i = 0;
	while (dict_mass[i] != '\0')
	{
		dict_mass[i] = &line;
		i++;
	};
	return (dict_mass);
}

void	tp(char **mass)
{
	int i;
	int j;

	i = 0;
	while (mass[i] != '\0')
	{
		j = 0;
		while (mass[i][j] != '\0')
		{
			write (1, &mass[i][j], 1);
			j;
		}
		i++;
	}

}

char **init_dict(char *name)
{
	int		fd;
	char	**dict_mass;
	int		z;
	char	*buffer;
	int		data;

	fd = open(name, O_RDONLY);
	if (fd == (-1))
		write(2, "dict error\n", 11);
	z = 0;
	while ((read(fd, &buffer, 1)))
		if (&buffer == '\n')
			z++;
	close(fd);
	dict_mass = (char **)malloc(sizeof(char) * z);
	dict_mass = write_on_mass(write_dict_line(dict_mass), name);       // Возврат заполненого массива
	tp(dict_mass);
	return (dict_mass);
}

