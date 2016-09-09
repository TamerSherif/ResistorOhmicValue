#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void printBand1Or2()
{
    printf("1. Black\n");
    printf("2. Brown\n");
    printf("3. Red\n");
    printf("4. Orange\n");
    printf("5. Yellow\n");
    printf("6. Green\n");
    printf("7. Blue\n");
    printf("8. Violet\n");
    printf("9. Gray\n");
    printf("10. White\n");
}

void printBand3()
{
    printf("1. Black\n");
    printf("2. Brown\n");
    printf("3. Red\n");
    printf("4. Orange\n");
    printf("5. Yellow\n");
    printf("6. Green\n");
    printf("7. Blue\n");
    printf("8. Violet\n");
    printf("9. Gray\n");
    printf("10. White\n");
    printf("11. Gold\n");
    printf("12. Silver\n");
}

void printBand4()
{
    printf("1. Gold\n");
    printf("2. Silver\n");
}
int main()
{
    int option;

    int fb, sb, mul, tol;
    double resistance;
    double resTolerance;
    while(1)
    {


    printf("\nPlease choose an option:\n\t1. Calculate resistance value\n\t2. Help\n\t3. Exit\n");
    scanf("%d",&option);

    if(option == 1)
        {
            printBand1Or2();

            printf("Pick the appropriate band colour's number from above for the first band: ");
            scanf("%d",&option);

            if(option < 1 || option > 10)
            {
                printf("Bad input! Try again\n");
                continue;
            }
            fb = option-1;

            printBand1Or2();

            printf("Pick the appropriate band colour's number from above for the second band: ");
            scanf("%d",&option);

            if(option < 1 || option > 10)
            {
                printf("Bad input! Try again\n");
                continue;
            }

            sb = option - 1;

            printBand3();

            printf("Pick the appropriate band colour's number from above for the third band: ");
            scanf("%d",&option);

             if(option < 1 || option > 12)
            {
                printf("Bad input! Try again\n");
                continue;
            }

            //if gold / silver is picked
            if(option > 10)
            {
                mul = (option - 10) * -1;
            }

            //all other cases
            else{ // can't be below 1 or above 12 since it was limited by the code above

                mul = option - 1;
            }

            printBand4();
            printf("Pick the appropriate band colour's number from above for the fourth band: ");
            scanf("%d",&option);

            if(option == 1)
                tol = 5;
            else if(option == 2)
                tol = 10;
            else{
                printf("Bad input! Try again\n");
                continue;
                }
            resistance = fb*pow(10,mul+1) + sb*pow(10,mul);
            resTolerance = tol/100.0*resistance;

            //printf("Your resistance value is %f ~ %f",resistance,resTolerance);


            if(resistance < 1000)
                printf("Resistance value: %.2f ~ %.2f Ohms.",resistance,resTolerance);
            else if(resistance < pow(10,6))
                printf("Resistance value: %.2f ~ %.2f KiloOhms.",resistance/pow(10,4),resTolerance/pow(10,4));
            else if(resistance < pow(10,9))
                printf("Resistance value: %.2f ~ %.2f MegOhms.",resistance/pow(10,6),resTolerance/pow(10,6));
            else {
            printf("Resistance value: %.2f ~ %.2f GigaOhms.",resistance/pow(10,9),resTolerance/pow(10,9));

            }


        }
    else if(option == 2)
        {
            printf("\nDescription: Given the colours of the 4 bands of a resistor\n(first digit, second digit, multiplier and tolerance) \nthis program will output the corresponding \nohmic value.\n");
            printf("1. First choose option 1\n2. Pick the colour of each band as you see on your resistor\n3. Type the number equivalent to the colour (provided in the list displayed)\n\nOutput: Program will output the corresponding ohmic value\n");

        }

    else if(option == 3)
        break;
    else
        {
            printf("Invalid option! Please pick 1, 2 or 3\n");
        }
    }
    return 0;

}
