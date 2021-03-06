#include <stdio.h>

void prchar(char c, int n)
{
    for(int i=1; i<=n; i++)
    {
        printf("%c",c);
    }
}

void drawRect(int height, int width, int filled)
{
    if(filled)
    {
        for(int i=1; i<=height ; ++i)
        {
            for(int j=1; j<=width ; ++j)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else
    {
        for(int i=1; i<=height ; ++i)
        {
            for(int j=1; j<=width ; ++j)
            {
                if(i==1 || j==1 || i==height || j==width)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

}

void drawVertT(int height, int type, int filled)
{
    switch(type)
    {
    case 1:
    {
        if(filled)
        {
            for(int i=1; i<=height ; ++i)
            {
                prchar('*',i);
                printf("\n");
            }
        }
        else
        {
            for(int i=1; i<=height ; ++i)
            {
                if(i==1 || i==height)
                {
                    prchar('*',i);
                }
                else
                {
                    printf("*");
                    prchar(' ',i-2);
                    printf("*");
                }
                printf("\n");
            }
        }
        break;
    }
    case 2:
    {
        if(filled)
        {
            for(int i=1 ; i<=height ; i++)
            {
                prchar(' ',height-i+1);
                prchar('*',i);
                printf("\n");
            }
        }
        else
        {
            for(int i=1 ; i<=height ; i++)
            {
                for(int j=1 ; j<=height ; j++)
                {
                    if(i==height || j==height || i==height || j==height-i+1)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    break;
    case 3:
    {
        if(filled)
        {
            for(int i=1 ; i<=height ; i++)
            {
                prchar('*',height-i+1);
                printf("\n");
            }
        }
        else
        {
            for(int i=1 ; i<=height ; i++)
            {
                for(int j=i ; j<=height ; j++)
                {
                    if(i==1 || j==i || j==height)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    break;
    case 4:
    {
        if(filled)
        {
            for(int i=1 ; i<=height ; i++)
            {
                prchar(' ',i);
                prchar('*',height-i+1);
                printf("\n");
            }
        }
        else
        {
            for(int i=1 ; i<=height ; i++)
            {
                for(int j=1 ; j<=height ; j++)
                {
                    if(j==i || j==height || i==1)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    }
}

void drawTri(int height, int type, int filled)
{
    switch(type)
    {
    case 1:
    {
        if(filled)
        {
            for(int i=1 ; i<=height ; i++)
            {
                prchar(' ',height-i+1);
                prchar('*',(i*2)-1);
                printf("\n");
            }
        }
        else
        {
            for(int i=1 ; i<=height ; i++)
            {
                for(int j=1 ; j<=height*2-1 ; j++)
                {
                    if(i==height|| i==height-j+1 || j==height+i-1 )
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    break;
    case 2:
    {
        if(filled)
        {
            for(int i=1 ; i<=height ; i++)
            {
                prchar(' ',i-1);
                prchar('*',2*(height-i)+1);
                printf("\n");
            }
        }
        else
        {
            for(int i=1 ; i<=height ; i++)
            {
                for(int j=1 ; j<=height*2-1 ; j++)
                {
                    if(j==i || i==1 || i==height*2-j )
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    break;
    }
}

int main()
{

    int choice;
    int height;
    int width;
    int type;
    int filled;

    while(1)
    {
        printf("Main Menu\n");
        printf("1. Rectangle\n");
        printf("2. Vertical Triangle\n");
        printf("3. Tsosceles Triangle\n");
        printf("4. Exit\n");
        printf("=> ");
        scanf("%d", &choice);
        if(choice==4)
            break;
        switch(choice)
        {
        case 1:
            printf("Enter Height, width, filled: ");
            scanf("%d %d %d", &height, &width, &filled);
            drawRect(height,width,filled);
            break;
        case 2:
            printf("Enter Height, type, filled: ");
            scanf("%d %d %d", &height, &type, &filled);
            drawVertT(height,type,filled);
            break;
        case 3:
            printf("Enter Height, type, filled: ");
            scanf("%d %d %d", &height, &type, &filled);
            drawTri(height,type,filled);
            break;
        }
    }
    return 0;
}

