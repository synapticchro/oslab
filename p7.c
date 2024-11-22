#include <stdio.h> 
#define MAX 10 
 
int main()  
{ 
    int allocation[MAX][MAX], max[MAX][MAX], available[MAX], 
need[MAX][MAX]; 
    int processes, resources; 
    int finish[MAX] = {0}, safeSequence[MAX]; 
     
    // Input number of processes and resources 
    printf("Enter number of processes: "); 
    scanf("%d", &processes); 
     
    printf("Enter number of resources: "); 
    scanf("%d", &resources); 
     
    // Input allocation matrix 
    printf("Enter allocation matrix:\n"); 
    for (int i = 0; i < processes; i++)  
{ 
          for (int j = 0; j < resources; j++)  
{ 
              scanf("%d", &allocation[i][j]); 
          } 
    } 
     
    // Input max matrix 
    printf("Enter max matrix:\n"); 
    for (int i = 0; i < processes; i++)  
{ 
          for (int j = 0; j < resources; j++)  
{ 
              scanf("%d", &max[i][j]); 
          } 
     } 
     
    // Input available resources 
    printf("Enter available resources:\n"); 
    for (int i = 0; i < resources; i++)  
{ 
          scanf("%d", &available[i]); 
     } 
     
    // Calculate need matrix: Need = Max - Allocation 
    for (int i = 0; i < processes; i++)  
{ 
          for (int j = 0; j < resources; j++)  
{ 
              need[i][j] = max[i][j] - allocation[i][j]; 
          } 
     } 
     
    // Banker's Algorithm to check for safe sequence 
    int count = 0; 
    for (int k = 0; k < processes; k++)  
{ 
          for (int i = 0; i < processes; i++)  
{ 
              if (!finish[i])  
{ 
                   int flag = 1; 
                   for (int j = 0; j < resources; j++)  
{ 
                        if (need[i][j] > available[j])  
{ 
                           flag = 0; 
                           break; 
                        } 
                   } 
                if (flag)  
{ 
                      for (int j = 0; j < resources; j++)  
{ 
                         available[j] += allocation[i][j]; 
                    } 
                    safeSequence[count++] = i; 
                    finish[i] = 1; 
                 } 
             } 
         } 
    } 
// Check if system is in a safe state 
    if (count == processes) { 
        printf("System is in a safe state.\nSafe sequence: "); 
        for (int i = 0; i < processes; i++)  
{ 
             printf("P%d ", safeSequence[i]); 
         } 
        printf("\n"); 
    } else  
{ 
          printf("System is not in a safe state.\n"); 
     } 
    return 0; 
} 
