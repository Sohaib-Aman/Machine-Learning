#include <stdio.h>

int count_non_zeros(int degree_seq[], int size)
{
    int i;
    int counter=0;
    for(i=0; i<size; i++)
    {
        if(degree_seq[i] != 0)
        {
            counter++;
        }
    }
    return counter;
}
// Function to sort the degree sequence in non-increasing order
void sort_descending(int degree_seq[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (degree_seq[i] < degree_seq[j])
            {
                int temp = degree_seq[i];
                degree_seq[i] = degree_seq[j];
                degree_seq[j] = temp;
            }
        }
    }
}


int havel_hakimi(int degree_seq[],int size)
{
    while(1)
    {
        // step1: sort in non-increasing
        sort_descending(degree_seq, size);
        
        //  step2: remove all zeros and get remaining size.
        size = count_non_zeros(degree_seq, size);
        if(size == 0)
        {
            return 1;
        }
        
        // step 3: select the largest degree and remove from the list.
        int largest = degree_seq[0];
        degree_seq[0] = 0;
        // If the largest degree is greater than the number of remaining 
        // elements, it's not graphical
        if(largest > size-1)
        {
            
            return 0;
        }
        
        // Step 4: Subtract 1 from the next d elements
        int i;
        for(i=1; i<=largest; i++)
        {
            degree_seq[i] = degree_seq[i] - 1;
            
            // If any degree becomes negative, it's not graphical
            if(degree_seq[i] < 0)
            {
                
                return 0;
            }
        }
    }
    
}
int main()
{
    int size;

    // Input the size of the degree sequence
    printf("Enter the number of vertices: ");
    scanf("%d", &size);

    int degree_seq[size];

    // Input the degree sequence
    printf("Enter the degree sequence:\n");
    for (int i = 0; i < size ; i++)
    {
        scanf("%d", &degree_seq[i]);
    }

    // Apply the Havel-Hakimi algorithm
    int result = havel_hakimi(degree_seq, size);
    if (result == 1)
    {
        printf("The sequence is graphical (can represent a graph).\n");
    }
    else
    {
        printf("The sequence is not graphical (cannot represent a graph).\n");
    }

    return 0;
}
