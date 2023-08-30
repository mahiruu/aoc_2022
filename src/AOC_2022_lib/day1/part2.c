//
// Created by ma on 8/29/23.
//

#include <stdio.h>
#include <stdlib.h>

int update_max_values(long elf_sum, long max_values[3])
{
        if(elf_sum > max_values[0])
        {
                max_values[2] = max_values[1];
                max_values[1] = max_values[0];
                max_values[0] = elf_sum;
                return 1;
        }
        else if(elf_sum > max_values[1])
        {
                max_values[2] = max_values[1];
                max_values[1] = elf_sum;
                return 1;
        }
        else if(elf_sum > max_values[2])
        {
                max_values[2] = elf_sum;
                return 1;
        }
        return 0;
}

int day1_part2()
{
        // loop through file located at path ./input1.txt

        FILE *fp;
        fp = fopen("../src/AOC_2022_lib/day1/input1.txt", "r");

        if (fp == NULL)
        {
                printf("Error opening file!\n");
                return 1;
        }

        // read file line by line
        char line[256];
        long elf_sum = 0;
        long max_values[3];

        max_values[0] = 0;
        max_values[1] = 0;
        max_values[2] = 0;

        while (fgets(line, sizeof(line), fp))
        {
                // check if the line is empty
                if (line[0] != '\n')
                {
                        elf_sum += strtol(line, NULL, 10);
                        continue;
                }

                update_max_values(elf_sum, max_values);
                elf_sum = 0;
        }

        fclose(fp);
        printf("max value: %ld\n", max_values[0]);
        printf("max value: %ld\n", max_values[1]);
        printf("max value: %ld\n", max_values[2]);

        printf("sum of max values: %ld\n", max_values[0] + max_values[1] + max_values[2]);

        return 0;
}


