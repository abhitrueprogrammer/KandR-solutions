// Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes each
// character in s1 that matches any character in the string s2. □
void squeeze(char s1[], char s2[])
{
    int replaceIndex;
    for(int i = 0; s2[i] != '\0'; i++)
    {
        for(int j = replaceIndex = 0; s1[j] != '\0'; j++)
        {
            if (s1[i] != s2[j])
            {
                s1[j++] = s1[i];
            }
        }
    }
}