#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap (char *p1, char*p2)
{
    //swapping the characters
    char temp = *p1;
    *p1 = *p2; 
    *p2 = temp;
}

int calculate_strength(char *password)
{
    //initialise all the counters to zero
    int num = 0;
    int lower_case = 0;
    int upper_case = 0;
    int special_char1 = 0;
    int special_char2 = 0;
    int invalid = 0;

    int count[6]; 
    //checking number of characters of each category for the entered password
    for(int i = 0; i<10; i++)
    {
        if(password[i] >= '0' && password[i]<='9') 
            num++;
        else if(password[i]>='a'&& password[i]<='z') 
            lower_case++;
        else if(password[i]>='A' && password[i]<='Z') 
            upper_case++;
        else if(password[i] == '?' || password[i] == '-' || password[i] == '+' || password[i] == '=') 
            special_char1++;
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$') 
            special_char2++;
        else 
            invalid++;
    }

    int special_char = special_char1 + special_char2;

    count[0] = num;
    count[1] = lower_case;
    count[2] = upper_case;
    count[3] = special_char1;
    count[4] = special_char2;

    int type = 0;

    for(int i = 0; i<3; i++)
    {
        if(count[i]!=0)
            type++;
    }
    if(special_char!=0) type++;

    //int has_num_twice = num >= 2;

    //returning the strength of password
    if (invalid !=0)
        return -1;
    else if (type == 1) 
        return 50;
    else if (type == 2) 
        return 65;
    else if (type == 3) 
        return 75;
    else if (special_char1 == 0 || special_char2 == 0)
        return 85;
    
    int has_two_num = (num == 2);
    int has_two_lower = (lower_case == 2); 
    int has_two_upper = (upper_case == 2);
    int has_two_char1 = (special_char1 == 2);
    int has_two_char2 = (special_char2 == 2);

    if(has_two_char1 && has_two_char2 && has_two_lower && has_two_num && has_two_upper)
        return 100;
    else 
        return 95;
}

void generate_password() 
{ 
    //creating arrays for different sets of characters
    char numbers[] = "0123456789"; 
    char lower_case[] = "abcdefghijklmnoqprstuvwyzx"; 
    char upper_case[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX"; 
    char special_char1[] = "?-+=";
    char special_char2[] = "!@#$";


    char password[10];
    //selecting two characters from each array
    int j = 0;
    for(int i = 0; i<2; i++)
    {
        password[j++] = numbers[rand()%10];
        password[j++] = lower_case[rand()%26];
        password[j++] = upper_case[rand()%26];
        password[j++] = special_char1[rand()%4];
        password[j++] = special_char2[rand()%4];
    }

    //shuffling the array
	for (int i = 9; i > 0; i--)
	{
		int k = rand() % (i+1); // Pick a random index from 0 to i
		swap(&password[i], &password[k]);
	}

    printf("\n Suggested 100%% strong password: ");
    for(int i = 0; i<10; i++)
    {
        printf("%c", password[i]);
    }
        
} 

int main()
{
    system("cls");                   // used to clear the screen each time the program is run
    char user_password[100];

    printf("\n This program will tell the strength of your password, and also suggest a randomly generated 100%% strength password. ");

    //labelled as repeat
    repeat: printf("\n The password should not contain the following characters:");
    printf("\n '_', '/', '*', '%%', '&', '\', ';', '|', '~'.");
    printf("\n The password should contain exactly 10 characters.");   

    printf("\n Enter your password: ");
    scanf("%s", user_password);

    if(strlen(user_password)!=10)
    {
        printf("\n Password should be 10 characters long.\n\n");
        goto repeat;    	    //restart from the label 'repeat'
    }


    int strength;
    strength = calculate_strength(user_password);


    if(strength != -1) 
        printf("\n Strength of your password is: %d%%\n", strength);
    else 
    {
        printf("\n Invalid password.\n\n");
        goto repeat;    //restart from the label 'repeat'
    }


    if(strength == 100) 
        printf("\n Great Work!! Your password is strong enough.");
    else
    {
        srand((unsigned int)(time(NULL))); 
        generate_password();
    }  
    printf("\n");
    return 0; 
}
