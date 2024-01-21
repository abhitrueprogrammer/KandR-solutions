// Exercise 3-3. Write a function expand(s1,s2) that expands shorthand nota-
// tions like a-z in the string s1 into the equivalent complete list abc...xyz in
// s2. Allow for letters of either case and digits, and be prepared to handle cases
// like a-b-c and a-z0−9 and -a-z. Arrange that a leading or trailing - is taken
// literally.
#include <stdio.h>
#include <ctype.h>
#define S2LENGTH 100
void expand(char s1[],char s2[], int size_s1);
int main()
{
    char s1[] = {'-','a','-','z','0','-','9'};
    char s2[S2LENGTH] = {-1};
    int size_s1 = sizeof(s1)/sizeof(s1[0]); //works
    expand(s1,s2, size_s1);
    for(int i = 0; s2[i] != '\0'; i++)
    {
        printf("%c", s2[i]);
    }
    printf("\n");
    return 0;
}
void expand(char s1[],char s2[], int size_s1)
{
    int i = 0, j = 0;//i is  position of pointer at s1 and j of s2
    char lower =0 , upper = 0; 
    if (s1[i] == '-')
    {
        s2[j] = '-';
        i++;
        j++;
    }
    for(;i+3 <= size_s1; i = i + 3)
    {
        if (s1[i+1] == '-')
        {
            lower = s1[i];
            upper = s1[i+2];
        }
        for(int k = lower; k <= upper ; k++, j++)
        {
            s2[j]= k;
        }
    }
    i++;
    if (s1[i] == '-')
    {
        s2[j] = '-';
        j++;
    }
    s2[j] == '\0';
        
}
//use ascii using upper and lower limits


// It is quite common knowledge that Nehru almost always disrespected Sardar Vallabhai Patel - the rightful first PM of India. It was so bad that Sardar wanted to quit from the cabinet, but the love of his country and wanting to ensure that he does something good for the nation kept him from actually resigning. We all already know how Nehru became the PM - and his ineptitude showed. You must check some of the speeches he has given in Europe etc, which were horrible, with no real matter in them
// Just going to answer a single paragraph prefacing by I hold no bias against Patel or Nehru
// > "Rightful first PM of India"
// If that means both Jawaharlal and Patel were rightful first PM of India, then I have no qualms. 
// > "It was so bad that Sardar wanted to quit from the cabinet, but the love of his country and wanting to ensure that he does something good for the nation kept him from actually resigning."
// Actually both threatened to resign at one point or another because of their differences. One of the moments that brought them together was Gandhi's death and they wrote letters to each other agreeing their bicker doesn't hold relevance now.

// >We all already know how Nehru became the PM
// Well, yeah, I think we do. By sacrificing a lot, being in jail for long times like other congressmen, being well learnt and intellectual and contributing to discussions, having support of younger generation(being young than his contemporaries), by having a more nationwide appeal. Also Gandhi choosing Nehru as his political heir(reasons are above), and since Gandhi had made great calls his opinion was respected by both Patel and Nehru and almost all of the congressman. It isn't that Gandhi was a Nehru fanatic, "The problem of the States is so difficult that you alone can solve it" - Gandhi to Patel. If people felt Gandhi was wrong in here, they would have resigned from congress left right and centre.
// "and his ineptitude showed."
// Then India was then considered a nation that was doomed to devolve into separate nations and kill itself because of disunity and poverty. Since its not possible to see how others would have fared if given the seat of prime minister, I think Nehru, by heading India for 16 of its formative and crucial years, have shown that while he had made several mistakes he wasn't a disaster either. 

// Yes, I took 9 years to write this.