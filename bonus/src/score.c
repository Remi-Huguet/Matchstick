/*
** EPITECH PROJECT, 2021
** score
** File description:
** score
*/

void get_mile(int *tab_score, int *int_score)
{
    *tab_score = (*int_score - (*int_score % 1000)) / 1000;
    *int_score = *int_score - (*tab_score * 1000);
}

void get_cent(int *tab_score, int *int_score)
{
    *tab_score = (*int_score - (*int_score % 100)) / 100;
    *int_score = *int_score - (*tab_score * 100);
}

void get_dec(int *tab_score, int *int_score)
{
    *tab_score = (*int_score - (*int_score % 10)) / 10;
    *int_score = *int_score - (*tab_score * 10);
}

void get_unit(int *tab_score, int *int_score)
{
    *tab_score = *int_score;
    *int_score = *int_score - *tab_score;
}

char *increase_score(char *char_score, int int_score)
{
    int tab_score[] = {0, 0, 0, 0};
    if (int_score < 10000 && int_score >= 1000)
        get_mile(&tab_score[0], &int_score);
    if (int_score < 1000 && int_score >= 100)
        get_cent(&tab_score[1], &int_score);
    if (int_score < 100 && int_score >= 10)
            get_dec(&tab_score[2], &int_score);
    if (int_score < 10)
        get_unit(&tab_score[3], &int_score);
    char_score[0] = tab_score[1] + 48;
    char_score[1] = tab_score[2] + 48;
    char_score[2] = tab_score[3] + 48;
    char_score[3] = '\0';
    return (char_score);
}
