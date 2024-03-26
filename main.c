#include "stdio.h"
#include "conio.h"
#include "math.h"

void parse(char coordinates[], float *x, float *y)
{
    // '%*c' tells to ignore char
    sscanf(coordinates, "%f%*c%f", &(*x), &(*y));
}

void distanceBetween(float ax, float ay, float bx, float by,  float *xDist, float *yDist, double *distance)
{
    float sqrSum, tempxDist = *xDist, tempyDist = *yDist;
    double diagonal;

    tempxDist = ax - bx;
    tempyDist = ay - by;

    if(tempxDist < 0)
    {
        tempxDist = tempxDist - (tempxDist * 2); 
    }
    if(tempyDist < 0)
    {
        tempyDist = tempyDist - (tempyDist * 2); 
    }

    sqrSum = (tempxDist * tempxDist) + (tempyDist * tempyDist);

    *xDist = tempxDist;
    *yDist = tempyDist;

    diagonal = sqrt((double)sqrSum);

    *distance = diagonal;
}

void triangleAreaPoints(float ax, float ay, float bx, float by, float cx, float cy, double *area)
{  
    float xDist, yDist;
    double lineAB, lineBC, lineCA;
    float s;

    distanceBetween(ax, ay, bx, by, &xDist, &yDist, &lineAB);
    distanceBetween(bx, by, cx, cy, &xDist, &yDist, &lineBC);
    distanceBetween(cx, cy, ax, ay, &xDist, &yDist, &lineCA);

    s = (lineAB + lineBC + lineCA) / 2;

    *area = sqrt(s * (s - lineAB) * (s - lineBC) * (s - lineCA));
}

void triangleAreaSides(float a,float b, float c, double *area)
{
    float s;

    s = (a + b + c) / 2;

    *area = sqrt(s * (s - a) * (s - b) * (s - c));
}
int main()
{
    float ax, ay, bx, by, cx, cy, dx, dy, xDist, yDist, a, b, c;
    double distance, area;
    char input[64], choice, temp, another = 'y', methodChoice;

    printf("\nHello. Welcome to Point distance calculator.\n\n");

    while((another != 'n' || another != 'N') && (another == 'y' || another == 'Y'))
    {
        printf("1. Calculate distance between points in 2D\n");
        printf("2. Calculate area of triangle\n\n");

        printf("Choose one: ");
        fflush(stdin);
        choice = getche();

        switch (choice)
        {
            case '1':
                printf("\n\nEnter x, y coordinates of first point: ");

                scanf("%s", &input);
                parse(input, &ax, &ay);

                printf("\nEnter x, y coordinates of second point: ");
                scanf("%s", &input);
                parse(input, &bx, &by);

                distanceBetween(ax, ay, bx, by, &xDist, &yDist, &distance); 

                printf("\n\nDistance on x-axis: %d units", xDist);
                printf("\nDistance on y-axis: %d units", yDist); 
                printf("\n\nActual distance: %0.14lf units\n\n", distance);

                printf("Want to calculate again (Y/N)? ");
                another = getche();

                while (another != 'n' && another != 'N' && another != 'y' && another != 'Y')
                {
                    printf("\n\nEnter 'Y' for yes or 'N' for no: ");
                    another = getche();
                } 
                
                break;

            case '2':

                printf("\n\nDo you want to calculate area with\n\n");
                printf("1. Point coordinates\n");
                printf("2. Side lengths");

                printf("\n\nChoose one: ");
                methodChoice = getche();

                switch (methodChoice)
                {
                    case '1':
                        printf("\n\nEnter x,y coordinates of\n\nPoint A: ");
                        scanf("%s", &input);
                        parse(input, &ax, &ay);

                        printf("\nPoint B: ");
                        scanf("%s", &input);
                        parse(input, &bx, &by);

                        printf("\nPoint C: ");
                        scanf("%s", &input);
                        parse(input, &cx, &cy);

                        triangleAreaPoints(ax, ay, bx, by, cx, cy, &area);

                        printf("\n\nArea of triangle: %0.3lf square units\n\n", area);

                        break;

                    case '2':
                        printf("\n\nEnter side length AB: ");
                        scanf("%f", &a);

                        printf("Enter side length BC: ");
                        scanf("%f", &b);

                        printf("Enter side length CA: ");
                        scanf("%f", &c);

                        triangleAreaSides(a, b, c, &area);

                        printf("\nArea of triangle: %0.3lf square units\n\n", area);
                        break;
                    
                    default:
                        break;
                }

                printf("Want to calculate again (Y/N)? ");
                another = getche();

                while (another != 'n' && another != 'N' && another != 'y' && another != 'Y')
                {
                    printf("\n\nEnter 'Y' for yes or 'N' for no: ");
                    another = getche();
                } 
                break;

            

            default:
                break;
        }

        if(another == 'y' || another == 'Y')
        {
            printf("\n\n___________\n\n");
            continue;
        }

        if(another == 'n' || another == 'N')
        {
            printf("\n\nPress any key to exit...");
            getch();
            break;
        }
    }

}