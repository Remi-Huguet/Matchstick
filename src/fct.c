/*
** EPITECH PROJECT, 2021
** fct
** File description:
** fct
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i = i + 1;
        }
        else
            return (nb * isneg);
    }
    return (nb * isneg);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
