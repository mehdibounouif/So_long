#include "../includes/so_long.h"

void     check_name(char *name)
{
        char    **tmp;
        int     i;

        i = 0;
        tmp = ft_split(name, '.');
        while (tmp[i])
                i++;
        i--;
        if (!ft_strcmp(tmp[i], "ber"))
        {
                ft_free_str(tmp);
                return ;
        }
		else
		{
			ft_free_str(tmp);
			write(2, "error\ninvalid file name!\n", 25);
			exit(1);
		}
}
