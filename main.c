#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Definition de la structure
typedef struct node
{
    int val;
    struct node *link;
} node;
node *Tete, *temp, *Tet1, *ink;
int i = 1, alt;
// Def de fonction de creation

node *creation(int n)
{
    // La fonction de creation de "Nodes"
    node *HEAD = NULL;
    node *TEMP = NULL;
    node *P = NULL;

    for (int i = 0; i < n; i++)
    {

        TEMP = (node *)malloc(sizeof(node));
        // printf("Entrer la valeur %d \n", i + 1);
        TEMP->val = i + 2;
        TEMP->link = NULL;

        if (HEAD == NULL)
        {
            HEAD = TEMP;
        }
        else
        {

            P = HEAD;
            while (P->link != NULL)
            {
                P = P->link;
            } // Loop
            P->link = TEMP;

        } // else
    }
    return HEAD;
}

void display(node *HEAD)
{

    node *P = HEAD;

    while (P->link != NULL)
    {
        if ((P->link) != NULL)
            printf("%d->", P->val);
        if ((P->link) == NULL)
            printf("%d", P->val);
        P = P->link;
    }
    printf("\n");
}

// La fonction de test les nombre premier
node *premier(node *Tete)
{
    int n, i, flag, j = 1;
    node *ptr = Tete, *alt;

    while (ptr->link != NULL)
    {
        n = ptr->val;
        flag = check_prime(n);
        if (flag == 0)
        {
            printf("  %d is a prime number.\n", n);
        }
        else
        {
            // printf("%d is not a prime number.\n",n);
            // printf("%d xxxx.\n",j);
            // deleteN(&Tete,j);
            if (ptr->link == NULL)
                free(ptr);
            alt->link = ptr->link;
            free(ptr);
            ptr = alt;
        }
        alt = ptr;
        ptr = ptr->link;
        j = j + 1;
    }
    return Tete;
}
int check_prime(int a)
{
    int c;

    for (c = 2; c <= a - 1; c++)
    {
        if (a % c == 0)
            return 1;
    }
    return 0;
}
// Fonction de deletion
void deleteN(node **head, int position)
{
    node *temp;
    node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            *head = (*head)->link;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->link = temp->link;
                free(temp);
            }
            else
            {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}
int main()
{
    int n = 0;
    printf("Donner la valeur n : \n");
    scanf("%d", &n);
    Tete = creation(n);
    display(Tete);
    Tete = premier(Tete);
    display(Tete);
    return 0;
}
