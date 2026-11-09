int hashInitial(char *key, int N)
{
    int h = 0;
    char *c;
    for (c = key; *c != '\0'; c++)
    {
        h = h + *c;
    }
    return h % N;
}

int hashBetter(char *key, int N)
{
    int h = 0;
    char *c;
    int i;
    for (c = key, i = 0; *c != '\0'; c++, i++)
    {
        h = h + (*c * i);
    }
    return h % N;
}
