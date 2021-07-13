/*
** EPITECH PROJECT, 2021
** stick
** File description:
** stick
*/

void put_stick(char **map, int *tab)
{
    if (tab[0] >= tab[1] && tab[0] <= tab[2] - 1 - tab[1])
        map[tab[3]][tab[0]] = '|';
}

int no_stick_line(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            return (-1);
        i = i + 1;
    }
    return (0);
}

int nb_stick(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}

int check_case(char **map, int i, int y)
{
    if (map[i][y] == '|')
        return (-1);
    return (0);
}

int no_stick_map(char **map)
{
    int i = 0;
    int y = 0;
    int rt = 0;

    while (map[i]) {
        while (map[i][y] != '\0' && rt == 0) {
            rt = check_case(map, i, y);
            y = y + 1;
        }
        if (rt == -1)
            return (-1);
        y = 0;
        i = i + 1;
    }
    return (0);
}
