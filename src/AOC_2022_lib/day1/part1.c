//
// Created by maa on 8/29/23.
//

#include <stdio.h>
#include <stdlib.h>

void day1_part1()
{
        // loop through file located at path ./input1.txt

        FILE *fp;
        fp = fopen("../src/AOC_2022_lib/day1/input1.txt", "r");

        if (fp == NULL)
        {
                printf("Error opening file!\n");
                return;
        }

        // read file line by line
        char line[256];
        long elf_sum = 0;
        long max_value = 0;

        while (fgets(line, sizeof(line), fp))
        {
               // check if the line is empty
                if (line[0] != '\n')
                {
                        elf_sum += strtol(line, NULL, 10);
                        continue;
                }

                if(elf_sum > max_value)
                {
                        max_value = elf_sum;

                }
                elf_sum = 0;

        }

        fclose(fp);
        printf("max value: %ld\n", max_value);
}