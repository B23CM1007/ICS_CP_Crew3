# ICS_CP_Crew3
Project name: Random Password generator

We have considered the following sets of characters:
set 1: numbers
set 2: lower case alphabets
set 3: upper case alphabets
set 4: ? + = - (special char 1)
set 5: @ # $ ! (special char 2)

First we take input password from the user and detect its strength based on the following criteria:
1. 50% - Only characters from any one set
2. 65% - Characters from any two sets 
3. 75% - Characters from any three sets
4. 85% - special characters from any four sets
5. 95% - All sets included but character from every set is not repeated twice
6. 100% - All sets included and character from every set is repeated twice which means there are two characters from each set.

P.S.: Considering set 4 and set 5 as one set for 50%, 65% and 75%

The password should be exactly 10 characters long and not contain '_', '/', '*', '%', '&', '\', ';', '|', '~'.
We take input of the password from the user and calculate its strength.

If the strength of password is less than 100% then we suggest a new randomly generated password with maximum robustness.
